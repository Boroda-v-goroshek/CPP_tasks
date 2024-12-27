#include <iostream>
#include <vector>
#include <memory>

class House {
public:
    virtual void build() const = 0;
    virtual ~House() = default;
};

class WoodHouse : public House {
public:
    void build() const override {
        std::cout << "Building a Wooden House." << std::endl;
    }
};

class BrickHouse : public House {
public:
    void build() const override {
        std::cout << "Building a Brick House." << std::endl;
    }
};

class ConcreteHouse : public House {
public:
    void build() const override {
        std::cout << "Building a Concrete House." << std::endl;
    }
};

class Developer {
public:
    virtual std::unique_ptr<House> BuildHouse() = 0;
    virtual ~Developer() = default;
};

class WoodHouseDeveloper : public Developer {
public:
    std::unique_ptr<House> BuildHouse() override {
        return std::make_unique<WoodHouse>();
    }
};

class BrickHouseDeveloper : public Developer {
public:
    std::unique_ptr<House> BuildHouse() override {
        return std::make_unique<BrickHouse>();
    }
};

class ConcreteHouseDeveloper : public Developer {
public:
    std::unique_ptr<House> BuildHouse() override {
        return std::make_unique<ConcreteHouse>();
    }
};

class Neighborhood {
public:
    void constructNeighborhood(Developer& developer, int houseCount) {
        std::vector<std::unique_ptr<House>> houses;
        for (int i = 0; i < houseCount; ++i) {
            houses.push_back(developer.BuildHouse());
        }
        
        for (const auto& house : houses) {
            house->build();
        }
    }
};

int main() {
    Neighborhood neighborhood;
    int houseCount = 10; // Пример: 10 домов в квартале

    std::cout << "Constructing Wooden Houses:" << std::endl;
    WoodHouseDeveloper woodDeveloper;
    neighborhood.constructNeighborhood(woodDeveloper, houseCount);

    std::cout << "\nConstructing Brick Houses:" << std::endl;
    BrickHouseDeveloper brickDeveloper;
    neighborhood.constructNeighborhood(brickDeveloper, houseCount);

    std::cout << "\nConstructing Concrete Houses:" << std::endl;
    ConcreteHouseDeveloper concreteDeveloper;
    neighborhood.constructNeighborhood(concreteDeveloper, houseCount);

    return 0;
}