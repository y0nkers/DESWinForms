#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

#include <random>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <utility>
#include <stdexcept>

#include <msclr\marshal_cppstd.h>

namespace DESWinForms {
	std::string getStringFromFile(std::string filename);
	std::vector<char> readBytesFromFile(std::string filename);

	std::string stringToHex(const std::string& input);
	int hexValue(unsigned char hex_digit);
	std::string hexToString(const std::string& input);
}

#endif // !HELPERS_HPP
