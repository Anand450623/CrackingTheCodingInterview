/*
 * Problem   : Assume to be given with a isSubstring method which check if one words is substring of another. Given two string s1 and s2, write code to check is s2 is rotation if s1 using only one call to isSubstring.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> computeZArrayOptimized(string s)
{
	int n = s.length();
	vector<int> array(n, 0);

	int l=0, r=0;
	for(int i=1; i<n; i++)
	{
		if(i<=r)
			array[i] = min(r-i+1, array[i-l]);
		while(i+array[i]<n && s[array[i]]==s[i+array[i]])
			array[i]++;
		if(i+array[i]-1>r)
		{
			l = i;
			r = i+array[i]-1;
		}
	}

	return array;
}

bool isSubString(string text, string pattern)
{

	string data = pattern+"#"+text;
	vector<int> zArray = computeZArrayOptimized(data);

	int patternLength = pattern.length();
	for(auto x: zArray)
		if(x==patternLength)
			return true;

	return false;

}



int main()
{

	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	string combined = s1+s1;
	if(isSubString(combined, s2))
		cout<<"s1 and s2 are rotation of one another "<<endl;
	else
		cout<<"s1 and s2 are not rotation of one another"<<endl;

	return 0;

}
