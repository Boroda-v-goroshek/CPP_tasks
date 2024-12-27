#ifndef READER_H
#define READER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Reader {
public:
    virtual void read(ifstream& conf) = 0; // Чисто виртуальная функция
    virtual ~Reader() {} // Виртуальный деструктор
};

class Conf_reader : public Reader {
    string command;
    vector<string> args;

public:
    void read(ifstream& conf) override; // Нормальная переопределенная функция
};

class WAV_reader : public Reader {
public:
    void read(ifstream& conf) override; // Переопределяем метод
};

#endif // READER_H