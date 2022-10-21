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

#include <msclr\marshal_cppstd.h>

namespace DESWinForms {
	std::string getStringFromFile(std::string filename);
	std::vector<char> readBytesFromFile(std::string filename);
}

#endif // !HELPERS_HPP
