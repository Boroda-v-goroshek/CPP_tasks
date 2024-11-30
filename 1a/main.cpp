#include "BitArray.hpp"
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
}
TEST(BitArrayConstructors, CopyAndSwap){
    BitArray a(8);
    a.set(0);
    a.set(1);
    BitArray b(a);

    EXPECT_EQ(a.to_string(), b.to_string());

    BitArray c(3);
    c.swap(a);
    EXPECT_FALSE(a[0]);
    EXPECT_FALSE(a[1]);
    EXPECT_TRUE(c[0]);
    EXPECT_TRUE(c[1]);
    EXPECT_EQ(a.size(), 8);
    EXPECT_EQ(c.size(), 3);
}

TEST(BitArrayChanges, SetAndGet) {
    BitArray bitArray(8);
    EXPECT_EQ(bitArray.size(), 8);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.set(2);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.set();
    EXPECT_TRUE(bitArray[2]);
    EXPECT_TRUE(bitArray[3]);
    EXPECT_TRUE(bitArray[4]);
}
TEST(BitArrayChanges, ResetAndGet) {
    BitArray bitArray(7);
    EXPECT_EQ(bitArray.size(), 7);
    EXPECT_EQ(bitArray.none(), true);

    bitArray.reset();
    EXPECT_FALSE(bitArray[2]);

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

    bitArray.resize(0);
    EXPECT_EQ(bitArray.size(), 0);
    EXPECT_EQ(bitArray.none(), true);
    EXPECT_EQ(bitArray.empty(), true);

    bitArray.resize(11, true);
    EXPECT_EQ(bitArray.size(),11);
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

TEST(BitArrayToString, ToString){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray abc(4, value);
    EXPECT_EQ(abc.to_string(), "1101");

    value = 0b000000000000000000000000001101101;
    BitArray bitArray(7, value);
    EXPECT_EQ(bitArray.to_string(), "1101101");
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

TEST(BitArrayOperatorsInThirdGroup, OperatorEqEq){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);
    BitArray b = a;

    EXPECT_EQ(a.to_string(), b.to_string());
    EXPECT_EQ(a == b, true);
    EXPECT_EQ(a != b, false);
    EXPECT_EQ(a.size(), b.size());

    BitArray c(4);
    EXPECT_EQ(c != b, true);
}
TEST(BitArrayOperatorsInThirdGroup, OperatorMinus){
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
}

TEST(BitArrayAnotherBoolFunction, FunctionEmptyAndCleare){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);

    EXPECT_EQ(a.any(), true);
    EXPECT_EQ(a.none(), false);

    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
}
TEST(BitArrayAnotherBoolFunction, FunctionCount){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);
    EXPECT_EQ(a.count(), 3);

    a.clear();
    EXPECT_EQ(a.count(), 0);
    
    a.push_back(true);
    EXPECT_EQ(a.count(), 1);
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


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
