/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �1
�������� 1
���� ����������� ������: ����'������ ����� ����� ���������.
��������: ��������� �������� ����� �\�++ ��� ����������� �������� ���������� 
�������� ������� �������������� ��������, �� �������� � ������� 1.1. 
��� ����� �������� ���������� ����������� ��� �������. ���������� �� 
���� � ���� ���������� ���������. ����� ���������� �� ����� 10 �� 10 �������.
*/

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

// �������, ���������� ��� ���������� ������� ������� �� ����� �� ������������ x, y
void gotoxy(int x, int y) {
	// �����, ��� ������� ���� ������� ������� �� ����� ������
	COORD coordinates;
	// �����, ��� ������� ���������� ������ ������ ������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x; coordinates.Y = y;
	// ������� ������� ������� �� �����
	SetConsoleCursorPosition(hStdOut, coordinates);
}

int main() {
	system("cls"); // ��������� ������� ������� ������
	// ������� �� ������� ���������� ��� ����������� �������� � 
	// ����������� ���
	// ������������ ������ ������� win-cp 1251 ��� ������ ��������
	SetConsoleCP(1251); 
	// ������������ ������ ������� win-cp 1251 �� ������ ���������
	SetConsoleOutputCP(1251);
	// ���� ������� ��� � ������ �� ����� ������ (��� �������� - ������ � ����)
	system("color 07"); 
	
	/*���������� ��� ��� ����'���� ������������ ��������*/
	
	// ������� �� ���� ���������� �������� ���������� ������� �� �����
	int x=2;
	int y=2;
	
	// ��������� ����� �����
	SetColor(8, 8);
	gotoxy(x+1, y);
	cout<<"====";
	gotoxy(x, y+1);
	cout<<"=";
	gotoxy(x+5, y+1);
	cout<<"=";
	gotoxy(x, y+2);
	cout<<"=";
	SetColor(8, 0);
	gotoxy(x+2, y+2);
	cout<<"()";
	SetColor(8, 8);
	gotoxy(x+5, y+2);
	cout<<"=";
	gotoxy(x, y+3);
	cout<<"=";
	gotoxy(x+5, y+3);
	cout<<"=";
	gotoxy(x+1, y+4);
	cout<<"====";
	
	// ��������� ������ �����
	SetColor(8, 8);
	gotoxy(x+16, y+1);
	cout<<"=============================";
	gotoxy(x+30, y+2);
	cout<<"H";
	
	// ��������� �������� �������
	SetColor(2, 0);
	gotoxy(x+6, y+4);
	cout<<"\\";
	gotoxy(x+7, y+4);
	cout<<"_____________";
	SetColor(2, 0);
	gotoxy(x+4, y+5);
	cout<<"\\";
	SetColor(2, 2);
	gotoxy(x+5, y+5);
	cout<<"_______________";
	SetColor(2, 0);	
	gotoxy(x+20, y+6);
	cout<<"\\";
	gotoxy(x+20, y+4);
	cout<<"/";
	
	// ��������� ������ ����
	SetColor(3, 0);	
	gotoxy(x+40, y+4);
	cout<<"\\";
	gotoxy(x+41, y+5);
	cout<<"\\";
	gotoxy(x+34, y+4);
	cout<<"| | |";
	gotoxy(x+34, y+5);
	cout<<"| | | |\\";
	
	// ��������� �����
	SetColor(2, 0);
	gotoxy(x+21, y+3);
	cout<<"________//";
	gotoxy(x+31, y+3);
	cout<<"\\________";
	SetColor(2, 2);
	gotoxy(x+30, y+3);
	cout<<"H";
	gotoxy(x+21, y+4);
	cout<<"=============";
	SetColor(2, 2);
	gotoxy(x+20, y+5);
	cout<<"==============";
	gotoxy(x+21, y+6);
	cout<<"======================";
	SetColor(2, 0);	
	gotoxy(x+43, y+6);
	cout<<"\\";
	gotoxy(x+21, y+7);
	cout<<"\\";
	SetColor(2, 2);
	gotoxy(x+22, y+7);
	cout<<"======================";
	
	// ��������� ����
	SetColor(8, 0);
	gotoxy(x+22, y+8);
	cout<<"  //               \\";
	gotoxy(x+23, y+9);
	cout<<"��                 �";
	
	// ������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0); 
	cout << "\n\n\n";
	system("pause");
	
	return 0;
}
