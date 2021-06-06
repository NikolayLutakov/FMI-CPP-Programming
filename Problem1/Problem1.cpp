// ���������� �����: 1901322007	�������	����������	�������

// 1.1) ���� �� ���������: ��� ������������ �����������; ����� �� ������ 
// ���� ������� �� ������ ������ � �������� ��� ���;
// �����: ��������� � ���� �� ����� ������, ����� � ������ �� ������ ����.

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


// ��������� ������� ����� �� ���������, ��������� ���� � ������� � 
// ������� ���������� ��������� � ������������ ���������� �� ����.

double inputReader(string selector, int a)
{
	string input;
	double out;
	string tNum = to_string(a);

	cout << "�������e " << selector << " �� ���������� " + tNum << endl;
	cin >> input;

	try
	{
		out = stod(input);
	}
	catch (invalid_argument e)
	{
		// ��� ����� � ��������� ��������� �� ������� ������ ����������,
		// �� ����������� �� ������� ���������.
		cout << "���������� �������� �� � �����." << endl;
		out = inputReader(selector, a);
	}

	return out;
}

// ������� ����� ��������� ������ �� ����������.

double calculateArea(double s, double h)
{
	double area = (s * h) / 2;
	return area;
}

// ������� ����� ��������� ���������� �� ����������� ����������,
// �� ������ ������ � �������� ��� ���.
double calculatePerimeter(double s, double h)
{
	double sideC = sqrt(pow(s / 2, 2) + pow(h, 2));

	double perimeter = 2 * sideC + s;

	return perimeter;
}

int main()
{
	setlocale(LC_ALL, "Bg");

	// ���������� �� ������������ � ����� �� �� �������� ������� �� �������������.
	double st0, st1, st2, ht0, ht1, ht2, pt0, pt1, pt2, at0, at1, at2, sumArea;
	
	// ��������� �� ��������� "inputReader()" �� �������� �������� � ����������
	// �� ������ ���������� � ����������� �� � ����������.
	st0 = inputReader("������", 1);
	ht0 = inputReader("��������", 1);


	// ��������� �� ��������� "inputReader()" �� �������� �������� � ����������
	// �� ������ ���������� � ����������� �� � ����������.
	st1 = inputReader("������", 2);
	ht1 = inputReader("��������", 2);

	// ��������� �� ��������� "inputReader()" �� �������� �������� � ����������
	// �� ������ ���������� � ����������� �� � ����������.
	st2 = inputReader("������", 3);
	ht2 = inputReader("��������", 3);

	// ��������� �� ��������� "calculatePerimeter()" �� ����������� ����������
	// �� �������������.
	pt0 = calculatePerimeter(st0, ht0);
	pt1 = calculatePerimeter(st1, ht1);
	pt2 = calculatePerimeter(st2, ht2);

	// ��������� �� ��������� "calculatePerimeter()" �� ����������� ������
	// �� �������������.
	at0 = calculateArea(st0, ht0);
	at1 = calculateArea(st1, ht1);
	at2 = calculateArea(st2, ht2);

	// ����������� ������ �� ������ �� �������������.
	sumArea = at0 + at1 + at2;

	// ����������� ������������ �� ���������.
	cout << "���������� �� ���������� 1 � : " << pt0 << endl;
	cout << "������ �� ���������� 1 � : " << at0 << endl;
	cout << "���������� �� ���������� 2 � : " << pt1 << endl;
	cout << "������ �� ���������� 2 � : " << at1 << endl;
	cout << "���������� �� ���������� 3 � : " << pt2 << endl;
	cout << "������ �� ���������� 3 � : " << at2 << endl;
	cout << "������ �� ������ �� ����������� 1, 2 � 3 � : " << sumArea << endl;
}