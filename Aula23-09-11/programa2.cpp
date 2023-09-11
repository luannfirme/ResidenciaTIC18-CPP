#include <iostream>
#include <string>

using namespace std;

struct MinhaData
{
    int dia, mes, ano;
};


struct TituloEleitor {
    string nome;
    MinhaData nascimento;
    string numEscricao;
    string zona, secao;
    string municipio, uf;
    MinhaData emissao;
};


void mostraData (MinhaData minhaData){
    cout <<"Data de nascimento: "<< minhaData.dia <<"/"<< minhaData.mes <<"/"<< minhaData.ano << endl;
}

int main (void){
 
    TituloEleitor el;
    cout << "Digite o nome do eleitor: ";
    cin >> el.nome;
    cout << "Digite a data de nascmento: ";
    cin >> el.nascimento.dia >> el.nascimento.mes >> el.nascimento.ano;

    cout << endl << endl << endl;
    cout <<"------ TITULO ELEITORAL ------"<< endl;
    cout <<"Nome: " << el.nome << endl;
    mostraData(el.nascimento);
    cout << endl << endl << endl;

    return 0;
}