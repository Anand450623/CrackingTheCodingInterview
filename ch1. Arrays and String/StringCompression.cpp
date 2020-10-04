/*
 * Problem   : Given a string convert it into pattern of character and count. Eg. aabbaa -> a2b2a2. If converted string is of bigger length return original string.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int getCount(int number)
{
	int count = 1;
	while(number/10)
	{
		count++;
		number /= 10;
	}
	return count;
}

int findCompressedSize(string input)
{
	int size = 0;
	int characterCount = 1;
	for(unsigned int i=0; i+1<input.length(); i++)
	{
		if(input[i] == input[i+1])
			characterCount++;
		else
		{
			size += (1 + getCount(characterCount));
			characterCount = 1;
		}
	}
	size += (1 + getCount(characterCount));
	return size;
}

string computeCompressedString(string input)
{
	int compressedLength = findCompressedSize(input);
	if(compressedLength > input.length())
		return input;
	else
	{
		string compressedString;
		int characterCount = 1;
		for(unsigned int i=0; i+1<input.length(); i++)
		{
			if(input[i] == input[i+1])
				characterCount++;
			else
			{
				compressedString += input[i]+ to_string(characterCount);
				characterCount = 1;
			}
		}
		compressedString += input[input.length()-1]+ to_string(characterCount);
		return compressedString;
	}
}

int main()
{

	string input1 = "aabbccddd";
	cout<<computeCompressedString(input1);
	return 0;

}
