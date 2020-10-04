/*
 * Problem   : Implement an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to zero.
 * Author    : Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

void nullifyRow(int mat[4][4], int rid)
{
	for(int j=0; j<4; j++)
		mat[rid][j] = 0;
}

void nullifyCol(int mat[4][4], int cid)
{
	for(int i=0; i<4; i++)
		mat[i][cid] = 0;
}

int main()
{

	int n=4;
	bool firstRowHasZero = false;
	bool firstColHasZero = false;
	int mat[4][4] = {{0,2,3,4}, {5,0,7,8}, {9,10,11,12}, {13,14,15,0}};

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<setw(2)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"***************************************"<<endl;

	for(int i=0; i<n; i++)
	{
		if(mat[0][i]==0)
		{
			firstRowHasZero = true;
			break;
		}
	}

	for(int i=0; i<n; i++)
	{
		if(mat[i][0]==0)
		{
			firstColHasZero = true;
			break;
		}
	}


	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			if(mat[i][j] == 0)
			{
				mat[i][0] = 0;
				mat[0][j] = 0;
			}
		}
	}

	for(int i=1; i<n; i++)
	{
		if(mat[i][0]==0)
		{
			nullifyRow(mat, i);
		}
	}

	for(int j=1; j<n; j++)
	{
		if(mat[0][j]==0)
		{
			nullifyCol(mat, j);
		}
	}

	if(firstRowHasZero)
		nullifyRow(mat, 0);

	if(firstColHasZero)
		nullifyCol(mat, 0);

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
