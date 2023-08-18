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
	cout << setw(32) << left << "��� ��������" << " ";
	cout << setw(32) << left << "������� ��������" << " ";
	cout << setw(12) << left << "����� ��������" << endl;
}

int main() {
	setlocale(0, "");

	string proof;
	person newer;
	bool stop = true, found = false;
	int choose;

	FILE* f;

	cout << "�������� �������� � ������." << endl;
	cout << "1. �������� ����� �����������." << endl;
	cout << "2. ���������� ����� ������." << endl;
	cout << "3. ����� �������� �� ����� � �������." << endl;
	cout << "4. �������/�������� �����." << endl;
	cout << "5. �������� ������." << endl;
	cout << "6. �������������� ������." << endl;
	cout << "7. ������� ����������� � ��������� ����." << endl;
	cout << "8. �����." << endl;

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

		cout << "�������� �������� � ������." << endl;
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
			cout << "������� ���:" << endl;
			cin >> newer.name;
			cout << "������� �������:" << endl;
			cin >> newer.lname;
			cout << "������� �������:" << endl;
			cin >> newer.phone;

			f = fopen("spravochnik.dat", "ab");
			fwrite(&newer, sizeof(person), 1, f);
		
			fclose(f);
			delete[] data;
			break;

		case 3:
			found = false;

			cout << "������� ���:" << endl;
			cin >> newer.name;
			cout << "������� �������:" << endl;
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
			if (!found) cout << "������ �� �������!" << endl;
			delete[] data;
			break;

		case 4:
			cout << "����� �������� ����, ������� 'Confirm'." << endl;
			cin >> proof;
			if (proof == "Confirm") {
				f = fopen("spravochnik.dat", "wb");
				fclose(f);
				cout << "���� ������." << endl;
			}
			delete[] data;
			break;

		case 5:
			found = false;

			cout << "������� ���:" << endl;
			cin >> newer.name;
			cout << "������� �������:" << endl;
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

			if (!found) cout << "������ �� �������!" << endl;
			delete[] data;
			break;

		case 6:
			found = false;

			cout << "������� ���:" << endl;
			cin >> newer.name;
			cout << "������� �������:" << endl;
			cin >> newer.lname;

			f = fopen("spravochnik.dat", "wb");

			for (int i = 0; i < size; i++) {
				if (!strcmp(newer.name, data[i].name) and !strcmp(newer.lname, data[i].lname)) {
					found = true;
					cout << "������� ��������� ���:" << endl;
					cin >> data[i].name;
					cout << "������� ��������� �������:" << endl;
					cin >> data[i].lname;
					cout << "������� ��������� ����� ��������:" << endl;
					cin >> data[i].phone;
				}
				fwrite(&data[i], sizeof(person), 1, f);
			}

			fclose(f);

			if (!found) cout << "������ �� �������!" << endl;
			delete[] data;
			break;

		case 7:
			cout << "������� ����������� � ��������� ����." << endl;
			cout << "��� �����: spravochnik.txt" << endl;

			f = fopen("spravochnik.txt", "wt");
			fprintf(f, "%-32s %-32s %-12s\n", "��� ��������", "������� ��������", "����� ��������");
			for (int i = 0; i < size; i++) {
				fprintf(f, "%-32s %-32s %-12s\n", data[i].name, data[i].lname, data[i].phone);
			}
			fclose(f);
			
			cout << "������� ��������." << endl;

			delete[] data;
			break;

		case 8:
			stop = false;
			delete[] data;
			break;

		default:
			cout << "������: ������������ �������." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	system("pause");
}