#include <iostream>

int n;

using namespace std;

int main() {

	setlocale(0, "");

	cout << "������� ����������� �������: " << endl;
	cin >> n;

	int *a = new int [n];

	cout << "��������� ������ �������: " << endl;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	//���������� 

	for (int i = 0; i < (n - 1); i++){

		int k = i + 1;

		while (a[i] > a[k] and k != 0){
			swap(a[i], a[k]);
			k--;
			i--;
		}
	}

	//����� ���������������� �������

	for (int i = 0; i < n; i++) cout << a[i] << " ";

	system("pause");
}