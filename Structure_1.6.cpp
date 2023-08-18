#include <iostream>
#include <ctime>

int col = 4, row = 5, maxR, maxC, minR, minC;

using namespace std;

int main() {
	setlocale(0, "");

	srand(time(0));                        //случайная генерация

	int matrix[5][4];

	for (int i = 0; i < row; i++) {                             
		for (int k = 0; k < col; k++) {   
			matrix[i][k] = rand() % 100;
		}
	}

	cout << "Исходная матрица:" << endl;   //вывод сгенерированной матрицы на экран

	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			cout << matrix[i][k] << " ";
		}
		cout << '\n';
	}

	for (int i = 0; i < row; i++){         //максимум по каждой строке
		maxR = -1;
		for (int k = 0; k < col; k++) {
			if (matrix[i][k] > maxR and matrix[i][k] < 100) maxR = matrix[i][k];
		}
		cout << "Максимум по строке " << i+1 << " равен " << maxR << endl;
	}

	cout << '\n';

	for (int i = 0; i < col; i++) {       //максимум по каждому столбцу
		maxC = -1;
		for (int k = 0; k < row; k++) {
			if (matrix[k][i] > maxC) maxC = matrix[k][i];
		}
		cout << "Максимум по столбцу " << i+1 << " равен " << maxC << endl;
	}
	cout << '\n';

	for (int i = 0; i < row; i++) {         //минимум по каждой строке
		minR = 1000;
		for (int k = 0; k < col; k++) {
			if (matrix[i][k] < minR) minR = matrix[i][k];
		}
		cout << "Минимум по строке " << i + 1 << " равен " << minR << endl;
	}

	cout << '\n';

	for (int i = 0; i < col; i++) {       //минимум по каждому столбцу
		minC = 1000;
		for (int k = 0; k < row; k++) {
			if (matrix[k][i] < minC) minC= matrix[k][i];
		}
		cout << "Минимум по столбцу " << i + 1 << " равен " << minC << endl;
	}
	system("pause");
}