#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool AnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool ValidarData(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12 || dia < 1 || dia > 31)
        return false;

    int diasInmes = 31;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        diasInmes = 30;
    else if (mes == 2) {
        diasInmes = AnoBissexto(ano) ? 29 : 28;
    }

    return dia <= diasInmes;
}

string ObterNomeDoMes(int mes) {
    static const string mess[] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    return mess[mes - 1];
}

int main() {
    string novaData;
    cout << "Digite uma data (dd/mm/aaaa): ";
    cin >> novaData;

    int dia, mes, ano;
    char delimitador;
    istringstream dataStream(novaData);
    dataStream >> dia >> delimitador >> mes >> delimitador >> ano;

    if (!dataStream || delimitador != '/' || !ValidarData(dia, mes, ano)) {
        cout << "Data invalida." << endl;
        return 1;
    }

    cout << "Dia: " << dia << endl;
    cout << "Mes: " << ObterNomeDoMes(mes) << endl;
    cout << "Ano: " << ano << endl;

    cout << "Data por extenso: " << dia << " de " << ObterNomeDoMes(mes) << " de " << ano << endl;

    return 0;
}