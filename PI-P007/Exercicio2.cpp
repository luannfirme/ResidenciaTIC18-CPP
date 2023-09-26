#include <iostream>

using namespace std ;

int main(void) {
    
   int numero, original, reverso = 0, digito;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    original = numero;

    while (numero > 0) {
        digito = numero % 10;
        reverso = reverso * 10 + digito;
        numero /= 10;
    }

    if (original == reverso) {
        cout << "O numero " << original << " e um palindromo." << endl;
    } else {
        cout << "O numero " << original << " nao e um palindromo." << endl;
    }

    return 0;
}