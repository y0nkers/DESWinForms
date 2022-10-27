#include "helpers.hpp"

namespace DESWinForms {

	/* Reads the entire contents of a file and writes it to a string */
	std::string getStringFromFile(std::string filename) {
		std::ifstream file(filename);
		std::stringstream buffer;
		std::string str = "";

		if (!file.is_open()) {
			std::cout << "An error occurred while opening " << filename << std::endl;
			exit(-1);
		}

		buffer << file.rdbuf();
		str = buffer.str();
		if (str == "") std::cout << "The specified file " << filename << " is empty" << std::endl;
		file.close();

		return str;
	}

	/* Reads the contents of a file in bytes and writes them to a vector */
	std::vector<char> readBytesFromFile(std::string filename) {
		std::ifstream file(filename, std::ios::binary | std::ios::ate);

		if (!file.is_open()) {
			std::cout << "An error occurred while opening " << filename << std::endl;
			exit(-1);
		}

		std::ifstream::pos_type length = file.tellg();
		std::vector<char> bytes(length);
		file.seekg(0, std::ios::beg);
		file.read(&bytes[0], length);

		return bytes;
	}

    std::string stringToHex(const std::string& input)
    {
        static const char hex_digits[] = "0123456789ABCDEF";

        std::string output;
        output.reserve(input.length() * 2);
        for (unsigned char c : input)
        {
            output.push_back(hex_digits[c >> 4]);
            output.push_back(hex_digits[c & 15]);
        }
        return output;
    }

    int hexValue(unsigned char hex_digit)
    {
        static const signed char hex_values[256] = {
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
             0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
            -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        };
        int value = hex_values[hex_digit];
        if (value == -1) throw std::invalid_argument("Invalid hex digit");
        return value;
    }

    std::string hexToString(const std::string& input)
    {
        const auto len = input.length();
        if (len & 1) throw std::invalid_argument("Hex string length must be even");

        std::string output;
        output.reserve(len / 2);
        for (auto it = input.begin(); it != input.end(); )
        {
            int hi = hexValue(*it++);
            int lo = hexValue(*it++);
            output.push_back(hi << 4 | lo);
        }
        return output;
    }
}
