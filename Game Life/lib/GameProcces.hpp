#include "Life.hpp"
#include <chrono>
#include <thread>
#include <sstream>

class GameProcces{
    public:

    int handleCommand(const string& command, Field& game_field);
};