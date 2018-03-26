#include <iostream>
#include <fstream>


using namespace std;


int main()
{

	ifstream f;
	string fileName;
	cin>>fileName;
	f.open(fileName, ios::in);
	if (f.is_open())
	{
		string line;
		while (getline(f, line))
		{
			if (line.length() == 0)
				cout<<"Empty line\n";
			else 
				cout<<line<<endl;
		}	
	}
	return 0;
}
