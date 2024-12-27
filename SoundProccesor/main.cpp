#include "lib/sound.hpp"
#include "lib/reader.hpp"

using namespace std;

// фабричный метод
unique_ptr<GeneralCreator> getFactory(const string& command) {
    if (command == "mix") {
        return make_unique<MixCreator>();
    } 
    else if (command == "mute") {
        return make_unique<MuteCreator>();
    }
    else if (command == "increase"){
        return make_unique<IncreaseCreator>();
    }
    return nullptr; // Если команда не распознана
}

int main(int argc, char** argv) {
    // Получаем аргументы ввиде строк
    vector<string> argv_s;
    for (int i = 0; i < argc; i++){
        string str = (string)argv[i];
        argv_s.push_back(str);
    }

    if (((argv_s[1] == "-h" || argv_s[1] == "--help") && argc == 2) || argc < 2){ // help
        cout << "sound_processor -c <config.txt> <output.wav> <input.wav>" << endl;
        return 1;
    }
    if (argc == 5){
        ifstream fconf(argv_s[2]); // config
        ifstream fin(argv_s[4]); // input

        Conf_reader conf; // файл конфигурации
        WAV_reader wav; // файл с записью

        conf.read(fconf);
        wav.read(fin);
        cout << 1 << endl;


        int size = conf.GetCount();
        for (int i = 0; i < size; i++){
            string command = conf.GetCommand(i);
            vector<string> args = conf.GetArgs(i);

            unique_ptr<GeneralCreator> factory = getFactory(command); // создание через Фабричный Метод

            if (factory) {
                unique_ptr<Convert> converter = factory->create();
                converter->change(wav, args); // Вызываем метод change
            }
            else {
                cerr << "Unknown command: " << command << endl;
            }
        }
        cout << 2 << endl;

        wav.write(argv_s[3]);
        cout << 3 << endl;

    }
    else {
        cerr << "Неверный формат данных!" << endl;
        return 1;
    }
    return 0;
}