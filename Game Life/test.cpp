#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

std::vector<std::string> splitString(const std::string& str) {
    std::vector<std::string> words; // Вектор для хранения слов
    std::stringstream ss(str);      // Создаем поток из строки
    std::string word;               // Переменная для хранения текущего слова

    // Разбиваем строку на слова, используя пробел в качестве разделителя
    while (ss >> word) {
        words.push_back(word);       // Добавляем каждое слово в вектор
    }

    return words;                   // Возвращаем вектор с словами
}

int main(){
    std::cout << "Введите строку: " << endl;
    std::string command;
    getline(cin, command);

    vector words = splitString(command);
    cout << words.size() << ' ' << words[1] << endl;

   

    return 0;
}

/*
std::cout << "Введите строку: " << endl;
    std::string command;
    std::cin >> command;while (ss >> word) {
        words.push_back(word);       // Добавляем каждое слово в вектор
    }


    int n = 1000;
    char* str = new char[n];
    for (int i = 0; i < command.length(); i++){
        str[i] = command[i];
    }
    str[command.length()] = '\0';
    
    // Разделители
    char sep [10] = " ,.!;";
    char* token = strtok(str, sep);
    while (token != nullptr){
        std::cout << token << std::endl;
        token = strtok(nullptr, sep);
    }*/