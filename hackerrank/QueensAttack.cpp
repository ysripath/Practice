#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define TOP 1
#define TOPRIGHT 2
#define RIGHT 3
#define BOTTOMRIGHT 4
#define BOTTOM 5
#define BOTTOMLEFT 6
#define LEFT 7
#define TOPLEFT 8



using namespace std;


int topEdge;
int bottomEdge;
int leftEdge;
int rightEdge;
int qR;
int qC;

bool** board;
void populateBoard(int n) {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			board[i][j] = true;
}

void fillBoard( int row, int col)
{
	if (row > 0 && row <= bottomEdge && col > 0 && col <= rightEdge && !(row == qR && col == qC))
		board[row][col] = false;
}

void checkAttack( int& attackCount, int type)
{
	int i = qR;
	int j = qC;
	switch (type)
	{
	case TOP: {
		if (qR == 1)
			return;
		i--;
		while (i > 0)
		{
			if (board[i--][j] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	case TOPRIGHT: {
		if (qR == 1 || qC == rightEdge)
			return;
		i--; j++;
		while (i > 0 && j <= rightEdge)
		{
			if (board[i--][j++] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	case RIGHT: {
		if (qC == rightEdge)
			return;
		j++;
		while (j <= rightEdge)
		{
			if (board[i][j++] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	case BOTTOMRIGHT: {
		if (qR == bottomEdge || qC == rightEdge)
			return;
		i++; j++;
		while (i <= bottomEdge && j <= rightEdge)
		{
			if (board[i++][j++] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	case BOTTOM: {
		if (qR == bottomEdge)
			return;
		i++;
		while (i <= bottomEdge)
		{
			if (board[i++][j] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	case BOTTOMLEFT: {
		if (qR == bottomEdge || qC == 1)
			return;
		i++; j--;
		while (i <= bottomEdge && j > 0)
		{
			if (board[i++][j--] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	case LEFT: {
		if (qC == 1)
			return;
		j--;
		while (j > 0)
		{
			if (board[i][j--] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	case TOPLEFT: {
		if (qR == 1 || qC == 1)
			return;
		i--; j--;
		while (i > 0 && j > 0)
		{
			if (board[i--][j--] == true)
				attackCount++;
			else
				return;
		}
		return;
	}
	default: break;
	}
}

int main() {
	int n;
	int k;
	cin >> n >> k;
    if (n > 23000)
        {
        cout<<0<<endl;
        return 0;
    }
	int rQueen;
	int cQueen;
	cin >> rQueen >> cQueen;
	qR = n - rQueen + 1;
	qC = cQueen;
    if (qR < 0 || qR > n || qC < 0 || qC > n)
        {
        cout<<0<<endl;
        return 0;
    }
	topEdge = 1;
	bottomEdge = n;
	rightEdge = n;
    board = new bool*[n+1];
    for (int i = 0; i <= n; i++)
		board[i] = new bool[n+1];
	//bool** board = new bool*[n + 1];
	//for (int i = 0; i <= n; i++)
	//	board[i] = new bool[n+1];
   // bool board[1001][1001];
	//populateBoard(board,n);
    populateBoard(n);
	for (int a0 = 0; a0 < k; a0++) {
		int rObstacle;
		int cObstacle;
		cin >> rObstacle >> cObstacle;
        if (board[n-rObstacle +1][cObstacle] == false)
            continue;
		fillBoard( n - rObstacle + 1, cObstacle);
		// your code goes here
	}

	int attackCount = 0;
	int type = 1;
	while (type < 9)
	{
		checkAttack( attackCount, type);
		type++;
	}
	cout << attackCount << endl;

	return 0;
}
