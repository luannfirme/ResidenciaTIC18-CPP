#include <iostream>

using namespace std;

void resto10 (int &k){
    if(k >= 10)
        k = k % 10;

    cout << "Valor de k: " << k << endl;
}

int main (void){

int a;

cout << "Digite um valor: ";
cin >> a;

resto10(a);

cout << "O novo valor de a: " << a << endl;

return 0;
}