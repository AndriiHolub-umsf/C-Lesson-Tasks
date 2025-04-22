// Lab04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Firm 
{
	const int id;
	string name;
	string profile;
	int year;
	bool hasBenefits;
	string director;

	inline Firm operator=(const Firm& other)
	{
		if (this != &other)
		{
			name = std::move(other.name);
			profile = std::move(other.profile);
			year = other.year;
			hasBenefits = other.hasBenefits;
			director = std::move(other.director);
			const_cast<int&>(id) = other.id;

		}
		return *this;
	}
};

class FirmsManagerBase
{
protected:
	vector<Firm> firms;
	int nextId = 1;
public:
	FirmsManagerBase() = default;

	FirmsManagerBase(const FirmsManagerBase& other)
	{
		firms = other.firms;
		nextId = other.nextId;
	}

	void addFirm(const Firm& f)
	{
		firms.push_back({ nextId++, f.name, f.profile, f.year, f.hasBenefits, f.director });
	}

	void addFirm(const string& name, const string& profile, int year, bool hasBenefits, const string& director)
	{
		firms.push_back({ nextId++, name, profile, year, hasBenefits, director });
	}

	void displayAll() const
	{
		for (const auto& f : firms)
		{
			cout << f.id << ") " << f.name << ", " << f.profile << ", " << f.year << ", "
				<< (f.hasBenefits ? "���" : "�") << ", " << f.director << std::endl;
		}
	}

	explicit operator int() const
	{
		return static_cast<int>(firms.size());
	}

	void displayProducers() const
	{
		cout << "Գ���, ������ ������������:\n";
		for (const auto& f : firms)
		{
			if (f.profile == "�����������")
			{
				cout << f.id << ") " << f.name << " - �������: " << f.director << std::endl;
			}
		}
	}

};

class FirmsManager : public FirmsManagerBase
{

public:

	void sortByYear()
	{
		sort(firms.begin(), firms.end(), [](const Firm& a, const Firm& b)
		{
			return a.year < b.year;
		});
	}
};



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FirmsManager manager;

	manager.addFirm("����", "�����������", 1995, true, "��������");
	manager.addFirm("MFK", "�������", 2000, false, "������");
	manager.addFirm("TOR.LTD", "�����������", 2010, true, "������");

	manager.sortByYear();
	manager.displayAll();

	cout << "�������� ������� ����: " << int(manager) << std::endl;

	manager.displayProducers();

	return 0;
}