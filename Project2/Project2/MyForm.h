#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <msclr\marshal_cppstd.h>
using namespace std;
struct main_factory {
	string factory_name; //имя завода
	string ceo; //имя гендиректора
	int year; //год основания
	int product_nums; // количество товаров
};
struct product {
	float cost; //цена
	int relevancy; //затраты на производство
	int year; //год производства
	std::string product_name; //название продукта
	main_factory* factory; //завод
};

void equalation(product& a, product& b) {
	a.cost = b.cost;
	a.factory = b.factory;
	a.product_name = b.product_name;
	a.relevancy = b.relevancy;
	a.year = b.year;
}
int most_valuable(product a[], int len, int max) {
	int maxj = 0;
	for (int i = 0; i < len; i++) {
		if (a[i].cost - a[i].relevancy > max) {
			maxj = i;
		}
	}
	return maxj;
}
float product_medium(product a[], int len) {
	float med = 0;
	for (int i = 0; i < len; i++) {
		med += a[i].cost;
	}
	med = med / len;
	return med;
}
void product_count(int poly_len, int ufa_len) {
	cout << "Количество товаров на Полиэф: " << poly_len;
	cout << "\nКоличество товаров на Уфаоргсинтез: " << ufa_len;
}
void change_product(product a[], int len, string inf) {
	string tmps; int tmp;
	for (int i = 0; i < len; i++) {
		if (a[i].product_name == inf) {
			cout << "Изменить имя\n";
			cin >> tmps; a[i].product_name = tmps;
			cout << "Изменить цену\n";
			cin >> tmp; a[i].cost = tmp;
			cout << "Изменить гарантию\n";
			cin >> tmp; a[i].year = tmp;
			cout << "Изменить затраты на производство\n";
			cin >> tmp; a[i].relevancy = tmp;

		}
	}

}
product* mass_add(product a[], int& len) {
	product* arr = new product[len + 1];
	for (int i = 0; i < len; i++) {
		equalation(arr[i], a[i]);
	}
	len += 1;
	delete[] a;
	return arr;
}

void product_sort(product a[], int len) {
	product tmp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (a[j].cost > a[j + 1].cost) {
				equalation(tmp, a[j]);
				equalation(a[j], a[j + 1]);
				equalation(a[j + 1], tmp);
			}
		}
	}
	cout << "Сортировка завершена\n\n";
}
void finput1(product * &a, product *&b, int& len_poly, int& len_ufa) {
	string s;
	int l1; int l2; 
	ifstream f("C:\\Users\\Artyom\\source\\repos\\Project2\\input.txt");
	f >> l1; f >> l2;
	while (len_poly < l1) { a = mass_add(a, len_poly); }
	while (len_ufa < l2) b = mass_add(b, len_ufa);
	for (int i = 0; i < len_poly; i++) {
		f >> a[i].product_name;
		f >> a[i].cost;
		f >> a[i].year;
		f >> a[i].relevancy;
		
	}
	for (int i = 0; i < len_ufa; i++) {
		f >> b[i].product_name;
		f >> b[i].cost;
		f >> b[i].year;
		f >> b[i].relevancy;
	}
	f.close();
}

void product_delete(product a[], int& len, string inf, int& check) {
	if (len == 0) return;
	for (int i = 0; i < len; i++) {
		if (a[i].product_name == inf) {
			for (int j = i; j < len - 1; j++) {
				a[j] = a[j + 1];
			}
			len--;
			return;
		}
		check += 1;
	}
}



namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int len_poly = 1; int len_ufa = 1;
	product* ufa_mass = new product[len_ufa];
	product* poly_mass = new product[len_poly];
	
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::ListBox^ listBox5;
	private: System::Windows::Forms::ListBox^ listBox6;
	private: System::Windows::Forms::ListBox^ listBox7;
	private: System::Windows::Forms::ListBox^ listBox8;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;


	private: System::Windows::Forms::ListBox^ listBox9;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;







	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->listBox9 = (gcnew System::Windows::Forms::ListBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(0, 81);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(99, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отсортировать по цене";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 33);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 38);
			this->button2->TabIndex = 1;
			this->button2->Text = L"ввод из файла";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Полиэф";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(49, 47);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(66, 173);
			this->listBox1->TabIndex = 4;
			this->listBox1->Click += gcnew System::EventHandler(this, &MyForm::listBox1_Click);
			this->listBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::listBox1_MouseClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(513, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Уфаоргсинтез";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(121, 47);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(61, 173);
			this->listBox2->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(0, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(103, 38);
			this->button3->TabIndex = 7;
			this->button3->Text = L"ввод с клавиатуры";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(188, 47);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(66, 173);
			this->listBox3->TabIndex = 10;
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Location = System::Drawing::Point(260, 47);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(66, 173);
			this->listBox4->TabIndex = 11;
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->Location = System::Drawing::Point(516, 47);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(66, 173);
			this->listBox5->TabIndex = 12;
			this->listBox5->Click += gcnew System::EventHandler(this, &MyForm::listBox5_Click);
			// 
			// listBox6
			// 
			this->listBox6->FormattingEnabled = true;
			this->listBox6->Location = System::Drawing::Point(588, 47);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(66, 173);
			this->listBox6->TabIndex = 13;
			// 
			// listBox7
			// 
			this->listBox7->FormattingEnabled = true;
			this->listBox7->Location = System::Drawing::Point(660, 47);
			this->listBox7->Name = L"listBox7";
			this->listBox7->Size = System::Drawing::Size(66, 173);
			this->listBox7->TabIndex = 14;
			// 
			// listBox8
			// 
			this->listBox8->FormattingEnabled = true;
			this->listBox8->Location = System::Drawing::Point(732, 47);
			this->listBox8->Name = L"listBox8";
			this->listBox8->Size = System::Drawing::Size(66, 173);
			this->listBox8->TabIndex = 15;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(260, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Расход";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(188, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Кол-во";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(121, 28);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Цена";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(49, 28);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Товар";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(513, 31);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Товар";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(585, 28);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Цена";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(729, 28);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Расход";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(657, 28);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(44, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Кол-во ";
			// 
			// listBox9
			// 
			this->listBox9->FormattingEnabled = true;
			this->listBox9->Location = System::Drawing::Point(445, 407);
			this->listBox9->Name = L"listBox9";
			this->listBox9->Size = System::Drawing::Size(149, 121);
			this->listBox9->TabIndex = 26;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(0, 167);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 28;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(106, 167);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 29;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(214, 167);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 30;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(317, 167);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 31;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(847, 221);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(99, 38);
			this->button5->TabIndex = 32;
			this->button5->Text = L"самый выгодный товар";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(699, 268);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(238, 37);
			this->textBox6->TabIndex = 33;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(699, 311);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(238, 43);
			this->textBox7->TabIndex = 34;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 76);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(127, 13);
			this->label11->TabIndex = 35;
			this->label11->Text = L"кол-во товаров Полиэф";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 115);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(158, 13);
			this->label12->TabIndex = 36;
			this->label12->Text = L"кол-во товаров уфаоргсинтез";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(6, 92);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 37;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(6, 131);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 38;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(6, 17);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(82, 56);
			this->button6->TabIndex = 39;
			this->button6->Text = L"обновить кол-во товаров";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(3, 42);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(88, 43);
			this->button7->TabIndex = 40;
			this->button7->Text = L"удалить товар";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(3, 16);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(271, 20);
			this->textBox10->TabIndex = 41;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(696, 246);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(136, 13);
			this->label13->TabIndex = 42;
			this->label13->Text = L"Самые выгодные товары";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(0, 19);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(138, 33);
			this->button8->TabIndex = 43;
			this->button8->Text = L"средняя цена товаров";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(0, 55);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 44;
			this->textBox11->Click += gcnew System::EventHandler(this, &MyForm::textBox11_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(109, 95);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(103, 38);
			this->button9->TabIndex = 45;
			this->button9->Text = L"ввод с клавиатуры";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(189, 42);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(86, 39);
			this->button10->TabIndex = 46;
			this->button10->Text = L"Изменить по имени";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(97, 42);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(86, 37);
			this->button11->TabIndex = 47;
			this->button11->Text = L"поиск товара по имени";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(218, 98);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(82, 35);
			this->button4->TabIndex = 48;
			this->button4->Text = L"прекратить ввод";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(3, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(158, 13);
			this->label14->TabIndex = 49;
			this->label14->Text = L"поле для ввода имени товара";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label14);
			this->flowLayoutPanel1->Controls->Add(this->textBox10);
			this->flowLayoutPanel1->Controls->Add(this->button7);
			this->flowLayoutPanel1->Controls->Add(this->button11);
			this->flowLayoutPanel1->Controls->Add(this->button10);
			this->flowLayoutPanel1->Location = System::Drawing::Point(641, 425);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(320, 114);
			this->flowLayoutPanel1->TabIndex = 50;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox9);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Location = System::Drawing::Point(332, 47);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(178, 201);
			this->groupBox1->TabIndex = 51;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(-2, 346);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(422, 193);
			this->groupBox2->TabIndex = 52;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"ввод данных";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button8);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Location = System::Drawing::Point(445, 254);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(189, 142);
			this->groupBox3->TabIndex = 53;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"работа с данным";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(958, 540);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->listBox9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox8);
			this->Controls->Add(this->listBox7);
			this->Controls->Add(this->listBox6);
			this->Controls->Add(this->listBox5);
			this->Controls->Add(this->listBox4);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		listBox1->Items->Clear();
		listBox2->Items->Clear();
		listBox3->Items->Clear();
		listBox4->Items->Clear();
		listBox5->Items->Clear();
		listBox6->Items->Clear();
		listBox7->Items->Clear();
		listBox8->Items->Clear();

		product_sort(poly_mass, len_poly);
		product_sort(ufa_mass, len_ufa);
		for (int i = 0; i < len_poly; i++) {
			listBox1->Items->Insert(i, gcnew System::String(poly_mass[i].product_name.c_str()));
			listBox2->Items->Insert(i, (poly_mass[i].cost.ToString()));
			listBox3->Items->Insert(i, (poly_mass[i].year.ToString()));
			listBox4->Items->Insert(i, (poly_mass[i].relevancy.ToString()));

		}
		for (int i = 0; i < len_ufa; i++) {
			listBox5->Items->Insert(i, gcnew System::String(ufa_mass[i].product_name.c_str()));
			listBox6->Items->Insert(i, (ufa_mass[i].cost.ToString()));
			listBox7->Items->Insert(i, (ufa_mass[i].year.ToString()));
			listBox8->Items->Insert(i, (ufa_mass[i].relevancy.ToString()));
		}
	}
	int flag = 0;
	public: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		flag = 1;
		listBox1->Items->Clear();
		listBox2->Items->Clear();
		listBox3->Items->Clear();
		listBox4->Items->Clear();
		listBox5->Items->Clear();
		listBox6->Items->Clear();
		listBox7->Items->Clear();
		listBox8->Items->Clear();
		finput1(poly_mass, ufa_mass, len_poly, len_ufa);
		for (int i = 0; i < len_poly; i++) {
			listBox1->Items->Insert(i, gcnew System::String(poly_mass[i].product_name.c_str()));
			listBox2->Items->Insert(i, (poly_mass[i].cost.ToString()));
			listBox3->Items->Insert(i, (poly_mass[i].year.ToString()));
			listBox4->Items->Insert(i, (poly_mass[i].relevancy.ToString()));
			
		}
		for (int i = 0; i < len_ufa; i++) {
			listBox5->Items->Insert(i, gcnew System::String(ufa_mass[i].product_name.c_str()));
			listBox6->Items->Insert(i, (ufa_mass[i].cost.ToString()));
			listBox7->Items->Insert(i, (ufa_mass[i].year.ToString()));
			listBox8->Items->Insert(i, (ufa_mass[i].relevancy.ToString()));
		}
		
		
		
	}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
}	
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
	main_factory poly; poly.ceo = "Григорий"; poly.factory_name = "Полиэф"; poly.year = 1965; poly_mass[0].factory = &poly;
	main_factory ufa; ufa.ceo = "Игорь"; ufa.factory_name = "УфаОргСинтез"; ufa.year = 1970; ufa_mass[0].factory = &ufa;
	
	listBox9->Items->Add(gcnew System::String(ufa_mass->factory->factory_name.c_str()));
	listBox9->Items->Add(gcnew System::String(ufa_mass->factory->ceo.c_str()));
	listBox9->Items->Add((ufa_mass->factory->year.ToString()));
}
private: System::Void listBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	listBox9->Items->Clear();
	main_factory poly; poly.ceo = "Григорий"; poly.factory_name = "Полиэф"; poly.year = 1965; poly_mass[0].factory = &poly;
	main_factory ufa; ufa.ceo = "Игорь"; ufa.factory_name = "УфаОргСинтез"; ufa.year = 1970; ufa_mass[0].factory = &ufa;
	listBox9->Items->Add(gcnew System::String(poly_mass->factory->factory_name.c_str()));
	listBox9->Items->Add(gcnew System::String(poly_mass->factory->ceo.c_str()));
	listBox9->Items->Add((poly_mass->factory->year.ToString()));
}
private: System::Void listBox5_Click(System::Object^ sender, System::EventArgs^ e) {
	listBox9->Items->Clear();
	main_factory poly; poly.ceo = "Григорий"; poly.factory_name = "Полиэф"; poly.year = 1965; poly_mass[0].factory = &poly;
	main_factory ufa; ufa.ceo = "Игорь"; ufa.factory_name = "УфаОргСинтез"; ufa.year = 1970; ufa_mass[0].factory = &ufa;
	listBox9->Items->Add(gcnew System::String(ufa_mass->factory->factory_name.c_str()));
	listBox9->Items->Add(gcnew System::String(ufa_mass->factory->ceo.c_str()));
	listBox9->Items->Add((ufa_mass->factory->year.ToString()));
}
	   msclr::interop::marshal_context context;
	   int counter1 = 1;
	   int flag1 = 0;
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		
	//whi
	
	if (flag == 1) {
		listBox1->Items->Clear();
		listBox2->Items->Clear();
		listBox3->Items->Clear();
		listBox4->Items->Clear();
		
		
		flag = 0;
		len_poly = 1;
		flag1 = 1;
	}
	if (counter1 >= len_poly) {
		poly_mass = mass_add(poly_mass, len_poly);
	}
	
	if (context.marshal_as<std::string>(textBox2->Text) == "stop") { len_poly--; return; }
		poly_mass[counter1-1].product_name = context.marshal_as<std::string>(textBox2->Text);
		
		poly_mass[counter1-1].cost = (float)(Convert::ToDouble(textBox3->Text));
		poly_mass[counter1-1].year = (float)(Convert::ToDouble(textBox4->Text));
		poly_mass[counter1-1].relevancy = (float)(Convert::ToDouble(textBox5->Text));

	
	
		listBox1->Items->Insert(counter1-1, gcnew System::String(poly_mass[counter1-1].product_name.c_str()));
		listBox2->Items->Insert(counter1-1, (poly_mass[counter1-1].cost.ToString()));
		listBox3->Items->Insert(counter1-1, (poly_mass[counter1-1].year.ToString()));
		listBox4->Items->Insert(counter1-1, (poly_mass[counter1-1].relevancy.ToString()));
		counter1++;
		
		if (context.marshal_as<std::string>(textBox2->Text) == "stop") --len_poly;
	
}	
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	int m = most_valuable(poly_mass, len_poly, poly_mass[0].cost);
	textBox6->Text = "Самый выгодный товар Полиэф: "; textBox6->AppendText(gcnew System::String(poly_mass[m].product_name.c_str()));
	textBox6->AppendText(" Прибыль: "); textBox6->AppendText((poly_mass[m].cost - poly_mass[m].relevancy).ToString());
	int mn = most_valuable(ufa_mass,len_ufa, ufa_mass[0].cost);
	textBox7->Text = "Самый выгодный товар УфаОргсинтез: "; textBox7->AppendText(gcnew System::String(ufa_mass[mn].product_name.c_str()));
	textBox7->AppendText(" Прибыль: "); textBox7->AppendText((ufa_mass[mn].cost - ufa_mass[mn].relevancy).ToString());
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	int counter = 0;
	for (int i = 0; i < len_poly; i++) {
		counter += poly_mass[i].year;
	}
	textBox8->Text = counter.ToString();
	counter - 0;
	for (int i = 0; i < len_ufa; i++) {
		counter += ufa_mass[i].year;
	}
	textBox9->Text = counter.ToString();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	
	for (int i = 0; i < len_poly; i++) {
		if (poly_mass[i].product_name == context.marshal_as<std::string>(textBox10->Text)) {
			listBox1->Items->Clear();
			listBox2->Items->Clear();
			listBox3->Items->Clear();
			listBox4->Items->Clear();
			for (int j = i; j < len_poly - 1; j++) {
				equalation(poly_mass[j], poly_mass[j+1]);
			}
			len_poly--;
			for (int i = 0; i < len_poly; i++) {
				listBox1->Items->Insert(i, gcnew System::String(poly_mass[i].product_name.c_str()));
				listBox2->Items->Insert(i, (poly_mass[i].cost.ToString()));
				listBox3->Items->Insert(i, (poly_mass[i].year.ToString()));
				listBox4->Items->Insert(i, (poly_mass[i].relevancy.ToString()));

			}
		}
	}
	
	
	for (int i = 0; i < len_ufa; i++) {
		if (ufa_mass[i].product_name == context.marshal_as<std::string>(textBox10->Text)) {
			listBox5->Items->Clear();
			listBox6->Items->Clear();
			listBox7->Items->Clear();
			listBox8->Items->Clear();
			for (int j = i; j < len_ufa - 1; j++) {
				equalation(ufa_mass[j], ufa_mass[j + 1]);
			}
			len_ufa--;
			for (int i = 0; i < len_ufa; i++) {
				listBox5->Items->Insert(i, gcnew System::String(ufa_mass[i].product_name.c_str()));
				listBox6->Items->Insert(i, (ufa_mass[i].cost.ToString()));
				listBox7->Items->Insert(i, (ufa_mass[i].year.ToString()));
				listBox8->Items->Insert(i, (ufa_mass[i].relevancy.ToString()));
			}
		}
		
	}
	
	
}
private: System::Void textBox11_Click(System::Object^ sender, System::EventArgs^ e) {
	float mid1 = product_medium(poly_mass, len_poly);
	float mid2 = product_medium(ufa_mass, len_ufa);
	textBox11->Text = ((mid1+mid2)/2).ToString();
}
	   int counter2 = 1;
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (flag1 == 1) {
		
		listBox5->Items->Clear();
		listBox6->Items->Clear();
		listBox7->Items->Clear();
		listBox8->Items->Clear();
		;
		flag1 = 0;
		len_ufa = 1;
		
		
		
	}
	if (counter2 >= len_ufa) {
		ufa_mass = mass_add(ufa_mass, len_ufa);
	}
	if (context.marshal_as<std::string>(textBox2->Text) == "stop") { len_ufa--; return; }
	ufa_mass[counter2 - 1].product_name = context.marshal_as<std::string>(textBox2->Text);

	ufa_mass[counter2 - 1].cost = (float)(Convert::ToDouble(textBox3->Text));
	ufa_mass[counter2 - 1].year = (float)(Convert::ToDouble(textBox4->Text));
	ufa_mass[counter2 - 1].relevancy = (float)(Convert::ToDouble(textBox5->Text));



	listBox5->Items->Insert(counter2 - 1, gcnew System::String(ufa_mass[counter2 - 1].product_name.c_str()));
	listBox6->Items->Insert(counter2 - 1, (ufa_mass[counter2 - 1].cost.ToString()));
	listBox7->Items->Insert(counter2 - 1, (ufa_mass[counter2 - 1].year.ToString()));
	listBox8->Items->Insert(counter2 - 1, (ufa_mass[counter2 - 1].relevancy.ToString()));
	counter2++;
	 
	
	if (context.marshal_as<std::string>(textBox2->Text) == "stop") --len_ufa;
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < len_poly; i++) {
		if (poly_mass[i].product_name == context.marshal_as<std::string>(textBox10->Text)) {
			poly_mass[i].product_name = context.marshal_as<std::string>(textBox2->Text);
			poly_mass[i].cost = (float)(Convert::ToDouble(textBox3->Text));
			poly_mass[i].year = (float)(Convert::ToDouble(textBox4->Text));
			poly_mass[i].relevancy = (float)(Convert::ToDouble(textBox5->Text));
			listBox1->Items->Clear();
			listBox2->Items->Clear();
			listBox3->Items->Clear();
			listBox4->Items->Clear();
			
			for (int i = 0; i < len_poly; i++) {
				listBox1->Items->Insert(i, gcnew System::String(poly_mass[i].product_name.c_str()));
				listBox2->Items->Insert(i, (poly_mass[i].cost.ToString()));
				listBox3->Items->Insert(i, (poly_mass[i].year.ToString()));
				listBox4->Items->Insert(i, (poly_mass[i].relevancy.ToString()));

			}
		}
	}
	for (int i = 0; i < len_ufa; i++) {
		if (ufa_mass[i].product_name == context.marshal_as<std::string>(textBox10->Text)) {
			ufa_mass[i].product_name = context.marshal_as<std::string>(textBox2->Text);
			ufa_mass[i].cost = (float)(Convert::ToDouble(textBox3->Text));
			ufa_mass[i].year = (float)(Convert::ToDouble(textBox4->Text));
			ufa_mass[i].relevancy = (float)(Convert::ToDouble(textBox5->Text));
			
			listBox5->Items->Clear();
			listBox6->Items->Clear();
			listBox7->Items->Clear();
			listBox8->Items->Clear();
			
			for (int i = 0; i < len_ufa; i++) {
				listBox5->Items->Insert(i, gcnew System::String(ufa_mass[i].product_name.c_str()));
				listBox6->Items->Insert(i, (ufa_mass[i].cost.ToString()));
				listBox7->Items->Insert(i, (ufa_mass[i].year.ToString()));
				listBox8->Items->Insert(i, (ufa_mass[i].relevancy.ToString()));
			}
		}

	}
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < len_poly; i++) {
		if (poly_mass[i].product_name == context.marshal_as<std::string>(textBox10->Text)) {
			listBox9->Items->Clear();
			
				listBox9->Items->Add( gcnew System::String(poly_mass[i].product_name.c_str()));
				listBox9->Items->Add(poly_mass[i].cost.ToString());
				listBox9->Items->Add(poly_mass[i].year.ToString());
				listBox9->Items->Add(poly_mass[i].relevancy.ToString());
				return;

			
		}
	}


	for (int i = 0; i < len_ufa; i++) {
		if (ufa_mass[i].product_name == context.marshal_as<std::string>(textBox10->Text)) {
			listBox9->Items->Clear();
			
				listBox9->Items->Add(gcnew System::String(ufa_mass[i].product_name.c_str()));
				listBox9->Items->Add(ufa_mass[i].cost.ToString());
				listBox9->Items->Add(ufa_mass[i].year.ToString());
				listBox9->Items->Add(ufa_mass[i].relevancy.ToString());
				return;

			
		}
	}
	listBox9->Items->Clear();
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	len_poly--;
	len_ufa--;
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
