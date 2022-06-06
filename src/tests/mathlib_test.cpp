#include <gtest/gtest.h>
#include "../lib/math_lib.h"

math_lib_t calculator;

TEST(Calculator, AddFunction) 
{
    EXPECT_EQ(calculator.add(10,5), 15);
    EXPECT_EQ(calculator.add(-80,-4), -84);
    EXPECT_EQ(calculator.add(-10,20), 10);
    EXPECT_EQ(calculator.add(10,-20), -10);
    EXPECT_FLOAT_EQ(calculator.add(1.345,8.23), 9.575);
    EXPECT_FLOAT_EQ(calculator.add(-5.846,-23.01), -28.856);
    EXPECT_FLOAT_EQ(calculator.add(349067234087520349572034957.0,2349582034852039485203948502.0), 2.6986493e+27);

    EXPECT_NE(calculator.add(10,10), 30);
    EXPECT_NE(calculator.add(0,0.125), 0);
    EXPECT_NE(calculator.add(3309548637495687322345234523452345.0,2346234562345234523452345252.0), 23452345);
}

TEST(Calculator, SubFunction)
{
    EXPECT_EQ(calculator.sub(20, 8), 12);
    EXPECT_EQ(calculator.sub(-50, -10), -40);
    EXPECT_EQ(calculator.sub(-234, 55), -289);
    EXPECT_EQ(calculator.sub(3452, -656), 4108);
    EXPECT_FLOAT_EQ(calculator.sub(8.456, 1.3948), 7.0612);
    EXPECT_FLOAT_EQ(calculator.sub(-2.439, -9.453), 7.014);
    EXPECT_FLOAT_EQ(calculator.sub(-23.25345, 98.3452), -121.59865);
    EXPECT_FLOAT_EQ(calculator.sub(234.393845, -1232.3047539), 1466.6985989);
    EXPECT_FLOAT_EQ(calculator.sub(2093485723094857203948572093485.0, 10934875239045872039485729034875209348.0), -1.093487315e+37);

    EXPECT_NE(calculator.sub(100, 20), 70);
    EXPECT_NE(calculator.sub(0, 20), 20);
    EXPECT_NE(calculator.sub(0, -20), -20);
    EXPECT_NE(calculator.sub(234523452345324523452.0, 234523453245234523452345.0), 245234532452345234523234523452.0);
}

TEST(Calculator, MultFunction)
{
    EXPECT_EQ(calculator.mult(234, 23), 5382);
    EXPECT_EQ(calculator.mult(-3453, -2), 6906);
    EXPECT_EQ(calculator.mult(-9483, 2342), -22209186);
    EXPECT_EQ(calculator.mult(1242, -948), -1177416);
    EXPECT_EQ(calculator.mult(0, 3453), 0);
    EXPECT_EQ(calculator.mult(34534, 0), 0);
    EXPECT_FLOAT_EQ(calculator.mult(1.5432, 6.0349), 9.31305768);
    EXPECT_FLOAT_EQ(calculator.mult(-1.5432,-6.0349), 9.31305768);
    EXPECT_FLOAT_EQ(calculator.mult(-1.5432, 6.0349), -9.31305768);
    EXPECT_FLOAT_EQ(calculator.mult(1.5432,-6.0349), -9.31305768);
    EXPECT_FLOAT_EQ(calculator.mult(0.5432, 6.0349), 3.27815768);
    EXPECT_FLOAT_EQ(calculator.mult(0.5432,0.0349), 0.01895768);
    EXPECT_FLOAT_EQ(calculator.mult(234857293487529834.0,803459830458309458.0), 1.886984012e+35);

    EXPECT_NE(calculator.mult(2342,0), 2342);
    EXPECT_NE(calculator.mult(20,-1), 20);
    EXPECT_NE(calculator.mult(-20,1), 20);
    EXPECT_NE(calculator.mult(-20,-1), -20);
}

TEST(Calculator, DivFunction)
{
    EXPECT_ANY_THROW(calculator.div(34534, 0));
    EXPECT_ANY_THROW(calculator.div(2342.25245, 0));
    
    EXPECT_EQ(calculator.div(0, 3453), 0);
    EXPECT_FLOAT_EQ(calculator.div(234, 23), 10.173913043478261);
    EXPECT_FLOAT_EQ(calculator.div(-3453, -2), 1726.5);
    EXPECT_FLOAT_EQ(calculator.div(-9483, 2342), -4.049103330486763);
    EXPECT_FLOAT_EQ(calculator.div(1242, -948), -1.310126582278481);
    EXPECT_FLOAT_EQ(calculator.div(1.5432, 6.0349), 0.255712605);
    EXPECT_FLOAT_EQ(calculator.div(-1.5432,-6.0349), 0.255712605);
    EXPECT_FLOAT_EQ(calculator.div(-1.5432, 6.0349), -0.255712605);
    EXPECT_FLOAT_EQ(calculator.div(1.5432,-6.0349),-0.255712605);
    EXPECT_FLOAT_EQ(calculator.div(0.5432, 6.0349), 0.09000977647);
    EXPECT_FLOAT_EQ(calculator.div(0.5432,0.0349), 15.56446991);
    EXPECT_FLOAT_EQ(calculator.div(234857293487529834.0,803459830458309458.0), 0.2923074491);

    EXPECT_NE(calculator.div(0, 25), 25);
    EXPECT_NE(calculator.div(100, -25), 4);
    EXPECT_NE(calculator.div(-100, 25), 4);
    EXPECT_NE(calculator.div(-100, -25), -4);
}

TEST(Calculator, FactFunction)
{
    EXPECT_ANY_THROW(calculator.fact(17));
    EXPECT_ANY_THROW(calculator.fact(34534234));
    EXPECT_ANY_THROW(calculator.fact(-30));
    EXPECT_ANY_THROW(calculator.fact(13));
    EXPECT_ANY_THROW(calculator.fact(-1));

    EXPECT_EQ(calculator.fact(5.234), 120);
    EXPECT_EQ(calculator.fact(1.353), 1);

    EXPECT_EQ(calculator.fact(5), 120);
    EXPECT_EQ(calculator.fact(1), 1);
    EXPECT_EQ(calculator.fact(0), 1);
    EXPECT_FLOAT_EQ(calculator.fact(12), 479001600);
}

TEST(Calculator, ExpFunction)
{   
    EXPECT_ANY_THROW(calculator.exp(0,-2));
    EXPECT_DOUBLE_EQ(calculator.exp(-25,-4), 2.56e-06);

    EXPECT_EQ(calculator.exp(5,2), 25);
    EXPECT_EQ(calculator.exp(0,2), 0);
    EXPECT_EQ(calculator.exp(-4,2), 16);
    EXPECT_EQ(calculator.exp(4,0), 1);
    EXPECT_EQ(calculator.exp(234234,0), 1);
    EXPECT_DOUBLE_EQ(calculator.exp(5,-2), 0.04);
    EXPECT_DOUBLE_EQ(calculator.exp(20,-33), 1.1641532182693502e-43);
    EXPECT_DOUBLE_EQ(calculator.exp(5,-325), 6.8351585149470374e-228);
    EXPECT_EQ(calculator.exp(234523452345234523234523452345.0,2345), std::numeric_limits<double>::infinity());
    EXPECT_FLOAT_EQ(calculator.exp(5,80), 8.27180613e+55);
    EXPECT_FLOAT_EQ(calculator.exp(5,325), 1.46302386e+227);
    EXPECT_FLOAT_EQ(calculator.exp(-5,-3), -0.008);
    EXPECT_FLOAT_EQ(calculator.exp(-10,-3), -0.001);
    EXPECT_FLOAT_EQ(calculator.exp(0.25,2), 0.0625);
    EXPECT_FLOAT_EQ(calculator.exp(0.25,10), 9.53674316e-7);
    EXPECT_FLOAT_EQ(calculator.exp(0.125,-2), 64);
    EXPECT_FLOAT_EQ(calculator.exp(0.256318,544), 2.3715151e-322);

    EXPECT_NE(calculator.exp(1.2342,2), 1);
    EXPECT_NE(calculator.exp(0,2), 1);
}

TEST(Calculator, MySqrtFunction)
{
    EXPECT_ANY_THROW(calculator.my_sqrt(-25,2));
    EXPECT_ANY_THROW(calculator.my_sqrt(-100,10));
    EXPECT_ANY_THROW(calculator.my_sqrt(-100,-10));
    EXPECT_ANY_THROW(calculator.my_sqrt(-9.453,-10));
    EXPECT_ANY_THROW(calculator.my_sqrt(-9.2342,2));

    EXPECT_ANY_THROW(calculator.my_sqrt(0,-10));
    EXPECT_ANY_THROW(calculator.my_sqrt(0,-3));

    EXPECT_FLOAT_EQ(calculator.my_sqrt(25,2), 5);
    EXPECT_EQ(calculator.my_sqrt(23525345,1), 23525345);
    EXPECT_EQ(calculator.my_sqrt(-23525345,1), -23525345);
    EXPECT_FLOAT_EQ(calculator.my_sqrt(-125,3), -5);
    EXPECT_EQ(calculator.my_sqrt(0,3), 0);
    EXPECT_EQ(calculator.my_sqrt(0,234), 0);
    EXPECT_ANY_THROW(calculator.my_sqrt(-25,-3));

    EXPECT_FLOAT_EQ(calculator.my_sqrt(25,-1), 0.04);
    EXPECT_FLOAT_EQ(calculator.my_sqrt(4.5345,1), 4.5345);
    EXPECT_FLOAT_EQ(calculator.my_sqrt(-4.5345,1), -4.5345);
    EXPECT_ANY_THROW(calculator.my_sqrt(-200,-9));
    EXPECT_ANY_THROW(calculator.my_sqrt(0,-1));

    EXPECT_FLOAT_EQ(calculator.my_sqrt(23.456,-3), 0.34934029);
    EXPECT_ANY_THROW(calculator.my_sqrt(-8.3452,-9));

    EXPECT_FLOAT_EQ(calculator.my_sqrt(0.5345,1), 0.5345);
    EXPECT_FLOAT_EQ(calculator.my_sqrt(-0.5345,1), -0.5345);
    EXPECT_FLOAT_EQ(calculator.my_sqrt(-0.5345,-1), -1.87090739);

    EXPECT_FLOAT_EQ(calculator.my_sqrt(0.5345,-1), 1.8709074);
    EXPECT_FLOAT_EQ(calculator.my_sqrt(0.125,2), 0.35355338);
    EXPECT_ANY_THROW(calculator.my_sqrt(-0.125,-3));

    EXPECT_FLOAT_EQ(calculator.my_sqrt(-0.125,3), -0.5);

    EXPECT_NE(calculator.my_sqrt(0,2), 1);
    EXPECT_NE(calculator.my_sqrt(1.02342,2), 1);
    EXPECT_NE(calculator.my_sqrt(0.2325,2), 1);
}

TEST(Calculator, ModFunction)
{
    EXPECT_ANY_THROW(calculator.modulo(17,0));
    EXPECT_ANY_THROW(calculator.modulo(3453452,0));
    EXPECT_ANY_THROW(calculator.modulo(5.34234,0));
    EXPECT_ANY_THROW(calculator.modulo(-5.34234,0));
    EXPECT_ANY_THROW(calculator.modulo(0.24234,0));

    EXPECT_EQ(calculator.modulo(17,3), 2);
    EXPECT_EQ(calculator.modulo(-17,3), -2);
    EXPECT_EQ(calculator.modulo(17,-3), -2);
    EXPECT_EQ(calculator.modulo(23425,52), 25);
    EXPECT_EQ(calculator.modulo(-23425,52), -25);
    EXPECT_EQ(calculator.modulo(23425,-52), -25);
    EXPECT_EQ(calculator.modulo(23425,2626), 2417);
    EXPECT_EQ(calculator.modulo(17,1), 0);
    EXPECT_EQ(calculator.modulo(17,17), 0);
    EXPECT_EQ(calculator.modulo(-17,-17), 0);
    EXPECT_EQ(calculator.modulo(2342342,2342342), 0);
    EXPECT_EQ(calculator.modulo(2342342,1), 0);
    EXPECT_EQ(calculator.modulo(1,3), 1);
    EXPECT_EQ(calculator.modulo(-1,3), -1);
    EXPECT_EQ(calculator.modulo(1,3453452), 1);
    EXPECT_EQ(calculator.modulo(0,3), 0);
    EXPECT_EQ(calculator.modulo(0,3453452), 0);
    EXPECT_FLOAT_EQ(calculator.modulo(5.234, 2.534), 0.16600000000000037);
    EXPECT_FLOAT_EQ(calculator.modulo(-5.234, 2.534), -0.16600000000000037);
    EXPECT_FLOAT_EQ(calculator.modulo(-5.234, -2.534), 0.16600000000000037);
    EXPECT_FLOAT_EQ(calculator.modulo(5.234, 1), 0.23399999999999999);
    EXPECT_FLOAT_EQ(calculator.modulo(0.5423, 1), 0.5423);
    EXPECT_FLOAT_EQ(calculator.modulo(5.234, 0.534), 0.42800000000000105);

    EXPECT_NE(calculator.modulo(0,3), 1);
    EXPECT_NE(calculator.modulo(0,345343), 1);
    EXPECT_NE(calculator.modulo(3,3), 1);
    EXPECT_NE(calculator.modulo(345343,345343), 1);
    EXPECT_NE(calculator.modulo(17,1), 17);
    EXPECT_NE(calculator.modulo(2342342,1), 2342342);
    EXPECT_NE(calculator.modulo(-1,3), 1);
    EXPECT_NE(calculator.modulo(-23425,52), 25);
    EXPECT_NE(calculator.modulo(-5.234, 2.534), 0.16600000000000037);
}

TEST(Calculator, divisionWithoutRemainderFunction)
{
    EXPECT_ANY_THROW(calculator.divisionWithoutRemainder(20,0));
    EXPECT_ANY_THROW(calculator.divisionWithoutRemainder(-20,0));
    EXPECT_ANY_THROW(calculator.divisionWithoutRemainder(3453452342,0));
    EXPECT_ANY_THROW(calculator.divisionWithoutRemainder(5.34234,0));
    EXPECT_ANY_THROW(calculator.divisionWithoutRemainder(-5.34234,0));
    EXPECT_ANY_THROW(calculator.divisionWithoutRemainder(0.24234,0));

    EXPECT_EQ(calculator.divisionWithoutRemainder(20,5), 4);
    EXPECT_EQ(calculator.divisionWithoutRemainder(20,1), 20);
    EXPECT_EQ(calculator.divisionWithoutRemainder(-20,5), -4);
    EXPECT_EQ(calculator.divisionWithoutRemainder(20,-5), -4);
    EXPECT_EQ(calculator.divisionWithoutRemainder(-20,-5), 4);
    EXPECT_EQ(calculator.divisionWithoutRemainder(0,25), 0);
    EXPECT_EQ(calculator.divisionWithoutRemainder(0,324534), 0);
    EXPECT_EQ(calculator.divisionWithoutRemainder(234234234,53453453), 4);
    EXPECT_EQ(calculator.divisionWithoutRemainder(-234234234,53453453), -4);
    EXPECT_EQ(calculator.divisionWithoutRemainder(-3453, -2), 1726);
    EXPECT_FLOAT_EQ(calculator.divisionWithoutRemainder(0.5432342,5242), 0);
    EXPECT_FLOAT_EQ(calculator.divisionWithoutRemainder(5.21533,0.9895), 5);
    EXPECT_FLOAT_EQ(calculator.divisionWithoutRemainder(5.21533,-0.9895), -5);
    EXPECT_FLOAT_EQ(calculator.divisionWithoutRemainder(0.5432,0.0349), 15);
    EXPECT_FLOAT_EQ(calculator.divisionWithoutRemainder(234857293487529834.0,803459830458309458.0), 0);

    EXPECT_NE(calculator.divisionWithoutRemainder(0, 25), 25);
    EXPECT_NE(calculator.divisionWithoutRemainder(100, -25), 4);
    EXPECT_NE(calculator.divisionWithoutRemainder(-100, 25), 4);
    EXPECT_NE(calculator.divisionWithoutRemainder(-100, -25), -4);
}
/*** End of file mathlib_test.cpp ***/