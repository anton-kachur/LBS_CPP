/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �6
�������� 3
���� ����������� ������: ���������� ����� ������� �������� ����������� �������� ������.
��������: ��������� ����-����� ��������� �� ���������� ���� ����� �\�++ ��� ������ ������������� 
������� �������� ������������ ������ �������� �� �������������� �������� � ������� 6.3. 
�������� ������� �������� ������ �������� � ���������. �������� �������� ������ ������ � 
���������. ������� �������� �������� ������ �� �������� ������������ �������� �� �����, ���� 
������� ������. � �������, ���� ������������� ������� �������, ��������� ���������� �� �������. 
��������� ������� ������ ���������.
������ �� ������� ���������� ������� �� ���� ������ � �������� �����.
*/

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
	int n, i;
	
	SetColor(11, 1);
	cout << "������ ������� �������� ������: ";
	cin >> n;
	
	int arr[n];
	
	SetColor(15, 9);
	cout << "������ �������� ������:" << endl;
	for (i = 0; i < n; i++) { // ������� �������� �������� ������
		cout << i+1 << ") ";
		cin >> arr[i];
	}
	
	// �������� 3 ����� ����������: ���������� ������� ������, ���� ��� ���� ����������, 
	// ���� ������������� �������� (�������, ���� �� ����� 1),
	// ������ ����������� ��������
	int min = arr[0];
	int min_sum = 0;
	int min_index;
	
	// ������� �������� ������, ���������� ��������� ���������� �������, ������ ����� �������� 
	// �� ������� ���� �������� � �����
	SetColor(0, 2);
	cout << "������� �����: ";
	for (i = 0; i < n; i++) { 
		cout << arr[i] << " ";
		if (arr[i] < min) {
			min = arr[i];
			min_index = i; 
			min_sum = 0;
		}
			
		if (arr[i] == min) 
			min_sum++;
	}
	
	cout << "\nMin: " << min << ", index = " << min_index << endl;
	if (min_sum > 1) // ���� ���������� ������� ����������� ������� ����, �������� �-��� ��� ����
		cout << "Min sum: " << min_sum << endl;
	
	// �������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}
