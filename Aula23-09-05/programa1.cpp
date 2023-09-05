#include <iostream>

using namespace std;

int fat (int n){
    int fatorial = 1;

    for(int i= 1; i <= n; i++)
        fatorial *= i;

    return fatorial;
}

int main (void){

int x, f;

cout << "Digite um numero: ";
cin >> x;

f= fat(x);

cout << x << "! = " << f << endl;

return 0;
}