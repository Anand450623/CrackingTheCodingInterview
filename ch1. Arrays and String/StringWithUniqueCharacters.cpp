/*
 * Problem   : Implement Algorithm to check if a string has all unique characters.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string input = "aabcdefgh";
	bool unique = true;
	int hash = 0;
	for(auto x: input)
	{
		int mask = x - 'a';
		mask = 1<<mask;
		if(hash & (mask))
		{
			unique = false;
			break;
		}

		hash |= mask;

	}

	if(unique)
		cout<<"All Characters are unique"<<endl;
	else
		cout<<"All Characters are not unique"<<endl;

	return 0;

}
