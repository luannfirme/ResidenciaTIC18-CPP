#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

    float a, b;

    cout << "Informe um numero inteiro: ";
    cin >> a;

    cout << "Informe outro numero inteiro: ";
    cin >> b;

    float soma = a + b;
    float subtracao = a - b;
    float multiplicacao = a * b;
    float divisao = a / b;

    cout << fixed << setprecision(1);
    cout << "Soma = " << soma << endl;
    cout << "Subtracao = " << subtracao << endl;
    cout << "Multiplicacao = " << multiplicacao << endl;
    cout << "Divisao = " << divisao << endl;

    return 0;
}