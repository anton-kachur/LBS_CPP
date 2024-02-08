/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �7
�������� 1
���� ����������� ������: ����'������ ����� ������� �������� �������� �������.
��������: ��������� ����-����� ��������� �� ���������� ���� ����� �\�++ ��� ������� ��� �������� 
������� ��� ����'���� �������������� �������� � ������� 7.1. ��������� ������� ������ ���������
������ ���������� ������� �������.
*/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

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
	
	srand(time(NULL)); 
	
	// �������� 4 ����� ����������: �-��� ����� �������, �-��� ���������, ���� �������, 
	// ���������� ������� �������
	int n = 3 + rand()%5, m = 3 + rand()%5;
	int matrix[n][m];
	int min = 0;
	int i, j;
	
	SetColor(11, 1);
	printf("������� matrix(%d, %d):\n", n, m);
	
	// ����������� �������� ������� �� ������� ��
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) { // ���������� ����� �� ������� ����
			matrix[i][j] = 40 - rand()%50;
			cout << matrix[i][j] << " ";
			
			if (min > matrix[i][j]) min = matrix[i][j]; 
		}
		cout << endl;		
	}
	
	SetColor(0, 2);
	cout << "\n̳��������� �������: " << min << endl;
	
	// �������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}
