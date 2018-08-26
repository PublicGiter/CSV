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
				cout << "\t" << "[密码到期：是]\t需要发送邮件通知\t[添加到收件人列表]" << endl;
			}
			else
			{
				cout << "\t" << "[密码到期：否]" << endl;
			}
		}
		
		line_nu++;
	}


	//printcsv(csv);


	system("pause");
	return EXIT_SUCCESS;
}