#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void){
    double a, b, c;
    double discriminante;

    cout << "Digite os coeficientes a do polinomio (ax^2 + bx + c): ";
    cin >> a;
    cout << "Digite os coeficientes b do polinomio (ax^2 + bx + c): ";
    cin >> b;
    cout << "Digite os coeficientes c do polinomio (ax^2 + bx + c): ";
    cin >> c;

    discriminante = b * b - 4 * a * c;

    if (discriminante > 0) {
        cout << "O polinomio tem duas raizes reais." << endl;
        double raiz1 = (-b + sqrt(discriminante)) / (2 * a);
        double raiz2 = (-b - sqrt(discriminante)) / (2 * a);
        cout << "Raiz 1: " << raiz1 << endl;
        cout << "Raiz 2: " << raiz2 << endl;
    } else if (discriminante == 0) {
        cout << "O polinomio tem uma raiz real." << endl;
        double raiz = -b / (2 * a);
        cout << "Raiz: " << raiz << endl;
    } else {
        cout << "O polinomio nao tem raizes reais." << endl;
    }

    double x;
    cout << "Digite o valor de x para calcular p(x): ";
    cin >> x;

    double px = a * x * x + b * x + c;
    cout << "p(x) = " << px << endl;

    return 0;
}
