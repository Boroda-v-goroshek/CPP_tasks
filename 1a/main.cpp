#include "BitArray.hpp"
#include <gtest/gtest.h>

TEST(BitArrayTest, SetAndGet) {
    BitArray bitArray(10);
    EXPECT_EQ(bitArray.size(), 10);

    bitArray.set(2);
    EXPECT_TRUE(bitArray[2]);
    EXPECT_FALSE(bitArray[3]);

    bitArray.reset();
    EXPECT_FALSE(bitArray[2]);

    bitArray.set();
    EXPECT_TRUE(bitArray[2]);
    EXPECT_TRUE(bitArray[3]);
    EXPECT_TRUE(bitArray[4]);

    bitArray.reset(2);
    EXPECT_FALSE(bitArray[2]);
}

TEST(BitArrayTest, CopyAndSwap) {
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

TEST(BitArrayTest, OperatorXOR) {
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
    c = c ^ b;

    EXPECT_TRUE(c[0]);
    EXPECT_FALSE(c[6]);
}

TEST(BitArrayTest, operatorAND){
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

TEST(BitArrayTest, operatorOR){
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

TEST(BitArrayTest, operatorToLeft){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(8, value);
    EXPECT_EQ(a.to_string(), "00001101");

    a <<= 2;
    EXPECT_EQ(a.to_string(), "00110100");

    a = a << 2;
    EXPECT_EQ(a.to_string(), "11010000");

}

TEST(BitArrayTest, operatorToRight){
    unsigned long value = 0b00000000000000000000000000111101;
    BitArray a(8, value);
    EXPECT_EQ(a.to_string(), "00111101");

    a >>= 2;
    EXPECT_EQ(a.to_string(), "00001111");

    a = a >> 3;
    EXPECT_EQ(a.to_string(), "00000001");

}

TEST(BitArrayTest, AnotherOperator){
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

TEST(BitArrayTest, AnotherFunction){
    unsigned long value = 0b00000000000000000000000000001101;
    BitArray a(4, value);

    EXPECT_EQ(a.any(), true);
    EXPECT_EQ(a.none(), false);

    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}