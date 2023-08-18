#include <iostream>
#include <cmath>

using namespace std;

float a, b, c, x1, x2, k, discr;

int main(){
    setlocale(0, "");

    //ввод данных
    cout << "Введите коэффициенты квадратного уравнения:\n";

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "c = ";
    cin >> c;
       
    //вычисление дискриминанта
    discr = b * b - (a * c)*4;
    
    //определение вида корней
    if (discr >= 0) {

        x1 = (-b + sqrt(discr)) / (2 * a);
        x2 = (-b - sqrt(discr)) / (2 * a);

        cout << "Уравнение имеет корни:\n";
        cout << "X1 = " << x1 << endl;
        cout << "X2 = " << x2;
    }
    else {
        cout << "Уравнение имеет комплексные корни:\n";

        //знак учтён в строке, поэтому хватит только x1
        x1 = (-b / (2 * a));
        k = sqrt(abs(discr)) / (2 * a);

        cout << "X1 = " << x1 << " + i" << k << endl;
        cout << "X2 = " << x1 << " - i" << k << endl;
    }
    system("pause");
}


