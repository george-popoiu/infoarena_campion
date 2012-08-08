/*******************************************************
*     MYCPLUS Sample Code - http://www.mycplus.com     *
*                                                     *
*   This code is made available as a service to our   *
*      visitors and is provided strictly for the      *
*               purpose of illustration.              *
*                                                     *
* Please direct all inquiries to saqib at mycplus.com *
*******************************************************/

/******************** By : Farshad Mojtabai *******************/
#include<iostream>
#include<conio.h>
//#include

using namespace std;

void possible();
void exits(int);

const int ver[]={-1,-2,-2,-1,1,2,2,1},
		  hor[]={2,1,-1,-2,-2,-1,1,2};

int row,col,npos;
int board[8][8],nextij[8][8][8],accessible[8][8];
int main()
{

	int count = 1,k,j;

	cout <<"position [from (0,0) to (7,7)]:";
	cin >>row >>col;
	cout << endl;

	board[row][col]=count;

	while(count!=64)
	{
		count++;
		possible();
		exits(count);
		/*for(j=0;j<=7;j++)
		{
			for(k=0;k<=7;k++)
				cout <<  setw(3) << accessible[j][k];
			cout <<"\t";
			for(k=0;k<=7;k++)
				cout <<  setw(3) << board[j][k];
			cout <<"\n\n";
		}

		cout <<"\n\n";		*/
	}
	for(j=0;j<=7;j++)
	{
		for(k=0;k<=7;k++)
			cout <<  setw(3) << board[j][k];
		cout <<"\n\n";
	}

	getch();

	return 0;
}
void possible()
{
	int npos;
	for(int r=0;r<=7;r++)
	{

		for(int c=0;c<=7;c++)
		{
			npos = 0;

			for(int i=0;i<=7;i++)
			{
				if(((r+ver[i] >=0) && (r+ver[i] <=7))&&((c+hor[i] >=0) && (c+hor[i] <=7))&&(board[r+ver[i]][c+hor[i]] == 0))
				{

					nextij[r][c][npos] = i;
					npos++;
				}
			}
			accessible[r][c] = npos;
		}
	}

}
void exits(int l)
{

	int min = accessible[row+ver[nextij[row][col][0]]][col+hor[nextij[row][col][0]]];
	int r = row+ver[nextij[row][col][0]],c=col+hor[nextij[row][col][0]];

	for(int i=1;i < accessible[row][col];i++)
		if(min >= accessible[row+ver[nextij[row][col][i]]][col+hor[nextij[row][col][i]]])
		{
			min =accessible[row+ver[nextij[row][col][i]]][col+hor[nextij[row][col][i]]];
			r = row + ver[nextij[row][col][i]];
			c = col + hor[nextij[row][col][i]];
		}

		//cout <<"\n min ="<<<"  ("<<<','<<<") \n";
		board[r][c]=l;
		row = r;
		col = c;

}
