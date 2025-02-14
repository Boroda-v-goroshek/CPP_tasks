#include <iostream>
#include <iomanip>

class Time {
private:
    int *hours;
    int *minutes;
    int *seconds;
    bool format24; // true для 24-часового формата, false для 12-часового формата
    int id;
    static int objectCount; // Счетчик объектов

public:
    // Конструктор
    Time(int h = 0, int m = 0, int s = 0, bool f24 = true): id (objectCount) {
        hours = new int (h);
        minutes = new int(m);
        seconds = new int (s);
        Normalize();
        objectCount++;
        std::cout << "Создан объект: " << id << std::endl;
    }

    Time(const Time& moved){
        id = objectCount++;
        hours = moved.hours;
        minutes = moved.minutes;
        seconds = moved.seconds;
        std::cout << "Создан объект копированием. " << id << std::endl;
        std::cout << "Копирование из " << moved.id << " в " << id << std::endl;

    }

    Time(Time&& moved){
        id = objectCount++;
        hours = moved.hours;
        minutes = moved.minutes;
        seconds = moved.seconds;
        moved.hours = 0;
        moved.minutes = 0;
        moved.seconds = 0;
        std::cout << "Создан объект перемещением. " << id << std::endl;
        std::cout << "Копирование из " << moved.id << " в " << id << std::endl;

    }

    Time& operator=(Time&& moved){
        std::cout << "Приравниваем объект " << this->id << " к объекту " << moved.id << std::endl;
        if (this != &moved){
           hours = moved.hours;
           minutes = moved.minutes;
           seconds = moved.seconds;
           moved.hours = 0;
           moved.minutes = 0;
           moved.seconds = 0;
        }
        return *this;
    }

    // Деструктор
    ~Time() {
        objectCount--;
        std::cout << "Удаление объекта: " << id << std::endl;
    }

    // Функция для нормализации времени
    void Normalize() {
        if (*seconds >= 60) {
            *minutes += *seconds / 60;
            *seconds = (*seconds) % 60;
        } else if (*seconds < 0) {
            *minutes -= (-*seconds) / 60 + 1;
            *seconds = (*seconds % 60 + 60) % 60;
        }

        if (*minutes >= 60) {
            *hours += *minutes / 60;
            *minutes %= 60;
        } else if (*minutes < 0) {
            *hours -= (-*minutes) / 60 + 1;
            *minutes = (*minutes % 60 + 60) % 60;
        }

        if (format24) {
            *hours = *hours % 24;
        } else {
            *hours = *hours % 12;
            if (*hours < 0) *hours += 12;
        }
    }

    // Функция для вывода времени
    void Print() const {
        std::cout << std::setw(2) << std::setfill('0') << *hours << ":";
        std::cout << std::setw(2) << std::setfill('0') << *minutes << ":";
        std::cout << std::setw(2) << std::setfill('0') << *seconds;
        if (!format24) {
            std::cout << (*hours < 12 ? " AM" : " PM");
        }
        std::cout << std::endl;
    }
};

// Инициализация статической переменной
int Time::objectCount = 0;

using namespace std;

int main() {
    cout << "t1" << endl;
    Time t1(12, 0, 1, true); 
    t1.Print();
    cout << "t2" << endl;
    Time t2 = std::move(t1);
    t2.Print();
    cout << "t3" << endl;
    Time t3 = (Time(1, 2, 3));
    t3.Print();
    cout << "t1=tx" << endl;
    Time tx(12, 0, 1, false);
    t1 = std::move(tx);
    t1.Print();
    cout << "t6" << endl;
    Time t6 = std::move(Time(1,3,2));
    t6.Print();
    return 0;
}