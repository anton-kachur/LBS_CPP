/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �8
�������� 2
���� ����������� ������: ���������� ����� ������� ���������� �����.
��������: ��������� ����-����� ��������� �� ���������� ���� ����� �\�++ ��� ������� ����� ��� ����������� �����, �� ��������� � 
������������� ���� ����� string, � ���������� �� �������������� �������� �������� � ������� 8.2. ��������� ������� ������ ���������.

� �������� ����������� ����� ��� ������� ����� ��������� �� ���� 5-� ������ � ����� �����, �� ������� ���� �� ������ �5�. � ������ 
������� �������� ����� ��� ����.
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

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
	// �������� �� ������� ���������� ��� ����������� �������� � ����������� ����
	SetConsoleCP(1251); // ������������ ������ ������� win-cp 1251 ��� ������ ��������
	SetConsoleOutputCP(1251); // ������������ ������ ������� win-cp 1251 �� ������ ���������
	
	/* ���������� ��� ��� ����'���� ������������ �������� */
	string str;	
	string word;
	vector<string> words;
	int i;
	
	SetColor(11, 1);
	cout << "������ �������: ";
	getline(cin, str); // ������� ���������� ����� (� ��������)
	
	istringstream iss(str); // �������� ���������� ����� � ����

    while (iss >> word) // ������� ����� � ������
        words.push_back(word); // �������� ����� � ������, ���������� ����������
	
	SetColor(0, 2);
	for(i = 0; i < words.size(); i++) {
		word = words.at(i); // ����������� �� ������ �� ���������� �� �� ��������� ����� �� 5-� �������
		if (word.length() >= 4 && !isalpha(word[4]) && !ispunct(word[4])) word[4] = '5';
		cout << word << " "; 
	}
    
	// �������� 3 ����� ������������ ������������ ����������� ������� ������ � ��� ��
	// ������������ ������ ��������
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}