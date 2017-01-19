#include <iostream>

using namespace std;


void sort(int* arr, int N)
{
	int aArr[10];
	for (int i = 0; i < 10; i++)
		aArr[i] = 0;

	for (int i = 1; i <= N; i++)
		aArr[arr[i]]++;

	for (int i = 1; i < 10; i++)
		aArr[i] += aArr[i - 1];

	int* cArr = new int[N];
	for (int j = N; j >= 1; j--)
	{
 		cArr[aArr[arr[j]]] = arr[j];
		aArr[arr[j]]--;
	}
	cout << endl;
	for (int i = 1; i <= N; i++)
		cout << cArr[i] << " ";
}

int main()
{
	cout << "Enter the number of items\n";
	int N;
	cin >> N;
	cout << "Enter the SINGLE DIGIT items to be sorted\n";
	int* arr = new int[N+1];
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	sort(arr, N);
	return 0;
}