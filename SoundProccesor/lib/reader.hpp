#ifndef READER_H
#define READER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Reader {
public:
    virtual int read(ifstream& conf) = 0; // Чисто виртуальная функция
    virtual ~Reader() {} // Виртуальный деструктор
};


class Conf_reader : public Reader {
    vector<string> command;
    vector<vector<string>> args;
    int count;

public:
    Conf_reader();
    int read(ifstream& conf);
    string GetCommand(int id);
    vector<string> GetArgs(int id);
    int GetCount();
};


class WAV_reader : public Reader {
    int sampleRate;
    vector<int16_t> audioData;

public:
    WAV_reader() = default;

    int read(ifstream& conf);
    int write(const string& filename);
    void update(vector<int16_t> new_audioData);
    vector<int16_t> getAudioData() const;
    int getSampleRate() const;
};

#endif // READER_H