#ifndef DES_HPP
#define DES_HPP

#include "helpers.hpp"
#include "boost/dynamic_bitset.hpp"

namespace DESWinForms {
	using namespace System;
	using namespace System::Windows::Forms;

	enum Mode {
		ENCRYPTION = 1,
		DECRYPTION = 2
	};

	// Key size - 56 (extra 8 for error detection) bits, Block size - 64 bits, 16 48bit round keys, plaintext block size 8, 16, ..., 64 bits
	class DES {
	private:
		std::bitset<64> key;
		std::bitset<64> IV;
		std::bitset<48> subkeys[16];
		unsigned int blockSize;

		static void leftShift(std::bitset<28>& bits, unsigned count);
		void generateSubkeys(std::string key_string);
		std::bitset<32> feistel(std::bitset<32>& block_R, std::bitset<48> subkey, unsigned round);
	public:
		DES(String^ keyStr, String^ ivStr, int blockSize);
		String^ process(String^ text, Mode mode);
		static std::string generateBytes(bool generateKey);
	};

}

#endif // !DES_HPP
