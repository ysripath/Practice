#include <iostream>

using namespace std;


int main()
{
	int a[2] = {1,2};
	int* b = a;

	int** c = &b;
	*b++;
	cout<<a<<"\t"<<&b<<"\t"<<**c<<endl;
	return 0;
}
