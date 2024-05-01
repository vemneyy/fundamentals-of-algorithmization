#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		int z;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			z = 1;
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
	private: System::Windows::Forms::TabPage^ tabCycle;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonCalculate;

	private: System::Windows::Forms::TextBox^ txtY;
	private: System::Windows::Forms::TextBox^ txtX;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioCos;
	private: System::Windows::Forms::RadioButton^ radioSqr;


	private: System::Windows::Forms::RadioButton^ radioSin;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

















	protected:




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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabLinear = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonCalculate = (gcnew System::Windows::Forms::Button());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabFork = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioSqr = (gcnew System::Windows::Forms::RadioButton());
			this->radioSin = (gcnew System::Windows::Forms::RadioButton());
			this->radioCos = (gcnew System::Windows::Forms::RadioButton());
			this->tabCycle = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabLinear->SuspendLayout();
			this->tabFork->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabLinear);
			this->tabControl1->Controls->Add(this->tabFork);
			this->tabControl1->Controls->Add(this->tabCycle);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1051, 639);
			this->tabControl1->TabIndex = 0;
			// 
			// tabLinear
			// 
			this->tabLinear->Controls->Add(this->label3);
			this->tabLinear->Controls->Add(this->buttonCalculate);
			this->tabLinear->Controls->Add(this->txtY);
			this->tabLinear->Controls->Add(this->txtX);
			this->tabLinear->Controls->Add(this->label2);
			this->tabLinear->Controls->Add(this->label1);
			this->tabLinear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabLinear->Location = System::Drawing::Point(4, 33);
			this->tabLinear->Name = L"tabLinear";
			this->tabLinear->Padding = System::Windows::Forms::Padding(3);
			this->tabLinear->Size = System::Drawing::Size(1043, 602);
			this->tabLinear->TabIndex = 0;
			this->tabLinear->Text = L"Линейные вычисления";
			this->tabLinear->UseVisualStyleBackColor = true;
			this->tabLinear->Click += gcnew System::EventHandler(this, &Form1::tabLinear_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(566, 45);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Вычислить значение выражения:";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// buttonCalculate
			// 
			this->buttonCalculate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalculate->Location = System::Drawing::Point(659, 424);
			this->buttonCalculate->Name = L"buttonCalculate";
			this->buttonCalculate->Size = System::Drawing::Size(289, 64);
			this->buttonCalculate->TabIndex = 4;
			this->buttonCalculate->Text = L"Вычислить";
			this->buttonCalculate->UseVisualStyleBackColor = true;
			this->buttonCalculate->Click += gcnew System::EventHandler(this, &Form1::buttonСalculate_Click);
			// 
			// txtY
			// 
			this->txtY->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtY->Location = System::Drawing::Point(88, 483);
			this->txtY->Name = L"txtY";
			this->txtY->Size = System::Drawing::Size(486, 51);
			this->txtY->TabIndex = 3;
			// 
			// txtX
			// 
			this->txtX->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtX->Location = System::Drawing::Point(88, 362);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(486, 51);
			this->txtX->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 489);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 45);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Y =";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 368);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X =";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// tabFork
			// 
			this->tabFork->Controls->Add(this->button1);
			this->tabFork->Controls->Add(this->textBox2);
			this->tabFork->Controls->Add(this->textBox1);
			this->tabFork->Controls->Add(this->label5);
			this->tabFork->Controls->Add(this->label4);
			this->tabFork->Controls->Add(this->groupBox1);
			this->tabFork->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabFork->Location = System::Drawing::Point(4, 33);
			this->tabFork->Name = L"tabFork";
			this->tabFork->Padding = System::Windows::Forms::Padding(3);
			this->tabFork->Size = System::Drawing::Size(1043, 602);
			this->tabFork->TabIndex = 1;
			this->tabFork->Text = L"Ветвления";
			this->tabFork->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(696, 512);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(236, 67);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(630, 439);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(404, 45);
			this->textBox2->TabIndex = 6;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(630, 353);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(404, 45);
			this->textBox1->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(539, 439);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 45);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Y =";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(537, 353);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 45);
			this->label4->TabIndex = 3;
			this->label4->Text = L"X =";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioSqr);
			this->groupBox1->Controls->Add(this->radioSin);
			this->groupBox1->Controls->Add(this->radioCos);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(8, 334);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(509, 261);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Группа переключателей";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// radioSqr
			// 
			this->radioSqr->AutoSize = true;
			this->radioSqr->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioSqr->Location = System::Drawing::Point(18, 187);
			this->radioSqr->Name = L"radioSqr";
			this->radioSqr->Size = System::Drawing::Size(216, 49);
			this->radioSqr->TabIndex = 2;
			this->radioSqr->TabStop = true;
			this->radioSqr->Text = L"F(x) = sqr(x)";
			this->radioSqr->UseVisualStyleBackColor = true;
			this->radioSqr->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioSqr_CheckedChanged);
			// 
			// radioSin
			// 
			this->radioSin->AutoSize = true;
			this->radioSin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioSin->Location = System::Drawing::Point(18, 132);
			this->radioSin->Name = L"radioSin";
			this->radioSin->Size = System::Drawing::Size(213, 49);
			this->radioSin->TabIndex = 1;
			this->radioSin->TabStop = true;
			this->radioSin->Text = L"F(x) = sin(x)";
			this->radioSin->UseVisualStyleBackColor = true;
			this->radioSin->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioSin_CheckedChanged);
			// 
			// radioCos
			// 
			this->radioCos->AutoSize = true;
			this->radioCos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioCos->Location = System::Drawing::Point(18, 77);
			this->radioCos->Name = L"radioCos";
			this->radioCos->Size = System::Drawing::Size(220, 49);
			this->radioCos->TabIndex = 0;
			this->radioCos->TabStop = true;
			this->radioCos->Text = L"F(x) = cos(x)";
			this->radioCos->UseVisualStyleBackColor = true;
			this->radioCos->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioCos_CheckedChanged);
			// 
			// tabCycle
			// 
			this->tabCycle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabCycle->Location = System::Drawing::Point(4, 33);
			this->tabCycle->Name = L"tabCycle";
			this->tabCycle->Padding = System::Windows::Forms::Padding(3);
			this->tabCycle->Size = System::Drawing::Size(1043, 602);
			this->tabCycle->TabIndex = 2;
			this->tabCycle->Text = L"Циклы";
			this->tabCycle->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1050, 640);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Лабораторная №13";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabLinear->ResumeLayout(false);
			this->tabLinear->PerformLayout();
			this->tabFork->ResumeLayout(false);
			this->tabFork->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonСalculate_Click(System::Object^ sender, System::EventArgs^ e) {
		double  x, y;
		x = System::Convert::ToDouble(txtX->Text);
		y = (1 - System::Math::Cos(2 * x) + System::Math::Sin(2 * x)) / (1 + System::Math::Cos(2 * x) + System::Math::Sin(2 * x));
		txtY->Text = y.ToString();
	}


	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tabLinear_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private:
		System::Void radioSin_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			if (radioSin->Checked) {
				z = 2;
			}
		}

	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private:
		System::Void radioSqr_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			if (radioSqr->Checked) {
				z = 3;
			}
		}

	private:
		System::Void radioCos_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			if (radioCos->Checked) {
				z = 1;
			}
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double x, y, fx;
		x = System::Convert::ToDouble(textBox1->Text);

		switch (z) {
		case 1: fx = System::Math::Cos(x); break;
		case 2: fx = System::Math::Sin(x); break;
		case 3: fx = x * x; break;
		default: fx = 1;
		}
		if (x >= -1 && x <= 1) y = fx * fx + 9;
		else y = 1 / (x * x * x + 1);
		textBox2->Text = y.ToString();

	}
	};
}
