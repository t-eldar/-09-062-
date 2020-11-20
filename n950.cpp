#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string code_alph[26];
	code_alph[0] = '1';
	for (int i = 1; i < 26; i++)
	{
		code_alph[i] += code_alph[i - 1] + '0';
		swap(code_alph[i][i], code_alph[i][i - 1]);
	}

	string alph = "abcdefghijklmnopqrstuvwxyz";

	string str;
	fin >> str;

	for (int i = 25; i >= 0 && str.find('1') != -1;)
	{
		if (str.find(code_alph[i]) != -1)
			str.replace(str.find(code_alph[i]), code_alph[i].size(), 1, alph[i]);
		if (str.find(code_alph[i]) == -1)
			i--;
	}
	fout << str;
}