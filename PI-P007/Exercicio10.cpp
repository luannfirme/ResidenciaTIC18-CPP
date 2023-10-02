#include <iostream>

using namespace std ;

int main(void) {
    int n;

    cout << "Digite um numero inteiro: ";
    cin >> n;
    cout << endl;

    int primeiro = 0, segundo = 1, proximo;

    cout << "Sequencia de Fibonacci ate " << n << ":\n";

    while (primeiro <= n) {
        cout << primeiro << " ";

        proximo = primeiro + segundo;
        primeiro = segundo;
        segundo = proximo;
    }

    cout << endl;

    return 0;
}