#include <iostream>
#include <limits>

using namespace std;

int main(void){

    // a
    int valorMinimoInt = numeric_limits<int>::min();
    int valorMaximoInt = numeric_limits<int>::max();

    cout << "Menor valor em int: " << valorMinimoInt << endl;
    cout << "Maior valor em int: " << valorMaximoInt << endl;

    // b
    unsigned long int uli = numeric_limits<unsigned long int>::max();

    // c
    long int li = uli;
    uli = li;

    cout << "Valor de li atribuido em uli: " << li << endl;
    cout << "Valor de uli atribuido em li: " << uli << endl;

    /*
     * Quando atribuí o valor máximo de um uli a li,
     * vi que li não pode representar o maior valor possível de uli
     * resultando em um valor negativo para li. 
     */

    // d
    li = numeric_limits<long int>::max();

    // e
    unsigned int ui = li;
    li = ui;

    cout << "Valor de ui atribuido em li: " << ui << endl;
    cout << "Valor de li atribuido em ui: " << li << endl;

    /*
     * Quando atribuí o valor máximo li a um ui,
     * O valor máximo de li é maior do que o valor máximo que ui pode ser atribuido
     * Quando atribuí li novamente a ui, o valor original de li não foi apresentado.
     */

    // f
    ui = numeric_limits<unsigned int>::max();
    cout << "Valor maximo de ui: " << li << endl;

    return 0;
}