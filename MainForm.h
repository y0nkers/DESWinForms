#pragma once
#include <string>
#include "src/DES.hpp"

namespace DESWinForms {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: String^ filePath;
	public:
		MainForm(void)
		{
			InitializeComponent();
			this->openFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
			this->saveFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
		}

	protected:
		~MainForm()
		{
			if (components) delete components;
		}
	private:
		System::Windows::Forms::Label^ labelText;
		System::Windows::Forms::TextBox^ textBoxInput;
		System::Windows::Forms::Button^ buttonEncrypt;
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ textBoxOutput;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelText = (gcnew System::Windows::Forms::Label());
			this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelText
			// 
			this->labelText->AutoSize = true;
			this->labelText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelText->Location = System::Drawing::Point(12, 25);
			this->labelText->Name = L"labelText";
			this->labelText->Size = System::Drawing::Size(141, 24);
			this->labelText->TabIndex = 0;
			this->labelText->Text = L"Text to Encrypt:";
			// 
			// textBoxInput
			// 
			this->textBoxInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxInput->Location = System::Drawing::Point(12, 97);
			this->textBoxInput->Multiline = true;
			this->textBoxInput->Name = L"textBoxInput";
			this->textBoxInput->Size = System::Drawing::Size(234, 187);
			this->textBoxInput->TabIndex = 1;
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEncrypt->Location = System::Drawing::Point(12, 290);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(111, 30);
			this->buttonEncrypt->TabIndex = 2;
			this->buttonEncrypt->Text = L"Encrypt";
			this->buttonEncrypt->UseVisualStyleBackColor = true;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &MainForm::buttonEncrypt_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(648, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBoxOutput
			// 
			this->textBoxOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxOutput->Location = System::Drawing::Point(263, 97);
			this->textBoxOutput->Multiline = true;
			this->textBoxOutput->Name = L"textBoxOutput";
			this->textBoxOutput->Size = System::Drawing::Size(234, 187);
			this->textBoxOutput->TabIndex = 4;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 469);
			this->Controls->Add(this->textBoxOutput);
			this->Controls->Add(this->buttonEncrypt);
			this->Controls->Add(this->textBoxInput);
			this->Controls->Add(this->labelText);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		//if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		String^ filename = saveFileDialog1->FileName;
		DES des("input\\key.txt", "output\\IV.txt");
		String^ encrypted = des.process(textBoxInput->Text, Mode::ENCRYPTION);
		textBoxOutput->Text = encrypted;
		//File::WriteAllText(filename, encrypted);
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) return;
		String^ filename = openFileDialog1->FileName;
		String^ text = File::ReadAllText(filename);
		textBoxInput->Text = text;
	}
	};
}
