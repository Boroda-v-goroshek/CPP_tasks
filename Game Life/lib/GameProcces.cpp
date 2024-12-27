#include "GameProcces.hpp"

int GameProcces::handleCommand(const string& command, Field& game_field){
    istringstream iss(command);
    string cmd;
    iss >> cmd; // Получить первую часть команды

    if (cmd == "dump") {
        string filename;
        iss >> filename;
        game_field.dump(filename);
        return 1;
    } 

    else if (cmd == "tick" || cmd == "t") {
        int num;
        if (iss >> num) { 
            for (int i = 0; i < num; ++i) {
                game_field.draw();
                this_thread::sleep_for(chrono::milliseconds(500));
                game_field.update();
            }
            game_field.draw();
        }
        else if (iss.eof()){
            game_field.draw();
            this_thread::sleep_for(chrono::milliseconds(500));
            game_field.update();
            game_field.draw();
        }
    } 
    else if (cmd == "exit") {
        cout << "Exiting the game..." << endl;
        exit(0); // Завершите программу
    } 
    else if (cmd == "help") {
        cout << "Available commands:\n";
        cout << "1. dump <filename> - Save universe to file\n";
        cout << "2. tick <n> (or t <n>) - Calculate n iterations (default 1)\n";
        cout << "3. exit - Exit the game\n";
        cout << "4. help - Print this help message\n";
    } 
    else {
        cout << "Unknown command: " << cmd << endl;
    }
    return 0;
}