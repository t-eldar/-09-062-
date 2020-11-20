#include <fstream>
#include <string>

using namespace std;

string max_of_strings(string str1, string str2)
{
	if (str1.size() > str2.size())
		return str1;
	if (str2.size() > str1.size())
		return str2;

	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] > str2[i])
			return str1;
		if (str2[i] > str1[i])
			return str2;
	}
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string number1, number2, number3;

	fin >> number1 >> number2 >> number3;

	fout << max_of_strings(number1, max_of_strings(number2, number3));
}