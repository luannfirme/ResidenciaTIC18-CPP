#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std ;

int main(void) {
    int a,b,c;

    cout<< "digite dois numeros inteiros: "<<endl;
    cin >> a >> b;

    c = 4 * a + b / 3 - 5;
    
    cout << "O resultado da expressao '4 * a + b / 3 - 5' e: " << c << endl;

    c = (4 * a + b) / (3 - 5);

    cout << "O resultado da expressao '(4 * a + b) / (3 - 5)' e: " << c << endl;

    /*
    O resultado é diferente porque não havendo os parênteses a expressão é calculada em conjunto por ordem de operação,
    Enquanto quando é inserido o parênteses é calculado inicialmente os valores dentro do parêntes e posteriormente o que está fora.
    */

    int d;

    d= pow(a,2) + 2 * b + c ;

    cout << "o resultado da expressao 'a² + 2 * b + c' e: "<< d << endl;

    return 0;
}
