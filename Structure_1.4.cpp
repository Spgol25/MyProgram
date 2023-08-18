#include <iostream>
#include <stdlib.h>
#include <ctime>

char start;
int a, b, s1, s2, agree;

using namespace std;

int main() {

	setlocale(0, "");

	//случайный seed
	srand(time(0));

	do
	{
		//запуск программы
		cout << "Добро пожаловать! Продолжите, чтобы начать игру.\n";
		system("pause");

		//первый игрок
		cout << "Первый игрок бросает кости.\n";
		a = 1 + rand() % 6;
		b = 1 + rand() % 6;
		cout << "Первый кубик: " << a << endl;
		cout << "Второй кубик: " << b << endl;

		//сумма выпавших чисел 1
		s1 = a + b;

		system("pause");

		//второй игрок
		cout << "Второй игрок бросает кости.\n";
		a = 1 + rand() % 6;
		b = 1 + rand() % 6;
		cout << "Первый кубик: " << a << endl;
		cout << "Второй кубик: " << b << endl;

		//сумма выпавших чисел2
		s2 = a + b;

		//определение победителя
		if (s1 > s2) cout << "Первый игрок выиграл. Сумма чисел: " << s1 << endl;
		else cout << "Второй игрок выиграл. Сумма чисел: " << s2 << endl;
		cout << "Хотите сыграть ещё? Тогда введите 1, иначе введите 0" << endl;
		cin >> agree;

	} while (agree);

	system("pause");
}