#include <iostream>
#include <string>

using namespace std;

struct titulo_eleitor {
    string nome;
    int diaNasc, mesNasc, anoNasc;
    string numEscricao;
    string zona, secao;
    string municipio, uf;
    int diaEmissao, mesEmissao, anoEmissao;
};

void mostraData (int d, int m, int a){
    cout <<"Data de nascimento: "<< d <<"/"<< m <<"/"<< a << endl;
}

int main (void){
 
    titulo_eleitor el;
    cout << "Digite o nome do eleitor: ";
    cin >> el.nome;
    cout << "Digite a data de nascmento: ";
    cin >> el.diaNasc >> el.mesNasc >> el.anoNasc;

    cout << endl << endl << endl;
    cout <<"------ TITULO ELEITORAL ------"<< endl;
    cout <<"Nome: " << el.nome << endl;
    mostraData(el.diaNasc, el.mesNasc, el.anoNasc);
    cout << endl << endl << endl;

    return 0;
}