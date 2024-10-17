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

    explicit BitArray(int num_bits, unsigned long value = 0);
    BitArray(const BitArray& b);

    void swap(BitArray& b);

    BitArray& operator=(const BitArray& b);
    BitArray& operator&=(const BitArray& b);
    BitArray& operator|=(const BitArray& b);
    BitArray& operator^=(const BitArray& b);

    BitArray& operator<<=(int n);
    BitArray& operator>>=(int n);
    BitArray operator<<(int n) const;
    BitArray operator>>(int n) const;

    BitArray operator~() const;
    bool operator[](int i) const;



    void resize(int num_bits, bool value = false);

    void push_back(bool bit);


    void set(unsigned char* elem, int n, bool val = true);

    BitArray& set(int n, bool val = true);

    BitArray& set();


    BitArray& reset(int n);

    BitArray& reset();

    void clear();

    bool any() const;
    
    bool none() const;

    int size() const;
    bool empty() const;

    std::string to_string() const;
};

bool operator==(const BitArray& a, const BitArray& b);
bool operator!=(const BitArray& a, const BitArray& b);

BitArray operator&(const BitArray& b1, const BitArray& b2);
BitArray operator|(const BitArray& b1, const BitArray& b2);
BitArray operator^(const BitArray& b1, const BitArray& b2);

#endif