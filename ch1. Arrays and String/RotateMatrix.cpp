/*
 * Problem   : Given a matrix, write a code to rotate matrix by 90 degrees.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n = 4;
	int mat[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<setw(2)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"*******************************\n";

	for(int layer=0; layer<n/2; layer++)
	{
		int first=layer;
		int last=n-1-layer;

		for(int i=first; i<last; i++)
		{

			int offset = i-first;

			int top = mat[first][i]; // save top

			// left->top
			mat[first][i] = mat[last-offset][first];

			// bottom->left
			mat[last-offset][first] = mat[last][last-offset];

			// right->bottom
			mat[last][last-offset] = mat[i][last];

			//top->right
			mat[i][last] = top; //right <- saved top
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<setw(2)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;

}
