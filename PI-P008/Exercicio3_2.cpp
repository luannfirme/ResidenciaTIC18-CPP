#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char gerarCaractereAleatorio() {
    return 'a' + rand() % ('z' - 'a' + 1);
}

void gerarStringAleatoria(string& str) {
    for (int i = 0; i < 10; i++) {
        str += gerarCaractereAleatorio();
    }
}

void tornarPrimeiroCaractereMaiusculo(string& str) {
    str[0] = toupper(str[0]);
}

int main() {
    srand(time(0));

    string string1, string2;

    gerarStringAleatoria(string1);
    gerarStringAleatoria(string2);

    tornarPrimeiroCaractereMaiusculo(string1);
    tornarPrimeiroCaractereMaiusculo(string2);

    if (string1 < string2) {
        cout << string1 << endl << string2 << endl;
    } else {
        cout << string2 << endl << string1 << endl;
    }

    return 0;
}
