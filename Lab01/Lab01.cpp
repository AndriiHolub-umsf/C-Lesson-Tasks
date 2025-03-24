// Lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
	double x, y, z;
	SetConsoleOutputCP(CP_UTF8);

	cout << u8"Введіть x: ";
	cin >> x;

	cout << u8"Введіть y: ";
	cin >> y;

	cout << u8"Введіть z: ";
	cin >> z;

	double a = pow(cos(atan(z)), 2) + 4.2 * exp(-pow(x, 2) + 1.3)
		- sqrt(2 * pow(x, 2) + pow(y, 2) + 1)
		+ log((2 + 3.3 * pow(x, 2) + pow(y, 2)) / (4 * pow(x, 2) + 5.5 * pow(y, 2) + 1));

	double b = sin(x + M_PI / 4) * log10(1 + sqrt(4 + pow(x, 2) + pow(y, 2) / 2) + tan(1 + pow(x, 2)));

	cout << u8"Результат обчислення a = " << a << endl;
	cout << u8"Результат обчислення b = " << b << endl;

	system("pause");

	return 0;
}

