#include <chrono>
#include <thread>
#include <sstream>
#include <lib/Life.hpp>

using namespace std;

int handleCommand(const string& command, Field& game_field) {
    istringstream iss(command);
    string cmd;
    iss >> cmd; // Получить первую часть команды

    if (cmd == "dump") {
        string filename;
        iss >> filename;
        game_field.dump(filename);
        return 0;
    } 
    else if (cmd == "tick" || cmd == "t") {
        int n = 1; // По умолчанию n = 1
        if (iss >> n) {
            // Если n было указано, то прочитаем его
            for (int i = 0; i < n; ++i) {
                game_field.update();
                game_field.draw();
                this_thread::sleep_for(chrono::milliseconds(200));
            }
            cout << "Iteration: " << n << endl;
        }
    } 
    else if (cmd == "exit") {
        cout << "Exiting the game..." << endl;
        exit(0); // Завершите программу
    } 
    else if (cmd == "help") {
        cout << "Available commands:\n";
        cout << "1. dump <filename> - Save universe to file\n";
        cout << "2. tick <n=1> (or t <n=1>) - Calculate n iterations (default 1)\n";
        cout << "3. exit - Exit the game\n";
        cout << "4. help - Print this help message\n";
    } 
    else {
        cout << "Unknown command: " << cmd << endl;
    }
    return 1;
}

int main(int argc, char **argv){
    string input_file;
    string output_file;
    int iteration;

    if (argv[2] == "--help" || argv[2] == "-h"){
        cout << "Использование:" << endl;
        cout << argv[0] << " inputfile -i x(--iteration=x) -o outfile(--output=outfile)" << endl;
        cout << argv[0] << " inputfile" << endl;
        cout << argv[0];
        return 0;
    }
    else if (argc == 0){
        cout << "Введите число от 1 до 5 включительно" << endl;

        int temp;
        cin >> temp;
        if (temp < 1 || temp > 5){
            cout << "Неверный формат ввода!" << endl;
            return 0;
        }
        input_file = "var" + to_string(temp) + ".txt";
    }
    else if (argc == 2){
        input_file = argv[1];
    }
    else if (argc == 6){
        input_file = argv[1];
        iteration = stoi(argv[3]);
        output_file = argv[5];
    }
    else{
        cout << "Неверный формат ввода!" << endl;
        return 0;
    }

    // переменные для чтения из файла
    ifstream fin(input_file);
    string line;

    // переменные для создания поля
    string name;
    int h, w;
    set<int> b, s;
    vector<int> coordinates;

    if (fin.is_open()){

        while (getline(fin, line)){
            if (line[1] == 'N'){
                name = line;
                name.erase(0, 3);
            }
            else if (line[1] == 'R'){
                int temp_num;

                for (int i = 4; i < line.length(); i++){
                    if (line[i] == '/'){
                        temp_num = i;
                        break;
                    }
                    b.insert(line[i] - 48);
                }
                for (int i = temp_num + 2; i < line.length() && line[i] != '\n'; i++){
                    s.insert(line[i] - 48);
                }
            }
            else if (line[1] == 'S'){
                string temp;
                int temp_num;

                for (int i = 3; i < line.length(); i++){
                    if (line[i] == 'x'){
                        temp_num = i;
                        break;
                    }
                    temp.push_back(line[i]);
                }

                h = stoi(temp);
                temp.erase();

                for (int i = temp_num + 1; i < line.length() && line[i] != '\n'; i++){
                    temp.push_back(line[i]);
                }
                w = stoi(temp);
            }
            else if (line[0] != '#') {
                int sign = 1;
                string temp;
                int temp_num;

                for (int i = 0; i < line.length(); i++){
                    if (line[i] == ' ') {
                        temp_num = i;
                        break;
                    }
                    if (line[i] == '-') {sign = -1;}
                    else if (line[i] != ' ') {temp.push_back(line[i]);}
                }
                
                coordinates.push_back(sign * stoi(temp));
                temp.erase();
                sign = 1;

                for (int i = temp_num + 1; i < line.length() && line[i] != '\n'; i++){
                    if (line[i] == '-') {sign = -1;}
                    else if (line[i] != ' ') {temp.push_back(line[i]);}
                }
                coordinates.push_back(sign * stoi(temp));
            }
        }
    }

    Field game_field(h, w, b, s, coordinates, name);
    while (1){
        string command;

        if (argc != 6){
            if (cin.peek() != '\n') { // Проверка, есть ли ввод
                getline(cin, command);
                if (!handleCommand(command, game_field)){break;}
            }
        }
        else{
            command = "tick " + iteration;
            handleCommand(command, game_field);
            command = "dump" + output_file;
            handleCommand(command, game_field);
            break;
        }
    }
    return 0;
}