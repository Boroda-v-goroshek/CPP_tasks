#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define LINE_IS_NUMBER (line[i] > 47 && line[i] < 58)

int str2num(std::string line, int start, int len){

}

int main(){
    // переменные для чтения из файла
    std::ifstream fin("var1.txt");
    std::string line;

    // переменные для создания поля
    std::string name;
    int h = 0, w = 0, n = 10;
    std::vector<char> b(8), s(8);
    std::vector<int> coordinates[n];

    if (fin.is_open()){
        int coordinates_count = 0;

        while (std::getline(fin, line)){
            if (line[1] == 'N'){
                name = line;
                name.erase(0, 3);
            }
            else if (line[1] == 'R'){
                int len_b = 0, len_s = 0, flag = 1;

                for (int i = 0; i < line.length(); i++){
                    if (line[i] == '/'){
                        flag = 2;
                    }
                    else if (LINE_IS_NUMBER && flag == 1){
                        b[len_b] = line[i] - 48;
                        len_b++;
                    }
                    else if (LINE_IS_NUMBER && flag == 2){
                        s[len_s] = line[i] - 48;
                        len_s++;
                    }
                }
                b.resize(len_b), s.resize(len_s);
            }
            else if (line[1] == 'S'){
                int len_h = 0, len_w = 0, flag = 1;

                for (int i = 0; flag != 3; i++){
                    if (flag == 1 && LINE_IS_NUMBER){
                        flag = 2;

                        char c = 0;
                        for (int j = i; c != 'x'; j++){
                            c = line[j];
                            len_h++;
                        }
                        h = str2num(line, i, len_h);
                    }
                    else if (flag == 2){
                        flag = 3;

                        char c = 0;
                        for (int j = i; c != '\0'; j++){
                            c = line[j];
                            len_w++;
                        }
                        w = str2num(line, i, len_w);
                    }
                }
            }
            else{
                coordinates_count++;
            }
        }
    }
    
    return 0;
}