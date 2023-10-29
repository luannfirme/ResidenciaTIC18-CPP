#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct DataHora {
    int dia, mes, ano, hora, minuto;
};

istream& operator>>(istream& is, DataHora& dataHora) {
    is >> dataHora.dia >> dataHora.mes >> dataHora.ano >> dataHora.hora >> dataHora.minuto;
    return is;
}

struct Passagem {
    int numeroAssento;
    DataHora dataHora;
    string cpf;
    string nomePassageiro;
    int idadePassageiro;
    double valor;
};

struct Viagem {
    int numero, assentosVendidos;
    string origem;
    string destino;
    string horario;
    vector<Passagem> passageiros;
};

vector<Passagem> passagens;
vector<Viagem> viagens;

void cadastrarPassageiro() {
    Passagem novaPassagem;
    cout << "Numero do assento: ";
    cin >> novaPassagem.numeroAssento;
    cout << "Data e Hora: ";
    cin >> novaPassagem.dataHora;
    cout << "CPF: ";
    cin >> novaPassagem.cpf;
    cout << "Nome do Passageiro: ";
    cin.ignore();
    getline(cin, novaPassagem.nomePassageiro);
    cout << "Idade do Passageiro: ";
    cin >> novaPassagem.idadePassageiro;
    novaPassagem.valor = 80.0;
    passagens.push_back(novaPassagem);
    cout << "Passagem cadastrada com sucesso!" << endl;
}

void cadastrarViagem() {
    Viagem novaViagem;
    novaViagem.numero = viagens.size() + 1;
    novaViagem.assentosVendidos = 0;
    cout << "Origem: ";
    cin >> novaViagem.origem;
    cout << "Destino: ";
    cin >> novaViagem.destino;
    cout << "Horario: ";
    cin >> novaViagem.horario;
    viagens.push_back(novaViagem);
    cout << "Viagem N. " << novaViagem.numero << " cadastrada  com sucesso!" << endl;
}

void associarPassageiroPorCPF() {
    string cpf;
    cout << "Informe o CPF do passageiro: ";
    cin >> cpf;

    int numeroViagem;
    cout << "Informe o numero da viagem: ";
    cin >> numeroViagem;

    if (numeroViagem <= viagens.size() && viagens[numeroViagem - 1].assentosVendidos < 40) {
        Passagem novaPassagem;
        novaPassagem.cpf = cpf;

        for (const auto& passagem : passagens) {
            if (passagem.cpf == cpf) {
                novaPassagem = passagem;
                break;
            }
        }

        viagens[numeroViagem - 1].passageiros.push_back(novaPassagem);
        viagens[numeroViagem - 1].assentosVendidos++;
        cout << "Passageiro associado a viagem com sucesso!" << endl;
    } else {
        cout << "Viagem nao encontrada ou todos os assentos ja foram vendidos." << endl;
    }
}

double totalArrecadadoViagem(int numeroViagem) {
    double total = 0.0;
    for (const auto& passagem : viagens[numeroViagem - 1].passageiros) {
        total += passagem.valor;
    }
    return total;
}

double totalArrecadadoMes(int mes) {
    double total = 0.0;
    for (const auto& viagem : viagens) {
        int mesViagem = viagem.passageiros[0].dataHora.mes;
        if (mesViagem == mes) {
            total += viagem.passageiros.size() * 80.0;
        }
    }
    return total;
}

string nomePassageiroPoltrona(int numeroViagem, int poltrona) {
    for (const auto& viagem : viagens) {
        if (viagem.numero == numeroViagem) {
            for (const auto& passagem : viagem.passageiros) {
                if (passagem.numeroAssento == poltrona) {
                    return passagem.nomePassageiro;
                }
            }
        }
    }
    return "Poltrona nao encontrada";
}

string horarioMaisRentavel() {
    unordered_map<string, double> arrecadacaoPorHorario;
    string horarioMaisRentavel;
    double maiorArrecadacao = 0.0;

    for (const auto& viagem : viagens) {
        for (const auto& passageiro : viagem.passageiros) {
            string horario = to_string(passageiro.dataHora.hora) + ":" + to_string(passageiro.dataHora.minuto);
            arrecadacaoPorHorario[horario] += passageiro.valor;
        }
    }

    for (const auto& par : arrecadacaoPorHorario) {
        if (par.second > maiorArrecadacao) {
            maiorArrecadacao = par.second;
            horarioMaisRentavel = par.first;
        }
    }

    return horarioMaisRentavel;
}

double mediaIdadePassageiros() {
    int totalIdades = 0;
    int totalPassageiros = 0;
    for (const auto& viagem : viagens) {
        for (const auto& passagem : viagem.passageiros) {
            totalIdades += passagem.idadePassageiro;
            totalPassageiros++;
        }
    }
    if (totalPassageiros > 0) {
        return static_cast<double>(totalIdades) / totalPassageiros;
    } else {
        return 0.0;
    }
}

int main() {
    int escolha;
    do {
        cout << endl << endl;
        cout << "######## MENU PRINCIPAL ########" << endl;
        cout << "1. Cadastrar Passagem" << endl;
        cout << "2. Cadastrar Viagem" << endl;
        cout << "3. Cadastrar Passagem em Viagem" << endl;
        cout << "4. Total arrecadado por viagem" << endl;
        cout << "5. Total arrecadado em um mes" << endl;
        cout << "6. Nome do passageiro de uma poltrona P de uma determinada viagem" << endl;
        cout << "7. Horario de viagem mais rentavel" << endl;
        cout << "8. Media de idade dos passageiros" << endl;
        cout << "0. Sair" << endl;
        cout << "Resposta: ";
        cin >> escolha;
        cout << endl << endl;
        cin.ignore();

        switch (escolha) {
            case 1: {
                cadastrarPassageiro();
                break;
            }
            case 2: {
                cadastrarViagem();
                break;
            }
            case 3: {
                associarPassageiroPorCPF();
                break;
            }
            case 4: {
                int numeroViagem;
                cout << "Informe o numero da viagem: ";
                cin >> numeroViagem;
                double total = totalArrecadadoViagem(numeroViagem);
                cout << "Total arrecadado para a viagem " << numeroViagem << ": R$ " << total << endl;
                break;
            }
            case 5: {
                int mes;
                cout << "Informe o mes (1-12): ";
                cin >> mes;
                double total = totalArrecadadoMes(mes);
                cout << "Total arrecadado no mes " << mes << ": R$ " << total << endl;
                break;
            }
            case 6: {
                int poltrona, numeroViagem;
                cout << "Informe o numero da viagem: ";
                cin >> numeroViagem;
                cout << "Informe o numero da poltrona: ";
                cin >> poltrona;
                string nome = nomePassageiroPoltrona(numeroViagem, poltrona);
                cout << "Nome do passageiro da poltrona " << poltrona << ": " << nome << endl;
                break;
            }
            case 7: {
                string horario = horarioMaisRentavel();
                cout << "Horario de viagem mais rentavel: " << horario << endl;
                break;
            }
            case 8: {
                double media = mediaIdadePassageiros();
                cout << "Media de idade dos passageiros: " << media << endl;
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