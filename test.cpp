#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include "CSV.h"
using namespace std;
using namespace csv;

int main()
{
	CSV csv;
	vector<string> header;

	reader("./test.csv", csv, ",");
	int line_nu = 0;
	for (auto row : csv)
	{
		if (line_nu == 0)
		{
			header = row;
		}
		else
		{
			cout << "ID:" << row[0] << endl;
			for (size_t i = 0; i < header.size(); i++)
			{
				cout << "\t" << header[i] << ": " << row[i] << endl;;
			}

			if (true)
			{
				cout << "\t" << "[���뵽�ڣ���]\t��Ҫ�����ʼ�֪ͨ\t[��ӵ��ռ����б�]" << endl;
			}
			else
			{
				cout << "\t" << "[���뵽�ڣ���]" << endl;
			}
		}
		
		line_nu++;
	}


	//printcsv(csv);


	system("pause");
	return EXIT_SUCCESS;
}