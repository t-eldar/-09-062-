#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string word1, word2;
	fin >> word1 >> word2;

	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector <int> num_of_letters1(letters.size(), 0);
	vector <int> num_of_letters2(letters.size(), 0);

	bool flag = true;

	if (word1.size() != word2.size())
		fout << "NO";
	else
	{
		for (int i = 0; i < letters.size(); i++)
		{
			for (int j = 0; j < word1.size(); j++)
			{
				if (word1[j] == letters[i])
					num_of_letters1[i]++;

				if (word2[j] == letters[i])
					num_of_letters2[i]++;
			}
		}

		for (int i = 0; i < letters.size(); i++)
		{
			if (num_of_letters1[i] != num_of_letters2[i])
			{
				flag = false;
				fout << "NO";
				return 0;
			}
			else
				flag = true;
		}

		if (flag)
			fout << "YES";
		else
			fout << "NO";
	}
}