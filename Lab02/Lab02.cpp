// Lab02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
using namespace std;

class Receipt {
private:
	int number;
	int date;
	float sum;

public:

	Receipt() : number(0), date(0), sum(0.0f) {
		cout << "��������� ����������� ��� ��������i�.\n";
	}


	Receipt(int n, int d, float s) : number(n), date(d), sum(s) {
		cout << "��������� ����������� � �����������.\n";
	}


	Receipt(const Receipt& other) {
		number = other.number;
		date = other.date;
		sum = other.sum;
		cout << "��������� ����������� ���i������.\n";
	}


	void inputNumber() {
		cout << "����i�� ����� �������i�: ";
		cin >> number;
	}


	void inputDate() {
		cout << "����i�� ���� (���������, � ������i YYYYMMDD): ";
		cin >> date;
	}


	void inputSum() {
		cout << "����i�� ���� �� ������: ";
		cin >> sum;
	}


	void printInfo() const {
		cout << "--------------------------\n";
		cout << "����� �������i�: " << number << "\n";
		cout << "���� �����i:     " << date << "\n";
		cout << "���� �� ������:  " << sum << "\n";
		cout << "--------------------------\n";
	}
};

class Item {
private:
	char* name;
	int count;
	float price;

public:

	Item() {
		name = NULL;
		count = 0;
		price = 0.0f;
	}

	Item(const char* n, int k, float v) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		count = k;
		price = v;
	}

	Item(const Item& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		count = other.count;
		price = other.price;
	}

	~Item() {
		if (name != NULL)
			delete[] name;
	}

	void setName() {
		char buffer[100];
		cout << "����i�� ����� ������: ";
		cin >> buffer;
		if (name != NULL)
			delete[] name;
		name = new char[strlen(buffer) + 1];
		strcpy(name, buffer);
	}


	void setCount(int k) {
		count = k;
	}

	void setPrice(float v) {
		price = v;
	}

	void printInfo() const {
		cout << "�����: " << name << endl;
		cout << "�i���i���: " << count << endl;
		cout << "����i���: " << price << " ���" << endl;
		cout << "------------------------" << endl;
	}
};

int main() {


	setlocale(LC_ALL, "");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#if 0
	Receipt receipt1;
	receipt1.inputNumber();
	receipt1.inputDate();
	receipt1.inputSum();
	receipt1.printInfo();


	Receipt receipt2(123, 20230324, 250.75f);
	receipt2.printInfo();


	Receipt receipt3(receipt2);
	receipt3.printInfo();
#else

	Item t1("��i�", 20, 15.5);
	t1.printInfo();

	Item t2;
	t2.setName();
	t2.setCount(10);
	t2.setPrice(25.0);
	t2.printInfo();


	Item t3 = t1;
	t3.printInfo();

#endif

	system("pause");

	return 0;
}
