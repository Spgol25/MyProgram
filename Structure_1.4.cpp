#include <iostream>
#include <stdlib.h>
#include <ctime>

char start;
int a, b, s1, s2, agree;

using namespace std;

int main() {

	setlocale(0, "");

	//��������� seed
	srand(time(0));

	do
	{
		//������ ���������
		cout << "����� ����������! ����������, ����� ������ ����.\n";
		system("pause");

		//������ �����
		cout << "������ ����� ������� �����.\n";
		a = 1 + rand() % 6;
		b = 1 + rand() % 6;
		cout << "������ �����: " << a << endl;
		cout << "������ �����: " << b << endl;

		//����� �������� ����� 1
		s1 = a + b;

		system("pause");

		//������ �����
		cout << "������ ����� ������� �����.\n";
		a = 1 + rand() % 6;
		b = 1 + rand() % 6;
		cout << "������ �����: " << a << endl;
		cout << "������ �����: " << b << endl;

		//����� �������� �����2
		s2 = a + b;

		//����������� ����������
		if (s1 > s2) cout << "������ ����� �������. ����� �����: " << s1 << endl;
		else cout << "������ ����� �������. ����� �����: " << s2 << endl;
		cout << "������ ������� ���? ����� ������� 1, ����� ������� 0" << endl;
		cin >> agree;

	} while (agree);

	system("pause");
}