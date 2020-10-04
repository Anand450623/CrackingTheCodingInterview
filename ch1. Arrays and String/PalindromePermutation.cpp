/*
 * Problem   : Given a string, Implement an Algorithm to test whether any permutation of given string is palindrome or not.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	string input = "tact coa";
	int hash = 0;
	for(auto x: input)
	{
		int diff = x-'a';
		if(diff >= 0)
			hash ^= (1<<diff);
	}

	int set_bits = __builtin_popcount(hash);
	if(set_bits <= 1)
		cout<<"The permutation of given string is palindrome"<<endl;
	else
		cout<<"No permutation of given string is palindrome"<<endl;

	return 0;

}
