#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string cipher, word;
	fin >> cipher >> word;

	bool flag = false;
	short shift = cipher[0];

	for (int i = 0; i <= 26 && !flag; i++)
	{
		if (cipher.find(word) != -1)
		{
			shift = i;
			flag = true;
		}

		for (int j = 0; j < word.size() && !flag; j++)
		{
			if (word[j] - 1 < 'A')
				word[j] = 'Z';
			else
				word[j]--;
		}
	}
	for (int i = 0; i < cipher.size(); i++)
	{
		if (cipher[i] + shift > 'Z')
			cipher[i] += shift - 26;
		else
			cipher[i] += shift;
	}
	if (flag)
		fout << cipher;
	else
		fout << "IMPOSSIBLE";
}