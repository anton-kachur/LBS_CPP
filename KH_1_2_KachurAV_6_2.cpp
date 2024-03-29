/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �6
�������� 2
���� ����������� ������: ���������� ����� ������� �������� ����������� �������� ������.
��������: ��������� ����-����� ��������� �� ���������� ���� ����� �\�++ ��� ���������� 
�������� ������ ������������ ������ �� �������� �������� ������������ ������ �������� 
�� �������������� ��������, �������� � ������� 6.2. ��������� ������� ������ ���������.
���������� ����� ����� � �������� �������� ������, �� ������ ����.
*/

#include <time.h>
#include <stdlib.h>
#include <iostream>
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
	
	// srand - �������, ���������� ��� ������������ ��������� �����, � ��� ���������� 
	// ��������� ���������� �����. ��� ������� ������� time() � ���������� NULL, 
	// ����������� �-��� ��������, �� ������� � 1 ���� 1970 ���� �� �������, ���� 
	// ���������� �������� ��������
	srand(time(NULL));
	
	// ������ 2 ����� ���������� �-��� �������� ������, ������� � ����� �����
	int n = 5 + rand()%15;
	int arr[n], arr1[n];
	int i;
	
	SetColor(11, 1);
	cout << "������� �����: ";
	
	// ������� ������� �����, ���������� ������������ ���� �������� �� �������� ������ ������
	for (i = 0; i < n; i++) {  
		arr[i] = 0 + rand()%50;
		arr1[i] = -1;
		cout << arr[i] << " ";
		
		// ����������� ����� ����� ���������� � �������� ������, �� ������ 5
		if (arr[i] % 5 == 0) arr1[i] = arr[i];	
	}
	
	SetColor(0, 2);
	cout << "\n����� �����: ";
	
	for (i = 0; i < n; i++)  // ������� ����� �����
		if (arr1[i] >= 0)
			cout << arr1[i] << " ";
	
	// �������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}
