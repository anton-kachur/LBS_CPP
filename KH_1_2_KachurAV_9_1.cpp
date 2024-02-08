/*
Група: KH–1-2
Здобувач: Качур Антон Вікторович
Лабораторна робота №9
Завдання 1
Тема лабораторної роботи: Розв'язання задач з використанням структур.
Завдання: Реалізувати роботу зі структурами мовою С\С++ відповідно до індивідуального завдання, що наведено у таблиці 9.1. 
Забезпечити: додавання нових записів у масив; виведення усіх елементів масиву у вигляді таблиці; крім заданих пошуків 
забезпечити додатково 1 пошук за різними полями; ввести не менше 10 записів.
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

// Функція, призначена для перетворення int в string 
string toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

// Функція, призначена для зміни кольору виводу. 
// В якості аргументів передаються числові значення кольорів тексту і тла
void SetColor(int text, int background) {
	// змінна, яка позначає дескриптор екрану консолі виводу
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// присвоєння значень кольорів тексту, який виводиться в консоль
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// оголошення структури книг
struct mobilePhone {
	string firm;
	string model; 
	int year;
	int numberOfCameras;
	double diagonal;	
};

// масив фірм мобільних телефонів для генерації випадкових елементів
const char* firms[8] = {"iOS", "Huawei", "Motorola", "Samsung", "LG", "Nokia", "Meizu", "Xiaomi"};

int main() {
	system("cls"); // викликаємо функцію очистку екрану
	// наступні дві команди призначено для відображення кирилиці у консольному вікні
	SetConsoleCP(1251); // встановлення кодової сторінки win-cp 1251 для потоку введення
	SetConsoleOutputCP(1251); // встановлення кодової сторінки win-cp 1251 до потоку виведення
	
	/* Програмний код для розв'язку поставленого завдання */
	
	int choice;
	int n = 100; // довжина масиву записів мобільних телефонів
	int i = 0; // індекс, що позначає першу вільну комірку в масиві записів мобільних телефонів
	mobilePhone mobilePhones[n]; // оголошення масиву записів мобільних телефонів
	bool mark = false; // індикатор того, що шукан(ий/і) запис(и) знайдено 
	
	tryAgain: // goto-мітка для вибору дії
		SetColor(11, 1);
		cout << "<******** Головне меню *********>" << endl;
		cout << "1) Додати новий мобільний телефон" << endl;
		cout << "2) Згенерувати список випадково  " << endl;
		cout << "3) Виведення усіх записів        " << endl;
		cout << "4) Пошук за фірмою               " << endl;
		cout << "5) Пошук за моделлю              " << endl;
		cout << "6) Пошук за роком випуску        " << endl;
		cout << "7) Пошук за різними полями       " << endl;
		cout << "8) Вийти погуляти                " << endl;
		cout << "<===============================>" << endl;
		cout << "Виберіть дію: ";
		cin >> choice;
		
		switch(choice) {
			case 1: // створення нового запису
				SetColor(0, 7);
				cout << "Створення запису №" << i << endl;
				cout << "Введіть фірму: ";
				cin >> mobilePhones[i].firm;
				cout << "Введіть модель: ";
				cin >> mobilePhones[i].model;
				cout << "Введіть рік випуску: ";
				cin >> mobilePhones[i].year;
				cout << "Введіть кількість камер: ";
				cin >> mobilePhones[i].numberOfCameras;
				cout << "Введіть діагональ: ";
				cin >> mobilePhones[i].diagonal;
				i++;
				
				SetColor(7, 0);
				goto tryAgain;
			
			case 2: // генерація випадкових записів
				srand(time(NULL)); 
				
				int numOfRandom;
				cout << "Введіть кількість випадкових елементів: ";
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
			
			case 3: // виведення усіх наявних записів
				if (i == 0) {
					SetColor(0, 4);
					cout << "Записів немає :(" << endl; 
				} else {
					SetColor(0, 8);
					cout << "-------------------------------------------------------------------" << endl;
					cout << "                     Наявні мобільні телефони                     |" << endl;
					cout << "-------------------------------------------------------------------" << endl;
                    cout << " Фірма" << setw(8) << "|"
                         << " Модель" << setw(5) << "|"
                         << " Рік" << setw(9) << "|"
                         << " Камери" << setw(6) << "|"
                         << " Діагональ" << setw(5) << "|" << endl;
                    cout << "-------------------------------------------------------------------" << endl;

                    for (int k = 0; k < i; k++) { // друкуємо таблицю
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
			
			case 4: // пошук за фірмою
				firmSearch: // goto-мітка для пошуку за фірмою
					if (i == 0) {
						SetColor(0, 4);
						cout << "Записів немає :(" << endl; 
					} else {
						SetColor(0, 7);
						string firm;
						cout << "Введіть фірму телефона: ";
						cin >> firm;
						
						for (int k = 0; k < i; k++) {
							if (mobilePhones[k].firm == firm) {
								mark = true;
								SetColor(0, 8);
								cout << "\nФірма: " << mobilePhones[k].firm << "\nМодель: " << mobilePhones[k].model << endl;
								cout << "Рік випуску: " << mobilePhones[k].year << "\nКількість камер: " << mobilePhones[k].numberOfCameras << endl;
								cout << "Діагональ: " << mobilePhones[k].diagonal << "\n\n";
							}
						}
						
						if (!mark) {
							SetColor(0, 4);
							cout << "Нажаль, нічого не знайдено :(" << endl; 
						}
					}
					
					SetColor(7, 0);
					mark = true;
					goto tryAgain;
				
			case 5: // пошук за моделлю
				modelSearch: // goto-мітка для пошуку за моделлю
					if (i == 0) {
						SetColor(0, 4);
						cout << "Записів немає :(" << endl; 
					} else {
						SetColor(0, 7);
						string model;
						cout << "Введіть модель телефона: ";
						cin >> model;
						
						for (int k = 0; k < i; k++) {
							if (mobilePhones[k].model == model) {
								mark = true;
								SetColor(0, 8);
								cout << "\nМодель: " << mobilePhones[k].model << "\nФірма: " << mobilePhones[k].firm << endl;
								cout << "Рік випуску: " << mobilePhones[k].year << "\nКількість камер: " << mobilePhones[k].numberOfCameras << endl;
								cout << "Діагональ: " << mobilePhones[k].diagonal << "\n\n";
							}
						}
						
						if (!mark) {
							SetColor(0, 4);
							cout << "Нажаль, нічого не знайдено :(" << endl; 
						}
					}
					
					SetColor(7, 0);
					mark = true;
					goto tryAgain;
				
			case 6: // пошук за роком випуску
				yearSearch: // goto-мітка для пошуку за роком випуску
					if (i == 0) {
						SetColor(0, 4);
						cout << "Записів немає :(" << endl; 
					} else {
						SetColor(0, 7);
						int year;
						cout << "Введіть рік випуску: ";
						cin >> year;
						
						for (int k = 0; k < i; k++) {
							if (mobilePhones[k].year == year) {
								mark = true;
								SetColor(0, 8);
								cout << "\nРік випуску: " << mobilePhones[k].year << "\nФірма: " << mobilePhones[k].firm << endl;
								cout << "Модель: " << mobilePhones[k].model << "\nКількість камер: " << mobilePhones[k].numberOfCameras << endl;
								cout << "Діагональ: " << mobilePhones[k].diagonal << "\n\n";
							}
						}
						
						if (!mark) {
							SetColor(0, 4);
							cout << "Нажаль, нічого не знайдено :(" << endl; 
						}
					}
					
					SetColor(7, 0);
					mark = true;
					goto tryAgain;
				
			case 7: // пошук за різними полями
				if (i == 0) {
					SetColor(0, 4);
					cout << "Записів немає :(" << endl; 
				} else {
					chooseCriteria: // goto-мітка для вибору критерію пошуку
						SetColor(0, 7);
						int criteria;
						cout << "---------------------------------" << endl;
						cout << "1) Фірма                         " << endl;
						cout << "2) Модель                        " << endl;
						cout << "3) Рік випуску                   " << endl;
						cout << "4) Кількість камер               " << endl;
						cout << "5) Діагональ                     " << endl;
						cout << "---------------------------------" << endl;
						cout << "Виберіть критерій пошуку: ";
						cin >> criteria;
						
						switch (criteria) {
							case 1: goto firmSearch;
							case 2: goto modelSearch;
							case 3: goto yearSearch;
							case 4: 
								int numberOfCameras;
								cout << "Введіть кількість камер: ";
								cin >> numberOfCameras;
						
								for (int k = 0; k < i; k++) {
									if (mobilePhones[k].numberOfCameras == numberOfCameras) {
										mark = true;
										SetColor(0, 8);
										cout << "\nКількість камер: " << mobilePhones[k].numberOfCameras << "\nФірма: " << mobilePhones[k].firm << endl;
										cout << "Модель: " << mobilePhones[k].model << "\nРік випуску: " << mobilePhones[k].year << endl;
										cout << "Діагональ: " << mobilePhones[k].diagonal << "\n\n";
									}
								}
								break;
								
							case 5:
								double diagonal;
								cout << "Введіть діагональ: ";
								cin >> diagonal;
								
								for (int k = 0; k < i; k++) {
									if (mobilePhones[k].diagonal == diagonal) {
										mark = true;
										SetColor(0, 8);
										cout << "\nДіагональ: " << mobilePhones[k].diagonal << "\nФірма: " << mobilePhones[k].firm << endl;
										cout << "Модель: " << mobilePhones[k].model << "\nРік випуску: " << mobilePhones[k].year << endl;
										cout << "Кількість камер: " << mobilePhones[k].numberOfCameras << "\n\n";
									}
								}
								break;
								
							default:
								SetColor(0, 4);
								cout << "Неправильний вибір! Спробуйте ще раз!";
								goto chooseCriteria;
						}
					
						if (!mark) {
							SetColor(0, 4);
							cout << "Нажаль, нічого не знайдено :(" << endl; 
						}
				}
				
				SetColor(7, 0);
				mark = true;
				goto tryAgain;
				
			case 8: // вихід з програми
				SetColor(7, 0);
				exit(0);
			
			default: // повернення до введення дії
				SetColor(0, 4);
				cout << "Неправильний вибір! Спробуйте ще раз!";
				goto tryAgain;
		}
	
	return 0;
}
