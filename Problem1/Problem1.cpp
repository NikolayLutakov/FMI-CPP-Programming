// Факултетен номер: 1901322007	Николай	Костадинов	Лютаков

// 1.1) Вход от конзолата: три равнобедрени триъгълника; всеки се задава 
// чрез дължина на едната страна и височина към нея;
// Изход: периметър и лице за всяка фигура, както и сумата на всички лица.

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


// Функцията прочита входа от конзолата, проверява дали е валиден и 
// записва въведените стойности в променливите предвидени за това.

double inputReader(string selector, int a)
{
	string input;
	double out;
	string tNum = to_string(a);

	cout << "Въведетe " << selector << " на триъгълник " + tNum << endl;
	cin >> input;

	try
	{
		out = stod(input);
	}
	catch (invalid_argument e)
	{
		// Ако входа е невалиден функцията се извиква отново рекурсивно,
		// до въвеждането на валидни стойности.
		cout << "Въведената стойност не е число." << endl;
		out = inputReader(selector, a);
	}

	return out;
}

// Функция която изчислява лицето на триъгълник.

double calculateArea(double s, double h)
{
	double area = (s * h) / 2;
	return area;
}

// Функция която изчислява периметъра на равнобедрен триъгълник,
// по дадена страна и височина към нея.
double calculatePerimeter(double s, double h)
{
	double sideC = sqrt(pow(s / 2, 2) + pow(h, 2));

	double perimeter = 2 * sideC + s;

	return perimeter;
}

int main()
{
	setlocale(LC_ALL, "Bg");

	// Декларация на променливите в които ще се записват данните за триъгълниците.
	double st0, st1, st2, ht0, ht1, ht2, pt0, pt1, pt2, at0, at1, at2, sumArea;
	
	// Извикване на функцията "inputReader()" за изчитане страната и височината
	// на първия триъгълник и записването им в променливи.
	st0 = inputReader("страна", 1);
	ht0 = inputReader("височина", 1);


	// Извикване на функцията "inputReader()" за изчитане страната и височината
	// на втория триъгълник и записването им в променливи.
	st1 = inputReader("страна", 2);
	ht1 = inputReader("височина", 2);

	// Извикване на функцията "inputReader()" за изчитане страната и височината
	// на третия триъгълник и записването им в променливи.
	st2 = inputReader("страна", 3);
	ht2 = inputReader("височина", 3);

	// Извикване на функцията "calculatePerimeter()" за изчисляване периметъра
	// на триъгълниците.
	pt0 = calculatePerimeter(st0, ht0);
	pt1 = calculatePerimeter(st1, ht1);
	pt2 = calculatePerimeter(st2, ht2);

	// Извикване на функцията "calculatePerimeter()" за изчисляване лицето
	// на триъгълниците.
	at0 = calculateArea(st0, ht0);
	at1 = calculateArea(st1, ht1);
	at2 = calculateArea(st2, ht2);

	// Изчисляване сумата от лицата на триъгълниците.
	sumArea = at0 + at1 + at2;

	// Изпечатване информацията на конзолата.
	cout << "Периметъра на триъгълник 1 е : " << pt0 << endl;
	cout << "Лицето на триъгълник 1 е : " << at0 << endl;
	cout << "Периметъра на триъгълник 2 е : " << pt1 << endl;
	cout << "Лицето на триъгълник 2 е : " << at1 << endl;
	cout << "Периметъра на триъгълник 3 е : " << pt2 << endl;
	cout << "Лицето на триъгълник 3 е : " << at2 << endl;
	cout << "Сумата от лицата на триъгълници 1, 2 и 3 е : " << sumArea << endl;
}