#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string str;
	fin >> str;

	string arrow1 = ">>-->", arrow2 = "<--<<";

	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str.find(arrow1) != -1)
		{
			str.replace(str.find(arrow1), arrow1.size(), ">>//>");
			count++;
		}
		if (str.find(arrow2) != -1)
		{
			str.replace(str.find(arrow2), arrow2.size(), "<//<<");
			count++;
		}
	}
	fout << count;
}