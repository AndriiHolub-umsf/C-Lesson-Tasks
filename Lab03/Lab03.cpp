// Lab02.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
};

class FirmsManager 
{
private:
	vector<Firm> firms;
	int nextId = 1;

public:
	FirmsManager() = default;

	FirmsManager(const FirmsManager& other) 
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
				<< (f.hasBenefits ? "так" : "ні") << ", " << f.director << std::endl;
		}
	}

	void sortByYear() 
	{
		sort(firms.begin(), firms.end(), [](const Firm& a, const Firm& b)
		{
			return a.year < b.year;
		});
	}

	explicit operator int() const 
	{
		return static_cast<int>(firms.size());
	}

	void displayProducers() const
	{
		cout << "Фірми, зайняті виробництвом:\n";
		for (const auto& f : firms)
		{
			if (f.profile == "виробництво") 
			{
				cout << f.id << ") " << f.name << " - Керівник: " << f.director << std::endl;
			}
		}
	}
};


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FirmsManager manager;

	manager.addFirm("Зоря", "виробництво", 1995, true, "Петренко");
	manager.addFirm("MFK", "торгівля", 2000, false, "Іванов");
	manager.addFirm("TOR.LTD", "виробництво", 2010, true, "Коваль");

	manager.sortByYear();
	manager.displayAll();

	cout << "Загальна кількість фірм: " << int(manager) << std::endl;

	manager.displayProducers();

	return 0;
}