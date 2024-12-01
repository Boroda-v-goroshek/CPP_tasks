#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

class Cell{
    bool status;
    int neighbours;
    //int x, y;

public:

    Cell(int neighbours = 0, bool status = true){
        //this->x = x;
        //this->y = y;
        this->status = status;
        this->neighbours = neighbours;
    }

    void to_life(){this->status = true;}
    void to_dead(){this->status = false;}
    bool is_life(){return this->status;}
};