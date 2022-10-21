#include "DES.hpp"
using namespace System;

namespace DESWinForms {

	// Initial permutation of message block
	int initial_message_permutation[64] = {
		58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17,  9, 1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7
	};

	// Bits 8, 16, 24, 32, 40, 48, 56 and 64 do not participate in the permutation
	int key_permutaion[2][28] = {
		{
			57, 49, 41, 33, 25, 17, 9,
			1,  58, 50, 42, 34, 26, 18,
			10, 2,  59, 51, 43, 35, 27,
			19, 11, 3,  60, 52, 44, 36
		},
		{
			63, 55, 47, 39, 31, 23, 15,
			7, 62, 54, 46, 38, 30, 22,
			14, 6, 61, 53, 45, 37, 29,
			21, 13, 5, 28, 20, 12, 4
		}
	};

	// Specifies how many times to shift blocks C and D to get a subkey on each round
	int key_shift_sizes[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	// Specifies which bits are taken from the 56-bit CD vector for a 48-bit round subkey
	int subkey_permutation[48] = {
		14, 17, 11, 24, 1,  5,
		3,  28, 15, 6,  21, 10,
		23, 19, 12, 4,  26, 8,
		16, 7,  27, 20, 13, 2,
		41, 52, 31, 37, 47, 55,
		30, 40, 51, 45, 33, 48,
		44, 49, 39, 56, 34, 53,
		46, 42, 50, 36, 29, 32
	};

	// Extends the R block inside the Feistel function by duplicating some bits
	int block_R_expansion[48] = {
		32, 1,  2,  3,  4,  5,
		4,  5,  6,  7,  8,  9,
		8,  9,  10, 11, 12, 13,
		12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21,
		20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29,
		28, 29, 30, 31, 32, 1
	};

	// S-boxes for transform block B inside the Feistel function from 6 bit to 4 bit
	int blocks_B_permutation[8][4][16] = {
		{
			14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
			0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
			4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
			15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
		},
		{
			15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
			3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
			0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
			13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
		},
		{
			10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
			13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
			13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
			1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
		},
		{
			7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
			13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
			10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
			3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
		},
		{
			2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
			14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
			4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
			11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
		},
		{
			12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
			10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
			9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
			4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
		},
		{
			4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
			13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
			1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
			6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
		},
		{
			13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
			1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
			7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
			2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
		}
	};

	// Permutation applied to the 32-bit block B1...B8 to obtain the value of the Feistel function
	int block_R_permutation[32] = {
		16, 7,  20, 21,
		29, 12, 28, 17,
		1,  15, 23, 26,
		5,  18, 31, 10,
		2,  8,  24, 14,
		32, 27, 3,  9,
		19, 13, 30, 6,
		22, 11, 4,  25
	};

	// Final permutation of message block
	int final_message_permutation[64] = {
		40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41,  9, 49, 17, 57, 25
	};

	// Rotate block bits to the left
	void DES::leftShift(std::bitset<28>& bits, unsigned count) {
		bits = bits << count | bits >> (28 - count);
	}

	/* Generate pseudo-random 64 bits. Can be used for generating key or initialization vector for CFB mode*/
	std::bitset<64> DES::generateBytes(std::string output_filename, bool generateKey) {
		std::mt19937_64 gen(time(NULL));
		unsigned long long number = gen();
		std::bitset<64> bits(number);

		// Parity bits - each byte must contain an odd number of ones
		if (generateKey) {
			const std::string key_string = bits.to_string();
			std::string fragment;
			for (int i = 0; i < 8; i++) {
				fragment = key_string.substr(i * 7 + i, 7);
				std::string::difference_type ones_count = std::count(fragment.begin(), fragment.end(), '1');
				if (ones_count % 2 == 0) bits[63 - (i * 8 + 7)] = 1;
				else bits[63 - (i * 8 + 7)] = 0;
			}
		}

		std::string bits_str = bits.to_string();
		std::vector<char> bits_vector;
		for (int i = 0; i < 8; ++i) {
			std::bitset<8> byte(bits_str.substr(i * 8, 8));
			int byte_value = byte.to_ulong();
			bits_vector.push_back(static_cast<char>(byte_value));
		}

		std::ofstream output_file(output_filename);
		output_file.write(&bits_vector[0], bits_vector.size());
		output_file.close();
		if (generateKey) std::cout << "Key generated and written to file " << output_filename << "." << std::endl;
		else std::cout << "Initial Vector generated and written to file " << output_filename << "." << std::endl;

		return bits;
	}

	// Generate 48-bit subkey for current round
	std::bitset<48> DES::generateSubKey(std::bitset<28>& block_C, std::bitset<28>& block_D, unsigned round) {
		leftShift(block_C, key_shift_sizes[round]);
		leftShift(block_D, key_shift_sizes[round]);

		std::string CD;
		CD += block_C.to_string();
		CD += block_D.to_string();

		std::bitset<48> subkey;
		for (int i = 0; i < 48; ++i) subkey[47 - i] = CD[subkey_permutation[i] - 1] - '0';

		return subkey;
	}

	// Feistel encryption function
	std::bitset<32> DES::feistel(std::bitset<32>& block_R, std::bitset<48> subkey) {
		// 1. Expand block_R from 32 to 48 bits by duplicating some bits
		std::bitset<48> expanded_block;
		for (int i = 0; i < 48; ++i) expanded_block[47 - i] = block_R[block_R_expansion[i] - 1];

		// 2. Expanded block XOR key
		expanded_block = expanded_block ^ subkey;

		// 3. Represent the result of step 2 in the form of 8 blocks of 6 bits each
		// Shrink every block to 4 bit using permutations
		std::string block_string = expanded_block.to_string();
		std::string fragment;
		std::bitset<4> blocks_b[8];
		for (int i = 0; i < 8; ++i) {
			fragment = block_string.substr(i * 6, 6); // 6 bit
			int row = (fragment[0] - '0') * 2 + (fragment[5] - '0'); // Row of needed permutation - first and last bits of fragment = binary number -> decimal number
			int column = (fragment[1] - '0') * 8 + (fragment[2] - '0') * 4 + (fragment[3] - '0') * 2 + (fragment[4] - '0'); // same with column
			blocks_b[i] = std::bitset<4>(blocks_B_permutation[i][row][column]);
		}

		// 4. Final permutation for vector (string) of 8 blocks of step 3.
		block_string = "";
		for (int i = 0; i < 8; ++i) block_string += blocks_b[i].to_string();

		std::bitset<32> result;
		for (int i = 0; i < 32; ++i) result[31 - i] = block_string[block_R_permutation[i] - 1] - '0';

		return result;
	}

	void DES::demonstration() {
		std::string key = "01001011010001010101100101010111010011110101001001000100";
		std::bitset<56> key_bits(key);
		std::cout << "����:\n" << key << std::endl;

		const std::string key_string = key;
		std::string extended_key_string;
		std::string fragment;
		for (int i = 0; i < 8; i++) {
			fragment = key_string.substr(i * 7, 7);
			std::string::difference_type ones_count = std::count(fragment.begin(), fragment.end(), '1');
			if (ones_count % 2 == 0) fragment += '1';
			else fragment += '0';
			extended_key_string += fragment;
		}
		std::cout << "��������� ���� �� 64 ���:\n" << extended_key_string << std::endl;

		std::bitset<28> block_C, block_D;
		for (int i = 0; i < 28; i++) {
			block_C[27 - i] = extended_key_string[key_permutaion[0][i] - 1] - '0';
			block_D[27 - i] = extended_key_string[key_permutaion[1][i] - 1] - '0';
		}
		std::cout << "\n����� C0 � D0, ���������� ������������� ������������ ����� �� �������:\nC0: " << block_C.to_string() << "\nD0: " << block_D.to_string() << std::endl;

		std::string msg = "ENCRYPT.";
		std::string block_str;
		for (auto c : msg) block_str += std::bitset<8>(c).to_string();
		std::cout << "\n���� ��� ����������: " << msg << std::endl << "����:\n" << block_str << std::endl;

		std::bitset<64> permutated_bits;
		for (int j = 0; j < 64; j++) permutated_bits[63 - j] = block_str[initial_message_permutation[j] - 1] - '0';
		block_str = permutated_bits.to_string();
		std::cout << "\n��������� ������������ �����:\n" << block_str << std::endl;

		std::bitset<32> block_L(block_str.substr(0, block_str.size() / 2));
		std::bitset<32> block_R(block_str.substr(block_str.size() / 2, block_str.size()));
		std::bitset<32> temp;
		std::cout << "\n1 ����� ����������\n\n������� ���� �� ��� ����� ��� ������������� � ������:\nL0=" << block_L.to_string() << " R0=" << block_R.to_string() << std::endl;

		std::cout << "\n������������� ����� k1:\n�������� ����� C1 � D1 � ������� ����� ����������� ������� C0 � D0\n";
		leftShift(block_C, key_shift_sizes[0]);
		leftShift(block_D, key_shift_sizes[0]);
		std::cout << "C1: " << block_C.to_string() << "\nD1: " << block_D.to_string() << std::endl;

		std::string CD;
		CD += block_C.to_string();
		CD += block_D.to_string();
		std::cout << "��������� �� ������, �������� 56 ���:\nCD: " << CD << std::endl;
		std::bitset<48> subkey;
		for (int i = 0; i < 48; ++i) subkey[47 - i] = CD[subkey_permutation[i] - 1] - '0';
		std::cout << "�������� 48-������ ���� k1, ��������� �� ��������� �� ������� ����� CD\nk1: " << subkey.to_string() << std::endl;

		std::cout << "\n��������� ������� �������� f(R0, k1):\n";
		temp = block_R;
		std::bitset<48> expanded_block;
		for (int i = 0; i < 48; ++i) expanded_block[47 - i] = block_R[block_R_expansion[i] - 1];
		std::cout << "��������� 32-������� R0 �� 48-�������� E(R0) ���� ������������ ����� �������� �������:\nR0:    " << temp.to_string() << "\nE(R0): " << expanded_block.to_string() << std::endl;

		std::cout << "\n����������� ���� ���������� �� ������ 2 � k1, �.� E(R0) XOR k1:\n    " << expanded_block << "\nXOR\n    " << subkey << std::endl;
		expanded_block = expanded_block ^ subkey;
		std::cout << "    " << expanded_block << std::endl;

		std::cout << "\n��������� �������������� � ���� 8 ���������������� ������ B �� 6 ���:\n";
		std::string block_string = expanded_block.to_string();
		std::bitset<4> blocks_b[8];
		for (int i = 0; i < 8; ++i) {
			fragment = block_string.substr(i * 6, 6); // 6 bit
			int row = (fragment[0] - '0') * 2 + (fragment[5] - '0'); // Row of needed permutation - first and last bits of fragment = binary number -> decimal number
			int column = (fragment[1] - '0') * 8 + (fragment[2] - '0') * 4 + (fragment[3] - '0') * 2 + (fragment[4] - '0'); // same with column
			blocks_b[i] = std::bitset<4>(blocks_B_permutation[i][row][column]);
			std::cout << "B" << i + 1 << ": " << fragment << std::endl;
		}
		std::cout << "\n����� ������ �� ������ B ���������������� � 4-������� ���� � ������� �������������� �� ������\n\n����� ��������������\n";
		for (int i = 0; i < 8; ++i) std::cout << "B" << i + 1 << ": " << blocks_b[i] << std::endl;

		block_string = "";
		for (int i = 0; i < 8; ++i) block_string += blocks_b[i].to_string();
		std::cout << "\n��������� ��� 8 ������ ������, �������� 32-������� ���� B: " << block_string << std::endl;
		std::bitset<32> result;
		for (int i = 0; i < 32; ++i) result[31 - i] = block_string[block_R_permutation[i] - 1] - '0';
		std::cout << "\n��������� � ���� ������������ P, �������� ��������� ������� ��������:\nf(R0, k1) = " << result << std::endl;

		std::cout << "\n����� �������� ������ ������ ������ �������� ����������� (L1 = R0)\nL1: " << block_R;
		std::cout << "\n\n������ �������� - XOR ����������� L � ���������� f, �.� R1 = L0 XOR f(R0, k1)\nR1:\n    " << block_L << "\nXOR\n    " << result;
		temp = block_R;
		block_R = block_L ^ result;
		block_L = temp;
		std::cout << "\n  = " << block_R << std::endl;

		block_str = block_L.to_string();
		block_str += block_R.to_string();
		std::cout << "\n��������� L1 � R1 ������:\n" << block_str;
		for (int j = 0; j < 64; j++) permutated_bits[63 - j] = block_str[final_message_permutation[j] - 1] - '0';
		block_str = permutated_bits.to_string();
		std::cout << "\n��������� �������� ������������ �� �������:\n" << block_str << std::endl;
	}

	String^ DES::test(String^ string) {
		std::string unmanaged = msclr::interop::marshal_as<std::string>(string);
		std::reverse(unmanaged.begin(), unmanaged.end());
		return msclr::interop::marshal_as<String^>(unmanaged);
	}

	DES::DES(std::string key_filename, std::string IV_filename) {
		auto key = readBytesFromFile(key_filename);
		if (key.size() != 8) {
			std::cout << "ERROR: Wrong key size (must be 8 bytes)" << std::endl;
			exit(-1);
		}

		std::string key_string;
		for (auto c : key) key_string += std::bitset<8>(c).to_string();

		std::string fragment;
		for (int i = 0; i < 8; i++) {
			fragment = key_string.substr(i * 8, 8);
			std::string::difference_type ones_count = std::count(fragment.begin(), fragment.end(), '1');
			if (ones_count % 2 == 0) {
				std::cout << "Error: bad key" << std::endl;
				exit(-1);
			}
		}

		try { this->key = std::bitset<64>(key_string); }
		catch (std::exception& e) {
			std::cout << "Error: invalid key characters" << std::endl;
			exit(-1);
		}

		if (IV_filename != "") {
			auto IV_bytes = readBytesFromFile(IV_filename);
			std::string block_str;
			for (auto c : IV_bytes) block_str += std::bitset<8>(c).to_string();
			this->IV = std::bitset<64>(block_str);
		}
		else IV = generateBytes("output\\IV.txt", false);
	}

	String^ DES::process(String^ text, Mode mode) {
		// Get message bytes
		std::string str = msclr::interop::marshal_as<std::string>(text);
		std::vector<char> message(str.begin(), str.end());
		int remain_bytes = 8 - (message.size() % 8); // How many bytes must be added so that the message length is a multiple of 8 bytes
		// if message length is already a multiple of 8 bytes
		if (remain_bytes != 8) {
			std::vector<char> tmp(remain_bytes, ' ');
			message.insert(message.end(), tmp.begin(), tmp.end());
		}

		// Extend key to 64 bit
		const std::string key_string = key.to_string();

		// Initialize C0, D0
		std::bitset<28> block_C, block_D;
		for (int i = 0; i < 28; i++) {
			block_C[27 - i] = key_string[key_permutaion[0][i] - 1] - '0';
			block_D[27 - i] = key_string[key_permutaion[1][i] - 1] - '0';
		}

		//std::ofstream output_file(output_filename);
		std::string output;

		for (int i = 0; i < message.size(); i += 8) {
			// Message block size - 8 bytes
			std::vector<char> message_block(message.cbegin() + i, message.cbegin() + i + 8);

			// Convert message block from 8 chars to 64 bits using string
			std::string block_str;
			for (auto c : message_block) block_str += std::bitset<8>(c).to_string();

			std::bitset<64> message_bits(block_str);

			// Initial message block permutation
			std::bitset<64> permutated_bits;
			for (int j = 0; j < 64; j++) permutated_bits[63 - j] = IV[initial_message_permutation[j] - 1];

			// Rewriting permutated bits to string
			block_str = permutated_bits.to_string();

			// Split the message block into two parts - L (32 left bits of message) and R (32 right bits of message)
			std::bitset<32> block_L(block_str.substr(0, block_str.size() / 2));
			std::bitset<32> block_R(block_str.substr(block_str.size() / 2, block_str.size()));
			std::bitset<32> temp;

			// 16 Feistel's rounds of encryption
			for (int round = 0; round < 16; ++round) {
				// Generate subkey for current round
				std::bitset<48> subkey = generateSubKey(block_C, block_D, round);
				// L(i) = R(i-1)
				// R(i) =  L(i-1) ^ f(R(i-1), k(i)) 
				temp = block_R;
				block_R = block_L ^ feistel(block_R, subkey);
				block_L = temp;
			}

			// Final permutation of message
			block_str = block_L.to_string();
			block_str += block_R.to_string();
			for (int j = 0; j < 64; j++) permutated_bits[63 - j] = block_str[final_message_permutation[j] - 1] - '0';

			permutated_bits = permutated_bits ^ message_bits;

			// CFB mode: Ciphertext going to next stage
			// Encrypt: Ciphertext = DES(Ci) XOR Plaintext
			// Decrypt: Plaintext = DES(Ci) XOR Ciphertext 
			if (mode == Mode::ENCRYPTION) IV = permutated_bits;
			else IV = message_bits;

			block_str = permutated_bits.to_string();
			message_block.clear();
			for (int i = 0; i < 8; ++i) {
				std::bitset<8> char1(block_str.substr(i * 8, 8));
				unsigned long x = char1.to_ulong();
				char c = static_cast<char>(x);
				output.append(1, c);
				message_block.push_back(c);
			}

			//output_file.write(&message_block[0], message_block.size());
		}

		//output_file.close();
		//std::string operation = mode == Mode::ENCRYPTION ? "encrypted" : "decrypted";
		//std::cout << "Message successfully " << operation << " and written to file " << output_filename << "." << std::endl;
		String^ out = msclr::interop::marshal_as<String^>(output);
		return out;
	}
}