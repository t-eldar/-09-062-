#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string number;
	fin >> number;

	string first, last;
	for (int i = 0; i < (number.size() - number.size() / 2); i++)
		first += number[i];
	for (int i = number.size() - 1; i >= (number.size() - number.size() / 2); i--)
		last += number[i];

	if (first == last)
		fout << "YES";
	else
		fout << "NO";
}