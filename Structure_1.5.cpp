#include <iostream>

int n;

using namespace std;

int main() {

	setlocale(0, "");

	cout << "¬ведите размерность массива: " << endl;
	cin >> n;

	int *a = new int [n];

	cout << "«аполните массив данными: " << endl;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	//сортировка 

	for (int i = 0; i < (n - 1); i++){

		int k = i + 1;

		while (a[i] > a[k] and k != 0){
			swap(a[i], a[k]);
			k--;
			i--;
		}
	}

	//вывод отсортированного массива

	for (int i = 0; i < n; i++) cout << a[i] << " ";

	system("pause");
}