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
		cout << "Викликано конструктор без параметрiв.\n";
	}


	Receipt(int n, int d, float s) : number(n), date(d), sum(s) {
		cout << "Викликано конструктор з параметрами.\n";
	}


	Receipt(const Receipt& other) {
		number = other.number;
		date = other.date;
		sum = other.sum;
		cout << "Викликано конструктор копiювання.\n";
	}


	void inputNumber() {
		cout << "Введiть номер квитанцiї: ";
		cin >> number;
	}


	void inputDate() {
		cout << "Введiть дату (наприклад, у форматi YYYYMMDD): ";
		cin >> date;
	}


	void inputSum() {
		cout << "Введiть суму до сплати: ";
		cin >> sum;
	}


	void printInfo() const {
		cout << "--------------------------\n";
		cout << "Номер квитанцiї: " << number << "\n";
		cout << "Дата видачi:     " << date << "\n";
		cout << "Сума до сплати:  " << sum << "\n";
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
