#include <iostream>
#include <cmath>

float a, b, x;

using namespace std;

int main() {

	setlocale (0, "");
	
	//задаём параметры
	cout << "Задайте интервал:\n" << "От A = ";
	cin >> a;

	cout << "До B = ";
	cin >> b;

	cout << "Задайте шаг:\n" << "dx = ";
	cin >> x;

	printf("\tФункция:%2s %2s\n", "Аргумент", "Значение");
	//расчёт таблицы
	for (float i = a; i <= b; i += x){
		printf("\tsin:\t%2.2f \t%.2f\n", i,  sin(i));
	}

	system("pause");

}