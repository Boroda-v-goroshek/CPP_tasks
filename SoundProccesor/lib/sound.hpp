#include <memory>
#include "reader.hpp"

class Convert{
public:
    virtual void change(WAV_reader& data, vector<string> args) = 0;
};


class Mix : public Convert{
public:
    int min(int a, int b);
    void change(WAV_reader& data, vector<string> args);
};


class Mute : public Convert{
public:
    void change(WAV_reader& data, vector<string> args);
};


class Increase : public Convert{
public:
    void change(WAV_reader& data, vector<string> args);
};


class GeneralCreator{
public:
    virtual unique_ptr<Convert> create() const = 0;

};


class MixCreator : public GeneralCreator{
public:
    unique_ptr<Convert> create() const;
};


class MuteCreator : public GeneralCreator{
public:
    unique_ptr<Convert> create() const;
};


class IncreaseCreator : public GeneralCreator{
public:
    unique_ptr<Convert> create() const;
};
