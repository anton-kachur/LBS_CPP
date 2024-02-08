/*
Група: KH–1-2
Здобувач: Качур Антон Вікторович
Лабораторна робота №3
Завдання 2
Тема лабораторної роботи: Розв'язання задач з використанням циклу з параметром.
Завдання: Розробити алгоритм для табулювання функції, що наведено у таблиці 3.2, відповідно до індивідуального 
завдання на заданому з клавіатури параметрів проміжку [xstart…xend] та кроком xstep, та реалізувати його мовою 
С\С++ з використанням циклу з параметром FOR. Результат вивести у вигляді таблиці та різними кольорами.
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція, призначена для зміни кольору виводу. 
// В якості аргументів передаються числові значення кольорів тексту і тла
void SetColor(int text, int background) {
	// змінна, яка позначає дескриптор екрану консолі виводу
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// присвоєння значень кольорів тексту, який виводиться в консоль
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void dashes(int val) {
	for (int i = 0; i < val; i++)
		cout << "-";
		
	cout << endl;
}


int main() {
	system("cls"); // викликаємо функцію очистку екрану
	// наступні дві команди призначено для відображення кирилиці у 
	// консольному вікні
	// встановлення кодової сторінки win-cp 1251 для потоку введення
	SetConsoleCP(1251); 
	// встановлення кодової сторінки win-cp 1251 до потоку виведення
	SetConsoleOutputCP(1251);
	
	/* Програмний код для розв'язку поставленого завдання */
	
	double x, y, xstart, xend, xstep;
	
	SetColor(11, 1);
	cout << "Введіть початкове значення x: ";
	cin >> xstart;
	cout << "Bведіть кінцеве значення x: ";
	cin >> xend;
	cout << "Введіть крок x: ";
	cin >> xstep;
	
	// виводимо таблицю
	SetColor(15, 8);
	
	
	dashes(26);
	cout << setw(8);
	cout << "x "; 
	cout << "|";
	cout << setw(16);
	cout << "y "; 
	cout << "|";
	cout << endl;
	dashes(26);
	
	for (x = xstart; x <= xend; x+=xstep) {
		y = exp(2.0*x) * sin(powf(x, 2.0));
		
		cout << setprecision(4) << setw(7) << fixed;
		cout << x << " | ";
		cout << setw(14);
		cout << y << " |" << endl;
	}
	
	// наступні 3 рядки демонструють встановлення стандартних кольорів тексту і тла та
	// призупинення роботи програми
	SetColor(7, 0);
	cout << "\n";
	system("pause");
	
	return 0;
}
