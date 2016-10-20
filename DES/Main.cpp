#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>


using namespace std;


string getBits(unsigned long long input)
{
	string str(64, '0');

	for (int i = 0; i < 64; i++)
	{
		if ((1ll << i) & input)
			str[63 - i] = '1';
	}
	return str;
}

string getBits2(long long input)
{


	bitset<sizeof(long long) * CHAR_BIT>    bits(input);
	cout << bits << "\n";

	return bits.to_string();

}

unsigned long long initialPermutation(unsigned long long input) {
	return input;
}

unsigned long long finalPermutation(unsigned long long input) {
	return input;
}


int main(int argcount, char *argvalues[])
{
	cout << sizeof(unsigned long long) << endl;
	string infileName, outfileName;
	cout << "Enter Input File" << endl;
	getline(cin, infileName);

	ifstream inFile;
	inFile.open(infileName);




	unsigned long long in8Byte;

	inFile >> in8Byte;



}

