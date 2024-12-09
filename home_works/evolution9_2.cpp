#include <iostream>
#include <string>

// Базовый класс для всех существ
class GenericCreature {
public:

    GenericCreature(){std::cout << "Создано общее существо." << std::endl;}
    // Метод для отображения информации о существе
    void info() const {
        std::cout << "Это общее существо." << std::endl;
    }
};

// Класс для морских существ, наследует от GenericCreature
class OceanCreature : virtual public GenericCreature {
public:
    void swim() const {
        std::cout << "Я умею плавать!" << std::endl;
    }

    void info() const {
        GenericCreature::info();
        std::cout << "Я морское существо." << std::endl;
    }
};

// Класс для амфибий, наследует от OceanCreature
class Amphibious : virtual public OceanCreature {
public:
    void walk() const {
        std::cout << "Я умею ходить!" << std::endl;
    }

    void info() const {
        OceanCreature::info();
        std::cout << "Я амфибия." << std::endl;
    }
};

// Класс для наземных существ, наследует от GenericCreature
class TerrestrialCreature : public GenericCreature {
public:
    void walk() const {
        std::cout << "Я умею ходить!" << std::endl;
    }

    void info() const {
        GenericCreature::info();
        std::cout << "Я наземное существо." << std::endl;
    }
};

// Класс для птиц, наследует от TerrestrialCreature
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

// Класс для водоплавающих птиц, наследует от Bird
class Waterfowl : public Bird, public OceanCreature {
public:
    void swim() const {
        std::cout << "Я умею плавать!" << std::endl;
    }

    void info() const {
        Bird::info();
        OceanCreature::info();

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

    // Демонстрируем работу методов
    generic.info();
    std::cout << "----" << std::endl;
    ocean.info();
    ocean.swim();
    std::cout << "----" << std::endl;
    
    amphibian.info();
    amphibian.swim();
    amphibian.walk();
    std::cout << "----" << std::endl;
    
    terrestrial.info();
    terrestrial.walk();
    std::cout << "----" << std::endl;
    
    bird.info();
    bird.walk();
    bird.fly();
    std::cout << "----" << std::endl;
    
    waterfowl.info();
    waterfowl.walk();
    waterfowl.fly();
    waterfowl.swim();
    std::cout << "----" << std::endl;

    return 0;
}