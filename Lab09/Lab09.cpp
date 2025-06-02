// Lab09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sqlite/sqlite3.h"

int main()
{
	sqlite3* db;
	char* errorMessage = nullptr;
	int rc = sqlite3_open("mydb.db", &db);
	if (rc) {
		std::cerr << "Not have database " << sqlite3_errmsg(db) << std::endl;
		return 1;
	}
	else {
		std::cout << "Greate database is open/create" << std::endl;
	}

	const char* createTableSQL =
		"CREATE TABLE IF NOT EXISTS students ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"name TEXT NOT NULL, "
		"grade INTEGER);";
	rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errorMessage);
	if (rc != SQLITE_OK) {
		std::cerr << "Error " << errorMessage << std::endl;
		sqlite3_free(errorMessage);
	}
	else {
		std::cout << "'students' is created" << std::endl;
	}
	sqlite3_close(db);
}