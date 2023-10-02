#include <iostream>

using namespace std ;

int main(void) {
    
int numero, soma = 0;

    cout << "Digite um numero: ";
    cin >> numero;

    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }

    if (soma == numero) {
        cout << numero << " e um numero perfeito." << endl;
    } else {
        cout << numero << " nao e um numero perfeito." << endl;
    }

    return 0;
}