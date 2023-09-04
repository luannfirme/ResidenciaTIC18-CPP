#include <iostream>

using namespace std;

int main (void){
    int a;
    string b;

    cout << "Digite um numero inteiro: ";
    cin >> a;

    if (a % 2 == 0)
        b = "Par";

    else
        b = "Impar";

    cout << "O numero informado e "<< b << endl;

    return 0;
}