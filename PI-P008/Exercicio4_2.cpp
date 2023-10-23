#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <bits/stdc++.h> 

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

    vector<string> listaDeStrings;

    for (int i = 0; i < 10; i++) {
        string novaString;
        gerarStringAleatoria(novaString);
        tornarPrimeiroCaractereMaiusculo(novaString);
        listaDeStrings.push_back(novaString);
    }

    sort(listaDeStrings.begin(), listaDeStrings.end());

    cout << endl;

    for (const auto& str : listaDeStrings) {
        cout << str << endl;
    }

    cout << endl;
    
    return 0;
}
