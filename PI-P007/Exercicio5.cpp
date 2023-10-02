#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std ;

int main(void) {
    int numSis, numUser, tentativas = 0;

    srand(time(0));

    numSis = 1 + rand() % 100;

    while (true) {
        cout << "Adivinhe qual sera o numero que o sistema ira gerar: ";
        cin >> numUser;
        tentativas++;

        if (numSis == numUser) {
            cout << "O palpite esta correto" << endl;
            break; 
        } else if (numSis < numUser) {
            cout << "O palpite esta alto" << endl;
        } else {
            cout << "O palpite esta baixo" << endl;
        }
    }

    cout << "O numero aleatorio gerado foi: " << numSis << endl;
    cout << "Voce acertou em " << tentativas << " tentativas." << endl;

    return 0;
}