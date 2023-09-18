#include <iostream>
#include <string>

using namespace std;

struct Cliente {
    string nome;
    string cpf;
};

void lerDados(Cliente *cliente ){
    cout << "Digite o nome do cliente: ";
    cin >> cliente->nome;

    cout << "Digite o CPF do cliente: ";
    cin >> cliente->cpf;
}


void mostrarDados(Cliente cliente ){
    cout << endl << endl<< endl<< endl;
    cout << "####### CLIENTE : #######" << endl;
    cout << "Nome: " << cliente.nome << endl;
    cout << "CPF: " << cliente.cpf << endl;
    cout << "########################" << endl;
    cout << endl << endl<< endl<< endl;
}

int main (void){

    Cliente cliente;

    lerDados(&cliente);

    mostrarDados(cliente);

    return 0;
}