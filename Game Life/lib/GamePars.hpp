#include "Life.hpp"

class Pars{
    public:

    int Argpars(int argc, char **argv, string* input_file, string* output_file, int* iteration);
    Field Gamepars(string input_file);
};