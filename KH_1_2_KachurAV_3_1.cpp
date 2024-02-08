/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �3
�������� 1
���� ����������� ������: ����'������ ����� � ������������� ����� � ����������.
��������: ��������� �������� ��� ��������� ��� �� �������, �������� �� �������������� ��������, 
�� �������� � ������� 3.1, �� ���������� ���� ����� �\�++ � ������������� ����� � ���������� FOR. 
�������� ��������� �� ������ ��� ��������� ��� �� ������� �������� � ���������. 
��������� ������� ������ ���������.
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;

// �������, ���������� ��� ���� ������� ������. 
// � ����� ��������� ����������� ������ �������� ������� ������ � ���
void SetColor(int text, int background) {
	// �����, ��� ������� ���������� ������ ������ ������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��������� ������� ������� ������, ���� ���������� � �������
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int main() {
	system("cls"); // ��������� ������� ������� ������
	// �������� �� ������� ���������� ��� ����������� �������� � 
	// ����������� ����
	// ������������ ������ ������� win-cp 1251 ��� ������ ��������
	SetConsoleCP(1251); 
	// ������������ ������ ������� win-cp 1251 �� ������ ���������
	SetConsoleOutputCP(1251);
	
	/* ���������� ��� ��� ����'���� ������������ �������� */
	
	double i, j, start_i, end_i, start_j, end_j, f, s = 0.0;
	
	SetColor(11, 1);
	cout << "������ ��������� �������� �: ";
	cin >> start_i;
	cout << "B����� ������ �������� �: ";
	cin >> end_i;
	cout << "������ ��������� �������� j: ";
	cin >> start_j;
	cout << "B����� ������ �������� j: ";
	cin >> end_j;
	
	for (i = end_i; i >= start_i; i--) {
		f = 1.0; // ����������� ����� ��� ���������� ��������
		
		for (j = end_j; j >= start_j; j--) {
			f *= (2.0 * i) / powf(j, 2.0);
		}
		s += powf(f, i);

		cout << "s = " << s << endl;
	}
	
	SetColor(0, 4);
	printf("S = %10.5f\n", s);
	
	// �������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}