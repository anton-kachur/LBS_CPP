/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �3
�������� 2
���� ����������� ������: ����'������ ����� � ������������� ����� � ����������.
��������: ��������� �������� ��� ����������� �������, �� �������� � ������� 3.2, �������� �� �������������� 
�������� �� �������� � ��������� ��������� ������� [xstart�xend] �� ������ xstep, �� ���������� ���� ����� 
�\�++ � ������������� ����� � ���������� FOR. ��������� ������� � ������ ������� �� ������ ���������.
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

// �������, ���������� ��� ���� ������� ������. 
// � ����� ��������� ����������� ������ �������� ������� ������ � ���
void SetColor(int text, int background) {
	// �����, ��� ������� ���������� ������ ������ ������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��������� ������� ������� ������, ���� ���������� � �������
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void dashes(int val) {
	for (int i = 0; i < val; i++)
		cout << "-";
		
	cout << endl;
}


int main() {
	system("cls"); // ��������� ������� ������� ������
	// ������� �� ������� ���������� ��� ����������� �������� � 
	// ����������� ���
	// ������������ ������ ������� win-cp 1251 ��� ������ ��������
	SetConsoleCP(1251); 
	// ������������ ������ ������� win-cp 1251 �� ������ ���������
	SetConsoleOutputCP(1251);
	
	/* ���������� ��� ��� ����'���� ������������ �������� */
	
	double x, y, xstart, xend, xstep;
	
	SetColor(11, 1);
	cout << "������ ��������� �������� x: ";
	cin >> xstart;
	cout << "B����� ������ �������� x: ";
	cin >> xend;
	cout << "������ ���� x: ";
	cin >> xstep;
	
	// �������� �������
	SetColor(15, 8);
	
	
	dashes(26);
	cout << setw(8);
	cout << "x "; 
	cout << "|";
	cout << setw(16);
	cout << "y "; 
	cout << "|";
	cout << endl;
	dashes(26);
	
	for (x = xstart; x <= xend; x+=xstep) {
		y = exp(2.0*x) * sin(powf(x, 2.0));
		
		cout << setprecision(4) << setw(7) << fixed;
		cout << x << " | ";
		cout << setw(14);
		cout << y << " |" << endl;
	}
	
	// ������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}
