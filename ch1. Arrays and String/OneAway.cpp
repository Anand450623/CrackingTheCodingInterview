/*
 * Problem   : Given a pair of string, find whether it's possible to make the string similar by a single operation of deletion, insertion or replacement.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	string input1 = "bale";
	string input2 = "pale";

	bool differnceFound = false;
	bool possible = true;

	string s1 = input1.length() < input2.length() ? input2 :input1;
	string s2 = input1.length() < input2.length() ? input1 :input2;

	unsigned int iter1 = 0, iter2 = 0;

	while(iter1 < s1.length() && iter2 < s2.length())
	{

		if(s1[iter1] != s2[iter2])
		{
			if(differnceFound)
			{
				possible = false;
				break;
			}

			differnceFound = true;
			if(s1.length() == s2.length())
				iter2++;

		}
		else
		{
			iter2++;
		}

		iter1++;

	}

	if(possible)
		cout<<"Both strings are one edit distance away"<<endl;
	else
		cout<<"Both strings are not one distance away"<<endl;

	return 0;

}
