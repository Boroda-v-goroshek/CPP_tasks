#include <chrono>
#include <thread>
#include <sstream>
#include "lib/Life.hpp"

//using namespace std;

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
        int num;
        if (iss >> num) { 
            for (int i = 0; i < num; ++i) {
                game_field.draw();
                this_thread::sleep_for(chrono::milliseconds(500));
                game_field.update();
            }
            game_field.draw();
            cout << "Iteration: " << num << endl;
        }
        else if (iss.eof()){
            game_field.draw();
            this_thread::sleep_for(chrono::milliseconds(500));
            game_field.update();
            cout << "Iteration: 1" << endl;
        }
    } 
    else if (cmd == "exit") {
        cout << "Exiting the game..." << endl;
        exit(0); // Завершите программу
    } 
    else if (cmd == "help") {
        cout << "Available commands:\n";
        cout << "1. dump <filename> - Save universe to file\n";
        cout << "2. tick <n> (or t <n>) - Calculate n iterations (default 1)\n";
        cout << "3. exit - Exit the game\n";
        cout << "4. help - Print this help message\n";
    } 
    else {
        cout << "Unknown command: " << cmd << endl;
    }
    return 1;
}

int main(int argc, char **argv){
    vector<string> argv_s;
    for (int i = 0; i < argc; i++){
        string str = (string)argv[i];
        argv_s.push_back(str);
    }

    //cout << argc << endl;
    string input_file;
    string output_file;
    int iteration;

    if (argc == 2 && (argv_s[1] == "--help" || argv_s[1] == "-h")){
        cout << "Использование:" << endl;
        cout << argv[0] << " --input inputfile -i x(--iteration x) -o outfile(--output outfile)" << endl;
        cout << argv[0] << " inputfile" << endl;
        cout << argv[0];
        return 0;
    }
    else if (argc == 1){
        cout << "Введите число от 1 до 4 включительно" << endl;

        int temp;
        cin >> temp;
        if (temp < 1 || temp > 5){
            cout << "Неверный формат ввода!" << endl;
            return 0;
        }
        input_file = "var" + to_string(temp) + ".txt";
    }
    else if (argc == 2){
        input_file = argv_s[1];
    }
    else if (argc == 7 && argv_s[1] == "--input" && (argv_s[3] == "-i" || argv_s[3] == "--iteration") && (argv_s[5] == "-o" || argv_s[5] == "--output")){
        input_file = argv[2];
        iteration = stoi(argv[4]);
        output_file = argv[6];
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
    else {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    Field game_field(h, w, b, s, coordinates, name);
    while (1){
        cout << "Ожидается ввод команды:";
        string command;
        getline(cin, command);

        if (argc != 7){
            if (!handleCommand(command, game_field)){break;}
        }
        else{
            command = "tick " + to_string(iteration);
            handleCommand(command, game_field);
            command = "dump" + output_file;
            handleCommand(command, game_field);
            break;
        }
    }
    return 0;
}