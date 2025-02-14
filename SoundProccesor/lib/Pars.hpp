#include "lib/sound.hpp"
#include "lib/reader.hpp"

class Pars{
public:
    unique_ptr<GeneralCreator> getFactory(const string& command);
    int ParsCmdArgs(int argc, char** argv);

};