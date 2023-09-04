#include <iostream>
#include <math.h>

using namespace std;

int main (void){
    float a, b, c, delta, x1, x2;

    cout << "Digite o coeficiente a: ";
    cin >> a;

    cout << "Digite o coeficiente b: ";
    cin >> b;

    cout << "Digite o coeficiente c: ";
    cin >> c;

    delta = pow(b,2) - 4 * a * c;

    if(delta > 0){
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "a primeira raiz: " << x1 <<endl;
        cout << "a segunda raiz: " << x2 <<endl;
    } else if ( delta == 0) {
        x1 = -b / (2 * a);
        cout << "a raiz: " << x1 <<endl;
    } else {
        cout << "Nao ha raiz real" << endl;
    }

    return 0;
}