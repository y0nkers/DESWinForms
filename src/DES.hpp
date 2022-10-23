#ifndef DES_HPP
#define DES_HPP

#include "helpers.hpp"

namespace DESWinForms {
	using namespace System;
	using namespace System::Windows::Forms;

	enum Mode {
		ENCRYPTION = 1,
		DECRYPTION = 2
	};

	// Key size - 56 (extra 8 for error detection) bits, Block size - 64 bits
	class DES {
	private:
		std::bitset<64> key;
		std::bitset<64> IV;

		static void leftShift(std::bitset<28>& bits, unsigned count);
		std::bitset<48> generateSubKey(std::bitset<28>& block_C, std::bitset<28>& block_D, unsigned round, TextBox^ tbLog);
		std::bitset<32> feistel(std::bitset<32>& block_R, std::bitset<48> subkey, unsigned round, TextBox^ tbLog);
	public:
		DES(String^ keyStr, String^ ivStr);
		String^ process(String^ text, Mode mode, TextBox^ tbLog);
		static void demonstration();
		static std::string generateBytes(bool generateKey);
	};

}

#endif // !DES_HPP
