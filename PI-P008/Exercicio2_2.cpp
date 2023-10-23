#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int numeroEstacoes = 250;

    float temperaturas[numeroEstacoes];

    srand(time(0));

    for (int i = 0; i < numeroEstacoes; ++i) {
        /* temperaturas[i] = 1 + 30.0 * (rand() % 100) / 3000.0;  [cálculo errado ?] */
        temperaturas[i] = 10 + (float) (rand() % 3001) / 100; 
    }

    cout << endl;

    cout << "Temperaturas geradas:" << endl;
    
    for (int i = 0; i < numeroEstacoes; ++i) {
        cout << fixed << setprecision(2) << temperaturas[i] << " ";
    }

    float tempMax = temperaturas[0];
    float tempMin = temperaturas[0];
    float somaTemperaturas = 0;

    for (int i = 1; i < numeroEstacoes; ++i) {
        if (temperaturas[i] > tempMax) {
            tempMax = temperaturas[i];
        }
        if (temperaturas[i] < tempMin) {
            tempMin = temperaturas[i];
        }
        somaTemperaturas += temperaturas[i];
    }

    float temperaturaMedia = somaTemperaturas / numeroEstacoes;

    cout << endl << endl;
    cout << "Temperatura maxima: " << tempMax << endl;
    cout << "Temperatura minima: " << tempMin << endl;
    cout << "Temperatura media: " << temperaturaMedia << endl;

    for (int i = 0; i < numeroEstacoes; ++i) {
        if (temperaturas[i] > temperaturaMedia) {
            temperaturas[i] += 1;
        } else {
            temperaturas[i] -= 2;
        }
    }

    cout << endl;
    cout << "Temperaturas atualizadas apos previsao:" << endl;

    for (int i = 0; i < numeroEstacoes; ++i) {
        cout << temperaturas[i] << " ";
    }

    cout << endl << endl;

    return 0;
}