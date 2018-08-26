#include "CSV.h"

bool csv::reader(const char *filename, CSV &csv, const char * separator)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return false;
	}

	char buf[1024];
	char *pbuf;

	while (!feof(file))
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), file);

		if (strcmp(buf, "") == 0)
		{
			continue;
		}

		vector<string> vline;

		pbuf = strtok(buf, ",");
		if (pbuf != NULL)
		{
			vline.push_back(pbuf);

			while ((pbuf = strtok(NULL, separator)) != NULL)
			{
				if (pbuf[strlen(pbuf) - 1] == '\n')
				{
					pbuf[strlen(pbuf) - 1] = '\0';
				}
				vline.push_back(pbuf);
			}
		}

		csv.push_back(vline);
	}

	fclose(file);

	return false;
}

bool csv::writer(const char *filename, CSV &csv, const char * separator)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		return false;
	}

	for (auto row : csv)
	{
		for (size_t i = 0; i < row.size(); i++)
		{
			if (i == 0)
			{
				fwrite(row[i].c_str(), 1, row[i].size(), file);
			}
			else
			{
				fwrite(separator, 1, strlen(separator), file);
				fwrite(row[i].c_str(), 1, row[i].size(), file);
			}
		}

		fwrite("\n", 1, strlen("\n"), file);
	}

	fclose(file);
	return false;
}

void csv::printcsv(CSV &csv)
{
	for (auto line : csv)
	{
		cout << "[";
		for (auto tmp : line)
		{
			if (tmp == line[0])
			{
				cout << "\"" << tmp << "\"";
			}
			else
			{
				cout << ", \"" << tmp << "\"";
			}
		}
		cout << "]" << endl << endl;
	}
}
