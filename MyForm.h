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
#include <Winhttp.h>
#include <iostream>
#include <winerror.h>
#include <Shlobj.h>
#pragma comment(lib, "winhttp.lib")

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


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ OutputInfo;
	private: System::Windows::Forms::Label^ ErrorInfo;
	private: System::Windows::Forms::Label^ label1;



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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->OutputInfo = (gcnew System::Windows::Forms::Label());
			this->ErrorInfo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->BackColor = System::Drawing::Color::Transparent;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->ForeColor = System::Drawing::Color::White;
			this->titleLabel->Location = System::Drawing::Point(170, 9);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(223, 29);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"C++ Font Converter";
			// 
			// pathLabel
			// 
			this->pathLabel->AutoSize = true;
			this->pathLabel->BackColor = System::Drawing::Color::Transparent;
			this->pathLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pathLabel->ForeColor = System::Drawing::Color::White;
			this->pathLabel->Location = System::Drawing::Point(7, 114);
			this->pathLabel->Name = L"pathLabel";
			this->pathLabel->Size = System::Drawing::Size(186, 29);
			this->pathLabel->TabIndex = 2;
			this->pathLabel->Text = L"Font To Convert";
			// 
			// convertButton
			// 
			this->convertButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->convertButton->Location = System::Drawing::Point(231, 327);
			this->convertButton->Name = L"convertButton";
			this->convertButton->Size = System::Drawing::Size(115, 35);
			this->convertButton->TabIndex = 3;
			this->convertButton->Text = L"Convert";
			this->convertButton->UseVisualStyleBackColor = true;
			this->convertButton->Click += gcnew System::EventHandler(this, &MyForm::convertButton_Click);
			// 
			// chooseFileButton
			// 
			this->chooseFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chooseFileButton->Location = System::Drawing::Point(12, 190);
			this->chooseFileButton->Name = L"chooseFileButton";
			this->chooseFileButton->Size = System::Drawing::Size(115, 35);
			this->chooseFileButton->TabIndex = 6;
			this->chooseFileButton->Text = L"Choose File";
			this->chooseFileButton->UseVisualStyleBackColor = true;
			this->chooseFileButton->Click += gcnew System::EventHandler(this, &MyForm::chooseFileButton_Click);
			// 
			// pathTextBox
			// 
			this->pathTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pathTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pathTextBox->Location = System::Drawing::Point(12, 146);
			this->pathTextBox->MaxLength = 1000;
			this->pathTextBox->Multiline = true;
			this->pathTextBox->Name = L"pathTextBox";
			this->pathTextBox->ReadOnly = true;
			this->pathTextBox->Size = System::Drawing::Size(236, 38);
			this->pathTextBox->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(539, 9);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 25);
			this->button2->TabIndex = 9;
			this->button2->Text = L"X";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// OutputInfo
			// 
			this->OutputInfo->AutoSize = true;
			this->OutputInfo->BackColor = System::Drawing::Color::Transparent;
			this->OutputInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OutputInfo->ForeColor = System::Drawing::Color::White;
			this->OutputInfo->Location = System::Drawing::Point(254, 142);
			this->OutputInfo->Name = L"OutputInfo";
			this->OutputInfo->Size = System::Drawing::Size(203, 72);
			this->OutputInfo->TabIndex = 10;
			this->OutputInfo->Text = L"Font: {}\r\nConverted Font Size: {}\r\nConverted in: {} ms";
			this->OutputInfo->Visible = false;
			// 
			// ErrorInfo
			// 
			this->ErrorInfo->AutoSize = true;
			this->ErrorInfo->BackColor = System::Drawing::Color::Transparent;
			this->ErrorInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ErrorInfo->ForeColor = System::Drawing::Color::Red;
			this->ErrorInfo->Location = System::Drawing::Point(12, 229);
			this->ErrorInfo->Name = L"ErrorInfo";
			this->ErrorInfo->Size = System::Drawing::Size(87, 24);
			this->ErrorInfo->TabIndex = 11;
			this->ErrorInfo->Text = L"Error Info";
			this->ErrorInfo->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(481, 347);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 18);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Version: 1.1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(580, 374);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ErrorInfo);
			this->Controls->Add(this->OutputInfo);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pathTextBox);
			this->Controls->Add(this->chooseFileButton);
			this->Controls->Add(this->convertButton);
			this->Controls->Add(this->pathLabel);
			this->Controls->Add(this->titleLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Font Converter";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Void convertButton_Click(Object^ sender, System::EventArgs^ e)
		{
			try
			{
				// Validate input
                if (String::IsNullOrEmpty(pathTextBox->Text)) 
				{
                    ErrorInfo->Text = "Please select a font file first!";
                    return;
                }

                const auto path = fs::path(marshal_as<std::string>(pathTextBox->Text));
                const auto file_name = path.filename().string();
                
                if (!exists(path)) 
				{
                    ErrorInfo->Text = "File does not exist!";
                    return;
                }
                
                if (!(file_name.ends_with(".ttf") || file_name.ends_with(".otf")))
                {
                    ErrorInfo->Text = "Please select a valid font file (.ttf or .otf)!";
                    return;
                }

                // Read file data
                std::ifstream ttf_file(path, std::ios::binary | std::ios::ate);
                if (!ttf_file) 
				{
                    ErrorInfo->Text = "Error opening file!";
                    return;
                }

                const auto file_size = ttf_file.tellg();
                ttf_file.seekg(0, std::ios::beg);

                std::vector<uint8_t> font_data(file_size);
                if (!ttf_file.read(reinterpret_cast<char*>(font_data.data()), file_size)) 
				{
                    ErrorInfo->Text = "Error reading file!";
                    return;
                }

                // Create output directory if needed
                const auto output_dir = fs::current_path() / "output";
                if (!exists(output_dir)) 
				{
                    create_directory(output_dir);
                }

                // Prepare output file
                const auto result_path = output_dir / path.filename().replace_extension(".cpp");
                std::ofstream out_file(result_path);
                if (!out_file) 
				{
                    ErrorInfo->Text = "Error creating output file!";
                    return;
                }

                // Convert and time the operation
                auto start = std::chrono::high_resolution_clock::now();
                
                // Write header
                out_file << "inline constexpr std::uint8_t " << path.filename().replace_extension().string() << "[" << file_size << "] = { ";

                // Write data with buffering for better performance
                constexpr size_t buffer_size = 1024;
                std::string buffer;
                buffer.reserve(buffer_size * 10); // Reserve space for 10x buffer size

                for (size_t i = 0; i < font_data.size(); ++i) 
				{
                    char hex[5];
                    snprintf(hex, sizeof(hex), "0x%02X", font_data[i]);
                    buffer.append(hex);

                    if (i + 1 < font_data.size()) {
                        buffer.append(", ");
                    }

                    // Flush buffer when it's full
                    if (buffer.size() >= buffer_size) {
                        out_file << buffer;
                        buffer.clear();
                    }
                }

                // Write remaining data and footer
                out_file << buffer << " };";
                
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

                // Update UI with results
				OutputInfo->Text = String::Format("Font: {0}\nConverted Font Size: {1} bytes\nConverted in: {2} ms", gcnew String(file_name.c_str()), Convert::ToString(static_cast<int>(file_size)), Convert::ToString(static_cast<int>(duration)));

                OutputInfo->Visible = true;

                ErrorInfo->ForeColor = Color::Green;
                ErrorInfo->Text = String::Format("Font converted successfully!\nThe file has been saved in: \n{0}",
                    gcnew String(result_path.wstring().c_str()));
                ErrorInfo->Visible = true;

                // Show the result in explorer
                ShellExecuteW(nullptr, L"open", L"explorer.exe", 
                    (std::wstring(L"/select,") + result_path.wstring()).c_str(), 
                    nullptr, SW_SHOW);
			}
			catch (const std::exception& ex) 
			{
				MessageBox::Show("Error: " + gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		Void chooseFileButton_Click(Object^ sender, System::EventArgs^ e)
		{
			auto open_file_dialog = gcnew OpenFileDialog();

			open_file_dialog->Filter = "All Files|*|Font Files (*.ttf, *.otf)|*.ttf;*.otf";
			open_file_dialog->FilterIndex = 2;
			open_file_dialog->RestoreDirectory = true;

			if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				pathTextBox->Text = open_file_dialog->FileName;
			}

			if (ErrorInfo->Visible)
				ErrorInfo->Visible = false;

			if (OutputInfo->Visible)
				OutputInfo->Visible = false;
		}

		// Form components
        bool isDragging = false;
		Point lastCursorPosition;

		// Make the form draggable
		Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			isDragging = true;
            lastCursorPosition = e->Location;
		}

		Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			if (isDragging)
			{
                int deltaX = e->X - lastCursorPosition.X;
                int deltaY = e->Y - lastCursorPosition.Y;
				this->Location = Point(this->Location.X + deltaX, this->Location.Y + deltaY);
            }
		}

		Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			isDragging = false;
		}

		Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
		{
			auto top_border_panel = gcnew Panel();
			top_border_panel->Dock = DockStyle::Top;
			top_border_panel->Height = 1;
			top_border_panel->BackColor = Color::White;

			auto bottom_border_panel = gcnew Panel();
			bottom_border_panel->Dock = DockStyle::Bottom;
			bottom_border_panel->Height = 1;
			bottom_border_panel->BackColor = Color::White;

			auto left_border_panel = gcnew Panel();
			left_border_panel->Dock = DockStyle::Left;
			left_border_panel->Width = 1;
			left_border_panel->BackColor = Color::White;

			auto right_border_panel = gcnew Panel();
			right_border_panel->Dock = DockStyle::Right;
			right_border_panel->Width = 1;
			right_border_panel->BackColor = Color::White;

			Controls->Add(top_border_panel);
			Controls->Add(bottom_border_panel);
			Controls->Add(left_border_panel);
			Controls->Add(right_border_panel);

			// Setting Title Text to the top center
			titleLabel->Location = Point((ClientSize.Width - titleLabel->Width) / 2, titleLabel->Location.Y);

			// Setting Button2 to the top right
			button2->Location = Point(ClientSize.Width - button2->Width - 10, button2->Location.Y);

			// Setting ConvertButton to the buttom center
			convertButton->Location = Point((ClientSize.Width - convertButton->Width) / 2, ClientSize.Height - convertButton->Height - 10);
		}

		Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Application::Exit();
		}
	};
}
