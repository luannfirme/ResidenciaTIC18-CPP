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

void mostrarDados(Cliente cliente){
    cout << endl << endl<< endl<< endl;
    cout << "####### CLIENTE : #######" << endl;
    cout << "Nome: " << cliente.nome << endl;
    cout << "CPF: " << cliente.cpf << endl;
    cout << "########################" << endl;
    cout << endl << endl<< endl<< endl;
}

int mostrarMenu(){
    int resp;
    do {
        cout << "####### MENU #######" << endl;
        cout << "1. Novo cliente" << endl;
        cout << "2. Buscar cliente" << endl;
        cout << "3. Excluir cliente" << endl;
        cin >> resp;
    } while ((resp < 1 ) || (resp > 3));
}

int main (void){

    Cliente cliente;
    int selecionado = mostrarMenu();

    cout << "Selecionado: " << selecionado << endl;    

    lerDados(&cliente);

    mostrarDados(cliente);

    return 0;
}