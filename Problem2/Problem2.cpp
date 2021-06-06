// Факултетен номер: 1901322007	Николай	Костадинов	Лютаков

// 2.3) Генерирайте 4 масива с 11 елемента, които са случайни реални числа в интервала(5, 88].
// Отпечатайте масивите!За всеки масив изведете средно - аритметично на числата, 
// които са по - големи от 55. 
// За всеки масив изведете минималната стойност.
// Изведете максималната стойност от минималните стойности по масиви.
// Отпечатайте сортираните масиви(в нарастващ ред)!

#include <iostream>
#include <time.h>

using namespace std;

// Функция която генерира масив от 11 елемента и го запълва със
// случайни числа в интервала от 5 до 88.
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
// Функция която изпечатва на конзолата генерираните масиви,
// средното аритметично на числата които са по-големи от 55 и минималната стойност
// във всеки масив, също така връща като резултат минималната стойност във всеки масив.
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
		cout << "Средно аритметично: " << aritmetic << endl;
	}
	else 
	{
		cout << "В масива няма числа които са по-големи от 55.";
	}
	cout << "Минимална стойност: " << minValue << endl;
	cout << endl;
	return minValue;

} 

// Функция която сортира масивите в нарастващ ред.
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
// Функция която изпечатва на конзолата сортираните масиви.
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
// Функция която намира и изпечатва на конзолата максималната стойност от
// минималните стойности на всички масиви също така в тялото на тазифункция се извиква
// функцията "arrayPrinter()" която изпечатва генерираните масиви.
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
	cout << "Максималната стойност от минималните е: " << maxOfMinValues << endl;
	cout << endl;

	return 0;
}


int main()
{
	setlocale(LC_ALL, "Bg");

	// Използва се за да се генерират различни случайни числа
	// при всяко пускане на програмата.
	srand(time(NULL));

	// Генериране на масивите.
	int* arr0 = arrayGenerator();
	int* arr1 = arrayGenerator();
	int* arr2 = arrayGenerator();
	int* arr3 = arrayGenerator();

	// Извикване на функцията за изпечатване на масивите и максималната
	// стойност от минималните стойности.
	printMaxOfMinValues(arr0, arr1, arr2, arr3);


	// Извикване на функцията за сортиране на масивите.
	int* sarr0 = arraySorter(arr0);
	int* sarr1 = arraySorter(arr1);
	int* sarr2 = arraySorter(arr2);
	int* sarr3 = arraySorter(arr3);


	// Изпечатване на сортираните масиви.
	cout << "Сортираните масиви са: " << endl;

	sortedArrayPrinter(sarr0);
	sortedArrayPrinter(sarr1);
	sortedArrayPrinter(sarr2);
	sortedArrayPrinter(sarr3);

}


