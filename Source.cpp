#include <iostream>


using namespace std;

int arr[9][9];

bool check(int i, int j);

int main()
{
	
	
	// Partial fill matrix
	cout << "Enter sudoku initial matrix\n";
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	cout << "Current sudoku puzzle\n";
	// DIsplay partial matrix
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	

	if (check(0,0))
	{
		//DIsplay solved matrix

		cout << endl << "Solved sudoku!\n";
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
	}
	else
	{
		cout << "Not possible to solve\n";
	}

	return 0;
}

bool checkRows()
{
	int row = 0;
	bool buf[10];
	while (row < 9)
	{

		for (int i = 1; i < 10; i++)
			buf[i] = false;
		for (int i = 0; i < 9; i++)
		{
			if (buf[arr[row][i]] == false)
				buf[arr[row][i]] = true;
			else
				return false;
		}
		row++;
	}

	for (int i = 1; i < 10; i++)
		if (buf[i] == false)
			return false;

	return true;
}

bool checkColumns()
{
	int col = 0;
	bool buf[10];
	while (col < 9)
	{

		for (int i = 1; i < 10; i++)
			buf[i] = false;
		for (int i = 0; i < 9; i++)
		{
			if (buf[arr[i][col]] == false)
				buf[arr[i][col]] = true;
			else
				return false;
		}
		col++;
	}

	for (int i = 1; i < 10; i++)
		if (buf[i] == false)
			return false;

	return true;

}

bool checkSquares(int rowStart, int columnStart)
{
	bool buf[10];
	for (int i = 1; i < 10; i++)
		buf[i] = false;
	for (int i = rowStart; i < (rowStart + 3); i++)
	{
		for (int j = columnStart; j < (columnStart + 3); j++)
		{
			if (buf[arr[i][j]] == false)
				buf[arr[i][j]] = true;
			else
				return false;
		}
	}
	for (int i = 1; i < 10; i++)
		if (buf[i] == false)
			return false;

	return true;
}

bool cc()
{
	if (checkRows() && checkColumns())
	{
		for (int i = 0; i <9; i += 3)
			for (int j = 0; j < 9; j += 3)
			{
				if (!checkSquares(i, j))
					return false;
			}
	}
	else
		return false;

	return true;

}

bool check(int i, int j)
{
	if (i == 8 && j == 8)
	{
		if (arr[i][j] == 0)
		{
			for (int k = 1; k < 10; k++)
			{
				arr[i][j] = k;
				if (cc())
				{
					return true;
				}
				arr[i][j] = 0;
			}
			return false;
		}
		else
		{
			if (cc())
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (arr[i][j] == 0)
	{
		for (int k = 1; k <= 9; k++)
		{
			arr[i][j] = k;
			if (check(i, j))
				return true;
		}
	}
	else
	{
		int temp2 = j;
		while (j < 8)
		{
			int temp = i;
			while (temp < 9)
			{
				if (check(temp, j+1))
					return true;
				temp++;
			}
			j++;
		}
		while (i < 8)
		{
			int temp = temp2;
			while (temp < 9)
			{
				if (check(i+1, temp))
					return true;
				temp++;
			}
			i++;
		}
	}

	// check row ending

	// check column ending

	// terminate loop and check for correctness if i = 9 and j = 9;
	//cout << " No Sudoku\n";
	return cc();
}

