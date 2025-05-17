// Lab06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iterator>
#include <windows.h>

#define ProgrammNum 3


#if ProgrammNum == 1

#include <set>


int main() 
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	std::set<int> s = { 1, 3, 5, 7, 9, 11, 13 };
	std::cout << "Початковий set: ";
	for (int x : s) std::cout << x << " ";
	std::cout << std::endl;

	
	s.erase(9);
	s.insert(8);

	
	std::cout << "Set після видалення та додавання: ";
	for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << " ";
	std::cout << std::endl;


	std::set<int> s2 = { 100, 200, 300 };
	std::cout << "Другий set: ";
	for (int x : s2) std::cout << x << " ";
	std::cout << std::endl;


	auto it = s.begin();
	++it;
	auto it2 = it;
	std::advance(it2, 2);
	s.erase(it, it2);


	s.insert(s2.begin(), s2.end());

	std::cout << "Перший set (після змін): ";
	for (int x : s) std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "Другий set (без змін): ";
	for (int x : s2) std::cout << x << " ";
	std::cout << std::endl;

	system("pause");

	return 0;
}
#elif ProgrammNum == 2
#include <stack>

struct Point {
	int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	std::stack<Point> st;
	st.push({ 1, 2 });
	st.push({ 3, 4 });
	st.push({ 5, 6 });
	st.push({ 7, 8 });
	std::cout << "Початковий стек: ";
	std::stack<Point> temp = st;
	while (!temp.empty()) {
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;


	st.pop();
	st.top() = { 100, 200 }; 


	std::cout << "Стек після змін (зверху до низу): ";
	temp = st;
	while (!temp.empty()) {
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;


	std::stack<Point> st2;
	st2.push({ 9, 10 });
	st2.push({ 11, 12 });

	std::cout << "Другий стек (зверху до низу): ";
	temp = st2;
	while (!temp.empty()) {
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;


	st.pop();

	
	std::stack<Point> reverse_st2;
	temp = st2;
	while (!temp.empty()) {
		reverse_st2.push(temp.top());
		temp.pop();
	}
	while (!reverse_st2.empty()) {
		st.push(reverse_st2.top());
		reverse_st2.pop();
	}


	std::cout << "Перший стек (після додавання): ";
	temp = st;
	while (!temp.empty()) {
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;

	std::cout << "Другий стек (без змін): ";
	temp = st2;
	while (!temp.empty()) {
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;

	system("pause");

	return 0;
}
#elif ProgrammNum == 3

#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

struct Point 
{
	int x, y;
	bool operator<(const Point& other) const
	{
		return (x < other.x) || (x == other.x && y < other.y);
	}
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p.x << "," << p.y << ")";
	return os;
}


bool condition(const Point& p) 
{ 
	return p.x > 5; 
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::set<Point> s = { {1,2}, {5,5}, {10,4}, {7,9}, {3,7} };
	//1.Відсортовано by default (за зростанням x, y)
	std::cout << "Set (за зростанням): ";
	for (const auto& p : s) 
		std::cout << p << " ";
	std::cout << std::endl;

	// 2. Знайти перший елемент, що задовольняє умову
	auto it = std::find_if(s.begin(), s.end(), condition);
	if (it != s.end())
		std::cout << "Знайдено елемент з x > 5: " << *it << std::endl;

	// 3. Перемістити всі з x > 5 у stack
	std::stack<Point> st;
	for (const auto& p : s) {
		if (condition(p)) st.push(p);
	}

	// 4. Переглянути stack (тільки через pop, бо інакше не можна)
	std::cout << "Stack (x > 5) (зверху до низу): ";
	std::stack<Point> st_copy = st;
	while (!st_copy.empty()) {
		std::cout << st_copy.top() << " ";
		st_copy.pop();
	}
	std::cout << std::endl;

	// 5. Порахувати елементи в set з x > 5
	int count = std::count_if(s.begin(), s.end(), condition);
	std::cout << "Кількість елементів з x > 5 у set: " << count << std::endl;

	// 6. Перевірити, чи є елемент з x == 10
	bool exists = std::any_of(s.begin(), s.end(), [](const Point& p) {return p.x == 10; });
	std::cout << "Чи є елемент з x == 10 у set? " << (exists ? "Так" : "Ні") << std::endl;

	// 7. Злити set і stack у новий set (set сам видалить дублікати)
	std::set<Point> merged = s;
	st_copy = st;
	while (!st_copy.empty()) {
		merged.insert(st_copy.top());
		st_copy.pop();
	}

	std::cout << "Merged set: ";
	for (const auto& p : merged) std::cout << p << " ";
	std::cout << std::endl;

	// 8. Порахувати елементи з x > 5 у merged set
	int count_merged = std::count_if(merged.begin(), merged.end(), condition);
	std::cout << "Кількість елементів з x > 5 у merged set: " << count_merged << std::endl;

	// 9. Перевірити, чи є елемент з x == 10 у merged set
	bool exists_merged = std::any_of(merged.begin(), merged.end(), [](const Point& p) {return p.x == 10; });
	std::cout << "Чи є елемент з x == 10 у merged set? " << (exists_merged ? "Так" : "Ні") << std::endl;

	system("pause");

	return 0;
}

#endif
