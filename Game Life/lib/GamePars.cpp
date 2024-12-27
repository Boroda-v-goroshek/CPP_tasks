#include "lib/Life.hpp"
#include "GamePars.hpp"

using namespace std;
int Pars::Argpars(int argc, char **argv, string* input_file, string* output_file, int* iteration){
    vector<string> argv_s;
    for (int i = 0; i < argc; i++){
        string str = (string)argv[i];
        argv_s.push_back(str);
    }


    if (argc == 2 && (argv_s[1] == "--help" || argv_s[1] == "-h")){
        cout << "Использование:" << endl;
        cout << argv[0] << " --input inputfile -i x(--iteration x) -o outfile(--output outfile)" << endl;
        cout << argv[0] << " inputfile" << endl;
        cout << argv[0];
        return 1;
    }
    else if (argc == 1){
        cout << "Введите число от 1 до 4 включительно" << endl;

        int temp;
        cin >> temp;
        if (temp < 1 || temp > 5){
            cout << "Неверный формат ввода!" << endl;
            return 1;
        }
        *input_file = "var/var" + to_string(temp) + ".txt";
    }
    else if (argc == 2){
        *input_file = argv_s[1];
    }
    else if (argc == 7 && argv_s[1] == "--input" && (argv_s[3] == "-i" || argv_s[3] == "--iteration") && (argv_s[5] == "-o" || argv_s[5] == "--output")){
        *input_file = argv[2];
        *iteration = stoi(argv[4]);
        *output_file = argv[6];
    }
    else{
        cout << "Неверный формат ввода!" << endl;
        return 1;
    }
    return 0;
}
Field Pars::Gamepars(string input_file){
    // переменные для чтения из файла
mark:
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
                int temp_num, id = 2;
                if (line[3] > 47 && line[3] < 58){id = 3;}

                for (int i = id; i < line.length(); i++){
                    if (line[i] == 'x'){
                        temp_num = i;
                        break;
                    }
                    temp.push_back(line[i]);
                }

                h = stoi(temp);
                temp.erase();

                if ((!line[temp_num] > 47) && (!line[temp_num] < 58)){temp_num++;}
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
        cout << "Не удалось открыть файл! Игра будет происходить на одном из заранее созданных полей!" << endl;
        input_file = "var/var2.txt";
        goto mark;
    }
    Field game(h, w, b, s, coordinates, name);
    return game;
}
