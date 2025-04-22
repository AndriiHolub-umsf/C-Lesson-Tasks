// Lab05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <Windows.h>

using namespace std;

template <typename T>
class Matrix
{
private:
	vector<vector<T>> data;
	int rows;
	int cols;

public:
	Matrix(int r, int c) : rows(r), cols(c), data(r, vector<T>(c)) {}


	void fillRandom(int minVal = -10, int maxVal = 10) {
		srand(static_cast<unsigned>(time(nullptr)));
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				data[i][j] = static_cast<T>(minVal + rand() % (maxVal - minVal + 1));
	}

	void display() const
	{
		cout << "Матриця:\n";
		for (const auto& row : data)
		{
			for (const auto& val : row)
				cout << val << "\t";
			cout << endl;
		}
	}

	int countRowsWithoutZeros() const 
	{
		int count = 0;
		for (const auto& row : data) 
		{
			if (none_of(row.begin(), row.end(), [](T val) { return val == 0; }))
				++count;
		}
		return count;
	}

	T findMaxDuplicate() const
	{
		unordered_map<T, int> freq;
		for (const auto& row : data)
			for (T val : row)
				freq[val]++;

		T maxVal = numeric_limits<T>::lowest();
		for (const auto& pair : freq) 
{
			T key = pair.first;
			int count = pair.second;

			if (count > 1)
				maxVal = max(maxVal, key);
		}



		return maxVal;
	}

	void moveZerosToFront()
	{
		vector<T> flat;
		for (auto& row : data)
			for (T val : row)
				flat.push_back(val);

		stable_partition(flat.begin(), flat.end(), [](T val) { return val == 0; });

		for (int i = 0, k = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				data[i][j] = flat[k++];
	}
};
int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int rows, cols;
	cout << "Введіть кількість рядків: ";
	cin >> rows;

	cout << "Введіть кількість стовпців: ";
	cin >> cols;

	Matrix<int> mat(rows, cols);
	mat.fillRandom(-5, 5);
	mat.display();

	int noZeroRows = mat.countRowsWithoutZeros();
	cout << "Кількість рядків без нулів: " << noZeroRows << endl;

	int maxDup = mat.findMaxDuplicate();
	cout << "Максимальне число, що повторюється: " << maxDup << endl;

	mat.moveZerosToFront();
	cout << "Матриця після переміщення нулів на початок:" << endl;
	mat.display();

	system("pause");

	return 0;
}