#include <iostream>
#include <string>

// Базовый класс для существ
class GenericCreature {
public:
    void info() const {
        std::cout << "Я существо." << std::endl;
    }
};

// Класс для морских существ, наследуется от GenericCreature
class OceanCreature : public GenericCreature {
public:
    void swim() const {
        std::cout << "Я умею плавать!" << std::endl;
    }

    void info() const {
        GenericCreature::info();
        std::cout << "Я морское существо." << std::endl;
    }
};

// Класс для амфибий, наследуется от OceanCreature
class Amphibious : public OceanCreature {
public:
    void walk() const {
        std::cout << "Я умею ходить!" << std::endl;
    }

    void info() const {
        OceanCreature::info();
        std::cout << "Я амфибия." << std::endl;
    }
};

// Класс для наземных существ, наследуется от GenericCreature
class TerrestrialCreature : public Amphibious {
public:
    void swim() const = delete;

    void info() const {
        Amphibious::info();
        std::cout << "Я наземное существо." << std::endl;
    }
};

// Класс для птиц, наследуется от TerrestrialCreature
class Bird : public TerrestrialCreature {
public:
    void fly() const {
        std::cout << "Я умею летать!" << std::endl;
    }

    void info() const {
        TerrestrialCreature::info();
        std::cout << "Я птица." << std::endl;
    }
};

// Класс для водоплавающих птиц, наследуется от Bird
class Waterfowl : public Bird {
public:
    using OceanCreature::swim;
    void info() const {
        Bird::info();
        std::cout << "Я водоплавающая птица." << std::endl;
    }
};

int main() {
    // Создаем объекты различных классов
    GenericCreature generic;
    OceanCreature ocean;
    Amphibious amphibian;
    TerrestrialCreature terrestrial;
    Bird bird;
    Waterfowl waterfowl;

    

    return 0;
}