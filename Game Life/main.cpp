#include "lib/Life.hpp"
#include "lib/GamePars.hpp"
#include "lib/GameProcces.hpp"

//using namespace std;

int main(int argc, char **argv){
    vector<string> argv_s;
    for (int i = 0; i < argc; i++){
        string str = (string)argv[i];
        argv_s.push_back(str);
    }

    //cout << argc << endl;
    string input_file;
    string output_file;
    int iteration;

    Pars pars;

    if (pars.Argpars(argc, argv, &input_file, &output_file, &iteration)){return 0;}
    Field game_field = pars.Gamepars(input_file);
    
    GameProcces game;

    while (1){
        if (argc != 7){
            cout << "Ожидается ввод команды:";
            string command;
            getline(cin, command);
            if (game.handleCommand(command, game_field)){break;}
        }
        else{
            string command = "tick " + to_string(iteration);
            game.handleCommand(command, game_field);
            command = "dump " + output_file;
            game.handleCommand(command, game_field);
            break;
        }
    }
    return 0;
}