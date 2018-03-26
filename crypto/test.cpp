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
		getline(f, line);

		char* buf = (char*)line.c_str();
		cout<<buf<<endl;
	}



	return 0;
}
