#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string name1, name2;

	fin >> name1 >> name2;

	const int size = 'z' - 'a' + 2;

	char letters[size]
	{
		'a','b','c','d','e','f',
		'g','h','i','j','k','l',
		'm','n','o','p','q','r',
		's','t','u','v','w','x',
		'y','z'
	};
	
	int num_of_letters_name1[size]{};
	int num_of_letters_name2[size]{};

	if (name1.size() != name2.size())
	{
		fout << "No";
		return 0;
	}
	else
	{
		for (int i = 0; i < name1.size(); i++)
		{
			for (int j = 0; j < size; j++)
			{
				if ((name1[i] == letters[j]) ^ (name1[i] + 32 == letters[j]))
					num_of_letters_name1[j]++;
				if ((name2[i] == letters[j]) ^ (name2[i] + 32 == letters[j]))
					num_of_letters_name2[j]++;
			}
		}

		for (int i = 0; i < size; i++)
		{
			if (num_of_letters_name1[i] != num_of_letters_name2[i])
			{
				fout << "No";
				return 0;
			}
		}

		fout << "Yes";
	}
}