/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �7
�������� 2
���� ����������� ������: ����'������ ����� ������� �������� �������� �������.
��������: ��������� ����-����� ��������� �� ���������� ���� ����� �\�++ ��� ������ � ���������� 
������� �������� �� �������������� �������� � ������� 7.2. ��������� ������� ������ ���������. 
� �������� ����������� ����� ���������� ���� ��� ��'����� ��������.
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
	 
	// �������� 5 ������ ����������: �-��� ���������� ������ � ����������� �����, �-��� ����� 
	// ����������� ������, �-���� ��������� ����������� ������, ���������� �����, ���� ���� ��'����� ��������
	int n = 1 + rand()%3, m = 3 + rand()%5, l = 3 + rand()%5;
	int mas[n][m][l];
	int neg_sum = 0;
	int i, j, k;
	
	SetColor(11, 1);
	printf("���������� ����� mas(%d, %d, %d):\n", n, m, l);
	
	// ����������� �������� ����������� ������ �� ������� ��
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) { // ���������� ���������� �����
			for (k = 0; k < l; k++) { // ���������� ����� ����������� ������ �� ������� ����
				mas[i][j][k] = 40 - rand()%50;
				cout << mas[i][j][k] << " ";
				
				if (mas[i][j][k] < 0) neg_sum += mas[i][j][k]; 
			}
			cout << endl;			
		}	
		cout << "\n";	
	}
	
	SetColor(0, 2);
	cout << "\n���� ��'����� ��������: " << neg_sum << endl;
	
	// �������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}
