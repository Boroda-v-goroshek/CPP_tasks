#include "reader.hpp"

Conf_reader::Conf_reader(): count{0} {}

int Conf_reader::read(ifstream& conf){
    //cout << 3 << endl;
    if(conf.is_open()){
        string line;
        //cout << 4 << endl;
        while(getline(conf, line)){
            if (line[0] != '#'){
                istringstream iss(line);
                string cmd;
                //cout << "a" << endl;

                iss >> cmd;
                this->command.push_back(cmd);
                //cout << "b" << endl;

                while(iss >> cmd){
                    if (count >= args.size()) {
                        args.resize(count + 1);
                    }
                    this->args[count].push_back(cmd);
                }
                this->count++;
                //cout << "c" << endl;
            }
        }
        //cout << 5 << endl;
        return 0;
    }
    else{
        cerr << "Ошибка: файл не открыт!" << endl;
        return 1;
    }
}

string Conf_reader::GetCommand(int id){
    return command[id];
}

vector<string> Conf_reader::GetArgs(int id){
    return args[id];
}

int Conf_reader::GetCount(){
    return count;
}

int WAV_reader::read(ifstream& conf) {
    if (!conf.is_open()) {
        cerr << "Ошибка: файл не открыт!" << endl;
        return 1;
    }

    // Структура WAV файла состоит из заголовка и данных
    char header[44]; // Заголовок WAV файла имеет фиксированную длину 44 байта
    conf.read(header, sizeof(header));

    // Проверяем формат
    if (header[0] != 'R' || header[1] != 'I' || header[2] != 'F' || header[3] != 'F') {
        cerr << "Ошибка: неверный формат WAV файла!" << endl;
        return 1;
    }

    // Получаем частоту дискретизации
    sampleRate = *reinterpret_cast<int32_t*>(&header[24]); // Частота дискретизации (байты 24-27)

    // Переход к началу данных
    conf.seekg(44, ios::beg);

    // Чтение сэмплов
    int16_t sample;
    while (conf.read(reinterpret_cast<char*>(&sample), sizeof(sample))) {
        audioData.push_back(sample);// для справки: в одной секунде может быть очень много сэмплов, в зависимости от частоты(сэмпл/с)
    }
    return 0;
}

int WAV_reader::write(const string& filename) {
        ofstream outFile(filename, ios::binary);
        if (!outFile.is_open()) {
            cerr << "Ошибка: не удалось открыть файл для записи!" << endl;
            return 1;
        }

        // Записываем заголовок WAV файла
        outFile << "RIFF";
        int32_t chunkSize = 36 + audioData.size() * sizeof(int16_t);
        outFile.write(reinterpret_cast<char*>(&chunkSize), 4);
        outFile << "WAVE";

        // Записываем "fmt " часть
        outFile << "fmt ";           
        int32_t fmtChunkSize = 16; // размер fmt блока
        outFile.write(reinterpret_cast<char*>(&fmtChunkSize), 4);
        int16_t audioFormat = 1; // формат PCM
        outFile.write(reinterpret_cast<char*>(&audioFormat), 2);
        int16_t numChannels = 1; // количество каналов (моно)
        outFile.write(reinterpret_cast<char*>(&numChannels), 2);
        outFile.write(reinterpret_cast<char*>(&sampleRate), 4);
        int32_t byteRate = sampleRate * numChannels * sizeof(int16_t);
        outFile.write(reinterpret_cast<char*>(&byteRate), 4);
        int16_t blockAlign = numChannels * sizeof(int16_t);
        outFile.write(reinterpret_cast<char*>(&blockAlign), 2);
        int16_t bitsPerSample = 16; // глубина бит
        outFile.write(reinterpret_cast<char*>(&bitsPerSample), 2);

        // Записываем "data" часть
        outFile << "data";
        int32_t dataSize = audioData.size() * sizeof(int16_t);
        outFile.write(reinterpret_cast<char*>(&dataSize), 4);
        outFile.write(reinterpret_cast<const char*>(audioData.data()), dataSize);

        outFile.close();
        return 0;
    }

void WAV_reader::update(vector<int16_t> new_audioData){
    int len = audioData.size();
    for (int i = 0; i < len; i++){
        audioData[i] = new_audioData[i];
    }
}

int WAV_reader::getSampleRate() const{
    return sampleRate;
}

vector<int16_t> WAV_reader::getAudioData() const{
    return audioData;
}