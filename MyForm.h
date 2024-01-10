#pragma once
#include <Windows.h>
#pragma comment(lib, "Shell32.lib")    
#include <shellapi.h>
#include <msclr/marshal_cppstd.h>
#include <CommCtrl.h>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;

namespace Font_To_Uint_8t {

	using namespace System;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace msclr::interop;


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
	private: System::Windows::Forms::Label^ titleLabel;
	protected:

	private: System::Windows::Forms::Label^ pathLabel;
	protected:


	private: System::Windows::Forms::Button^ convertButton;
	private: System::Windows::Forms::Button^ chooseFileButton;
	private: System::Windows::Forms::TextBox^ pathTextBox;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->pathLabel = (gcnew System::Windows::Forms::Label());
			this->convertButton = (gcnew System::Windows::Forms::Button());
			this->chooseFileButton = (gcnew System::Windows::Forms::Button());
			this->pathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->BackColor = System::Drawing::Color::Transparent;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->ForeColor = System::Drawing::Color::White;
			this->titleLabel->Location = System::Drawing::Point(49, 9);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(477, 29);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Font TTF / OTF To Unsigned Char (uint8_t)";
			// 
			// pathLabel
			// 
			this->pathLabel->AutoSize = true;
			this->pathLabel->BackColor = System::Drawing::Color::Transparent;
			this->pathLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pathLabel->ForeColor = System::Drawing::Color::White;
			this->pathLabel->Location = System::Drawing::Point(12, 61);
			this->pathLabel->Name = L"pathLabel";
			this->pathLabel->Size = System::Drawing::Size(186, 29);
			this->pathLabel->TabIndex = 2;
			this->pathLabel->Text = L"Font To Convert";
			// 
			// convertButton
			// 
			this->convertButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->convertButton->Location = System::Drawing::Point(443, 79);
			this->convertButton->Name = L"convertButton";
			this->convertButton->Size = System::Drawing::Size(125, 46);
			this->convertButton->TabIndex = 3;
			this->convertButton->Text = L"Convert";
			this->convertButton->UseVisualStyleBackColor = true;
			this->convertButton->Click += gcnew System::EventHandler(this, &MyForm::convertButton_Click);
			// 
			// chooseFileButton
			// 
			this->chooseFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chooseFileButton->Location = System::Drawing::Point(312, 79);
			this->chooseFileButton->Name = L"chooseFileButton";
			this->chooseFileButton->Size = System::Drawing::Size(125, 46);
			this->chooseFileButton->TabIndex = 6;
			this->chooseFileButton->Text = L"Choose File";
			this->chooseFileButton->UseVisualStyleBackColor = true;
			this->chooseFileButton->Click += gcnew System::EventHandler(this, &MyForm::chooseFileButton_Click);
			// 
			// pathTextBox
			// 
			this->pathTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pathTextBox->Location = System::Drawing::Point(17, 102);
			this->pathTextBox->MaxLength = 1000;
			this->pathTextBox->Name = L"pathTextBox";
			this->pathTextBox->ReadOnly = true;
			this->pathTextBox->Size = System::Drawing::Size(240, 23);
			this->pathTextBox->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(580, 137);
			this->Controls->Add(this->pathTextBox);
			this->Controls->Add(this->chooseFileButton);
			this->Controls->Add(this->convertButton);
			this->Controls->Add(this->pathLabel);
			this->Controls->Add(this->titleLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Font Converter";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void convertButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			const auto path = fs::path(marshal_as<std::string>(pathTextBox->Text));
			const auto fileName = path.filename().string();
			if (!fs::exists(path) || (!fileName.ends_with(".ttf") && !fileName.ends_with(".otf")))
			{
				MessageBox::Show("Please select a valid font file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Open the TTF file
			std::ifstream ttfFile(path, std::ios::binary);

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
				constexpr std::size_t bufferSize = 100000;
				ttfFile.read(reinterpret_cast<char*>(fontData.data() + bytesRead), bufferSize);
				bytesRead += ttfFile.gcount();
			}

			// create output folder if its not existing
			if (!fs::exists(fs::current_path() / "output"))
				fs::create_directory(fs::current_path() / "output");

			// output stream
			const auto resultPath = fs::current_path() / "output" / path.filename().replace_extension(".cpp");
			std::ofstream outFile(resultPath);

			//clear txt file before writing in it (just in case to override)
			outFile.clear();

			// Print the font data as hex
			outFile << "inline constexpr std::uint8_t " << path.filename().replace_extension().string() << "[" << fileSize << "] = { ";
			for (std::size_t i = 0; i < fileSize; ++i) {
				outFile << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(1) << static_cast<int>(fontData[i]);
				if (i + 1 < fileSize)
				{
					outFile << ", ";
				}
			}
			outFile << " };";

			outFile.close();
			ttfFile.close();

			MessageBox::Show(marshal_as<String^>(std::string("Font converted successfully\nThe file has been saved in: ") + resultPath.string()), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			ShellExecuteW(nullptr, L"open", L"explorer.exe", (std::wstring(L"/select,") + resultPath.wstring()).c_str(), nullptr, SW_SHOW);
		}
		catch (const std::exception& ex) {
			MessageBox::Show("Error: " + gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void chooseFileButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

		openFileDialog->Filter = "All Files|*|Font Files (*.ttf, *.otf)|*.ttf;*.otf";
		openFileDialog->FilterIndex = 2;
		openFileDialog->RestoreDirectory = true;

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			pathTextBox->Text = openFileDialog->FileName;
		}
	}
	};
}