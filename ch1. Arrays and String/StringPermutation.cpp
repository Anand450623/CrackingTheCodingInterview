/*
 * Problem   : Given two strings, write a method to decide if one is permutation of other.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	string input1 = "abcd";
	string input2 = "dbca";
	int hash = 0;

	for(auto x: input1)
		hash ^= (1<<(x-'a'));

	for(auto x: input2)
		hash ^= (1<<(x-'a'));

	if(hash)
		cout<<"The given strings are not permutations of one another"<<endl;
	else
		cout<<"The given strings are permutations of one another"<<endl;

	return 0;

}
