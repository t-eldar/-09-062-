#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string number;
	fin >> number;

	int first = 0, last = 0;

	for (int i = 0; i < number.size() / 2; i++)
		first += number[i] - '0';

	for (int i = number.size() - 1; i >= number.size() / 2; i--)
		last += number[i] - '0';

	if (last == first)
		fout << "YES";
	else
		fout << "NO";
}