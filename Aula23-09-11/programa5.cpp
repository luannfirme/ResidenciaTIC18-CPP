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
    cout << minhaData.dia <<"/"<< minhaData.mes <<"/"<< minhaData.ano << endl;
}

void lerData (MinhaData *minhaData){
    cin >> minhaData->dia >> minhaData->mes >> minhaData->ano;
}


int anosCompletos (MinhaData dtFinal, MinhaData dtInicial){

    int x;
    x = dtFinal.ano - dtInicial.ano;

    if(dtFinal.mes > dtInicial.mes)
        x--;
    
    if(dtFinal.mes == dtInicial.mes && dtFinal.dia > dtInicial.dia)
        x--;

    return x;
}

void escreveTitulo (TituloEleitor titulo){

    MinhaData hoje;

    hoje.dia = 11;
    hoje.mes = 9;
    hoje.ano = 2023;

    cout << endl << endl << endl;
    cout <<"------ TITULO ELEITORAL ------"<< endl;
    cout <<"Nome: " << titulo.nome << endl;
    cout <<"Data de Nacimento: ";
    mostraData(titulo.nascimento);
    cout <<"Inscricao: " << titulo.numEscricao << endl;
    cout <<"Zona: " << titulo.zona <<"   Secao: " << titulo.secao<< endl;
    cout <<"Local: " << titulo.municipio <<" - " << titulo.uf << endl;
    cout <<"Emissao: ";
    mostraData(titulo.emissao);
    cout <<"Titulo emitido a " << anosCompletos(hoje, titulo.emissao) <<" anos."<< endl;
    cout <<"------------------------------"<< endl;
    cout << endl << endl << endl;
}

void lerTitulo(TituloEleitor *titulo){
    cout << "Digite o nome do eleitor: ";
    cin >> titulo->nome;
    cout << "Digite a data de nascimento: ";
    lerData(&titulo->nascimento);
    cout << "Digite o numero de Inscricao: ";
    cin >> titulo->numEscricao;
    cout << "Digite a Zona: ";
    cin >> titulo->zona;
    cout << "Digite a Secao: ";
    cin >> titulo->secao;
    cout << "Digite o Municipio: ";
    cin >> titulo->municipio;
    cout << "Digite a UF: ";
    cin >> titulo->uf;
    cout << "Digite a data de emissao: ";
    lerData(&titulo->emissao);
}

int main (void){

    TituloEleitor el; 

    lerTitulo(&el);

    escreveTitulo(el);

    return 0;
}