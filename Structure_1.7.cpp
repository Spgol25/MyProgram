#include <iostream>

using namespace std;

char password[10] = "123456789";
char *attempt = new char [10];
float o1, o2;
char oper;

void calculator() {
	//ввод данных
	cout << "Введите операнды:\n" << "Operand1 = ";
	cin >> o1;

	cout << "Operand2 = ";
	cin >> o2;

	cout << "Введите символ операции: +, -, /, * " << endl;
	cin >> oper;

	switch (oper) {
	case '+':
		cout << o1 << " + " << o2 << " = " << o1 + o2;
		break;
	case '-':
		cout << o1 << " - " << o2 << " = " << o1 - o2;
		break;
	case '/':
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
}

int main() {

	setlocale(0, "");

	cout << "Для продолжения введите пароль." << endl;

	int k;
	int i;

	for (i = 1; i <= 3; i++) {
		cin >> attempt;

		if (strcmp(attempt, password)) {
			cout << "Вы ввели неверный пароль." << endl;
			cout << "У вас осталось " << 3 - i << " попыток." << endl;
		}
		else {
			cout << "Добро пожаловать." << endl;
			calculator();
			break;
		}

		if (i == 3) {
			cout << "Доступ запрещён." << endl;
		}

	}
	system("pause");
}


