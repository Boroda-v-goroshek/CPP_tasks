#include "lib/BitArray.hpp"
#include <gtest/gtest.h>

TEST(BitArrayConstructors, Constructor){
    BitArray bitArray(10);
    EXPECT_EQ(bitArray.size(), 10);
    EXPECT_EQ(bitArray.none(), true);

    unsigned long value = 0b00000000000000000000000000001101;
    BitArray abc(4, value);
    EXPECT_EQ(abc.size(), 4);
    EXPECT_EQ(abc[0], true);
    EXPECT_EQ(abc[1], false);
    EXPECT_EQ(abc[2], true);
    EXPECT_EQ(abc[3], true);



    

    BitArray a(3, 7);
    EXPECT_EQ(a.size(), 3);
    EXPECT_EQ(a.none(), false);

    BitArray b(0, 7);
    EXPECT_EQ(b.size(), 0);
    EXPECT_EQ(b.none(), true);

    BitArray c(31);
    EXPECT_EQ(c.size(), 31);
    EXPECT_EQ(c.none(), true);
}
TEST(BitArrayConstructors, Copy){
    BitArray a(8);
    a.set(0);
    a.set(1);
    BitArray b(a);

    EXPECT_EQ(a.to_string(), b.to_string());
}

TEST(BitArrayChanges, Swap){
    BitArray a(3);
    a.set(0);
    a.set(1);
    BitArray b(a);

    EXPECT_EQ(a.to_string(), b.to_string());

    BitArray c(5);
    c.swap(a);
    EXPECT_FALSE(a[0]);
    EXPECT_FALSE(a[1]);
    EXPECT_TRUE(c[0]);
    EXPECT_TRUE(c[1]);
    EXPECT_EQ(a.size(), 5);
    EXPECT_EQ(c.size(), 3);

    c.swap(c);
    EXPECT_TRUE(c[0]);
    EXPECT_TRUE(c[1]);
    EXPECT_EQ(c.size(), 3);
}
TEST(BitArrayChanges, Set) {
    BitArray bitArray(8);
    EXPECT_EQ(bitArray.size(), 8);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.set(2);
    EXPECT_FALSE(bitArray[1]);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.set(2);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_FALSE(bitArray[3]);
    EXPECT_FALSE(bitArray[1]);

    bitArray.set();
    EXPECT_TRUE(bitArray[2]);
    EXPECT_TRUE(bitArray[3]);
    EXPECT_TRUE(bitArray[4]);

    bitArray.set();
    EXPECT_TRUE(bitArray[2]);
    EXPECT_TRUE(bitArray[3]);
    EXPECT_TRUE(bitArray[4]);
}
TEST(BitArrayChanges, Reset) {
    BitArray bitArray(7);
    EXPECT_EQ(bitArray.size(), 7);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.reset();
    EXPECT_FALSE(bitArray[2]);
    EXPECT_FALSE(bitArray[1]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.reset();
    EXPECT_FALSE(bitArray[2]);
    EXPECT_FALSE(bitArray[1]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.set();
    EXPECT_TRUE(bitArray[2]);
    EXPECT_TRUE(bitArray[3]);
    EXPECT_TRUE(bitArray[4]);

    bitArray.reset(2);
    EXPECT_FALSE(bitArray[2]);
}
TEST(BitArrayChanges, Resize){
    BitArray bitArray(3);
    EXPECT_EQ(bitArray.size(), 3);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.resize(8);
    EXPECT_EQ(bitArray.size(), 8);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.resize(8);
    EXPECT_EQ(bitArray.size(), 8);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.resize(0);
    EXPECT_EQ(bitArray.size(), 0);
    EXPECT_EQ(bitArray.none(), true);
    EXPECT_EQ(bitArray.empty(), true);

    bitArray.resize(0);
    EXPECT_EQ(bitArray.size(), 0);
    EXPECT_EQ(bitArray.none(), true);
    EXPECT_EQ(bitArray.empty(), true);

    bitArray.resize(11, true);
    EXPECT_EQ(bitArray.size(), 11);
    EXPECT_EQ(bitArray.none(), false);
}
TEST(BitArrayChanges, Pushback){
    BitArray bitArray(3);
    EXPECT_EQ(bitArray.size(), 3);
    EXPECT_EQ(bitArray.none(), true);
    
    bitArray.push_back(true);
    EXPECT_EQ(bitArray.size(), 4);
    EXPECT_EQ(bitArray.any(), true);
}

TEST(BitArrayPrintResults, ToString){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray abc(4, value);
    EXPECT_EQ(abc.to_string(), "1101");

    value = 0b000000000000000000000000001101101;
    BitArray bitArray(7, value);
    EXPECT_EQ(bitArray.to_string(), "1101101");
}
TEST(BitArrayPrintResults, Get){
    BitArray bitArray(19);
    EXPECT_EQ(bitArray.size(), 19);

    bitArray.set(2);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.set();
    EXPECT_TRUE(bitArray[0]);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_TRUE(bitArray[3]);
    EXPECT_TRUE(bitArray[4]);

    BitArray a(1, 1);
    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(a.any(), true);
    EXPECT_TRUE(a[0]);
}
TEST(BitArrayPrintResults, Any){
    BitArray bitArray(19);
    EXPECT_EQ(bitArray.size(), 19);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.set(2);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.set();
    EXPECT_EQ(bitArray.any(), true);
    BitArray a(1, 1);
    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(a.any(), true);
}
TEST(BitArrayPrintResults, None){
    BitArray bitArray(19);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.set(2);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.set();
    BitArray a(1, 1);
    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(a.none(), false);
}

TEST(BitArrayOperatorsInFirstGroup, OperatorEq){
    BitArray a(8);
    BitArray b(8);
    EXPECT_EQ(b.size(), 8);

    a.set(0);
    a.set(1);
    b.set(2);
    a = b;

    EXPECT_TRUE(a[2]);
    EXPECT_FALSE(a[0]);
    EXPECT_FALSE(a[1]);
    EXPECT_EQ(b.size(), 8);
    EXPECT_EQ(a.size(), 8);

    a = a;
    EXPECT_TRUE(a[2]);
    EXPECT_FALSE(a[0]);
    EXPECT_FALSE(a[1]);


    b.resize(5);
    b.reset();
    b.set(0);
    b.set(1);
    a = b;
    EXPECT_TRUE(a[0]);
    EXPECT_TRUE(a[1]);
    EXPECT_FALSE(a[2]);
    EXPECT_EQ(b.size(), 5);
    EXPECT_EQ(a.size(), 5);

}
TEST(BitArrayOperatorsInFirstGroup, OperatorEqXOR){
    BitArray a(8);
    BitArray b(8);
    EXPECT_EQ(b.size(), 8);

    a.set(0);
    a.set(1);
    b.set(1);
    a ^= b;

    EXPECT_TRUE(a[0]);
    EXPECT_FALSE(a[1]);
    EXPECT_FALSE(a[2]);

    a^= a;
    EXPECT_FALSE(a[0]);
    EXPECT_FALSE(a[1]);
    EXPECT_FALSE(a[2]);

    BitArray c(7);
    b.resize(7, true);

    EXPECT_FALSE(c[0]);

    b.set(6);

    c.set();
    c ^= b;

    EXPECT_TRUE(c[0]);
    EXPECT_FALSE(c[6]);
}
TEST(BitArrayOperatorsInFirstGroup, OperatorEqAND){
    BitArray a(8);
    BitArray b(8);

    a.set(0);
    a.set(1);
    b.set(1);
    a &= b;

    EXPECT_TRUE(a[1]);
    EXPECT_FALSE(a[0]);

    unsigned long value = 0b00000000000000000000000000001101;
    BitArray c(4, value);
    EXPECT_EQ(c.to_string(), "1101");

    b.resize(4);
    b &= c;
    EXPECT_EQ(b.to_string(), "0000");

    b &= c;
    EXPECT_EQ(b.to_string(), "0000");

}
TEST(BitArrayOperatorsInFirstGroup, OperatorEqOR){
    BitArray a(8);
    BitArray b(8);

    a.set(0);
    a.set(1);
    b.set(1);
    a |= b;

    EXPECT_TRUE(a[1]);
    EXPECT_TRUE(a[1]);

    unsigned long value = 0b00000000000000000000000000001101;
    BitArray c(8, value);
    EXPECT_EQ(c.to_string(), "00001101");

    b |= c;
    EXPECT_EQ(b.to_string(), "00001111");

    b |= b;
    EXPECT_EQ(b.to_string(), "00001111");
}

TEST(BitArrayOperatorsInSecondGroup, OperatorToLeft){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(8, value);
    EXPECT_EQ(a.to_string(), "00001101");

    a <<= 2;
    EXPECT_EQ(a.to_string(), "00110100");

    a = a << 2;
    EXPECT_EQ(a.to_string(), "11010000");

    BitArray b(8, value);
    EXPECT_EQ(b.to_string(), "00001101");
    b = a << 2;
    EXPECT_EQ(b.to_string(), "01000000");
}
TEST(BitArrayOperatorsInSecondGroup, OperatorToRight){
    unsigned long value = 0b00000000000000000000000000111101;
    BitArray a(8, value);
    EXPECT_EQ(a.to_string(), "00111101");

    a >>= 2;
    EXPECT_EQ(a.to_string(), "00001111");

    a = a >> 3;
    EXPECT_EQ(a.to_string(), "00000001");

    BitArray b(8, value);
    EXPECT_EQ(b.to_string(), "00111101");
    b = a << 2;
    EXPECT_EQ(b.to_string(), "00000100");
}

TEST(BitArrayOperatorsInThirdGroup, OperatorBoolEq){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);
    BitArray b = a;

    EXPECT_EQ(a.to_string(), b.to_string());
    EXPECT_EQ(a == b, true);
    EXPECT_EQ(b == a, true);
    EXPECT_EQ(a == a, true);
    EXPECT_EQ(a.size(), b.size());
}
TEST(BitArrayOperatorsInThirdGroup, OperatorBoolNotEq){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);
    BitArray b = a;

    EXPECT_EQ(a.to_string(), b.to_string());
    EXPECT_EQ(a != a, false);
    EXPECT_EQ(a != b, false);
    EXPECT_EQ(b != a, false);
    EXPECT_EQ(a.size(), b.size());

    BitArray c(4);
    EXPECT_EQ(c != b, true);
    EXPECT_EQ(b != c, true);
}
TEST(BitArrayOperatorsInThirdGroup, OperatorTilda){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);
    BitArray b = a;

    EXPECT_EQ(a.to_string(), b.to_string());
    EXPECT_EQ(a == b, true);
    EXPECT_EQ(a.size(), b.size());

    b = ~b;
    EXPECT_EQ(b.to_string(), "0010");
    EXPECT_EQ(a != b, true);
    EXPECT_EQ(a == b, false);

    b = ~b;
    EXPECT_EQ(b.to_string(), "1101");
}

TEST(BitArrayAnotherBoolFunctions, Clear){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);

    EXPECT_EQ(a.any(), true);
    EXPECT_EQ(a.none(), false);

    a.clear();
    EXPECT_EQ(a.size(), 0);
    a.clear();
    EXPECT_EQ(a.size(), 0);
    a.clear();
    a.clear();
    EXPECT_EQ(a.size(), 0);

}
TEST(BitArrayAnotherBoolFunctions, IsEmpty){
    unsigned long value = 0b00000000000000000000000111001101;
    BitArray a(12, value);

    EXPECT_EQ(a.any(), true);
    EXPECT_EQ(a.none(), false);

    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);

    a.resize(19, true);
    EXPECT_EQ(a.empty(), false);
    a.clear();
    EXPECT_EQ(a.empty(), true);
}

TEST(BitArrayOperatorsInFourthGroup, OperatorXOR){
    BitArray a(8);
    BitArray b(8);
    EXPECT_EQ(b.size(), 8);

    a.set(0);
    a.set(1);
    b.set(1);
    a = a ^ b;

    EXPECT_TRUE(a[0]);
    EXPECT_FALSE(a[1]);
    EXPECT_FALSE(a[2]);

    BitArray c(7);
    b.resize(7, true);
    a.resize(7, true);

    EXPECT_FALSE(c[0]);

    b.set();
    a.reset();

    c = a ^ b;

    EXPECT_TRUE(c[0]);
    EXPECT_TRUE(c[6]);
    EXPECT_EQ(c.to_string(), "1111111");
}
TEST(BitArrayOperatorsInFourthGroup, OperatorAND){
    BitArray a(8);
    BitArray b(8);

    a.set(0);
    a.set(1);
    b.set(1);
    a &= b;

    EXPECT_TRUE(a[1]);
    EXPECT_FALSE(a[0]);

    unsigned long value = 0b00000000000000000000000000001101;
    BitArray c(4, value);
    EXPECT_EQ(c.to_string(), "1101");

    b.resize(4);
    b = b & c;
    EXPECT_EQ(b.to_string(), "0000");
}
TEST(BitArrayOperatorsInFourthGroup, OperatorOR){
    BitArray a(8);
    BitArray b(8);

    a.set(0);
    a.set(1);
    b.set(1);
    a |= b;

    EXPECT_TRUE(a[1]);
    EXPECT_TRUE(a[1]);

    unsigned long value = 0b00000000000000000000000000001101;
    BitArray c(8, value);
    EXPECT_EQ(c.to_string(), "00001101");

    b = b | c;
    EXPECT_EQ(b.to_string(), "00001111");
}
