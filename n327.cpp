#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int sum_of_nums(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number = number / 10;
	}
	return sum;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	for (int i = 0; i < n; i++)
	{
		string number;
		fin >> number;

		string s_first, s_last;
		int i_first, i_last;

		for (int i = 0; i < number.size() / 2; i++)
			s_first += number[i];

		for (int i = number.size() / 2; i < number.size(); i++)
			s_last += number[i];

		i_first = stoi(s_first);
		i_last = stoi(s_last);

		if (sum_of_nums(i_first) == sum_of_nums(i_last + 1) || sum_of_nums(i_first) == sum_of_nums(i_last - 1))
			fout << "Yes\n";
		else
			fout << "No\n";
	}
}