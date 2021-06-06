// ���������� �����: 1901322007	�������	����������	�������

// 2.3) ����������� 4 ������ � 11 ��������, ����� �� �������� ������ ����� � ���������(5, 88].
// ����������� ��������!�� ����� ����� �������� ������ - ����������� �� �������, 
// ����� �� �� - ������ �� 55. 
// �� ����� ����� �������� ����������� ��������.
// �������� ������������ �������� �� ����������� ��������� �� ������.
// ����������� ����������� ������(� ��������� ���)!

#include <iostream>
#include <time.h>

using namespace std;

// ������� ����� �������� ����� �� 11 �������� � �� ������� ���
// �������� ����� � ��������� �� 5 �� 88.
int* arrayGenerator() 
{
	int* arr = new int[11];

	for (int i = 0; i < 11; i++)
	{
		int rNum = rand() % (88 - 5 + 1) + 5;

		arr[i] = rNum;
	}

	return arr;
}
// ������� ����� ��������� �� ��������� ������������ ������,
// �������� ����������� �� ������� ����� �� ��-������ �� 55 � ����������� ��������
// ��� ����� �����, ���� ���� ����� ���� �������� ����������� �������� ��� ����� �����.
int arrayPrinter(int arr[])
{
	int cnt = 0;
	int sum = 0;
	int minValue = INT_MAX;
	
	for (int i = 0; i < 11; i++)
	{
		if (i <= 9)
		{
			cout << arr[i] << ", ";
		}
		else 
		{
			cout << arr[i];
		}
		
		
		if (arr[i] > 55)
		{
			sum += arr[i];
			cnt++;
		}
		if (arr[i] < minValue)
		{
			minValue = arr[i];
		}
		
	}
	cout << endl;
	if (sum != 0)
	{
		float aritmetic = sum / (float)cnt;
		cout << "������ �����������: " << aritmetic << endl;
	}
	else 
	{
		cout << "� ������ ���� ����� ����� �� ��-������ �� 55.";
	}
	cout << "��������� ��������: " << minValue << endl;
	cout << endl;
	return minValue;

} 

// ������� ����� ������� �������� � ��������� ���.
int* arraySorter(int arr[]) 
{
	int* arrs = new int[11];
	arrs = arr;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - i; j++)
		{
			if (arrs[j] > arrs[j + 1])
			{
				int temp = arrs[j];
				arrs[j] = arrs[j + 1];
				arrs[j + 1] = temp;
			}
		}
	}
	return arr;
}
// ������� ����� ��������� �� ��������� ����������� ������.
int sortedArrayPrinter(int arr[])
{
	for (int i = 0; i < 11; i++)
	{
		if (i <= 9)
		{
			cout << arr[i] << ", ";
		}
		else
		{
			cout << arr[i];
		}

	}
	cout << endl;
	return 0;
}
// ������� ����� ������ � ��������� �� ��������� ������������ �������� ��
// ����������� ��������� �� ������ ������ ���� ���� � ������ �� ����������� �� �������
// ��������� "arrayPrinter()" ����� ��������� ������������ ������.
int printMaxOfMinValues(int a[], int b[], int c[], int d[]) 
{

	int minValuesArr[4];

	minValuesArr[0] = arrayPrinter(a);
	minValuesArr[1] = arrayPrinter(b);
	minValuesArr[2] = arrayPrinter(c);
	minValuesArr[3] = arrayPrinter(d);

	int maxOfMinValues = INT_MIN;
	for (int i = 0; i < 4; i++)
	{
		if (minValuesArr[i] > maxOfMinValues)
		{
			maxOfMinValues = minValuesArr[i];
		}
	}
	cout << "������������ �������� �� ����������� �: " << maxOfMinValues << endl;
	cout << endl;

	return 0;
}


int main()
{
	setlocale(LC_ALL, "Bg");

	// �������� �� �� �� �� ��������� �������� �������� �����
	// ��� ����� ������� �� ����������.
	srand(time(NULL));

	// ���������� �� ��������.
	int* arr0 = arrayGenerator();
	int* arr1 = arrayGenerator();
	int* arr2 = arrayGenerator();
	int* arr3 = arrayGenerator();

	// ��������� �� ��������� �� ����������� �� �������� � ������������
	// �������� �� ����������� ���������.
	printMaxOfMinValues(arr0, arr1, arr2, arr3);


	// ��������� �� ��������� �� ��������� �� ��������.
	int* sarr0 = arraySorter(arr0);
	int* sarr1 = arraySorter(arr1);
	int* sarr2 = arraySorter(arr2);
	int* sarr3 = arraySorter(arr3);


	// ����������� �� ����������� ������.
	cout << "����������� ������ ��: " << endl;

	sortedArrayPrinter(sarr0);
	sortedArrayPrinter(sarr1);
	sortedArrayPrinter(sarr2);
	sortedArrayPrinter(sarr3);

}


