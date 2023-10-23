#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int tamanhoArray = 100;
    const int valorMaximo = 20;

    int array[tamanhoArray];

    srand(time(0));

    for (int i = 0; i < tamanhoArray; ++i) {
        array[i] = 1 + rand() % valorMaximo;
    }

    int frequencia[valorMaximo] = {0};

    cout << endl;

    cout << "Numeros gerados:" << endl;
    
    for (int i = 0; i < tamanhoArray; ++i) {
        frequencia[array[i] - 1]++;
        cout << array[i] << " ";
    }

    int maxFrequencia = 0;
    for (int i = 0; i < valorMaximo; ++i) {
        if (frequencia[i] > maxFrequencia) {
            maxFrequencia = frequencia[i];
        }
    }

    cout << endl << endl;

    cout << "Valor(es) que aparece(m) com mais frequencia: " << endl;
    for (int i = 0; i < valorMaximo; ++i) {
        if (frequencia[i] == maxFrequencia) {
            cout << i + 1 << " ";
        }
    }

    cout << endl << endl;

    return 0;
}