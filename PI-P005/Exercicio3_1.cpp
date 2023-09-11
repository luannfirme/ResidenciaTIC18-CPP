#include <iostream>

using namespace std;

int main(void){
    int a, b, c;

    cout << "Digite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;

    c = a + b;
    cout << "Soma de a e b em formato hexadecimal: " << hex << c << endl;

    c = a * b;
    cout << "Produto de a e b em formato octal: " << oct << c << endl;

    c = abs(a - b);
    cout << "Valor absoluto da diferenca entre a e b: " << c << endl;

    if (b != 0) {
        c = a / b;
        cout << "Quociente de a dividido por b: " << c << endl;

        cout << (a % b == 0 ? "a e divisivel de forma exata por b" : "a nao e divisivel de forma exata por b") << endl;

    } else {
        cout << "A divisão por zero nao e possivel." << endl;
    }

    return 0;
}