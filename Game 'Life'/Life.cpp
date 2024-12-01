#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

class Cell{
    bool status;
    int neighbours;
public:

    Cell(int neighbours = 0, bool status = false) : status(status), neighbours(neighbours) {}
    ~Cell(){}
    void to_life(){this->status = true;}
    void to_dead(){this->status = false;}
    void inc(){this->neighbours++;}
    void dec(){this->neighbours--;}
    bool is_life(){return this->status;}
    int get_n(){return this->neighbours;}
};


class Field
{
    string name;
    int h, w;
    set<int> rules_b, rules_s;
    vector<vector<Cell>> field;
public:

    // Реализация зацикленного поля
    pair<int, int> normalize(int x, int y){
        if (x < 0){x = w - 1;}
        else if (x >= w){x = 0;}

        if (y < 0){y = h - 1;}
        else if (y >= h){y = 0;}

        return pair<int, int>(x, y);
    }

    void change(int x, int y, int sign){
        auto [id_x, id_y] = normalize(x, y);
        if (sign == 1){field[id_y][id_x].inc();}
        else {field[id_y][id_x].dec();}
    }

    // Изменение кол-ва соседей для клеток вокруг заданной
    void changes(int x, int y, int sign){

        change(x + 1, y, sign);
        change(x - 1, y, sign);

        change(x, y + 1, sign);
        change(x, y - 1, sign);

        change(x + 1, y + 1, sign);
        change(x + 1, y - 1, sign);

        change(x - 1, y + 1, sign);
        change(x - 1, y - 1, sign);
    }

    void printN(){
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cout << field[i][j].get_n() << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    void printRules(){
        for (auto rule : rules_b){
            cout << rule << ' ';
        }
        cout << endl;
        for (auto rule : rules_s){
            cout << rule << ' ';
        }
        cout << endl;
    }

    Field(int height, int width, set<int> b, set<int> s, vector<int> coordinates, string name)
    :h(height), w(width), rules_b(b), rules_s(s), name(name)
    {
        field.resize(h, vector<Cell>(w));
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                field[i][j] = Cell();
            }
        }

        for (int i = 0; i < coordinates.size(); i += 2){
            int id_x = w/2 + coordinates[i] - 1, id_y = h/2 - coordinates[i + 1] - 1;
            field[id_y][id_x].to_life();
            changes(id_x, id_y, 1);        
        }
    }
    ~Field(){
        name = nullptr;
        rules_b.clear();
        rules_s.clear();
    }

    void draw(){
        cout << name << endl;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if(field[i][j].is_life()){
                    cout << "■ "; // Живые клетки
                }
                else{
                    cout << "□ "; // Мертвые клетки
                }
            }
            cout << endl;
        }
        cout << endl;
        system("clear");
    }

    void update(){
        vector<pair<int,int>> to_changes;

        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                int neighbours_count = field[i][j].get_n();
                pair<int, int> temp;

                    // если кандидат на жизнь
                if (rules_b.count(neighbours_count)){
                    if (!field[i][j].is_life()){
                        temp.first = j;
                        temp.second = i;
                        to_changes.push_back(temp);
                    }
                }
                    // если кандидат на смерть
                else if (!rules_s.count(neighbours_count)){
                    if (field[i][j].is_life()){
                        temp.first = -j;
                        temp.second = -i;
                        to_changes.push_back(temp);
                    }
                }
            }
        }

        // итерируем систему
        for (int j = 0; j < to_changes.size(); j++){
            int id_x = to_changes[j].first, id_y = to_changes[j].second;

            if (id_x < 0 || id_y < 0){
                field[-id_y][-id_x].to_dead();
                changes(-id_x, -id_y, -1);
            }
            else{
                field[id_y][id_x].to_life();
                changes(id_x, id_y, 1);
            }
        }
    }
};

int main(){
    // переменные для чтения из файла
    ifstream fin("var1.txt");
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
    //game_field.printN();
    game_field.update();
    game_field.draw();
    game_field.update();
    game_field.draw();



    return 0;
}
