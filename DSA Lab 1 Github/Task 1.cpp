#include<iostream>
using namespace std;
int main()
{
	int arr[5];
	cout << "Enter the five numbers in array: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	cout << "The numbers in array are: ";
	for (int i = 0;i < 5;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0;i < 5 - 1;i++)
	{
		for (int j = 0;j < 5 - i - 1;j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Array after sorting is:";
	for (int i = 0;i < 5;i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}