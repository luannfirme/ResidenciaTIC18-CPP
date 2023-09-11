#include <iostream>
#include <climits>

using namespace std;

int main(void){

    int numero;
    cout << "Digite um numero inteiro: ";
    cin >> numero;

    cout << "O numero fornecido (" << numero << ") " << (numero > SHRT_MAX ? "e maior que um short int" : "pertence ao intervalo dos short int") << endl;

    return 0;
}