#include <iostream>

using namespace std;

int main(void){

   int a, b;

    cout << "Informe um numero inteiro: ";
    cin >> a;

    cout << "Informe outro numero inteiro: ";
    cin >> b;

    int soma = a + b;
    int subtracao = a - b;
    int multiplicacao = a * b;
    int divisao = a / b;
    int resto = a % b;

    cout << "Soma = " << soma << endl;
    cout << "Subtracao = " << subtracao << endl;
    cout << "Multiplicacao = " << multiplicacao << endl;
    cout << "Divisao = " << divisao << endl;
    cout << "Resto = " << resto << endl;

    return 0;
}