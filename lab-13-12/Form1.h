#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabLinear;
	private: System::Windows::Forms::TabPage^ tabFork;
	protected:


	private: System::Windows::Forms::TabPage^ tabCycle;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtX;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtY;
	private: System::Windows::Forms::Button^ buttonCalculate;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabLinear = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabFork = (gcnew System::Windows::Forms::TabPage());
			this->tabCycle = (gcnew System::Windows::Forms::TabPage());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->buttonCalculate = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabLinear->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabLinear);
			this->tabControl1->Controls->Add(this->tabFork);
			this->tabControl1->Controls->Add(this->tabCycle);
			this->tabControl1->Location = System::Drawing::Point(13, 26);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(869, 580);
			this->tabControl1->TabIndex = 0;
			// 
			// tabLinear
			// 
			this->tabLinear->Controls->Add(this->buttonCalculate);
			this->tabLinear->Controls->Add(this->txtY);
			this->tabLinear->Controls->Add(this->txtX);
			this->tabLinear->Controls->Add(this->label2);
			this->tabLinear->Controls->Add(this->label1);
			this->tabLinear->Controls->Add(this->textBox1);
			this->tabLinear->Controls->Add(this->pictureBox1);
			this->tabLinear->Location = System::Drawing::Point(4, 33);
			this->tabLinear->Name = L"tabLinear";
			this->tabLinear->Padding = System::Windows::Forms::Padding(3);
			this->tabLinear->Size = System::Drawing::Size(861, 543);
			this->tabLinear->TabIndex = 0;
			this->tabLinear->Text = L"Линейные вычисления";
			this->tabLinear->UseVisualStyleBackColor = true;
			this->tabLinear->Click += gcnew System::EventHandler(this, &Form1::tabLinear_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(23, 88);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(766, 246);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// tabFork
			// 
			this->tabFork->Location = System::Drawing::Point(4, 33);
			this->tabFork->Name = L"tabFork";
			this->tabFork->Padding = System::Windows::Forms::Padding(3);
			this->tabFork->Size = System::Drawing::Size(1282, 862);
			this->tabFork->TabIndex = 1;
			this->tabFork->Text = L"Ветвления";
			this->tabFork->UseVisualStyleBackColor = true;
			// 
			// tabCycle
			// 
			this->tabCycle->Location = System::Drawing::Point(4, 33);
			this->tabCycle->Name = L"tabCycle";
			this->tabCycle->Padding = System::Windows::Forms::Padding(3);
			this->tabCycle->Size = System::Drawing::Size(1282, 862);
			this->tabCycle->TabIndex = 2;
			this->tabCycle->Text = L"Циклы";
			this->tabCycle->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(23, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(517, 44);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Вычислить значение выражения:";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 379);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 38);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X =";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(16, 461);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 38);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Y =";
			// 
			// txtX
			// 
			this->txtX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtX->Location = System::Drawing::Point(122, 379);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(165, 44);
			this->txtX->TabIndex = 5;
			this->txtX->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// txtY
			// 
			this->txtY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtY->Location = System::Drawing::Point(122, 461);
			this->txtY->Name = L"txtY";
			this->txtY->Size = System::Drawing::Size(165, 44);
			this->txtY->TabIndex = 6;
			// 
			// buttonCalculate
			// 
			this->buttonCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalculate->Location = System::Drawing::Point(448, 408);
			this->buttonCalculate->Name = L"buttonCalculate";
			this->buttonCalculate->Size = System::Drawing::Size(231, 54);
			this->buttonCalculate->TabIndex = 7;
			this->buttonCalculate->Text = L"Вычислить";
			this->buttonCalculate->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(922, 641);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->tabControl1->ResumeLayout(false);
			this->tabLinear->ResumeLayout(false);
			this->tabLinear->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabLinear_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void buttonСalculate_Click(System::Object^ sender, System::EventArgs^ e) {
	double  x, y;
	x = System::Convert::ToDouble(txtX->Text);
	y = (1 - System::Math::Cos(2 * x) + System::Math::Sin(2 * x)) / (1 + System::Math::Cos(2 * x) + System::Math::Sin(2 * x));
	txtY->Text = y.ToString();
}

private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};



}
