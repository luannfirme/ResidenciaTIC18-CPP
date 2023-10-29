#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Empregado {
    string nome, sobrenome, Rg;
    int anoNascimento, anoAdmissao;
    double salario;
};

void Reajustar(vector<Empregado>& empregados, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        empregados[i].salario *= 1.10;  
    }
    cout << endl;
    cout << "Aumento aplicado com sucesso !" << endl;
}

int main() {
    const int maxEmpregados = 50;
    vector<Empregado> empregados;
    int qtdEmpregados = 0;
    int escolha;

    do {
        cout << endl << endl;
        cout << "######## MENU PRINCIPAL ########" << endl;
        cout << "1. Cadastrar Empregado" << endl;
        cout << "2. Visualizar Empregados" << endl;
        cout << "3. Aumentar Salario (10%)" << endl;
        cout << "0. Sair" << endl;
        cout << "Resposta: ";
        cin >> escolha;
        cin.ignore();

        switch (escolha) {
            case 1: {
                if (empregados.size() < maxEmpregados) {
                    Empregado novoEmpregado;
                    cout << endl;
                    cout << "Nome: ";
                    getline(cin, novoEmpregado.nome);
                    cout << "Sobrenome: ";
                    getline(cin, novoEmpregado.sobrenome);
                    cout << "Ano de nascimento: ";
                    cin >> novoEmpregado.anoNascimento;
                    cout << "RG: ";
                    cin >> novoEmpregado.Rg;
                    cout << "Ano de admissao: ";
                    cin >> novoEmpregado.anoAdmissao;
                    cout << "Salario: ";
                    cin >> novoEmpregado.salario;
                    qtdEmpregados += 1;
                    empregados.push_back(novoEmpregado);
                    cout << "Empregado cadastrado com sucesso!" << endl;
                } else {
                    cout << "Limite de empregados atingido!" << endl;
                }
                break;
            }
            case 2: {
                cout << endl;
                cout << "######## Lista de Empregados ########" << endl;
                for (int i = 0; i < qtdEmpregados; i++) {
                    cout << "Nome Completo: " << empregados[i].nome << " " << empregados[i].sobrenome << " - ";
                    cout << "RG: " << empregados[i].Rg << " - Nascido em: " << empregados[i].anoNascimento << " - ";
                    cout << "Admitido em: " << empregados[i].anoAdmissao << " - Salario: R$ "  << fixed << setprecision(2) << empregados[i].salario << endl;
                }
                break;
            }
            case 3: {
                Reajustar(empregados, qtdEmpregados);
                break;
            }
            case 0: {
                break;
            }
            default: {
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
            }
        }
    } while (escolha != 0);

    return 0;
}