#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int numeroAlunos = 15;

    srand(time(0));

    float notasAvaliacao1[numeroAlunos];
    for (int i = 0; i < numeroAlunos; ++i) {
        notasAvaliacao1[i] = ((float)rand() / RAND_MAX) * 10;
    }

    float notasAvaliacao2[numeroAlunos];
    for (int i = 0; i < numeroAlunos; ++i) {
        notasAvaliacao2[i] = ((float)rand() / RAND_MAX) * 10;
    }

    cout << endl;

    for (int i = 0; i < numeroAlunos; ++i) {
        float media = (notasAvaliacao1[i] + notasAvaliacao2[i]) / 2.0;
        
        cout << "Aluno " << setw(2) << setfill('0') << i+1 << " | Nota 1: " << fixed << setprecision(2) << notasAvaliacao1[i] << " | Nota 2: " << notasAvaliacao2[i] << " | Media: " << media << " | ";

        if (notasAvaliacao2[i] > notasAvaliacao1[i]) {
            cout << "Melhorou" << endl;
        } else if (notasAvaliacao2[i] < notasAvaliacao1[i]) {
            cout << "Piorou" << endl;
        } else {
            cout << "Manteve a nota" << endl;
        }
    }

    cout << endl;

    return 0;
}