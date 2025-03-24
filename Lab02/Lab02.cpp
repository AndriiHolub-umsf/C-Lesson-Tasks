// Lab02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

int main() {


	setlocale(LC_ALL, "");


	Receipt receipt1;
	receipt1.inputNumber();
	receipt1.inputDate();
	receipt1.inputSum();
	receipt1.printInfo();


	Receipt receipt2(123, 20230324, 250.75f);
	receipt2.printInfo();


	Receipt receipt3(receipt2);
	receipt3.printInfo();

	system("pause");

	return 0;
}
