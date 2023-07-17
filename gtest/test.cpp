#include <random>
#include <limits>
#include <gtest/gtest.h>
#include <weigand.h>

/*----------------  TEST PARITY  --------------*/
TEST(CheckParity, Test_1)
{
    std::vector<bool> binaryArray;
 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < 80; ++i) {
        bool value = dis(gen);
        binaryArray.push_back(value);
    }

    for (bool value : binaryArray) {
        std::cout << value << " ";
    }

	checkParity(binaryArray);
    //EXPECT_TRUE(checkParity(binaryArray));
}

/*----------------  SET BITS  --------------*/
TEST(SetBits, Test_2)
{
    std::array<uint8_t, keySize> keyArr;
    std::vector<bool> binaryArray(80);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (auto &i: binaryArray) {
        i = dis(gen);
    }

    bool checkParity;
    std::uniform_int_distribution<> dis2(0, 1);
    checkParity = dis2(gen);

    setBits(binaryArray, keyArr, checkParity);
}

/*----------------  TEST PRINT  --------------*/
TEST(PrintKey, Test_3)
{
	std::array<uint8_t, keySize> keyArr;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, std::numeric_limits<uint8_t>::max());

    for (uint8_t& value : keyArr) {
        value = dis(gen);
    }

	printKey(keyArr);
}

/*----------------  COUNT KEY  --------------*/
TEST(CountKey, Test_4)
{
    std::string binaryString;
    std::string result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < 80; i++) {
        char ch = dis(gen) ? '1' : '0';
        result.push_back(ch);
    }

    std::uniform_int_distribution<int> dis2(0, 6);

    bool cardState = false;
    countKey(binaryString, static_cast<T_Weigand>(dis2(gen)), cardState);
}

//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//
//    for (int i = 0; i < 100; i++) {
//        std::cout << "Running Test #" << i + 1 << std::endl;
//        bool result = RUN_ALL_TESTS();
//
//        if (result != 0) {
//            std::cout << "Test run #" << i + 1 << " failed!" << std::endl;
//            break;
//        }
//    }
//    return 0;
//}