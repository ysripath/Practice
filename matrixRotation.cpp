// Program to rotate the matrix by 90/180/270 deg

#include <iostream>


using namespace std;

int arr[5][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
int N = 5;
int TLx, TLy, TRx, TRy, BLx, BLy, BRx, BRy;
int NN;



void displayMatrix()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

void initializeVar()
{
	TLx = 0;
	TLy = 0;

	TRx = 0;
	TRy = N-1;
	
	BLx = N-1;
	BLy = 0;

	BRx = N-1;
	BRy = N-1;
}

void changeOrder()
{
	TLy += 1;
	TRx += 1;
	BRy -= 1;
	BLx -= 1;
}

void swap(int n)
{
	int temp1, temp2;

	while (n!=0)
	{
		temp1 = arr[TRx][TRy];
		arr[TRx][TRy] = arr[BRx][BRy];
		temp2 = arr[TLx][TLy];
		arr[TLx][TLy] = temp1;
		temp1 = arr[BLx][BLy];
		arr[BLx][BLy] = temp2;
		arr[BRx][BRy] = temp1;
		n--;
		temp1 = temp2 = 0;
	}
}

void solve(int deg)
{
	int c = 1;
	for (int i = 0; i < N/2; i++)
	{
		int k = 1;
		while(k <= NN)
		{
			swap(deg);
			changeOrder();
			k++;
		}
		initializeVar();
		TLx += c;
		TLy += c;
		TRx += c;
		TRy -= c;
		BLx -= c;
		BLy += c;
		BRx -= c;
		BRy -= c;
		c++;
		NN-=2;
	}
}


int main()
{
	//int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	NN = N-1;
	cout<<"Matrix is \n";
	displayMatrix();
	initializeVar();
	cout<<"Choice of rotation\n";
	int choice;
	cout<<"1.90deg \t 2.180deg \t 3.270deg\n";
	cin>>choice;
	switch(choice)
	{
		case 1: { solve(1); break;}
		case 2: { solve(2); break;}
		case 3: { solve(3); break;}
		default: break;
	}
	cout<<"Rotated matrix is\n";
	displayMatrix();
	return 0;
}
