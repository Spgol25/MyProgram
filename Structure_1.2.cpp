#include <iostream>

using namespace std;

float o1, o2;
char oper;

int main (){

	setlocale(0, "");

	//���� ������
	cout << "������� ��������:\n" << "Operand1 = ";
	cin >> o1;

	cout << "Operand2 = ";
	cin >> o2;

	cout << "������� ������ ��������: +, -, /, * " << endl;
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
				cout << "�� 0 ������ ������.";
				break; 
			}
			cout << o1 << " / " << o2 << " = " << o1 / o2;
			break;
		case '*':
			cout << o1 << " * " << o2 << " = " << o1 * o2;
			break;
	default:
		cout << "�� ����� ������������ ��������.\n";
		cout << "���������� �����, �� ����������� �������.";
		break;

	}
	cout << "\n";
	system("pause");
}