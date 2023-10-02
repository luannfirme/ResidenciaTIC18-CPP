#include <iostream>

using namespace std ;

int main(void) {
    int altura;
    char letra = 'A';

    cout << "Digite a altura do padrao: ";
    cin >> altura;

    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            cout << letra;
            letra++;
        }
        cout << endl;
    }

    return 0;
}