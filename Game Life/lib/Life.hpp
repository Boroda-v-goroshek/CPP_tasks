#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <fstream>

using namespace std;

class Cell{
    bool status;
    int neighbours;

public:

    Cell(int neighbours = 0, bool status = false);
    ~Cell();
    void to_life();
    void to_dead();
    void inc();
    void dec();
    bool is_life();
    int get_n();
};

class Field
{
    string name;
    int h, w;
    set<int> rules_b, rules_s;
    vector<vector<Cell>> field;
public:

    // Реализация зацикленного поля
    pair<int, int> normalize(int x, int y);

    void change(int x, int y, int sign);

    // Изменение кол-ва соседей для клеток вокруг заданной
    void changes(int x, int y, int sign);

    vector<vector<int>> GetN();

    void printRules();

    Field(int height, int width, set<int> b, set<int> s, vector<int> coordinates, string name);



    void draw();

    void update();

    void dump(string filename);

    vector<int> getSize();
    string getName();
    vector<vector<Cell>> getField();
    vector<set<int>> getRules();


};