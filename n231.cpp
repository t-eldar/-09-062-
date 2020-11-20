#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string str;
	fin >> str;

	int j = 0;
	string num_s;
	
	int num_of_symbols = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= 57 && str[i] >= 48)
		{
			num_s += str[i];
			j++;
		}
		else if (num_s[0] > 0)
		{
			int num_i = stoi(num_s);
			for (int j = 0; j < num_i; j++, num_of_symbols++)
			{
				if (num_of_symbols == 40)
				{
					fout << endl;
					num_of_symbols = 0;
				}

				fout << str[i];
			}

			num_s.clear();
			j = 0;
		}
		else
		{
			if (num_of_symbols == 40)
			{
				fout << endl;
				num_of_symbols = 0;
			}

			num_of_symbols++;

			fout << str[i];
			num_s.clear();
			j = 0;
		}
	}
}