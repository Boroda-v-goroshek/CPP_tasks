#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>

class Time;

class Watch {
    char format;
public:
    Watch(char c) :format(c) {}

    void setTime(Time& t, int hours, int minutes, int seconds);
    void getTime(const Time& t);
    void addTime(Time& t, int hours, int minutes, int seconds);

};

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
        Normalize();
        return *this;
    }
    bool operator == (const Time& other) noexcept {
        return (this->hours == other.hours &&
            this->minutes == other.minutes &&
            this->seconds == other.seconds);
    }
    Time& operator += (int s) noexcept {
        this->seconds += s;
        Normalize();
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
    void Normalize() noexcept {
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
    void SetHours(int h) noexcept { 
        hours += h;
        Normalize();
    }
    void SetMinutes(int m) noexcept { 
        minutes += m;
        Normalize();
    }
    void SetSeconds(int s) noexcept { 
        seconds += s;
        Normalize();
    }
    void PrintTime() noexcept {
        std::cout << this->GetHours() << ":" << this->GetMinutes() << ":" << this->GetSeconds() << std::endl;
    }
    friend class SimpleWatch;

    friend void Watch::setTime(Time& t, int hours, int minutes, int seconds);
    friend void Watch::getTime(const Time& t);
    friend void Watch::addTime(Time& t, int hours, int minutes, int seconds);
};
unsigned Time::count = 0;

class SimpleWatch {
public:
    void SetTime(Time& t, int hours, int minutes, int seconds) {
        // Меняем значения полей h, m, s объекта t
        t.hours = hours;
        t.minutes = minutes;
        t.seconds = seconds;
    }

    void AddTime(Time& t, int hours, int minutes, int seconds) {
        t.SetHours(t.hours + hours);
        t.SetMinutes(t.minutes + minutes);
        t.SetSeconds(t.seconds + seconds);
    }
    void GetTime(Time& t, Watch) {
        std::cout << t.hours << ':' << t.minutes << ':' << t.seconds << std::endl;
    }
};

void Watch::setTime(Time& t, int hours, int minutes, int seconds) {
    // Меняем значения полей h, m, s объекта t
    t.hours = hours;
    t.minutes = minutes;
    t.seconds = seconds;
}
void Watch::getTime(const Time& t) {
    std::cout << t.hours << this->format << t.minutes << this->format << t.seconds << std::endl;
}
void Watch::addTime(Time& t, int hours, int minutes, int seconds) {
    t.SetHours(t.hours + hours);
    t.SetMinutes(t.minutes + minutes);
    t.SetSeconds(t.seconds + seconds);
}

int main()
{
    /*
    Time t1(1, 1, 1);
    Time t2(2, 2, 2);
    Time t3(3, 3, 3);

    //Time* t_ptr = new Time [3];
    //t_ptr[0] = t1;
    //t_ptr[1] = t2;
    //t_ptr[2] = t3;

    //std::vector<Time> t_vec;
    //t_vec.push_back(t1);
    //t_vec.push_back(t1);
    //t_vec.push_back(t1);

    auto t_u{ std::make_unique<Time[]>(3) };
    t_u[0] = t1;


    //delete[] t_ptr;
    //t_ptr = nullptr;*/

    Time t(1, 1, 1);
    SimpleWatch s_w;
    t.PrintTime();
    s_w.SetTime(t, 2, 2, 2);
    t.PrintTime();

    Watch w('-');
    w.setTime(t, 3, 3, 3);
    w.getTime(t);

    return 0;
}
