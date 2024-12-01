#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    // переменные для чтения из файла
    ifstream fin("var1.txt");
    string line;

    // переменные для создания поля
    string name;
    int h, w;
    vector<char> b, s;
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
                    b.push_back(line[i] - 48);
                }
                for (int i = temp_num + 2; i < line.length() && line[i] != '\n'; i++){
                    s.push_back(line[i] - 48);
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
    
    
    return 0;
}