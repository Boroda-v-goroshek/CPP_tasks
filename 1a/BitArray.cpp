#include <cmath>
#include "BitArray.hpp"

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}
int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

BitArray::~BitArray() {
    delete[] bit_array;
    this->bit_array = nullptr;
    this->len = 0;
}

void BitArray::set(unsigned char* elem, int n, bool val) {
    if (val)
        *elem |= (1 << n); // Устанавливаем бит
    else
        *elem &= ~(1 << n); // Сбрасываем бит
}

BitArray& BitArray::set(int n, bool val) {
    int byteIndex = n / 8; // Определяем индекс байта
    int bitIndex = n % 8;  // Определяем индекс бита в байте
    if (byteIndex >= 0 && byteIndex < (len + 7) / 8) {
        if (val)
            bit_array[byteIndex] |= (1 << bitIndex); // Устанавливаем бит
        else
            bit_array[byteIndex] &= ~(1 << bitIndex); // Сбрасываем бит
    }

    return *this;
}

BitArray& BitArray::set() {
    int len = this->len;
    int j = 0;

    while (len >= 8) {
        bit_array[j] = 255;
        len -= 8;
        j++;
    }
    for (int i = 0; i < len; i++) {
        bit_array[j] |= (1 << i);
    }

    return *this;
}


void BitArray::resize(int num_bits, bool value) {
    int n = std::ceil(num_bits / 8.0);
    int min_len = min(this->len, num_bits);
    int max_len = max(this->len, num_bits);

    if (n > std::ceil(this->len / 8.0)) {
        unsigned char* new_array = new unsigned char[n]();

        int j = 0;
        while (min_len >= 8) {
            new_array[j] = this->bit_array[j];
            min_len -= 8;
            j++;
        }
        for (int i = 0; i < min_len; i++) {
            char value = this->bit_array[j] & (1 << i);
            set(&new_array[j], i, value != 0);
        }
        for (int i = this->len; i < num_bits; i++) {
            set(&new_array[i / 8], i % 8, value);
        }

        delete[] bit_array;
        this->bit_array = new_array;
    }
    else if (n == 0) {
        delete[] this->bit_array;
        this->bit_array = nullptr;
        this->len = 0;
        return;
    }
    else if (n < 0) {
        std::cout << "Размер не может быть отрицательным!" << std::endl;
    }
    else {
        for (int i = min_len; i < max_len; i++) {
            set(i, value);
        }
    }
    this->len = num_bits;
}


BitArray::BitArray(int num_bits, unsigned long value) {
    this->len = num_bits;
    int n = std::ceil(num_bits / 8.0);
    this->bit_array = new unsigned char[n]();

    int min_len = min(num_bits, 32);
    for (int i = 0; i < min_len; i++) {
        this->bit_array[i / 8] |= ((value >> i) & 1) << (i % 8);
    }
}

BitArray::BitArray(const BitArray& b) {
    this->len = b.len;
    int n = std::ceil(b.len / 8.0);
    this->bit_array = new unsigned char[n]();

    int temp = b.len, j = 0;
    while (temp >= 8) {
        this->bit_array[j] = b.bit_array[j];
        j++;
        temp -= 8;
    }
    for (int i = 0; i < temp; i++) {
        this->set(j * 8 + i, (b.bit_array[j] & (1 << i)) != 0);
    }
}

void BitArray::swap(BitArray& b) {
    int min_len = min(this->len, b.len);
    int j = 0;

    while (min_len >= 8) {
        char temp = this->bit_array[j];
        this->bit_array[j] = b.bit_array[j];
        b.bit_array[j] = temp;

        //std::cout << (unsigned int) this->bit_array[j] << " ";
        //std::cout << (unsigned int) b.bit_array[j] << std::endl;

        min_len -= 8;
        j++;
    }
    for (int i = 0; i < min_len; i++) {
        char temp = this->bit_array[j] & (1 << i);
        //std::cout << (unsigned int)temp << " ";
        //std::cout << (unsigned int)value << std::endl;

        this->set(j * 8 + i, (b.bit_array[j] & (1 << i)) != 0);
        b.set(j * 8 + i, temp != 0);
        //std::cout << (unsigned int)b.bit_array[j] << " ";
        //std::cout << (unsigned int)this->bit_array[j] << std::endl;
    }
}

BitArray& BitArray::operator=(const BitArray& b) {
    resize(b.len);

    int temp = this->len, j = 0;
    while (temp >= 8) {
        this->bit_array[j] = b.bit_array[j];
        temp -= 8;
        j++;
    }
    for (int i = 0; i < temp; i++) {
        this->set(j * 8 + i, (b.bit_array[j] & (1 << i)) != 0);
    }
    this->len = b.len;
    return *this;
}
BitArray& BitArray::operator&=(const BitArray& b) {
    if (this->len == b.len) {
        int n = std::ceil(this->len / 8.0);
        for (int i = 0; i < n; i++) {
            this->bit_array[i] &= b.bit_array[i];
        }
    }
    else {
        std::cout << "Массивы разных размеров!" << std::endl;
    }
    return *this;
}
BitArray& BitArray::operator|=(const BitArray& b) {
    if (this->len == b.len) {
        int n = std::ceil(this->len / 8.0);
        for (int i = 0; i < n; i++) {
            this->bit_array[i] |= b.bit_array[i];
        }
    }
    else {
        std::cout << "Массивы разных размеров!" << std::endl;
    }
    return *this;
}
BitArray& BitArray::operator^=(const BitArray& b) {
    if (this->len == b.len) {
        int n = std::ceil(this->len / 8.0);
        for (int i = 0; i < n; i++) {
            this->bit_array[i] ^= b.bit_array[i];
        }
    }
    else {
        std::cout << "Массивы разных размеров!" << std::endl;
    }
    return *this;
}
BitArray& BitArray::operator<<=(int n) {
    for (int i = this->len - 1; i >= n; i--) {
        set(i, (this->bit_array[(i - n) / 8] & (1 << ((i - n) % 8))) != 0);
    }
    for (int i = 0; i < n; i++) {
        reset(i);
    }
    return *this;
}
BitArray& BitArray::operator>>=(int n) {
    for (int i = 0; i < this->len - n; i++) {
        set(i, (this->bit_array[(i + n) / 8] & (1 << ((i + n) % 8))) != 0);
    }
    for (int i = this->len - n; i < this->len; i++) {
        reset(i);
    }
    return *this;
}
BitArray BitArray::operator<<(int n) const {
    unsigned long value = 0;
    BitArray result(this->len, value);

    for (int i = this->len - 1; i >= n; i--) {
        result.set(i, (this->bit_array[(i - n) / 8] & (1 << ((i - n) % 8))) != 0);
    }

    return result;
}
BitArray BitArray::operator>>(int n) const {
    unsigned long value = 0;
    BitArray result(this->len, value);

    for (int i = 0; i < this->len - n; i++) {
        result.set(i, (this->bit_array[(i + n) / 8] & (1 << ((i + n) % 8))) != 0);
    }

    return result;
}

BitArray BitArray::operator~() const {
    unsigned long value = 0;
    BitArray result(this->len, value);

    int temp = this->len, j = 0;
    while (temp >= 8) {
        result.bit_array[j] = ~(this->bit_array[j]);
        temp -= 8;
        j++;
    }
    for (int i = 0; i < temp; i++) {
        result.set(j * 8 + i, (this->bit_array[j] & (1 << i)) == 0);
    }


    return result;
}
bool BitArray::operator[](int i) const {
    return ((this->bit_array[i / 8] & (1 << (i % 8))) != 0);
}

void BitArray::push_back(bool bit) {
    if (this->len % 8 == 0 && this->len != 0) {
        resize(this->len + 1);
    }
    set(this->len, bit);
    this->len++;
}

BitArray& BitArray::reset(int n) {
    set(n, false);
    return *this;
}

BitArray& BitArray::reset() {
    int len = this->len;
    int j = 0;

    while (len >= 8) {
        bit_array[j] = 0;
        len -= 8;
        j++;
    }
    for (int i = 0; i < len; i++) {
        bit_array[j] &= ~(1 << i);
    }

    return *this;
}

void BitArray::clear() {
    resize(0);
}


bool BitArray::any() const {
    int n = std::ceil(this->len / 8.0);

    for (int j = 0; j < n; j++) {
        if (this->bit_array[j] != 0)
            return true;
    }
    return false;
}

bool BitArray::none() const {
    int n = std::ceil(this->len / 8.0);

    for (int j = 0; j < n; j++) {
        if (this->bit_array[j] != 0)
            return false;
    }
    return true;
}

int BitArray::size() const {
    return this->len;
}

bool BitArray::empty() const {
    return this->len == 0;
}


std::string BitArray::to_string() const {
    std::string str(this->len, '0');

    for (int i = 0; i < this->len; i++) {
        if (this->bit_array[i / 8] & (1 << (i % 8)))
            str[this->len - i - 1] = '1';
    }

    //std::cout << str.length() << std::endl;
    return str;
}

bool operator==(const BitArray& a, const BitArray& b) {
    return (a.to_string() == b.to_string());
}
bool operator!=(const BitArray& a, const BitArray& b) {
    return (a.to_string() != b.to_string());
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
    if (b1.size() == b2.size()) {
        BitArray result(b1);
        result &= b2;
        return result;
    }
    else {
        std::cout << "Массивы не могут быть разных размеров!" << std::endl;
    }
}
BitArray operator|(const BitArray& b1, const BitArray& b2) {
    if (b1.size() == b2.size()) {
        BitArray result(b1);
        result |= b2;
        return result;
    }
    else {
        std::cout << "Массивы не могут быть разных размеров!" << std::endl;
    }
}
BitArray operator^(const BitArray& b1, const BitArray& b2) {
    if (b1.size() == b2.size()) {
        BitArray result(b1);
        result ^= b2;
        return result;
    }
    else {
        std::cout << "Массивы не могут быть разных размеров!" << std::endl;
    }
}