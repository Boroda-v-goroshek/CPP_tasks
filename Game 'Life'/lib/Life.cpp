#include <Life.hpp>

using namespace std;

Cell::Cell(int neighbours = 0, bool status = false) : status(status), neighbours(neighbours) {}
Cell::~Cell(){}
void Cell::to_life(){this->status = true;}
void Cell::to_dead(){this->status = false;}
void Cell::inc(){this->neighbours++;}
void Cell::dec(){this->neighbours--;}
bool Cell::is_life(){return this->status;}
int Cell::get_n(){return this->neighbours;}

    /**
     * Реализация зацикленного поля
     */
    pair<int, int> Field::normalize(int x, int y){
        if (x < 0){x = w - 1;}
        else if (x >= w){x = 0;}

        if (y < 0){y = h - 1;}
        else if (y >= h){y = 0;}

        return pair<int, int>(x, y);
    }

    void Field::change(int x, int y, int sign){
        auto [id_x, id_y] = normalize(x, y);
        if (sign == 1){field[id_y][id_x].inc();}
        else {field[id_y][id_x].dec();}
    }

    /**
     * Изменение кол-ва соседей для клеток вокруг заданной
     */
    void Field::changes(int x, int y, int sign){

        change(x + 1, y, sign);
        change(x - 1, y, sign);

        change(x, y + 1, sign);
        change(x, y - 1, sign);

        change(x + 1, y + 1, sign);
        change(x + 1, y - 1, sign);

        change(x - 1, y + 1, sign);
        change(x - 1, y - 1, sign);
    }

    /**
     * Выводит поле, где каждая клетка характеризуется
     * кол-вом соседей
     */
    void Field::printN(){
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cout << field[i][j].get_n() << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    Field::Field(int height, int width, set<int> b, set<int> s, vector<int> coordinates, string name)
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
    Field::~Field(){
        name = nullptr;
        rules_b.clear();
        rules_s.clear();
    }
    /**
     * Вывод состояния поля
     */
    void Field::draw(){
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

    /**
     * Одна итерация системы
     */
    void Field::update(){
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

    void Field::dump(string filename){
        ofstream outfile(filename);
        if (!outfile) {
            cerr << "Не удалось открыть файл для записи: " << filename << endl;
            return;
        }

        // Записываем метаданные
        outfile << "#Life 1.06\n";
        outfile << "#N " << name << "\n";
        outfile << "#R B";
        for (auto elem : rules_b){
            outfile << elem;
        }
        outfile << "/S";
        for (auto elem : rules_s){
            outfile << elem;
        }
        outfile << '\n';
        outfile << "#S " << h << "x" << w << "\n";

        // Записываем координаты живых клеток
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (field[y][x].is_life()) {
                    // Вычисляем координаты относительно центра
                    int relative_x = x + (w / 2);
                    int relative_y = (h / 2) - y; // обрати внимание на направление оси Y
                    outfile << relative_x << " " << relative_y << "\n";
                }
            }
        }

        outfile.close();
        cout << "Состояние вселенной успешно записано в файл: " << filename << endl;
    }

    