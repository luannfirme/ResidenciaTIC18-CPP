#include <iostream>

using namespace std;

void troca (float &k, float &l){
    swap(k, l);
}

int main (void){

float a, b;

cout << "Digite dois valores: ";
cin >> a >> b;

troca(a, b);

cout << "O novo valor de a: " << a << endl;
cout << "O novo valor de b: " << b << endl;

return 0;
}