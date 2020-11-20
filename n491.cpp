#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string str;
	fin >> str;

	string check_str;
	bool flag = true, repeat_check = false;
	int j = 1;

	char check = str[0];
	for (int i = 0; i < str.size() - 1; i++)
		if (str[i] != check)
			repeat_check = true;

	if (!repeat_check)
		fout << "NO SOLUTION";
	else
	{
		while (flag)
		{
			for (int i = str.size() - j; i >= 0; i--)
				check_str.push_back(str[i]);

			if (str != check_str)
			{
				fout << str;

				return 0;
				flag = false;
			}
			else
			{
				str.pop_back();
				check_str.clear();

				flag = true;
				j++;
			}
		}
	}
}