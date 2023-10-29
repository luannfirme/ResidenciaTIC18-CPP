#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Produto {
    string codigo, nome;
    double preco;
};

const int maxProdutos = 300;
vector<Produto> produtos(maxProdutos);
int totalProdutos = 0;

bool validarCodigo(string codigo) {
    if (codigo.length() > 13) {
        cout << "Limite de numeros excedido." << endl;
        return false;
    }

    for (char c : codigo) {
        if (!isdigit(c)) {
            cout << "Apenas numeros sao aceitos." << endl;
            return false;
        }
    }

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            cout << "Produto com o mesmo codigo ja cadastrado." << endl;
            return false;
        }
    }

    return true;
}

bool validarNome(string nome) {
    if (nome.length() > 20) {
        cout << "Limite de caracteres excedido." << endl;
        return false;
    }

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].nome == nome) {
            cout << "Produto com o mesmo nome ja cadastrado." << endl;
            return false;
        }
    }

    return true;
}

void inserirProduto() {
    if (totalProdutos >= maxProdutos) {
        cout << "Limite de produtos cadastrados atingido." << endl;
        return;
    }

    Produto novoProduto;
    string codigo, nome;

    do {
        cout << "Digite o codigo do produto (max 13 numeros): ";
        getline(cin, codigo);

    } while (!validarCodigo(codigo));
    novoProduto.codigo = codigo;

    do {
        cout << "Digite o nome do produto (max. 20 caracteres): ";;
        getline(cin, nome);

        if (!validarNome(nome)) {
            cout << "Nome invalido. Tente novamente." << endl;
        }
    } while (!validarNome(nome));
    novoProduto.nome = nome;

    cout << "Digite o preco do produto (R$): ";
    cin >> novoProduto.preco;

    produtos[totalProdutos++] = novoProduto;
    cout << "Produto cadastrado com sucesso!" << endl;
}


void excluirProduto() {
    string codigo;

    cout << endl;
    cout << "Digite o codigo do produto a ser excluido: ";
    cin >> codigo;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            
            for (int j = i; j < totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            totalProdutos--;

            cout << endl;
            cout << "Produto excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Produto nao encontrado." << endl;
}


void listarProdutos() {
    if (totalProdutos == 0) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }
    
    cout << endl;
    cout << "Lista de produtos cadastrados:" << endl;
    cout << setw(10) << "Codigo" << setw(25) << "Produto" << setw(10) << "Preco" << endl;
    for (int i = 0; i < totalProdutos; i++) {
        cout << setw(10) << produtos[i].codigo << setw(25) << produtos[i].nome << setw(10) << "R$ "<< fixed << setprecision(2) << produtos[i].preco << endl;
    }
}


void consultarPreco() {
    string codigo;

    cout << endl;
    cout << "Digite o codigo do produto para consultar o preco: ";
    cin >> codigo;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            cout << endl;
            cout << "Preco do produto '" << produtos[i].nome << "': R$ " << fixed << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }

    cout << "Produto nao encontrado." << endl;
}

int main() {
    int escolha;

    do {
        cout << endl << endl;
        cout << "######## MENU PRINCIPAL ########" << endl;
        cout << "1. Cadastrar Produto" << endl;
        cout << "2. Consultar Produto" << endl;
        cout << "3. Listar todos" << endl;
        cout << "4. Excluir Produto" << endl;
        cout << "0. Sair" << endl;
        cout << "Resposta: ";
        cin >> escolha;
        cin.ignore();

        switch (escolha) {
            case 1:
                inserirProduto();
                break;
            case 2:
                consultarPreco();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                excluirProduto();
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (escolha != 0);

    return 0;
}
