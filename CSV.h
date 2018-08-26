#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace csv{

	typedef vector<vector<string>> CSV;

	bool reader(const char *filename, CSV &csv, const char * separator);

	bool writer(const char *filename, CSV &csv, const char * separator);

	void printcsv(CSV &csv);
}
