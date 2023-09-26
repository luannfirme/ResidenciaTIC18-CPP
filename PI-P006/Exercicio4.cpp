#include <iostream>

using namespace std ;

int main(void) {

    int a,b;

    cout << "digite dois numeros inteiros:" << endl;
    cin >> a >> b;
    cout << endl;
    
    (a > b  && a != b) ? cout << a << " e maior que " << b : cout << "";
    (b > a  && b != a) ? cout << b << " e maior que " << a : cout << "";
    (b == a) ? cout << "Estes numeros sao iguais" : cout << "";

    cout << endl;

    return 0;
}
