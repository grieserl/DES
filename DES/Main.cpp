#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//For testing only, outputs the binary representation of the 64 bit unsigned input
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


uint64_t initialPermutation(uint64_t x) 
{
	unsigned long long y = 0;
	unsigned long long i = 1;

	

	if (x & (i << 63)) y |= (i << 24); //Bit 1 -> 40
	if (x & (i << 62)) y |= (i << 56); //Bit 2 -> 8
	if (x & (i << 61)) y |= (i << 16); //Bit 3 -> 48
	if (x & (i << 60)) y |= (i << 48); //Bit 4 -> 16
	if (x & (i << 59)) y |= (i << 8); //Bit 5 -> 56
	if (x & (i << 58)) y |= (i << 40); //Bit 6 -> 24
	if (x & (i << 57)) y |= (i << 0); //Bit 7 -> 64
	if (x & (i << 56)) y |= (i << 32); //Bit 8 -> 32
	if (x & (i << 55)) y |= (i << 25); //Bit 9 -> 39
	if (x & (i << 54)) y |= (i << 57); //Bit 10 -> 7
	if (x & (i << 53)) y |= (i << 17); //Bit 11 -> 47
	if (x & (i << 52)) y |= (i << 49); //Bit 12 -> 15
	if (x & (i << 51)) y |= (i << 9); //Bit 13 -> 55
	if (x & (i << 50)) y |= (i << 41); //Bit 14 -> 23
	if (x & (i << 49)) y |= (i << 1); //Bit 15 -> 63
	if (x & (i << 48)) y |= (i << 33); //Bit 16 -> 31
	if (x & (i << 47)) y |= (i << 26); //Bit 17 -> 38
	if (x & (i << 46)) y |= (i << 58); //Bit 18 -> 6
	if (x & (i << 45)) y |= (i << 18); //Bit 19 -> 46
	if (x & (i << 44)) y |= (i << 50); //Bit 20 -> 14
	if (x & (i << 43)) y |= (i << 10); //Bit 21 -> 54
	if (x & (i << 42)) y |= (i << 42); //Bit 22 -> 22
	if (x & (i << 41)) y |= (i << 2); //Bit 23 -> 62
	if (x & (i << 40)) y |= (i << 34); //Bit 24 -> 30
	if (x & (i << 39)) y |= (i << 27); //Bit 25 -> 37
	if (x & (i << 38)) y |= (i << 59); //Bit 26 -> 5
	if (x & (i << 37)) y |= (i << 19); //Bit 27 -> 45
	if (x & (i << 36)) y |= (i << 51); //Bit 28 -> 13
	if (x & (i << 35)) y |= (i << 11); //Bit 29 -> 53
	if (x & (i << 34)) y |= (i << 43); //Bit 30 -> 21
	if (x & (i << 33)) y |= (i << 3); //Bit 31 -> 61
	if (x & (i << 32)) y |= (i << 35); //Bit 32 -> 29
	if (x & (i << 31)) y |= (i << 28); //Bit 33 -> 36
	if (x & (i << 30)) y |= (i << 60); //Bit 34 -> 4
	if (x & (i << 29)) y |= (i << 20); //Bit 35 -> 44
	if (x & (i << 28)) y |= (i << 52); //Bit 36 -> 12
	if (x & (i << 27)) y |= (i << 12); //Bit 37 -> 52
	if (x & (i << 26)) y |= (i << 62); //Bit 38 -> 2
	if (x & (i << 25)) y |= (i << 4); //Bit 39 -> 60
	if (x & (i << 24)) y |= (i << 36); //Bit 40 -> 28
	if (x & (i << 23)) y |= (i << 30); //Bit 41 -> 34
	if (x & (i << 22)) y |= (i << 61); //Bit 42 -> 3
	if (x & (i << 21)) y |= (i << 21); //Bit 43 -> 43
	if (x & (i << 20)) y |= (i << 53); //Bit 44 -> 11
	if (x & (i << 19)) y |= (i << 13); //Bit 45 -> 51
	if (x & (i << 18)) y |= (i << 45); //Bit 46 -> 19
	if (x & (i << 17)) y |= (i << 5); //Bit 47 -> 59
	if (x & (i << 16)) y |= (i << 37); //Bit 48 -> 27
	if (x & (i << 15)) y |= (i << 30); //Bit 49 -> 34
	if (x & (i << 14)) y |= (i << 62); //Bit 50 -> 2
	if (x & (i << 13)) y |= (i << 22); //Bit 51 -> 42
	if (x & (i << 12)) y |= (i << 54); //Bit 52 -> 10
	if (x & (i << 11)) y |= (i << 14); //Bit 53 -> 50
	if (x & (i << 10)) y |= (i << 46); //Bit 54 -> 18
	if (x & (i << 9)) y |= (i << 6); //Bit 55 -> 58
	if (x & (i << 8)) y |= (i << 38); //Bit 56 -> 26
	if (x & (i << 7)) y |= (i << 31); //Bit 57 -> 33
	if (x & (i << 6)) y |= (i << 63); //Bit 58 -> 1
	if (x & (i << 5)) y |= (i << 23); //Bit 59 -> 41
	if (x & (i << 4)) y |= (i << 55); //Bit 60 -> 9
	if (x & (i << 3)) y |= (i << 15); //Bit 61 -> 49
	if (x & (i << 2)) y |= (i << 47); //Bit 62 -> 17
	if (x & (i << 1)) y |= (i << 7); //Bit 63 -> 57
	if (x & (i << 0)) y |= (i << 39); //Bit 64 -> 25




	return y;
}


char getPadding()
{
		int ascii = rand() % 256;
		char thispad = char(ascii);
		return thispad;
}



int main(int argcount, char *argvalues[])
{
	char input[30]; 
	char action[30];
	char key[30];
	char mode[30];
	char infile[30];
	char outfile[30];
	
	cin >> input;
	cin >> action;
	cin >> key;
	cin >> mode;
	cin >> infile;
	cin >> outfile;

	FILE * inFilePnt, * outFilePnt;
	long lSize;
	size_t result;
	unsigned long long currentBlock;

	fopen_s(&inFilePnt, infile, "rb");
	fopen_s(&outFilePnt, outfile, "wb");
	if (inFilePnt == NULL) { fputs("File error", stderr); exit(1); }
	if (outFilePnt == NULL) { fputs("File error", stderr); exit(1); }

	//obtain file size:
	fseek(inFilePnt, 0, SEEK_END);
	lSize = ftell(inFilePnt);
	rewind(inFilePnt);


	int i = 0;
	while (i < lSize)
	{
		int numLeft = lSize - i;
		if (numLeft > 0 && numLeft < 8) 
		{	
			char * buffer = (char*)malloc(8);
			int padNum = 8 - numLeft;
			result = fread(buffer, 1, numLeft, inFilePnt);
			//char * paddedBuffer = new char[8];
			//strcpy_s(paddedBuffer, buffer);

			while (padNum > 0)
			{	
				buffer[8 - padNum] = getPadding();				
				padNum--;
			}
			i += 8;
		

			//call function to add random characters to &currentBlock
		}
		else
		{
			result = fread(&currentBlock, 1, 8, inFilePnt);
			fwrite(&currentBlock, 1, 8, outFilePnt);
			i += 8;
		}
	}

	fclose(inFilePnt);
	fclose(outFilePnt);

	cout << getBits(currentBlock) << endl;
	cout << getBits(initialPermutation(currentBlock)) << endl;
	cout << "done";

}
