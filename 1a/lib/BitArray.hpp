#pragma once

#ifndef BITARRAY_H
#define BITARRAY_H

#include <iostream>

int min(int a, int b);
int max(int a, int b);

class BitArray{
unsigned char* bit_array;
    int len;
public:


    ~BitArray();

    //Конструирует массив, хранящий заданное количество бит.
    //Первые sizeof(long) бит можно инициализровать с помощью параметра value.

    explicit BitArray(int num_bits, unsigned long value = 0);
    BitArray(const BitArray& b);

    //Обменивает значения двух битовых массивов.
    void swap(BitArray& b);

    //Битовые операции над массивами.
    //Работают только на массивах одинакового размера.

    BitArray& operator=(const BitArray& b);
    BitArray& operator&=(const BitArray& b);
    BitArray& operator|=(const BitArray& b);
    BitArray& operator^=(const BitArray& b);

    //Битовый сдвиг с заполнением нулями.
    BitArray& operator<<=(int n);
    BitArray& operator>>=(int n);
    BitArray operator<<(int n) const;
    BitArray operator>>(int n) const;

    //Битовая инверсия
    BitArray operator~() const;

    //Возвращает значение бита по индексу i.
    bool operator[](int i) const;


    //Изменяет размер массива. В случае расширения, новые элементы 
    //инициализируются значением value.
    void resize(int num_bits, bool value = false);

    //Добавляет новый бит в конец массива. В случае необходимости 
    //происходит перераспределение памяти.
    void push_back(bool bit);

    //Устанавливает бит с индексом n в значение val.
    void set(unsigned char* elem, int n, bool val = true);
    BitArray& set(int n, bool val = true);

    //Заполняет массив истиной.
    BitArray& set();

    //Устанавливает бит с индексом n в значение false.
    BitArray& reset(int n);

    //Заполняет массив ложью.
    BitArray& reset();

    //Очищает массив.
    void clear();

    //true, если массив содержит истинный бит.
    bool any() const;
    
    //true, если все биты массива ложны.
    bool none() const;

    //Подсчитывает количество единичных бит.
    int count() const;

    int size() const;
    bool empty() const;

    //Возвращает строковое представление массива.
    std::string to_string() const;
};

bool operator==(const BitArray& a, const BitArray& b);
bool operator!=(const BitArray& a, const BitArray& b);

BitArray operator&(const BitArray& b1, const BitArray& b2);
BitArray operator|(const BitArray& b1, const BitArray& b2);
BitArray operator^(const BitArray& b1, const BitArray& b2);

#endif