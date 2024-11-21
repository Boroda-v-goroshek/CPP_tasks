#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>

class Time {
    int hours, minutes, seconds;
    static unsigned count;
public:
    Time() noexcept : hours(0), minutes(0), seconds(0) {
        count++;
        std::cout << "Объект создан\n" << "Суммарно: " << count << std::endl;
    }
    Time(int h, int m, int s, bool flag = true) {
        try {
            if (h < 0 || m < 0 || s < 0) {
                throw std::invalid_argument("Неправильный формат ввода!");
            }
            hours = h;
            minutes = m;
            seconds = s;
        }
        catch (const std::invalid_argument&) {
            Time();
        }

        count++;
        if (flag) {
            std::cout << "Объект создан\n" << "Суммарно: " << count << std::endl;
        }
    }
    Time(const Time& t) noexcept : Time(t.hours, t.minutes, t.seconds, false) {
        std::cout << "Объект создан копированием\n" << "Суммарно: " << count << std::endl;
    } 

    Time& operator= (const Time& other) {
        this->hours = other.hours;
        this->minutes = other.minutes;
        this->seconds = other.seconds;
        Normilize();
        return *this;
    }
    bool operator == (const Time& other) noexcept {
        return (this->hours == other.hours &&
            this->minutes == other.minutes &&
            this->seconds == other.seconds);
    }
    Time& operator += (int s) noexcept {
        this->seconds += s;
        Normilize();
        return *this;
    }
    Time operator + (int s) const noexcept {
        return Time(hours, minutes, seconds + s);
    }
    Time& operator -= (int s) noexcept {
        return operator += (-s);
    }
    Time operator - (int s) const noexcept {
        return operator + (-s);
    }
    ~Time() noexcept {
        count--;
        std::cout << "Объект удален\n" << "Осталось: " << count << std::endl;
    } //деструктор

    int ToSeconds() const noexcept {
        int sum_sec = this->seconds;
        sum_sec += this->minutes * 60;
        sum_sec += this->hours * 3600;
        return sum_sec;
    }
    void Normilize() noexcept {
        int sum_sec = this->ToSeconds();
        if (sum_sec < 0) {
            sum_sec = (24 * 3600) + sum_sec;
        }

        this->hours = sum_sec / 3600;
        sum_sec %= 3600;
        this->minutes = sum_sec / 60;
        sum_sec %= 60;
        this->seconds = sum_sec;
    }

    int GetHours() const noexcept { return hours; }
    int GetMinutes() const noexcept { return minutes; }
    int GetSeconds() const noexcept { return seconds; }
    int SetHours(int h) const noexcept { return hours; }
    int SetMinutes() const noexcept { return minutes; }
    int SetSeconds() const noexcept { return seconds; }
    void PrintTime() noexcept {
        std::cout << this->GetHours() << ":" << this->GetMinutes() << ":" << this->GetSeconds() << std::endl;
    }


};
unsigned Time::count = 0;

int main()
{
    Time t1(1,1,1);
    Time t2(2,2,2);
    Time t3(3,3,3);

    //Time* t_ptr = new Time [3];
    //t_ptr[0] = t1;
    //t_ptr[1] = t2;
    //t_ptr[2] = t3;

    //std::vector<Time> t_vec;
    //t_vec.push_back(t1);
    //t_vec.push_back(t1);
    //t_vec.push_back(t1);

    auto t_u {std::make_unique<Time[]>(3) };
    t_u[0] = t1;

    
    //delete[] t_ptr;
    //t_ptr = nullptr;
}
