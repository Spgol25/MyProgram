#include <iostream>
#include <string.h>

using namespace std;

struct Person {
	char firstname[30];
	char lastname[30];
	char surname[30];
	char adres[30];
	char phone[12];
};

int main() {

	setlocale(LC_ALL, "");
	system("chcp 1251");

	Person data[5];
	char firstname[30], lastname[30] ;
	int otst;
	char space[2] = " ";

	for (size_t i = 0; i < 5; i++) {
		cout << "Введите информацию о человеке." << endl;
		cin >> data[i].firstname;
		cin >> data[i].lastname;
		cin >> data[i].surname;
		cin >> data[i].adres;
		cin >> data[i].phone;
	}

	cout << "Журнал." << endl;
	cout << "\nФамилия     Имя      Отчество   Адрес       Телефон" << endl;
	for (size_t i = 0; i < 5; i++) {
		cout << data[i].firstname << "      ";
		cout << data[i].lastname << "     ";
		cout << data[i].surname << "     ";
		cout << data[i].adres << "     ";
		cout << data[i].phone << endl;
	}

	cout << "\nВведите фамилию и имя пользователя, информацию о котором хотите узнать." << endl;
	cin >> firstname;
	cin >> lastname;
	cout << firstname;
	cout << lastname;

	int i;

	for (i = 0; i < 5; i++) {
		if (!strcmp(data[i].firstname, firstname) and !strcmp(data[i].lastname, lastname)) {
			cout << "\n" <<data[i].firstname << "    ";
			cout << data[i].lastname << "     ";
			cout << data[i].surname << "     ";
			cout << data[i].adres << "     ";
			cout << data[i].phone << endl;
			break;
		}
	}
	if (i == 5) cout << "Пользователь не найден." << endl;

	system("pause");
}