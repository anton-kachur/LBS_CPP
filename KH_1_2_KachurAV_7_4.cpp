/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �7
�������� 4
���� ����������� ������: ����'������ ����� ������� �������� �������� �������.
��������: ��������� ����-����� ��������� �� ���������� ���� ����� �\�++ ��� ������� 
�������� � ���������� ������� ������� �������� �� �������������� �������� � ������� 
7.4. ��������� ������� ������ ���������.
� ������������ ������� ������� ���������� ������� ��������, �� ������ �� �����.
*/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cmath>

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
	// �-��� ��������, �� ������ �� �����
	int n = 3 + rand()%3, m = n;
	int matrix[n][m];
	int amount = 0;
	int i, j;
	
	SetColor(11, 1);
	printf("������� matrix(%d, %d):\n", n, m);
	
	// ����������� �������� ������� �� ������� ��
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) { // ���������� �����
			matrix[i][j] = 40 - rand()%50;
			SetColor(11, (j==n-i-1 ? 4 : 1));
			cout << matrix[i][j] << " ";
		}
		cout << endl;		
	}
	
	// ��������� �-��� ��������, �� ������ �� �����
	for (i = n; i > 0; i--) {
		for (j = n-i; j < m; j++) {
			int len = trunc(log10(matrix[i][j]))+1; // �-��� ���� � ����
			if (len == 2) amount++;	
		}
	}
	
	SetColor(0, 2);
	cout << "ʳ������ ��������, �� ������ �� �����: " << amount << endl;
	
	// �������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}