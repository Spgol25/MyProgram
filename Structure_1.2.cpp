#include <iostream>

using namespace std;

float o1, o2;
char oper;

int main (){

	setlocale(0, "");

	//ввод данных
	cout << "Введите операнды:\n" << "Operand1 = ";
	cin >> o1;

	cout << "Operand2 = ";
	cin >> o2;

	cout << "Введите символ операции: +, -, /, * " << endl;
	cin >> oper;

	switch (oper){
		case '+': 
			cout << o1 << " + " << o2 << " = " << o1 + o2;
			break;
		case '-':
			cout << o1 << " - " << o2 << " = " << o1 - o2;
			break;
		case '/':
			if (o2 == 0) { 
				cout << "На 0 делить нельзя.";
				break; 
			}
			cout << o1 << " / " << o2 << " = " << o1 / o2;
			break;
		case '*':
			cout << o1 << " * " << o2 << " = " << o1 * o2;
			break;
	default:
		cout << "Вы ввели некорректную операцию.\n";
		cout << "Попробуйте снова, не используйте пробелы.";
		break;

	}
	cout << "\n";
	system("pause");
}