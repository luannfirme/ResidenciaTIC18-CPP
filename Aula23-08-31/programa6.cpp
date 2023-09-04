#include <iostream>
#include <math.h>

using namespace std;

int main (void){

    int valor, x;
    int soma = 0;
    int fatorial = 1;
    int divisores = 0;

    cout << "Informe um numero: ";
    cin >> valor;

    for (x = 0; x <= valor; x++)
    {
        soma += x;
    }

    for (x = 1; x <= valor; x++)
    {
        fatorial *= x ;

        if (valor % x == 0){
            divisores++;
            cout << "O numero "<< x << " e divisor " << valor << endl;
        }
    }

    cout << endl << "A soma de todos valores abaixo de "<< valor << " Foi: " << soma << endl << endl;
    cout << "O fatorial de "<< valor << " Foi: " << fatorial << endl << endl;
    cout << "O numero "<< valor << " tem " << divisores << " divisores " << endl << endl;

    if(divisores == 2)
        cout << valor << " e primo " << endl;

    return 0;
}