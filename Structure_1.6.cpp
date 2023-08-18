#include <iostream>
#include <ctime>

int col = 4, row = 5, maxR, maxC, minR, minC;

using namespace std;

int main() {
	setlocale(0, "");

	srand(time(0));                        //��������� ���������

	int matrix[5][4];

	for (int i = 0; i < row; i++) {                             
		for (int k = 0; k < col; k++) {   
			matrix[i][k] = rand() % 100;
		}
	}

	cout << "�������� �������:" << endl;   //����� ��������������� ������� �� �����

	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			cout << matrix[i][k] << " ";
		}
		cout << '\n';
	}

	for (int i = 0; i < row; i++){         //�������� �� ������ ������
		maxR = -1;
		for (int k = 0; k < col; k++) {
			if (matrix[i][k] > maxR and matrix[i][k] < 100) maxR = matrix[i][k];
		}
		cout << "�������� �� ������ " << i+1 << " ����� " << maxR << endl;
	}

	cout << '\n';

	for (int i = 0; i < col; i++) {       //�������� �� ������� �������
		maxC = -1;
		for (int k = 0; k < row; k++) {
			if (matrix[k][i] > maxC) maxC = matrix[k][i];
		}
		cout << "�������� �� ������� " << i+1 << " ����� " << maxC << endl;
	}
	cout << '\n';

	for (int i = 0; i < row; i++) {         //������� �� ������ ������
		minR = 1000;
		for (int k = 0; k < col; k++) {
			if (matrix[i][k] < minR) minR = matrix[i][k];
		}
		cout << "������� �� ������ " << i + 1 << " ����� " << minR << endl;
	}

	cout << '\n';

	for (int i = 0; i < col; i++) {       //������� �� ������� �������
		minC = 1000;
		for (int k = 0; k < row; k++) {
			if (matrix[k][i] < minC) minC= matrix[k][i];
		}
		cout << "������� �� ������� " << i + 1 << " ����� " << minC << endl;
	}
	system("pause");
}