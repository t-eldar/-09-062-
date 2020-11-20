#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string rune;
	fin >> rune;

	bool flag = true;
	int num_of_symbols = 1;
	
	for (int i = 0; i < rune.size() && flag; i++)
	{
		if (rune[i] >= 'A' && rune[i] <= 'Z')
		{
			for (int j = i + 1; j < rune.size() && rune[j] <= 'z' && rune[j] >= 'a'; j++)
				num_of_symbols++;
			
			if (num_of_symbols > 4 || num_of_symbols < 2)
			{
				fout << "No";
				flag = false;
			}
			else
			{
				flag = true;
				i += num_of_symbols - 1;

				num_of_symbols = 1;
			}
		}
		else
		{
			fout << "No";
			flag = false;
		}
	}

	if (flag)
		fout << "Yes";
}