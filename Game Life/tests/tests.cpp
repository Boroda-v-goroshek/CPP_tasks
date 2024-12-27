#include "lib/Life.hpp"
#include <gtest/gtest.h>
#include "lib/GamePars.hpp"
#include "lib/GameProcces.hpp"

using namespace std;

TEST(GameFieldCreate, Construct){
    Pars pars;

    Field game1 = pars.Gamepars("var/var1.txt");
    EXPECT_EQ(game1.getName(), "Planer");

    vector<int> size = game1.getSize();
    EXPECT_EQ(size[0], 21);
    EXPECT_EQ(size[1], 20);


}
TEST(GameFieldCreate, is_life){
    Pars pars;
    Field game1 = pars.Gamepars("var/var1.txt");

    vector<vector<Cell>> field = game1.getField();

    EXPECT_TRUE(field[10][9].is_life());
    EXPECT_TRUE(field[9][10].is_life());
    EXPECT_TRUE(field[8][8].is_life());
    EXPECT_TRUE(field[9][10].is_life());
    EXPECT_TRUE(field[8][10].is_life());

}
TEST(GameFieldCreate, to_life){
    Pars pars;
    Field game1 = pars.Gamepars("var/var1.txt");

    vector<vector<Cell>> field = game1.getField();
    EXPECT_TRUE(field[10][9].is_life());
    EXPECT_TRUE(field[9][10].is_life());
    EXPECT_TRUE(field[8][8].is_life());
    EXPECT_TRUE(field[9][10].is_life());
    EXPECT_TRUE(field[8][10].is_life());

    field[10][9].to_life();
    EXPECT_TRUE(field[10][9].is_life());
    EXPECT_EQ(field[11][13].is_life(), false);
    field[11][13].to_life();
    EXPECT_EQ(field[11][13].is_life(), true);

}
TEST(GameFieldCreate, to_dead){
    Pars pars;
    Field game1 = pars.Gamepars("var/var1.txt");

    vector<vector<Cell>> field = game1.getField();
    EXPECT_TRUE(field[10][9].is_life());
    EXPECT_TRUE(field[9][10].is_life());
    EXPECT_TRUE(field[8][8].is_life());
    EXPECT_TRUE(field[9][10].is_life());
    EXPECT_TRUE(field[8][10].is_life());

    field[10][9].to_dead();
    EXPECT_TRUE(!field[10][9].is_life());
    EXPECT_EQ(field[11][13].is_life(), false);
    field[11][13].to_dead();
    EXPECT_EQ(field[11][13].is_life(), false);
}

bool compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "Не удалось открыть один из файлов." << std::endl;
        return false;
    }

    std::set<std::string> header1;
    std::set<std::string> header2;
    std::set<std::string> coordinates1;
    std::set<std::string> coordinates2;

    std::string line;

    // Считывание первого файла
    while (std::getline(f1, line)) {
        // Проверяем, является ли строка заголовком или координатой
        if (line.empty()) continue; // Игнорируем пустые строки
        if (line[0] == '#') {
            header1.insert(line);
        } else {
            coordinates1.insert(line);
        }
    }

    // Считывание второго файла
    while (std::getline(f2, line)) {
        // Проверяем, является ли строка заголовком или координатой
        if (line.empty()) continue; // Игнорируем пустые строки
        if (line[0] == '#') {
            header2.insert(line);
        } else {
            coordinates2.insert(line);
        }
    }

    f1.close();
    f2.close();

    // Сравниваем заголовки и координаты
    bool headersEqual = (header1 == header2);
    bool coordinatesEqual = (coordinates1 == coordinates2);

    return headersEqual && coordinatesEqual;
}

TEST(GameProccess, update){
    Pars pars;
    GameProcces game_procces;

    Field game1 = pars.Gamepars("var/var1.txt");
    vector<vector<int>> start = game1.GetN();

    game1.update();
    vector<vector<Cell>> field = game1.getField();

    vector<int> size = game1.getSize();
    int h = size[0], w = size[1];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (field[i][j].is_life()){
                EXPECT_TRUE((start[i][j] == 2 || start[i][j] == 3));
            }
        }
    }

    start = game1.GetN();

    game1.update();
    field = game1.getField();

    size = game1.getSize();
    h = size[0], w = size[1];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (field[i][j].is_life()){
                EXPECT_TRUE((start[i][j] == 2 || start[i][j] == 3));
            }
        }
    }
}

TEST(GameResults, OutputFile){
    Pars pars;
    GameProcces game_procces;

    Field game1 = pars.Gamepars("var/var1.txt");
    game_procces.handleCommand("dump lib/output.txt", game1);
    EXPECT_TRUE(compareFiles("var/var1.txt", "lib/output.txt"));

    Field game2 = pars.Gamepars("var/var2.txt");
    game_procces.handleCommand("dump lib/output.txt", game2);
    EXPECT_TRUE(compareFiles("var/var2.txt", "lib/output.txt"));

    Field game3 = pars.Gamepars("var/var3.txt");
    game_procces.handleCommand("dump lib/output.txt", game3);
    EXPECT_TRUE(compareFiles("var/var3.txt", "lib/output.txt"));

    Field game4 = pars.Gamepars("var/var4.txt");
    game_procces.handleCommand("dump lib/output.txt", game4);
    EXPECT_TRUE(compareFiles("var/var4.txt", "lib/output.txt"));
}