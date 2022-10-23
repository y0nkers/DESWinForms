#pragma once

#include "src/DES.hpp"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

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
	private: System::Windows::Forms::Button^ buttonEncrypt;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ textBoxOutput;
	private: System::Windows::Forms::Button^ buttonDecrypt;
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
	private: System::Windows::Forms::TextBox^ textBoxLog;
	private: System::Windows::Forms::Label^ labelLog;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			   this->labelInput = (gcnew System::Windows::Forms::Label());
			   this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			   this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
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
			   this->buttonDecrypt = (gcnew System::Windows::Forms::Button());
			   this->labelOutput = (gcnew System::Windows::Forms::Label());
			   this->labelKey = (gcnew System::Windows::Forms::Label());
			   this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			   this->buttonBrowseKey = (gcnew System::Windows::Forms::Button());
			   this->buttonBrowseIV = (gcnew System::Windows::Forms::Button());
			   this->textBoxIV = (gcnew System::Windows::Forms::TextBox());
			   this->labelIV = (gcnew System::Windows::Forms::Label());
			   this->textBoxLog = (gcnew System::Windows::Forms::TextBox());
			   this->labelLog = (gcnew System::Windows::Forms::Label());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->menuStrip1->SuspendLayout();
			   this->groupBox1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // labelInput
			   // 
			   this->labelInput->AutoSize = true;
			   this->labelInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelInput->Location = System::Drawing::Point(2, 10);
			   this->labelInput->Name = L"labelInput";
			   this->labelInput->Size = System::Drawing::Size(59, 25);
			   this->labelInput->TabIndex = 0;
			   this->labelInput->Text = L"Input";
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
			   this->textBoxInput->Size = System::Drawing::Size(242, 150);
			   this->textBoxInput->TabIndex = 1;
			   // 
			   // buttonEncrypt
			   // 
			   this->buttonEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonEncrypt->Location = System::Drawing::Point(10, 178);
			   this->buttonEncrypt->Name = L"buttonEncrypt";
			   this->buttonEncrypt->Size = System::Drawing::Size(100, 32);
			   this->buttonEncrypt->TabIndex = 2;
			   this->buttonEncrypt->Text = L"Encrypt";
			   this->buttonEncrypt->UseVisualStyleBackColor = true;
			   this->buttonEncrypt->Click += gcnew System::EventHandler(this, &FormMain::buttonEncrypt_Click);
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
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(50, 24);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // openToolStripMenuItem
			   // 
			   this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			   this->openToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			   this->openToolStripMenuItem->Text = L"Open";
			   this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::openToolStripMenuItem_Click);
			   // 
			   // saveOutputToolStripMenuItem
			   // 
			   this->saveOutputToolStripMenuItem->Name = L"saveOutputToolStripMenuItem";
			   this->saveOutputToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			   this->saveOutputToolStripMenuItem->Text = L"Save output";
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
			   this->optionsToolStripMenuItem->Size = System::Drawing::Size(83, 24);
			   this->optionsToolStripMenuItem->Text = L"Options";
			   // 
			   // generateKeyToolStripMenuItem
			   // 
			   this->generateKeyToolStripMenuItem->Name = L"generateKeyToolStripMenuItem";
			   this->generateKeyToolStripMenuItem->Size = System::Drawing::Size(314, 24);
			   this->generateKeyToolStripMenuItem->Text = L"Generate Key";
			   this->generateKeyToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::generateKeyToolStripMenuItem_Click);
			   // 
			   // generateInitializaitonVectorToolStripMenuItem
			   // 
			   this->generateInitializaitonVectorToolStripMenuItem->Name = L"generateInitializaitonVectorToolStripMenuItem";
			   this->generateInitializaitonVectorToolStripMenuItem->Size = System::Drawing::Size(314, 24);
			   this->generateInitializaitonVectorToolStripMenuItem->Text = L"Generate Initializaiton Vector";
			   this->generateInitializaitonVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::generateInitializationVectorToolStripMenuItem_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // textBoxOutput
			   // 
			   this->textBoxOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->textBoxOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxOutput->Location = System::Drawing::Point(7, 217);
			   this->textBoxOutput->Multiline = true;
			   this->textBoxOutput->Name = L"textBoxOutput";
			   this->textBoxOutput->ReadOnly = true;
			   this->textBoxOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->textBoxOutput->Size = System::Drawing::Size(242, 150);
			   this->textBoxOutput->TabIndex = 4;
			   // 
			   // buttonDecrypt
			   // 
			   this->buttonDecrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonDecrypt->Location = System::Drawing::Point(134, 178);
			   this->buttonDecrypt->Name = L"buttonDecrypt";
			   this->buttonDecrypt->Size = System::Drawing::Size(100, 32);
			   this->buttonDecrypt->TabIndex = 5;
			   this->buttonDecrypt->Text = L"Decrypt";
			   this->buttonDecrypt->UseVisualStyleBackColor = true;
			   this->buttonDecrypt->Click += gcnew System::EventHandler(this, &FormMain::buttonDecrypt_Click);
			   // 
			   // labelOutput
			   // 
			   this->labelOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->labelOutput->AutoSize = true;
			   this->labelOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelOutput->Location = System::Drawing::Point(2, 191);
			   this->labelOutput->Name = L"labelOutput";
			   this->labelOutput->Size = System::Drawing::Size(76, 25);
			   this->labelOutput->TabIndex = 6;
			   this->labelOutput->Text = L"Output";
			   // 
			   // labelKey
			   // 
			   this->labelKey->AutoSize = true;
			   this->labelKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelKey->Location = System::Drawing::Point(5, 30);
			   this->labelKey->Name = L"labelKey";
			   this->labelKey->Size = System::Drawing::Size(49, 25);
			   this->labelKey->TabIndex = 7;
			   this->labelKey->Text = L"Key";
			   // 
			   // textBoxKey
			   // 
			   this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxKey->Location = System::Drawing::Point(10, 60);
			   this->textBoxKey->Name = L"textBoxKey";
			   this->textBoxKey->Size = System::Drawing::Size(189, 29);
			   this->textBoxKey->TabIndex = 8;
			   // 
			   // buttonBrowseKey
			   // 
			   this->buttonBrowseKey->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonBrowseKey.BackgroundImage")));
			   this->buttonBrowseKey->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->buttonBrowseKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->buttonBrowseKey->Location = System::Drawing::Point(205, 60);
			   this->buttonBrowseKey->Name = L"buttonBrowseKey";
			   this->buttonBrowseKey->Size = System::Drawing::Size(29, 29);
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
			   this->buttonBrowseIV->Location = System::Drawing::Point(205, 133);
			   this->buttonBrowseIV->Name = L"buttonBrowseIV";
			   this->buttonBrowseIV->Size = System::Drawing::Size(29, 29);
			   this->buttonBrowseIV->TabIndex = 12;
			   this->buttonBrowseIV->UseVisualStyleBackColor = true;
			   this->buttonBrowseIV->Click += gcnew System::EventHandler(this, &FormMain::buttonBrowseIV_Click);
			   // 
			   // textBoxIV
			   // 
			   this->textBoxIV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxIV->Location = System::Drawing::Point(10, 133);
			   this->textBoxIV->Name = L"textBoxIV";
			   this->textBoxIV->Size = System::Drawing::Size(189, 29);
			   this->textBoxIV->TabIndex = 11;
			   // 
			   // labelIV
			   // 
			   this->labelIV->AutoSize = true;
			   this->labelIV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelIV->Location = System::Drawing::Point(5, 103);
			   this->labelIV->Name = L"labelIV";
			   this->labelIV->Size = System::Drawing::Size(193, 25);
			   this->labelIV->TabIndex = 10;
			   this->labelIV->Text = L"Initialization Vector";
			   // 
			   // textBoxLog
			   // 
			   this->textBoxLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->textBoxLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxLog->Location = System::Drawing::Point(270, 60);
			   this->textBoxLog->Multiline = true;
			   this->textBoxLog->Name = L"textBoxLog";
			   this->textBoxLog->ReadOnly = true;
			   this->textBoxLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->textBoxLog->Size = System::Drawing::Size(709, 529);
			   this->textBoxLog->TabIndex = 13;
			   // 
			   // labelLog
			   // 
			   this->labelLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->labelLog->AutoSize = true;
			   this->labelLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelLog->Location = System::Drawing::Point(265, 32);
			   this->labelLog->Name = L"labelLog";
			   this->labelLog->Size = System::Drawing::Size(59, 25);
			   this->labelLog->TabIndex = 14;
			   this->labelLog->Text = L"Logs";
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left));
			   this->groupBox1->Controls->Add(this->labelInput);
			   this->groupBox1->Controls->Add(this->textBoxInput);
			   this->groupBox1->Controls->Add(this->labelOutput);
			   this->groupBox1->Controls->Add(this->textBoxOutput);
			   this->groupBox1->Location = System::Drawing::Point(3, 216);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(256, 373);
			   this->groupBox1->TabIndex = 15;
			   this->groupBox1->TabStop = false;
			   // 
			   // FormMain
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(991, 601);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->labelLog);
			   this->Controls->Add(this->textBoxLog);
			   this->Controls->Add(this->buttonBrowseIV);
			   this->Controls->Add(this->textBoxIV);
			   this->Controls->Add(this->labelIV);
			   this->Controls->Add(this->buttonBrowseKey);
			   this->Controls->Add(this->textBoxKey);
			   this->Controls->Add(this->labelKey);
			   this->Controls->Add(this->buttonDecrypt);
			   this->Controls->Add(this->buttonEncrypt);
			   this->Controls->Add(this->menuStrip1);
			   this->MinimumSize = System::Drawing::Size(570, 640);
			   this->Name = L"FormMain";
			   this->Text = L"DES CFB";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		DES des(textBoxKey->Text, textBoxIV->Text);
		textBoxLog->Text = "";
		String^ encrypted = des.process(textBoxInput->Text, Mode::ENCRYPTION, textBoxLog);
		textBoxOutput->Text = encrypted;
	}

	private: System::Void buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		DES des(textBoxKey->Text, textBoxIV->Text);
		textBoxLog->Text = "";
		String^ decrypted = des.process(textBoxInput->Text, Mode::DECRYPTION, textBoxLog);
		textBoxOutput->Text = decrypted;
	}

	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		String^ text = File::ReadAllText(openFileDialog1->FileName);
		textBoxInput->Text = text;
	}

	private: System::Void saveOutputToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		String^ filename = saveFileDialog1->FileName;
		File::WriteAllText(filename, textBoxOutput->Text);
		MessageBox::Show("width = " + this->Width + ", height = " + this->Height);
	}

	private: System::Void generateKeyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		std::string data = DES::generateBytes(true);
		String^ key = msclr::interop::marshal_as<String^>(data);
		File::WriteAllText(saveFileDialog1->FileName, key);
		MessageBox::Show("The key was successfully generated and saved in " + saveFileDialog1->FileName, "Generate key");
	}

	private: System::Void generateInitializationVectorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		std::string data = DES::generateBytes(false);
		String^ IV = msclr::interop::marshal_as<String^>(data);
		File::WriteAllText(saveFileDialog1->FileName, IV);
		MessageBox::Show("The initialization vector was successfully generated and saved in " + saveFileDialog1->FileName, "Generate initialization vector");
	}

	// Open file dialog menu and gets string from the specified file
	private: String^ getStringFromFile() {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return "";
		String^ filename = openFileDialog1->FileName;
		String^ data = File::ReadAllText(filename);
		return data;
	}

	// Get key from file
	private: System::Void buttonBrowseKey_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ key = getStringFromFile();
		if (key != "") textBoxKey->Text = key;
	}

	// Get initialization vector from file
	private: System::Void buttonBrowseIV_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ IV = getStringFromFile();
		if (IV != "") textBoxIV->Text = IV;
	}

	};
}
