#include "sound.hpp"
#include "reader.hpp"

int Mix::min(int a, int b){
    if (a > b){return b;}
    return a;
}

// 
void Mix::change(WAV_reader& data, vector<string> args){
    // Получаем индекс начала
    // Подготавливаем данные
    int start = stoi(args[1]) * data.getSampleRate();
    ifstream fpath(args[0]);
    WAV_reader addit_data;
    addit_data.read(fpath);

    vector<int16_t> audioData = data.getAudioData();
    vector<int16_t> addit_audioData = addit_data.getAudioData();

    int min_len = min(audioData.size() * data.getSampleRate(), addit_audioData.size() * addit_data.getSampleRate());

    for (int i = start; i < min_len; i++){
        audioData[i] = (audioData[i] + addit_audioData[i]) / 2;
    }
    data.update(audioData);
}


void Mute::change(WAV_reader& data, vector<string> args){
    // получаем индексы сэмплов: частота умноженная на кол-во секунд.
    // Подготавливаем данные
    int start = stoi(args[0]) * data.getSampleRate() , finish = stoi(args[1]) * data.getSampleRate();
    vector <int16_t> audioData = data.getAudioData();

    for (int i = start; i < finish; i++){
        audioData[i] = 0;
    }
    data.update(audioData);
}


void Increase::change(WAV_reader& data, vector<string> args){
        // получаем индексы сэмплов: частота умноженная на кол-во секунд.
        // Подготавливаем данные
        int start = stoi(args[0]) * data.getSampleRate();
        int finish = stoi(args[1]) * data.getSampleRate();
        vector<int16_t> audioData = data.getAudioData();
        
        // Коэффициент усиления
        float gain = 1.5; // Например, увеличиваем громкость в 1.5 раза

        // Проходим по заданному диапазону и усиливаем громкость
        for (int i = start; i < finish && i < audioData.size(); i++) {
            int32_t newSample = static_cast<int32_t>(audioData[i] * gain);

            // Ограничиваем значение в допустимом диапазоне
            if (newSample > INT16_MAX) {
                audioData[i] = INT16_MAX; // Ограничиваем максимум
            } else if (newSample < INT16_MIN) {
                audioData[i] = INT16_MIN; // Ограничиваем минимум
            } else {
                audioData[i] = static_cast<int16_t>(newSample);
            }
        }
        
        // Обновляем аудиоданные в WAV_reader
        data.update(audioData);
    }


unique_ptr<Convert> MixCreator::create() const{
    return make_unique<Mix>();
}
unique_ptr<Convert> MuteCreator::create() const{
    return make_unique<Mute>();
}
unique_ptr<Convert> IncreaseCreator::create() const{
    return make_unique<Increase>();
}