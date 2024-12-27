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
class OceanCreature : private GenericCreature {
public:
    void move_ocean_creature() const {
        std::cout << "Я умею плавать!" << std::endl;
    }

    void info() const {
        GenericCreature::info();
        std::cout << "Я морское существо." << std::endl;
    }
};

// Класс для амфибий, наследуется от OceanCreature
class Amphibious : private OceanCreature {
public:
    void move_amphibious() const {
        OceanCreature::move_ocean_creature();
        std::cout << "Я умею ходить!" << std::endl;
    }

    void info() const {
        OceanCreature::info();
        std::cout << "Я амфибия." << std::endl;
    }
};

// Класс для наземных существ, наследуется от GenericCreature
class TerrestrialCreature : private Amphibious {
public:
    void move_terresrial_creature() const {
        std::cout << "Я умею ходить!" << std::endl;
    }

    void info() const {
        Amphibious::info();
        std::cout << "Я наземное существо." << std::endl;
    }
};

// Класс для птиц, наследуется от TerrestrialCreature
class Bird : private TerrestrialCreature {
public:
    void move_bird() const {
        TerrestrialCreature::move_terresrial_creature();
        std::cout << "Я умею летать!" << std::endl;
    }

    void info() const {
        TerrestrialCreature::info();
        std::cout << "Я птица." << std::endl;
    }
};

// Класс для водоплавающих птиц, наследуется от Bird
class Waterfowl : private Bird {
public:
    void move_waterfowl() const {
        Bird::move_bird();
        std::cout << "Я умею плавать!" << std::endl;
    }

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

    // Демонстрируем работу методов
    generic.info();
    std::cout << "----" << std::endl;
    ocean.info();
    ocean.move_ocean_creature();
    std::cout << "----" << std::endl;
    
    amphibian.info();
    amphibian.move_amphibious();
    std::cout << "----" << std::endl;
    
    terrestrial.info();
    terrestrial.move_terresrial_creature();
    std::cout << "----" << std::endl;
    
    bird.info();
    bird.move_bird();
    std::cout << "----" << std::endl;
    
    waterfowl.info();
    waterfowl.move_waterfowl();
    std::cout << "----" << std::endl;

    return 0;
}