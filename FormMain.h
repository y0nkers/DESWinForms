#pragma once

#include "src/DES.hpp"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace msclr::interop;

namespace DESWinForms {

	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void)
		{
			InitializeComponent();
			this->openFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
			this->saveFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";

		}

	protected:
		~FormMain()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::Label^ labelInput;
	private: System::Windows::Forms::TextBox^ textBoxInput;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ textBoxOutput;
	private: System::Windows::Forms::Label^ labelOutput;
	private: System::Windows::Forms::Label^ labelKey;
	private: System::Windows::Forms::ToolStripMenuItem^ saveOutputToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBoxKey;
	private: System::Windows::Forms::Button^ buttonBrowseKey;
	private: System::Windows::Forms::Button^ buttonBrowseIV;
	private: System::Windows::Forms::TextBox^ textBoxIV;
	private: System::Windows::Forms::Label^ labelIV;
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generateKeyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generateInitializaitonVectorToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonAction;
	private: System::Windows::Forms::GroupBox^ groupBoxAction;
	private: System::Windows::Forms::RadioButton^ radioButtonDecrypt;
	private: System::Windows::Forms::RadioButton^ radioButtonEncrypt;
	private: System::Windows::Forms::Label^ labelBlockSize;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownBlockSize;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			   this->labelInput = (gcnew System::Windows::Forms::Label());
			   this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveOutputToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->generateKeyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->generateInitializaitonVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->textBoxOutput = (gcnew System::Windows::Forms::TextBox());
			   this->labelOutput = (gcnew System::Windows::Forms::Label());
			   this->labelKey = (gcnew System::Windows::Forms::Label());
			   this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			   this->buttonBrowseKey = (gcnew System::Windows::Forms::Button());
			   this->buttonBrowseIV = (gcnew System::Windows::Forms::Button());
			   this->textBoxIV = (gcnew System::Windows::Forms::TextBox());
			   this->labelIV = (gcnew System::Windows::Forms::Label());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->buttonAction = (gcnew System::Windows::Forms::Button());
			   this->groupBoxAction = (gcnew System::Windows::Forms::GroupBox());
			   this->radioButtonDecrypt = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonEncrypt = (gcnew System::Windows::Forms::RadioButton());
			   this->labelBlockSize = (gcnew System::Windows::Forms::Label());
			   this->numericUpDownBlockSize = (gcnew System::Windows::Forms::NumericUpDown());
			   this->menuStrip1->SuspendLayout();
			   this->groupBox1->SuspendLayout();
			   this->groupBoxAction->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBlockSize))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // labelInput
			   // 
			   this->labelInput->AutoSize = true;
			   this->labelInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelInput->Location = System::Drawing::Point(6, 11);
			   this->labelInput->Name = L"labelInput";
			   this->labelInput->Size = System::Drawing::Size(60, 24);
			   this->labelInput->TabIndex = 0;
			   this->labelInput->Text = L"Ввод";
			   // 
			   // textBoxInput
			   // 
			   this->textBoxInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->textBoxInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxInput->Location = System::Drawing::Point(7, 38);
			   this->textBoxInput->Multiline = true;
			   this->textBoxInput->Name = L"textBoxInput";
			   this->textBoxInput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->textBoxInput->Size = System::Drawing::Size(593, 249);
			   this->textBoxInput->TabIndex = 1;
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->fileToolStripMenuItem,
					   this->optionsToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(991, 28);
			   this->menuStrip1->TabIndex = 3;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->openToolStripMenuItem,
					   this->saveOutputToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			   this->fileToolStripMenuItem->Text = L"Файл";
			   // 
			   // openToolStripMenuItem
			   // 
			   this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			   this->openToolStripMenuItem->Size = System::Drawing::Size(227, 24);
			   this->openToolStripMenuItem->Text = L"Открыть";
			   this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::openToolStripMenuItem_Click);
			   // 
			   // saveOutputToolStripMenuItem
			   // 
			   this->saveOutputToolStripMenuItem->Name = L"saveOutputToolStripMenuItem";
			   this->saveOutputToolStripMenuItem->Size = System::Drawing::Size(227, 24);
			   this->saveOutputToolStripMenuItem->Text = L"Сохранить вывод";
			   this->saveOutputToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::saveOutputToolStripMenuItem_Click);
			   // 
			   // optionsToolStripMenuItem
			   // 
			   this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->generateKeyToolStripMenuItem,
					   this->generateInitializaitonVectorToolStripMenuItem
			   });
			   this->optionsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			   this->optionsToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			   this->optionsToolStripMenuItem->Text = L"Опции";
			   // 
			   // generateKeyToolStripMenuItem
			   // 
			   this->generateKeyToolStripMenuItem->Name = L"generateKeyToolStripMenuItem";
			   this->generateKeyToolStripMenuItem->Size = System::Drawing::Size(407, 24);
			   this->generateKeyToolStripMenuItem->Text = L"Сгенерировать ключ";
			   this->generateKeyToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::generateKeyToolStripMenuItem_Click);
			   // 
			   // generateInitializaitonVectorToolStripMenuItem
			   // 
			   this->generateInitializaitonVectorToolStripMenuItem->Name = L"generateInitializaitonVectorToolStripMenuItem";
			   this->generateInitializaitonVectorToolStripMenuItem->Size = System::Drawing::Size(407, 24);
			   this->generateInitializaitonVectorToolStripMenuItem->Text = L"Сгенерировать вектор инициализации";
			   this->generateInitializaitonVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::generateInitializationVectorToolStripMenuItem_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // textBoxOutput
			   // 
			   this->textBoxOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->textBoxOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxOutput->Location = System::Drawing::Point(8, 317);
			   this->textBoxOutput->Multiline = true;
			   this->textBoxOutput->Name = L"textBoxOutput";
			   this->textBoxOutput->ReadOnly = true;
			   this->textBoxOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->textBoxOutput->Size = System::Drawing::Size(593, 235);
			   this->textBoxOutput->TabIndex = 4;
			   // 
			   // labelOutput
			   // 
			   this->labelOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->labelOutput->AutoSize = true;
			   this->labelOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelOutput->Location = System::Drawing::Point(6, 290);
			   this->labelOutput->Name = L"labelOutput";
			   this->labelOutput->Size = System::Drawing::Size(74, 24);
			   this->labelOutput->TabIndex = 6;
			   this->labelOutput->Text = L"Вывод";
			   // 
			   // labelKey
			   // 
			   this->labelKey->AutoSize = true;
			   this->labelKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelKey->Location = System::Drawing::Point(8, 32);
			   this->labelKey->Name = L"labelKey";
			   this->labelKey->Size = System::Drawing::Size(60, 24);
			   this->labelKey->TabIndex = 7;
			   this->labelKey->Text = L"Ключ";
			   // 
			   // textBoxKey
			   // 
			   this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxKey->Location = System::Drawing::Point(12, 59);
			   this->textBoxKey->Name = L"textBoxKey";
			   this->textBoxKey->Size = System::Drawing::Size(306, 26);
			   this->textBoxKey->TabIndex = 8;
			   // 
			   // buttonBrowseKey
			   // 
			   this->buttonBrowseKey->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonBrowseKey.BackgroundImage")));
			   this->buttonBrowseKey->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->buttonBrowseKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->buttonBrowseKey->Location = System::Drawing::Point(340, 59);
			   this->buttonBrowseKey->Name = L"buttonBrowseKey";
			   this->buttonBrowseKey->Size = System::Drawing::Size(26, 26);
			   this->buttonBrowseKey->TabIndex = 9;
			   this->buttonBrowseKey->UseVisualStyleBackColor = true;
			   this->buttonBrowseKey->Click += gcnew System::EventHandler(this, &FormMain::buttonBrowseKey_Click);
			   // 
			   // buttonBrowseIV
			   // 
			   this->buttonBrowseIV->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonBrowseIV.BackgroundImage")));
			   this->buttonBrowseIV->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->buttonBrowseIV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonBrowseIV->Location = System::Drawing::Point(340, 111);
			   this->buttonBrowseIV->Name = L"buttonBrowseIV";
			   this->buttonBrowseIV->Size = System::Drawing::Size(26, 26);
			   this->buttonBrowseIV->TabIndex = 12;
			   this->buttonBrowseIV->UseVisualStyleBackColor = true;
			   this->buttonBrowseIV->Click += gcnew System::EventHandler(this, &FormMain::buttonBrowseIV_Click);
			   // 
			   // textBoxIV
			   // 
			   this->textBoxIV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxIV->Location = System::Drawing::Point(12, 111);
			   this->textBoxIV->Name = L"textBoxIV";
			   this->textBoxIV->Size = System::Drawing::Size(306, 26);
			   this->textBoxIV->TabIndex = 11;
			   // 
			   // labelIV
			   // 
			   this->labelIV->AutoSize = true;
			   this->labelIV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelIV->Location = System::Drawing::Point(8, 88);
			   this->labelIV->Name = L"labelIV";
			   this->labelIV->Size = System::Drawing::Size(238, 24);
			   this->labelIV->TabIndex = 10;
			   this->labelIV->Text = L"Вектор инициализации";
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->groupBox1->Controls->Add(this->labelInput);
			   this->groupBox1->Controls->Add(this->textBoxInput);
			   this->groupBox1->Controls->Add(this->labelOutput);
			   this->groupBox1->Controls->Add(this->textBoxOutput);
			   this->groupBox1->Location = System::Drawing::Point(372, 31);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(607, 558);
			   this->groupBox1->TabIndex = 15;
			   this->groupBox1->TabStop = false;
			   // 
			   // buttonAction
			   // 
			   this->buttonAction->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonAction->Location = System::Drawing::Point(9, 246);
			   this->buttonAction->Name = L"buttonAction";
			   this->buttonAction->Size = System::Drawing::Size(356, 32);
			   this->buttonAction->TabIndex = 16;
			   this->buttonAction->Text = L"Шифрование";
			   this->buttonAction->UseVisualStyleBackColor = true;
			   this->buttonAction->Click += gcnew System::EventHandler(this, &FormMain::buttonAction_Click);
			   // 
			   // groupBoxAction
			   // 
			   this->groupBoxAction->Controls->Add(this->radioButtonDecrypt);
			   this->groupBoxAction->Controls->Add(this->radioButtonEncrypt);
			   this->groupBoxAction->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->groupBoxAction->Location = System::Drawing::Point(9, 178);
			   this->groupBoxAction->Name = L"groupBoxAction";
			   this->groupBoxAction->Size = System::Drawing::Size(357, 62);
			   this->groupBoxAction->TabIndex = 17;
			   this->groupBoxAction->TabStop = false;
			   this->groupBoxAction->Text = L"Выберите действие";
			   // 
			   // radioButtonDecrypt
			   // 
			   this->radioButtonDecrypt->AutoSize = true;
			   this->radioButtonDecrypt->Location = System::Drawing::Point(171, 28);
			   this->radioButtonDecrypt->Name = L"radioButtonDecrypt";
			   this->radioButtonDecrypt->Size = System::Drawing::Size(180, 28);
			   this->radioButtonDecrypt->TabIndex = 1;
			   this->radioButtonDecrypt->TabStop = true;
			   this->radioButtonDecrypt->Text = L"Дешифрование";
			   this->radioButtonDecrypt->UseVisualStyleBackColor = true;
			   // 
			   // radioButtonEncrypt
			   // 
			   this->radioButtonEncrypt->AutoSize = true;
			   this->radioButtonEncrypt->Checked = true;
			   this->radioButtonEncrypt->Location = System::Drawing::Point(6, 28);
			   this->radioButtonEncrypt->Name = L"radioButtonEncrypt";
			   this->radioButtonEncrypt->Size = System::Drawing::Size(153, 28);
			   this->radioButtonEncrypt->TabIndex = 0;
			   this->radioButtonEncrypt->TabStop = true;
			   this->radioButtonEncrypt->Text = L"Шифрование";
			   this->radioButtonEncrypt->UseVisualStyleBackColor = true;
			   this->radioButtonEncrypt->CheckedChanged += gcnew System::EventHandler(this, &FormMain::radioButtonEncrypt_CheckedChanged);
			   // 
			   // labelBlockSize
			   // 
			   this->labelBlockSize->AutoSize = true;
			   this->labelBlockSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelBlockSize->Location = System::Drawing::Point(8, 145);
			   this->labelBlockSize->Name = L"labelBlockSize";
			   this->labelBlockSize->Size = System::Drawing::Size(200, 24);
			   this->labelBlockSize->TabIndex = 19;
			   this->labelBlockSize->Text = L"Размер блока (бит)";
			   // 
			   // numericUpDownBlockSize
			   // 
			   this->numericUpDownBlockSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->numericUpDownBlockSize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			   this->numericUpDownBlockSize->Location = System::Drawing::Point(214, 146);
			   this->numericUpDownBlockSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			   this->numericUpDownBlockSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			   this->numericUpDownBlockSize->Name = L"numericUpDownBlockSize";
			   this->numericUpDownBlockSize->ReadOnly = true;
			   this->numericUpDownBlockSize->Size = System::Drawing::Size(63, 26);
			   this->numericUpDownBlockSize->TabIndex = 7;
			   this->numericUpDownBlockSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			   // 
			   // FormMain
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(991, 601);
			   this->Controls->Add(this->numericUpDownBlockSize);
			   this->Controls->Add(this->labelBlockSize);
			   this->Controls->Add(this->groupBoxAction);
			   this->Controls->Add(this->buttonAction);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->buttonBrowseIV);
			   this->Controls->Add(this->textBoxIV);
			   this->Controls->Add(this->labelIV);
			   this->Controls->Add(this->buttonBrowseKey);
			   this->Controls->Add(this->textBoxKey);
			   this->Controls->Add(this->labelKey);
			   this->Controls->Add(this->menuStrip1);
			   this->MinimumSize = System::Drawing::Size(570, 640);
			   this->Name = L"FormMain";
			   this->Text = L"DES CFB";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBoxAction->ResumeLayout(false);
			   this->groupBoxAction->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBlockSize))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	// Open file dialog menu and gets string from the specified file
	private: String^ getStringFromFile(boolean isKeyOrIV) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return "";
		String^ filename = openFileDialog1->FileName;
		String^ data = File::ReadAllText(filename);
		// Uncomment line below if need to represent data in hex format
		if (isKeyOrIV) data = marshal_as<String^>(stringToHex(marshal_as<std::string>(data)));
		return data;
	}

	// Open file and put its content in input textbox
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = getStringFromFile(false);
		if (text != "") textBoxInput->Text = text;
	}

	// Save data from output textbox into file
	private: System::Void saveOutputToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog1->FileName = "";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		String^ filename = saveFileDialog1->FileName;
		File::WriteAllText(filename, textBoxOutput->Text);
	}

	// Generate key for DES and save it in file
	private: System::Void generateKeyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog1->FileName = "";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		std::string data = DES::generateBytes(true);
		String^ key = marshal_as<String^>(data);
		File::WriteAllText(saveFileDialog1->FileName, key);
		MessageBox::Show("Ключ был успешно сгенерирован и сохранён в " + saveFileDialog1->FileName, "Генерация ключа");
	}

	// Generate initialization vector and save it in file
	private: System::Void generateInitializationVectorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog1->FileName = "";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		std::string data = DES::generateBytes(false);
		String^ IV = marshal_as<String^>(data);
		File::WriteAllText(saveFileDialog1->FileName, IV);
		MessageBox::Show("Вектор инициализации был успешно сгенерирован и сохранён в " + saveFileDialog1->FileName, "Генерация вектора инициализации");
	}

	// Get key from file
	private: System::Void buttonBrowseKey_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ key = getStringFromFile(true);
		if (key != "") textBoxKey->Text = key;
	}

	// Get initialization vector from file
	private: System::Void buttonBrowseIV_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ IV = getStringFromFile(true);
		if (IV != "") textBoxIV->Text = IV;
	}

	// Encrypt/decrypt button
	private: System::Void buttonAction_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ output;
		int blockSize = System::Convert::ToInt32(numericUpDownBlockSize->Value);
		if (radioButtonEncrypt->Checked) {
			DES des(textBoxKey->Text, textBoxIV->Text, blockSize);
			output = des.process(textBoxInput->Text, Mode::ENCRYPTION);
		}
		else {
			DES des(textBoxKey->Text, "", blockSize);
			output = des.process(textBoxInput->Text, Mode::DECRYPTION);
		}
		textBoxOutput->Text = output;
	}

	// Radio button for encrypt/decrypt action
	private: System::Void radioButtonEncrypt_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButtonEncrypt->Checked) {
			labelIV->Visible = true;
			textBoxIV->Visible = true;
			buttonBrowseIV->Visible = true;
			buttonAction->Text = "Шифрование";
		}
		else {
			labelIV->Visible = false;
			textBoxIV->Visible = false;
			buttonBrowseIV->Visible = false;
			buttonAction->Text = "Расшифрование";
		}
	}
};
}
