#include <iostream>
#include <vector>

// Абстрактный базовый класс
class GenericCreature {
public:
    virtual void eat(){std::cout << "alalal" << std::endl;} 
    ~GenericCreature() {}
};

// Класс для морских существ
class OceanCreature : public GenericCreature {
public:
    void eat() { std::cout << "OceanCreature ate some small fish." << std::endl; }
};

// Класс для амфибий
class Amphibious : public OceanCreature {
public:
    void eat() { std::cout << "Amphibious creature is catching insects." << std::endl; }
};

// Класс для наземных существ
class TerrestrialCreature : public GenericCreature {
public:
    void eat() { std::cout << "TerrestrialCreature is grazing on grass." << std::endl; }
};

// Класс для птиц
class Bird : public TerrestrialCreature {
public:
    void eat() { std::cout << "Bird is pecking seeds." << std::endl; }
};

// Класс для водоплавающих птиц
class Waterfowl : public Bird, public OceanCreature {
public:
    void eat() { std::cout << "Om-nom-nom..." << std::endl; }
};

// Функция для демонстрации полиморфного поведения
void demonstratePolymorphism(const std::vector<GenericCreature> &creatures) {
    for (auto creature : creatures) {
        creature.eat(); // Полиморфный вызов eat()
    }
}

int main() {
    OceanCreature oceanCreature;
    Amphibious amphibiousCreature;
    TerrestrialCreature terrestrialCreature;
    Bird bird;
    Waterfowl waterfowl;

    std::vector<GenericCreature> creatures;
    creatures.push_back(oceanCreature);
    creatures.push_back(amphibiousCreature);
    creatures.push_back(terrestrialCreature);
    creatures.push_back(bird);
    //creatures.push_back(waterfowl);

    // Демонстрация полиморфного поведения
    std::cout << "Demonstrating polymorphism:" << std::endl;
    demonstratePolymorphism(creatures);

    return 0;
}