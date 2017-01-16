#include <iostream>


using namespace std;


bool checkRows(int** arr)
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

bool checkColumns(int** arr)
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

bool checkSquares(int** arr, int rowStart, int columnStart)
{
	bool buf[10];
	for (int i = 1; i < 10; i++)
		buf[i] = false; 
	for (int i = rowStart; i < (rowStart+3); i++)
	{
		for (int j = columnStart; j < (columnStart+3); j++)
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

bool check(int** arr)
{
	if (checkRows(arr) && checkColumns(arr))
	{	
		for (int i = 0; i <9; i+=3)
			for (int j = 0; j < 9; j+=3)
			{
				if(!checkSquares(arr,i,j))
					return false;
			}
	}
	else
		return false;

	return true;

}

int main()
{
	cout<<"Enter the sudoko matrix\n";
	int** arr = new int*[9];
	for (int i = 0; i < 9; i++)
		arr[i] = new int[9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin>>arr[i][j];

	if (check(arr))
		cout<<"Sudoko!!"<<endl;

	else
		cout<<"NOt sudoko\n";
	return 0;
}
