Установка googletest:
ВАЖНО!!! Находиться нужно в рабочей директории!

git clone https://github.com/google/googletest.git -b v1.15.2
cd googletest
mkdir build
cd build
cmake ..


Cборка:

cmake -S. -Bbuild
cmake --build build


Запуск тестов:
./build/tests/game_test

Запуск игры:
./build/run_game --help 
Выведет справку о командах



папка lib - там лежит библиотека с классами для игры и парсинга
папка tests - там лежат тесты