#include <iostream>

using namespace std;

int main (void){
    int a, b, c;

    cout << "Digite um numero inteiro: ";
    cin >> a;

    cout << "Digite outro numero inteiro: ";
    cin >> b;

    if (a >= b)
        c = a - b;

    else
        c =  b - a;

    cout << "O calculo deu: "<< c << endl;

    return 0;
}