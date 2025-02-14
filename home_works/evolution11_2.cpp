#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GenericCreature { // generic creature - общий родитель
    private:
        string name;
        int hanger;
    public:
        GenericCreature (string nameSelf): name(nameSelf), hanger(1) {}
        ~GenericCreature() = default;

        string introduce () { return name; }
        void pickUpFood () { hanger = 100; }
        void pickUpHanger (int n = 1) { hanger -= n; }
        int GetHunder () {return hanger;}

        virtual void eat() {cout << "i eat somethig";};  
        virtual string typeOfFood() = 0;
};
class OceanCreature: public GenericCreature {// наследник умеющий плавать
    public:
        OceanCreature (string nameSelf): GenericCreature(nameSelf) {}
        void swim() {cout << this->introduce() << " is can swim...\n"; }
        void eat() {cout << "I eat other fish\n";}
};
class Amphibious: public OceanCreature { // наследник умеющий плавать и ходить
    public:
        Amphibious (string nameSelf): OceanCreature(nameSelf) {}     
        void walk () {cout << this->introduce() <<" is can walk...\n";}  
        void eat() {cout << "I eat something small\n";} 
};
class TerrestrialCreature: public Amphibious { // не умеет плавать, но умеет ходить
    public:
        TerrestrialCreature(string nameSelf): Amphibious(nameSelf) {}  
        void swim() = delete;
        void eat() {cout << "I eat other grass and amphibious\n";}
};
class Bird : public TerrestrialCreature { // умеет ходить и летать
    public:
        Bird(string nameSelf): TerrestrialCreature(nameSelf) {}
        void fly() { cout << this->introduce() << " is can fly...\n"; };
        void eat() { cout << "I eat seeds\n";}
};
class Waterfowl : public Bird { // Умеет ходить, летать и плавать.
    public:
        Waterfowl(string nameSelf): Bird(nameSelf) {}
        using OceanCreature::swim;  
        void eat() { cout << "I can eat you\n";}
};

// Наследники для OceanCreature
class Fish : public OceanCreature {
public:
    Fish(string nameSelf):OceanCreature(nameSelf) {}
    string typeOfFood() {return "Fish";}
};
class Whale : public OceanCreature {
public:
    Whale(string nameSelf):OceanCreature(nameSelf) {}
    string typeOfFood() {return "Fish";}
};
// Наследники для Amphibious
class Frog : public Amphibious {
public:
    Frog(string nameSelf):Amphibious(nameSelf) {}
    string typeOfFood() {return "flies";}
};
class Turtle : public Amphibious {
public:
    Turtle(string nameSelf):Amphibious(nameSelf) {}
    string typeOfFood() {return "seaweed";}
};
// Наследники для TerrestrialCreature
class Lion : public TerrestrialCreature {
public:
    Lion(string nameSelf):TerrestrialCreature(nameSelf) {}
    string typeOfFood() {return "antelope";}
};
class Elephant : public TerrestrialCreature {
public:
    Elephant(string nameSelf):TerrestrialCreature(nameSelf) {}
    string typeOfFood() {return "trees";}
};
// Наследники для Bird
class Sparrow : public Bird {
public:
    Sparrow(string nameSelf):Bird(nameSelf) {}
    string typeOfFood() {return "bread";}
};
class Eagle : public Bird {
public:
    Eagle(string nameSelf):Bird(nameSelf) {}
    string typeOfFood() {return "Sparrow";}
};
// Наследники для Waterfowl
class Duck : public Waterfowl {
public:
    Duck(string nameSelf):Waterfowl(nameSelf) {}
    string typeOfFood() {return "Fish";}
};
class Swan : public Waterfowl {
public:
    Swan(string nameSelf):Waterfowl(nameSelf) {}
    string typeOfFood() {return "aquatic plants";}
};

class Creator {
    public:
        virtual GenericCreature* factoryMethod(string nameSelf) = 0;
        vector<GenericCreature*> makeHerd (string nameSelf, int n = 3){
            if (n < 3)
                throw string{"herd should be more!"};
            
            cout << "this Herd eat " << this->factoryMethod(nameSelf)->typeOfFood() << endl;
            vector<GenericCreature*> result;
            for (int i = 0; i < n; i++){
                result.push_back(this->factoryMethod(nameSelf));
                result[i]->pickUpFood();
            }
            return result;
       }
};

template <class Base>
class SpecificCreator : public Creator{
    public:
        GenericCreature* factoryMethod(string nameSelf) {return new Base(nameSelf);}
};

int main () {
    Creator* fishCreator = new SpecificCreator<Lion> ();
    vector<GenericCreature*> herd = fishCreator->makeHerd("Donald", 5);
    //herd[2]->pickUpHanger(80);
    cout << "[ ";
    for (int i = 0; i < herd.size(); i++){
        cout << "-" << herd[i]->introduce() << " " << herd[i]->GetHunder() << "-";
    }
    cout << " ]\n";
}