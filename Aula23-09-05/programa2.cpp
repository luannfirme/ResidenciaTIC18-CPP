#include <iostream>

using namespace std;

int fat (int n){
    int fatorial = 1;

    for(int i= 1; i <= n; i++)
        fatorial *= i;

    return fatorial;
}

int main (void){

int n, p, a;

cout << "Digite o total de itens: ";
cin >> n;


cout << "Digite quantos serao tomados: ";
cin >> p;

a= fat(n) / fat(n-p);

cout << n << " itens tomados " << p << " a " << p << endl;
cout << "Arranjo de " << a << " maneiras" << endl;

return 0;
}