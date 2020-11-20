#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	string correct_symbols = "ABCEHKMOPTXY";

	for (int i = 0; i < n; i++)
	{
		string car_number;
		fin >> car_number;

		if (car_number.size() != 6)
		{
			fout << "No" << endl;
		}
		else
		{
			short check = 0;

			if (car_number[1] <= 57 && car_number[1] >= 48)
				check++;
			if (car_number[2] <= 57 && car_number[2] >= 48)
				check++;
			if (car_number[3] <= 57 && car_number[3] >= 48)
				check++;

			if (correct_symbols.find(car_number[0]) != -1)
				check++;
			if (correct_symbols.find(car_number[4]) != -1)
				check++;
			if (correct_symbols.find(car_number[5]) != -1)
				check++;
			if (check == 6)
				fout << "Yes" << endl;
			else
				fout << "No" << endl;
		}
	}
}