#include <iostream>
#include <cmath>

float a, b, x;

using namespace std;

int main() {

	setlocale (0, "");
	
	//����� ���������
	cout << "������� ��������:\n" << "�� A = ";
	cin >> a;

	cout << "�� B = ";
	cin >> b;

	cout << "������� ���:\n" << "dx = ";
	cin >> x;

	printf("\t�������:%2s %2s\n", "��������", "��������");
	//������ �������
	for (float i = a; i <= b; i += x){
		printf("\tsin:\t%2.2f \t%.2f\n", i,  sin(i));
	}

	system("pause");

}