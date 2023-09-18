#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Veiculo {
    string Cor;
    string Placa;
    string Modelo;
};

struct Cliente {
    string nome;
    string cpf;
    vector<Veiculo> veiculos;
};

void lerDados(Cliente *cliente ){
    cout << "Digite o nome do cliente: ";
    cin >> cliente->nome;

    cout << "Digite o CPF do cliente: ";
    cin >> cliente->cpf;
}

void mostrarDados(Cliente cliente){
    cout << endl << endl<< endl<< endl;
    cout << "####### CLIENTE : #######" << endl << endl;
    cout << "Nome: " << cliente.nome << endl;
    cout << "CPF: " << cliente.cpf << endl;
    if(cliente.veiculos.size() > 0){
    cout << "------- VEICULOS -------" << endl;
    for (int i = 0; i < cliente.veiculos.size(); ++i) {
        cout << "Modelo: " << cliente.veiculos[i].Modelo << " Placa: " << cliente.veiculos[i].Placa << " Cor: " << cliente.veiculos[i].Cor << endl << endl;
    }
    }
    cout << "########################" << endl;
    cout << endl << endl<< endl<< endl;
}

void excluirDados (Cliente *cliente){
    cliente->nome.erase();
    cliente->cpf.erase();
    cout << endl;
    cout << "Cliente excluido com sucesso" << endl;
    cout << endl << endl<< endl<< endl;
}

void alterarDados(Cliente *cliente){
    string nome;
    cout << "Informe o novo nome: ";
    cin >> nome;
    cliente->nome = nome;
    cout << "Cliente alterado com sucesso" << endl;
}

void novoVeiculo(Cliente *cliente){
    Veiculo veiculo;
    cout << "Informe a cor do veiculo: ";
    cin >> veiculo.Cor;
    cout << "Informe a placa do veiculo: ";
    cin >> veiculo.Placa;
    cout << "Informe o modelo do veiculo: ";
    cin >> veiculo.Modelo;
    cliente->veiculos.push_back(veiculo);
    cout << "Cliente alterado com sucesso" << endl;
}

int buscarPosicao(vector<Cliente> clientes, string cpf){
    for (int i = 0; i < clientes.size(); ++i) {
        if(clientes[i].cpf == cpf){
            return i;
        }
    }
}

int mostrarMenu(){
    int resp;
    do {
        cout << "####### MENU #######" << endl;
        cout << "1. Novo cliente" << endl;
        cout << "2. Buscar cliente" << endl;
        cout << "3. Excluir cliente" << endl;
        cout << "4. Listar todos" << endl;
        cout << "5. Alterar Cliente" << endl;
        cout << "6. Novo Veiculo" << endl;
        cout << "0. Encerrar" << endl;
        cin >> resp;
    } while ((resp < 0 ) || (resp > 6));
}

string DataTimeAtual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
 
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %X", now);
    return buffer;
}

int main (void){

    vector<Cliente> clientes;
    int selecionado;

    cout << endl << endl<< endl<< endl;
    cout << "Horario atual: " << DataTimeAtual() << endl << endl;

    do {
        selecionado = mostrarMenu();

        if(selecionado == 1){
            Cliente cliente;
            lerDados(&cliente);
            clientes.push_back(cliente);
        }

        if (selecionado >= 2 && selecionado <= 3 || selecionado == 5 || selecionado == 6){
                string cpf;
                cout << "Informe o CPF do cliente: ";
                cin >> cpf;

                int posicao = buscarPosicao(clientes, cpf);

                if(selecionado == 2)
                    mostrarDados(clientes[posicao]);

                if (selecionado == 3)
                    excluirDados(&clientes[posicao]);

                if (selecionado == 5)
                    alterarDados(&clientes[posicao]);

                if (selecionado == 6)
                    novoVeiculo(&clientes[posicao]);
                
        }

        if (selecionado == 4){
            if (clientes.empty()) {
                cout << "Nenhum cliente cadastrado." << endl;
            } else {
                cout << endl;
                for (int i = 0; i < clientes.size(); ++i) {
                    cout << "Cliente: " << clientes[i].nome << " - CPF: " << clientes[i].cpf << endl;
                }
                cout << endl << endl<< endl<< endl;
            }
        }

    } while (selecionado != 0);


    cout << "Programa encerrado..." << endl;

    return 0;
}