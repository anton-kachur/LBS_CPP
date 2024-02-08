/*
�����: KH�1-2
��������: ����� ����� ³��������
����������� ������ �9
�������� 1
���� ����������� ������: ����'������ ����� � ������������� ��������.
��������: ���������� ������ � ����������� ����� �\�++ �������� �� �������������� ��������, �� �������� � ������� 9.1. 
�����������: ��������� ����� ������ � �����; ��������� ��� �������� ������ � ������ �������; ��� ������� ������ 
����������� ��������� 1 ����� �� ������ ������; ������ �� ����� 10 ������.
*/

#include <iostream>
#include <cmath>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>

using namespace std;

// �������, ���������� ��� ������������ int � string 
string toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

// �������, ���������� ��� ���� ������� ������. 
// � ����� ��������� ����������� ������ �������� ������� ������ � ���
void SetColor(int text, int background) {
	// �����, ��� ������� ���������� ������ ������ ������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��������� ������� ������� ������, ���� ���������� � �������
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// ���������� ��������� ����
struct mobilePhone {
	string firm;
	string model; 
	int year;
	int numberOfCameras;
	double diagonal;	
};

// ����� ���� �������� �������� ��� ��������� ���������� ��������
const char* firms[8] = {"iOS", "Huawei", "Motorola", "Samsung", "LG", "Nokia", "Meizu", "Xiaomi"};

int main() {
	system("cls"); // ��������� ������� ������� ������
	// ������� �� ������� ���������� ��� ����������� �������� � ����������� ���
	SetConsoleCP(1251); // ������������ ������ ������� win-cp 1251 ��� ������ ��������
	SetConsoleOutputCP(1251); // ������������ ������ ������� win-cp 1251 �� ������ ���������
	
	/* ���������� ��� ��� ����'���� ������������ �������� */
	
	int choice;
	int n = 100; // ������� ������ ������ �������� ��������
	int i = 0; // ������, �� ������� ����� ����� ������ � ����� ������ �������� ��������
	mobilePhone mobilePhones[n]; // ���������� ������ ������ �������� ��������
	bool mark = false; // ��������� ����, �� �����(��/�) �����(�) �������� 
	
	tryAgain: // goto-���� ��� ������ 䳿
		SetColor(11, 1);
		cout << "<******** ������� ���� *********>" << endl;
		cout << "1) ������ ����� �������� �������" << endl;
		cout << "2) ����������� ������ ���������  " << endl;
		cout << "3) ��������� ��� ������        " << endl;
		cout << "4) ����� �� ������               " << endl;
		cout << "5) ����� �� �������              " << endl;
		cout << "6) ����� �� ����� �������        " << endl;
		cout << "7) ����� �� ������ ������       " << endl;
		cout << "8) ����� ��������                " << endl;
		cout << "<===============================>" << endl;
		cout << "������� ��: ";
		cin >> choice;
		
		switch(choice) {
			case 1: // ��������� ������ ������
				SetColor(0, 7);
				cout << "��������� ������ �" << i << endl;
				cout << "������ �����: ";
				cin >> mobilePhones[i].firm;
				cout << "������ ������: ";
				cin >> mobilePhones[i].model;
				cout << "������ �� �������: ";
				cin >> mobilePhones[i].year;
				cout << "������ ������� �����: ";
				cin >> mobilePhones[i].numberOfCameras;
				cout << "������ ��������: ";
				cin >> mobilePhones[i].diagonal;
				i++;
				
				SetColor(7, 0);
				goto tryAgain;
			
			case 2: // ��������� ���������� ������
				srand(time(NULL)); 
				
				int numOfRandom;
				cout << "������ ������� ���������� ��������: ";
				cin >> numOfRandom;
				
				for (int k = i; k < i+numOfRandom; k++) {
					mobilePhones[k].firm = firms[0 + rand()%8];
					mobilePhones[k].model = toString(1 + rand()%numOfRandom) + toString(0 + rand()%numOfRandom) + toString(0 + rand()%numOfRandom);
					mobilePhones[k].year = 1973 + rand()%50;
					mobilePhones[k].numberOfCameras = 1 + rand()%5;
					mobilePhones[k].diagonal = 2.8 + 2.7 * (rand() % 1000000L) / 1000000L;	
				}
				
				i += numOfRandom;
				
				SetColor(7, 0);
				goto tryAgain;
			
			case 3: // ��������� ��� ������� ������
				if (i == 0) {
					SetColor(0, 4);
					cout << "������ ���� :(" << endl; 
				} else {
					SetColor(0, 8);
					cout << "-------------------------------------------------------------------" << endl;
					cout << "                     ����� ������ ��������                     |" << endl;
					cout << "-------------------------------------------------------------------" << endl;
                    cout << " Գ���" << setw(8) << "|"
                         << " ������" << setw(5) << "|"
                         << " г�" << setw(9) << "|"
                         << " ������" << setw(6) << "|"
                         << " ĳ�������" << setw(5) << "|" << endl;
                    cout << "-------------------------------------------------------------------" << endl;

                    for (int k = 0; k < i; k++) { // ������� �������
						cout << k << ")" << mobilePhones[k].firm << setw(12 - mobilePhones[k].firm.size()) << "|"
                             << mobilePhones[k].model << setw(12 - mobilePhones[k].model.size()) << "|"
                             << mobilePhones[k].year << setw(12 - trunc(log10(mobilePhones[k].year))) << "|"
						     << mobilePhones[k].numberOfCameras << setw(12 - trunc(log10(mobilePhones[k].numberOfCameras))) << "|"
                             << setprecision(2) << mobilePhones[k].diagonal << setw(12 - trunc(log10(int(mobilePhones[k].diagonal)))) << "|" << endl;
					}
                    cout << "-------------------------------------------------------------------" << endl;
				}
				
				SetColor(7, 0);
				goto tryAgain;
			
			case 4: // ����� �� ������
				firmSearch: // goto-���� ��� ������ �� ������
					if (i == 0) {
						SetColor(0, 4);
						cout << "������ ���� :(" << endl; 
					} else {
						SetColor(0, 7);
						string firm;
						cout << "������ ����� ��������: ";
						cin >> firm;
						
						for (int k = 0; k < i; k++) {
							if (mobilePhones[k].firm == firm) {
								mark = true;
								SetColor(0, 8);
								cout << "\nԳ���: " << mobilePhones[k].firm << "\n������: " << mobilePhones[k].model << endl;
								cout << "г� �������: " << mobilePhones[k].year << "\nʳ������ �����: " << mobilePhones[k].numberOfCameras << endl;
								cout << "ĳ�������: " << mobilePhones[k].diagonal << "\n\n";
							}
						}
						
						if (!mark) {
							SetColor(0, 4);
							cout << "������, ����� �� �������� :(" << endl; 
						}
					}
					
					SetColor(7, 0);
					mark = true;
					goto tryAgain;
				
			case 5: // ����� �� �������
				modelSearch: // goto-���� ��� ������ �� �������
					if (i == 0) {
						SetColor(0, 4);
						cout << "������ ���� :(" << endl; 
					} else {
						SetColor(0, 7);
						string model;
						cout << "������ ������ ��������: ";
						cin >> model;
						
						for (int k = 0; k < i; k++) {
							if (mobilePhones[k].model == model) {
								mark = true;
								SetColor(0, 8);
								cout << "\n������: " << mobilePhones[k].model << "\nԳ���: " << mobilePhones[k].firm << endl;
								cout << "г� �������: " << mobilePhones[k].year << "\nʳ������ �����: " << mobilePhones[k].numberOfCameras << endl;
								cout << "ĳ�������: " << mobilePhones[k].diagonal << "\n\n";
							}
						}
						
						if (!mark) {
							SetColor(0, 4);
							cout << "������, ����� �� �������� :(" << endl; 
						}
					}
					
					SetColor(7, 0);
					mark = true;
					goto tryAgain;
				
			case 6: // ����� �� ����� �������
				yearSearch: // goto-���� ��� ������ �� ����� �������
					if (i == 0) {
						SetColor(0, 4);
						cout << "������ ���� :(" << endl; 
					} else {
						SetColor(0, 7);
						int year;
						cout << "������ �� �������: ";
						cin >> year;
						
						for (int k = 0; k < i; k++) {
							if (mobilePhones[k].year == year) {
								mark = true;
								SetColor(0, 8);
								cout << "\nг� �������: " << mobilePhones[k].year << "\nԳ���: " << mobilePhones[k].firm << endl;
								cout << "������: " << mobilePhones[k].model << "\nʳ������ �����: " << mobilePhones[k].numberOfCameras << endl;
								cout << "ĳ�������: " << mobilePhones[k].diagonal << "\n\n";
							}
						}
						
						if (!mark) {
							SetColor(0, 4);
							cout << "������, ����� �� �������� :(" << endl; 
						}
					}
					
					SetColor(7, 0);
					mark = true;
					goto tryAgain;
				
			case 7: // ����� �� ������ ������
				if (i == 0) {
					SetColor(0, 4);
					cout << "������ ���� :(" << endl; 
				} else {
					chooseCriteria: // goto-���� ��� ������ ������� ������
						SetColor(0, 7);
						int criteria;
						cout << "---------------------------------" << endl;
						cout << "1) Գ���                         " << endl;
						cout << "2) ������                        " << endl;
						cout << "3) г� �������                   " << endl;
						cout << "4) ʳ������ �����               " << endl;
						cout << "5) ĳ�������                     " << endl;
						cout << "---------------------------------" << endl;
						cout << "������� ������� ������: ";
						cin >> criteria;
						
						switch (criteria) {
							case 1: goto firmSearch;
							case 2: goto modelSearch;
							case 3: goto yearSearch;
							case 4: 
								int numberOfCameras;
								cout << "������ ������� �����: ";
								cin >> numberOfCameras;
						
								for (int k = 0; k < i; k++) {
									if (mobilePhones[k].numberOfCameras == numberOfCameras) {
										mark = true;
										SetColor(0, 8);
										cout << "\nʳ������ �����: " << mobilePhones[k].numberOfCameras << "\nԳ���: " << mobilePhones[k].firm << endl;
										cout << "������: " << mobilePhones[k].model << "\nг� �������: " << mobilePhones[k].year << endl;
										cout << "ĳ�������: " << mobilePhones[k].diagonal << "\n\n";
									}
								}
								break;
								
							case 5:
								double diagonal;
								cout << "������ ��������: ";
								cin >> diagonal;
								
								for (int k = 0; k < i; k++) {
									if (mobilePhones[k].diagonal == diagonal) {
										mark = true;
										SetColor(0, 8);
										cout << "\nĳ�������: " << mobilePhones[k].diagonal << "\nԳ���: " << mobilePhones[k].firm << endl;
										cout << "������: " << mobilePhones[k].model << "\nг� �������: " << mobilePhones[k].year << endl;
										cout << "ʳ������ �����: " << mobilePhones[k].numberOfCameras << "\n\n";
									}
								}
								break;
								
							default:
								SetColor(0, 4);
								cout << "������������ ����! ��������� �� ���!";
								goto chooseCriteria;
						}
					
						if (!mark) {
							SetColor(0, 4);
							cout << "������, ����� �� �������� :(" << endl; 
						}
				}
				
				SetColor(7, 0);
				mark = true;
				goto tryAgain;
				
			case 8: // ����� � ��������
				SetColor(7, 0);
				exit(0);
			
			default: // ���������� �� �������� 䳿
				SetColor(0, 4);
				cout << "������������ ����! ��������� �� ���!";
				goto tryAgain;
		}
	
	return 0;
}
