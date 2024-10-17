#include <iostream>

class Time{
    int hours, minutes, seconds;
public:
    Time(){} //default конструктор
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {} //конструктор
    Time(const Time& t) : Time(t.hours, t.minutes, t.seconds) {} //конструктор копирования

    Time& operator= (const Time& other) {
        this->hours = other.hours;
        this->minutes = other.minutes;
        this->seconds = other.seconds;
        Normilize();
        return *this;
    }
    bool operator == (const Time& other){
        return (this->hours == other.hours &&
        this->minutes == other.minutes &&
        this->seconds == other.seconds);
    }
    Time& operator += (int s){
        this->seconds += s;
        Normilize();
        return *this;
    }
    Time operator + (int s) const{
        return Time(hours, minutes, seconds + s);
    }
    Time& operator -= (int s){
        return operator += (-s);
    }
    Time operator - (int s) const{
        return operator + (-s);
    }
    ~Time(){} //деструктор

    int ToSeconds() const{
        int sum_sec = this->seconds;
        sum_sec += this->minutes * 60;
        sum_sec += this->hours * 3600;
        return sum_sec;
    }
    void Normilize(){
        int sum_sec = this->ToSeconds();
        if (sum_sec < 0){
            sum_sec = (24 * 3600) + sum_sec;
        }

        this->hours = sum_sec / 3600;
        sum_sec %= 3600;
        this->minutes = sum_sec / 60;
        sum_sec %= 60;
        this->seconds = sum_sec;
    }

    int GetHours() const{ return hours; }
    int GetMinutes() const{ return minutes; }
    int GetSeconds() const{ return seconds; }
    void PrintTime(){
        std::cout << this->GetHours() << ": " << this->GetMinutes() << ": " << this->GetSeconds() << std::endl;
    }


};

int main(){


    return 0;
}
