#include <iostream>

using namespace std;

int fat(int v){
    int fatorial = 1;

    for(int i= 1; i <= v; i++)
        fatorial *= i;

     return fatorial;
}
int combinacao (int n, int p){

    int calc = fat(n) / (fat(p) * fat(n - p));

    return calc;
}

int main (void){

int n, p, a, o;

cout << "Digite o total de itens: ";
cin >> n;


cout << "Digite quantos serao tomados: ";
cin >> p;
    
do {
    cout << "O que voce deseja fazer?" << endl;
    cout << "1 - Arranjo" << endl;
    cout << "2 - Combinacao" << endl;
    cout << "R = ";
    cin >> o;

    if( o == 1)
        a= fat(n) / fat(n-p);

    else if (o == 2)
        a = combinacao(n, p);

    else
        cout << "Opcao invalida - Programa encerrado !" << endl << endl;

} while (true);

cout << n << " itens tomados " << p << " a " << p << endl;
cout << "Combinacao de " << a << " maneiras" << endl;

return 0;
}