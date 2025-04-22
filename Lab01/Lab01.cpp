// Lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

#if 0
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
#else
int main() {
	double x, y, z;
	SetConsoleOutputCP(CP_UTF8);

	cout << u8"Введіть x: ";
	cin >> x;

	cout << u8"Введіть y: ";
	cin >> y;

	cout << u8"Введіть z: ";
	cin >> z;

	double numerator = y;
	double denominator = 2 + pow(y, 2) + abs(y * z);
	double expr1 = numerator / denominator;

	double expr2 = sqrt(3.14 + pow(x,2) + pow(sin(y * z), 3));
	double expr3 = log10(2.0 / (pow(x, 2) + pow(y, 2) + 1));

	cout << u8"Проміжні значення обчислень:" << endl;
	cout << u8"expr1 = " << expr1 << endl;
	cout << u8"expr2 = " << expr2 << endl;
	cout << u8"expr3 = " << expr3 << endl;

	double a = acos(expr1 * (expr2 - expr3));


	expr1 = exp(-3 * pow(x, 2) + y / 5.0 - z);
	expr2 = cbrt(pow(tan(x), 2) / (1 + sin(M_PI * y / 2)));
	expr3 = pow((x + y + z) / (x * y * z), 3);

	cout << u8"Проміжні значення обчислень:" << endl;
	cout << u8"expr1 = " << expr1 << endl;
	cout << u8"expr2 = " << expr2 << endl;
	cout << u8"expr3 = " << expr3 << endl;

	double b = expr1 + expr2 - expr3;


	cout << u8"Результати обчислень:" << endl;
	cout << u8"a = " << a << endl;
	cout << u8"b = " << b << endl;

	system("pause");

	return 0;
}

#endif

