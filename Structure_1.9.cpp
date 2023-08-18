#include <iostream>
#include <cstdio>
#include <limits>
#include <string>
#include <iomanip>
#pragma warning(disable:4996)

using namespace std;

struct person {
	char name[32];
	char lname[32];
	char phone[12];
};

void hat() {
	cout << setw(32) << left << "ИМЯ АБОНЕНТА" << " ";
	cout << setw(32) << left << "ФАМИЛИЯ АБОНЕНТА" << " ";
	cout << setw(12) << left << "НОМЕР ТЕЛЕФОНА" << endl;
}

int main() {
	setlocale(0, "");

	string proof;
	person newer;
	bool stop = true, found = false;
	int choose;

	FILE* f;

	cout << "Выберите действие с файлом." << endl;
	cout << "1. Просмотр всего справочника." << endl;
	cout << "2. Добавление новой записи." << endl;
	cout << "3. Поиск абонента по имени и фамилии." << endl;
	cout << "4. Очистка/создание файла." << endl;
	cout << "5. Удаление записи." << endl;
	cout << "6. Редактирование записи." << endl;
	cout << "7. Экспорт справочника в текстовый файл." << endl;
	cout << "8. Выход." << endl;

	f = fopen("spravochnik.dat", "rb");

	if (!f) {
		f = fopen("spravochnik.dat", "wb");
		fclose(f);
	}
	else fclose(f);

	while (stop) {

		f = fopen("spravochnik.dat", "rb");

		fseek(f, 0, SEEK_END);
		int size = ftell(f) / sizeof(person);
		person* data = new person[size];
		fseek(f, 0, SEEK_SET);
		fread(data, sizeof(person), size, f);
		fclose(f);

		cout << "Выберите действие с файлом." << endl;
		cin >> choose;

		switch (choose) {

		case 1:
			hat();

			for (int i = 0; i < size; i++) {
				cout << setw(32) << left << data[i].name << " ";
				cout << setw(32) << left << data[i].lname << " ";
				cout << setw(12) << left << data[i].phone << endl;
			}
			delete[] data;
			break;

		case 2:
			cout << "Введите имя:" << endl;
			cin >> newer.name;
			cout << "Введите фамилию:" << endl;
			cin >> newer.lname;
			cout << "Введите телефон:" << endl;
			cin >> newer.phone;

			f = fopen("spravochnik.dat", "ab");
			fwrite(&newer, sizeof(person), 1, f);
		
			fclose(f);
			delete[] data;
			break;

		case 3:
			found = false;

			cout << "Введите имя:" << endl;
			cin >> newer.name;
			cout << "Введите фамилию:" << endl;
			cin >> newer.lname;

			for (int i = 0; i < size; i++) {
				
				if (!strcmp(newer.name, data[i].name) and !strcmp(newer.lname, data[i].lname)) {
					if (!found) hat();
					cout << setw(32) << left << data[i].name << " ";
					cout << setw(32) << left << data[i].lname << " ";
					cout << setw(12) << left << data[i].phone << endl;
					found = true;
				}

			}
			if (!found) cout << "Записи не найдены!" << endl;
			delete[] data;
			break;

		case 4:
			cout << "Чтобы очистить файл, введите 'Confirm'." << endl;
			cin >> proof;
			if (proof == "Confirm") {
				f = fopen("spravochnik.dat", "wb");
				fclose(f);
				cout << "Файл очищен." << endl;
			}
			delete[] data;
			break;

		case 5:
			found = false;

			cout << "Введите имя:" << endl;
			cin >> newer.name;
			cout << "Введите фамилию:" << endl;
			cin >> newer.lname;

			f = fopen("spravochnik.dat", "wb");

			for (int i = 0; i < size; i++) {
				if (!strcmp(newer.name, data[i].name) and !strcmp(newer.lname, data[i].lname)) {
					found = true;
					continue;
				}
				fwrite(&data[i], sizeof(person), 1, f);
			}

			fclose(f);

			if (!found) cout << "Записи не найдены!" << endl;
			delete[] data;
			break;

		case 6:
			found = false;

			cout << "Введите имя:" << endl;
			cin >> newer.name;
			cout << "Введите фамилию:" << endl;
			cin >> newer.lname;

			f = fopen("spravochnik.dat", "wb");

			for (int i = 0; i < size; i++) {
				if (!strcmp(newer.name, data[i].name) and !strcmp(newer.lname, data[i].lname)) {
					found = true;
					cout << "Введите изменённое имя:" << endl;
					cin >> data[i].name;
					cout << "Введите изменённую фамилию:" << endl;
					cin >> data[i].lname;
					cout << "Введите изменённый номер телефона:" << endl;
					cin >> data[i].phone;
				}
				fwrite(&data[i], sizeof(person), 1, f);
			}

			fclose(f);

			if (!found) cout << "Записи не найдены!" << endl;
			delete[] data;
			break;

		case 7:
			cout << "Экспорт справочника в текстовый файл." << endl;
			cout << "Имя файла: spravochnik.txt" << endl;

			f = fopen("spravochnik.txt", "wt");
			fprintf(f, "%-32s %-32s %-12s\n", "ИМЯ АБОНЕНТА", "ФАМИЛИЯ АБОНЕНТА", "НОМЕР ТЕЛЕФОНА");
			for (int i = 0; i < size; i++) {
				fprintf(f, "%-32s %-32s %-12s\n", data[i].name, data[i].lname, data[i].phone);
			}
			fclose(f);
			
			cout << "Экспорт завершён." << endl;

			delete[] data;
			break;

		case 8:
			stop = false;
			delete[] data;
			break;

		default:
			cout << "Ошибка: некорректная функция." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	system("pause");
}