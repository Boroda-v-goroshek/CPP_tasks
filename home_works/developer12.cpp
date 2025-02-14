#include <iostream>
#include <vector>

using namespace std;

/*
районы:
    деревянный:
        дом - %
        забор - !
        сарай - :
    кирпичный:
        дом - #
        забор - $
        сарай - &
    бетонный:
        дом - @
        забор - ^
        сарай - H
*/

class abstractHouse {
    protected:
        char symbol;
    public:
        char getSymbol () {return symbol;}
};

class abstractFence {
    protected:
        char symbol;
    public:
        char getSymbol () {return symbol;}
};

class abstractBarn {
    protected:
        char symbol;
    public:
        char getSymbol () {return symbol;}
};

class WoodHouse: public abstractHouse {
    public: 
        WoodHouse (): abstractHouse() {symbol = '%';}
};
class BrickHouse: public abstractHouse {
    public: 
        BrickHouse (): abstractHouse() {symbol = '#';}
};
class ConcreteHouse: public abstractHouse {
    public: 
        ConcreteHouse (): abstractHouse() {symbol = '@';}
};

class WoodFence: public abstractFence {
    public: 
        WoodFence (): abstractFence() {symbol = '!';}
};
class BrickFence: public abstractFence {
    public: 
        BrickFence (): abstractFence() {symbol = '$';}
};
class ConcreteFence: public abstractFence {
    public: 
        ConcreteFence (): abstractFence() {symbol = '^';}
};

class WoodBarn: public abstractBarn {
    public: 
        WoodBarn (): abstractBarn() {symbol = ':';}
};
class BrickBarn: public abstractBarn {
    public: 
        BrickBarn (): abstractBarn() {symbol = '&';}
};
class ConcreteBarn: public abstractBarn {
    public: 
        ConcreteBarn (): abstractBarn() {symbol = 'H';}
};

class abstractFabric {
    public:
        virtual abstractHouse* createHouse () = 0;
        virtual abstractFence* createFence () = 0;
        virtual abstractBarn*  createBarn  () = 0;
};

class WoodCreator: public abstractFabric {
    public:
        abstractHouse* createHouse () {return new WoodHouse();}
        abstractFence* createFence () {return new WoodFence();}
        abstractBarn*  createBarn  () {return new WoodBarn ();}
};
class BrickCreator: public abstractFabric {
    public:
        abstractHouse* createHouse () {return new BrickHouse();}
        abstractFence* createFence () {return new BrickFence();}
        abstractBarn*  createBarn  () {return new BrickBarn ();}
};
class ConcreteCreator: public abstractFabric {
    public:
        abstractHouse* createHouse () {return new ConcreteHouse();}
        abstractFence* createFence () {return new ConcreteFence();}
        abstractBarn*  createBarn  () {return new ConcreteBarn ();}
};

vector<string> ClientCode (vector<string> develop_map, abstractFabric* fabrick){
    abstractHouse *house = fabrick->createHouse();
    abstractFence *fence = fabrick->createFence();
    abstractBarn  *barn  = fabrick->createBarn ();
    for (int y = 0 ; y < develop_map.size(); y++){
        for (int x = 0; x < develop_map[y].size(); x++){
            switch (develop_map[y][x])
            {
            case 'h':
             develop_map[y][x] = house->getSymbol(); 
                break;
            case 'f':
             develop_map[y][x] = fence->getSymbol(); 
                break;
            case 'b':
             develop_map[y][x] = barn->getSymbol(); 
                break;
            default:
                break;
            }
        }
    }
    return develop_map;
}

void printDistrict (vector<string> develop_map){
    for (string str : develop_map)
        cout<<str<<endl;
}

int main(){
    vector<string> develop_map = {{"ffffff"},
                            {"f  hhf"},
                            {"fb hhf"},
                            {"fb   f"},
                            {"ffffff"}};
    abstractFabric *woodFab = new WoodCreator();
    abstractFabric *brickFab = new BrickCreator();
    abstractFabric *concreteFab = new ConcreteCreator();

    cout << endl << "Деревянный район: " << endl ;
    vector<string> tmp = ClientCode(develop_map, woodFab);
    printDistrict(tmp);

    cout << endl << "Кирпичный район: " << endl;
    tmp = ClientCode (develop_map, brickFab);
    printDistrict(tmp);

    cout << endl << "Бетонный район: " << endl;
    tmp = ClientCode (develop_map, concreteFab);
    printDistrict(tmp);
    return 0;
}