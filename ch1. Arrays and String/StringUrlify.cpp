/*
 * Problem   : Given a string, Implement algorithm to replace all spaces with %20. Assume that input has enough space to make the required changes.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int getSpaceCount(char str[], int actualLength)
{
	int space = 0;
	for(int i=0; i < actualLength && str[i]; i++)
		if(str[i] == ' ')
			space++;
	return space;
}

void stringUrlify(char str[], int actualLength)
{

	int spaces = getSpaceCount(str, actualLength);
	int requiredLength = actualLength+(2*spaces);

	assert(strlen(str) >= requiredLength);

	str[requiredLength--] = '\0';

	for(int i=actualLength-1; i>0; i--)
	{
		if(str[i] == ' ')
		{
			str[requiredLength--] = '0';
			str[requiredLength--] = '2';
			str[requiredLength--] = '%';
		}
		else
		{
			str[requiredLength--] = str[i];
		}
	}

}

int main()
{

	char str[] = "Mr John Smith    ";
	int actualength = 13;
	stringUrlify(str, actualength);
	cout<<str<<endl;
	return 0;

}
