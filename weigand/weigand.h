#pragma once
#include <iostream>
#include <cstdint>
#include <array>
#include <bitset>
#include <vector>
#include <numeric>
#include <vector>

const uint8_t keySize = 10;


enum T_Weigand {
	WEIGAND_26,
	WEIGAND_32,
	WEIGAND_34,
	WEIGAND_35,
	WEIGAND_37,
	WEIGAND_64,
	WEIGAND_80
};

bool checkParity(const std::vector<bool>& binaryArray);
void setBits(const std::vector<bool>& binaryArray, std::array<uint8_t, keySize>& keyArr, bool checkParity);
void printKey(const std::array<uint8_t, keySize>& keyArr);
std::array <uint8_t, keySize> countKey(std::string binaryString, T_Weigand weigan, bool& cardState);


