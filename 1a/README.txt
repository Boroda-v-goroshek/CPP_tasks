Установка googletest:
ВАЖНО!!! Находиться нужно в папке '1a'!

git clone https://github.com/google/googletest.git -b v1.15.2
cd googletest
mkdir build
cd build
cmake ..


Cборка:

cmake -S. -Bbuild
cmake --build build


Запуск тестов:

./build/tests/BA_test



папка lib - там лежит библиотека с классом BitArray
папка tests - там лежат тесты