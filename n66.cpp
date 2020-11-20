#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	const int size = 'z' - 'a' + 2;
	char keyboard[size]{ "qwertyuiopasdfghjklzxcvbnm" };

	char letter;
	fin >> letter;
	if (letter == 'm')
		fout << 'q';
	else
		for (int i = 0; i < size - 1; i++)
			if (letter == keyboard[i])
				fout << keyboard[i + 1];
}
