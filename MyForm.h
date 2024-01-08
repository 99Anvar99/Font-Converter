#pragma once
#include <windows.h>
#include <filesystem>
#include <tchar.h>
#include <CommCtrl.h>
#include <vector>
#include <string>
#include <set>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <iostream>

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(49, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(481, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Font TTF / OTF To Unsigned Char (Uint_8t)";
			// 
			// comboBox1
			// 
			this->comboBox1->Location = System::Drawing::Point(12, 101);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(259, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"Select Font";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(7, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Font To Convert";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(312, 76);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 46);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Convert";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &MyForm::button1_MouseLeave);
			this->button1->MouseHover += gcnew System::EventHandler(this, &MyForm::button1_MouseHover);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(326, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(193, 120);
			this->label3->TabIndex = 5;
			this->label3->Text = L"This will create a .txt file in \r\n(C:/FileConverter)\r\n\r\nThe .txt file will have a"
				L" \r\nprinted/converted\r\nfont to hex";
			this->label3->Visible = false;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(443, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 46);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Open Folder";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(580, 137);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Font Converter";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Checks if extention is supported
		inline bool contain_ext(const std::filesystem::path& path)
		{
			static const std::set<std::string> supported_formats = {
				".ttf", ".otf"
			};
			const auto ext = path.extension().string();
			return supported_formats.contains(ext);
		}

		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
		{
			// Clear Combo box dropdown
			comboBox1->Items->Clear();

			// Check if FontConverter folder exists
			if (const std::filesystem::path font_path = "C:/FontConverter"; exists(font_path))
			{
				for (const auto& dir_entry : std::filesystem::directory_iterator(font_path))
				{
					if (dir_entry.is_regular_file() && contain_ext(dir_entry.path()))
					{
						// Add file to combo box (only file names)
						comboBox1->Items->Add(gcnew String(dir_entry.path().filename().string().c_str()));
					}
				}
			}
			else
			{
				// Create FontConverter folder
				std::filesystem::create_directory(font_path);
			}
		}
		private: System::Void button1_MouseHover(System::Object^ sender, System::EventArgs^ e) 
		{
			MyForm::Size = System::Drawing::Size(600, 325);
			label3->Visible = true;
		}
		private: System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			MyForm::Size = System::Drawing::Size(600, 180);
			label3->Visible = false;
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try 
			{
				// Check if file exist and directory is not empty
				if (comboBox1->Text == "Select Font" || comboBox1->Text == "" || comboBox1->Text == nullptr)
				{
					MessageBox::Show("Please select a font", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				const std::size_t bufferSize = 100000;

				// Get selected font
				std::string font_name = msclr::interop::marshal_as<std::string>(comboBox1->SelectedItem->ToString());

				// Open the TTF file
				std::ifstream ttfFile("C:/FontConverter/" + font_name, std::ios::binary);

				if (!ttfFile.is_open()) {
					MessageBox::Show("Error opening file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Get the size of the file
				ttfFile.seekg(0, std::ios::end);
				std::streampos fileSize = ttfFile.tellg();
				ttfFile.seekg(0, std::ios::beg);

				// Read the file in chunks
				std::vector<uint8_t> fontData;
				fontData.resize(fileSize);

				std::size_t bytesRead = 0;
				while (bytesRead < fileSize) {
					ttfFile.read(reinterpret_cast<char*>(fontData.data() + bytesRead), bufferSize);
					bytesRead += ttfFile.gcount();
				}

				// Print the font data as hex
				std::ofstream outFile("C:/FontConverter/" + font_name + ".txt");

				//clear txt file before writing in it (just in case to prevent override)
				outFile.clear();

				outFile << "inline constexpr std::uint8_t " << font_name << "[" << fileSize << "] = { ";

				for (std::size_t i = 0; i < fileSize; ++i) {
					outFile << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(1) << static_cast<int>(fontData[i]) << ", ";
				}

				outFile << " };";

				outFile.close();
				ttfFile.close();

				MessageBox::Show("Font converted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (const std::exception& ex) {
				MessageBox::Show("Error: " + gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// Open FontConverter folder	
			system("start C:/FontConverter");
		}
	};
}