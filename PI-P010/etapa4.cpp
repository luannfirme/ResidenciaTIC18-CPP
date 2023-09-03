#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

int main(void){
    int limiteAlunos;
    cout << "Informe o numero limite de alunos: ";
    cin >> limiteAlunos;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    char incluir, excluir, alterar;

    do {
        cout << "Deseja incluir mais alunos (s/n)? ";
        cin >> incluir;

        if (incluir == 's' || incluir == 'S') {
            if (nomes.size() >= limiteAlunos) {
                cout << "Limite de alunos atingido. Nao e possivel incluir mais alunos." << endl;
            } else {
                string nome;
                float nota1, nota2;

                cout << "Informe o nome do aluno: ";
                cin >> nome;

                cout << "Informe a primeira nota do aluno: ";
                cin >> nota1;

                cout << "Informe a segunda nota do aluno: ";
                cin >> nota2;

                auto it = lower_bound(nomes.begin(), nomes.end(), nome);
                int pos = it - nomes.begin();

                nomes.insert(it, nome);
                notas1.insert(notas1.begin() + pos, nota1);
                notas2.insert(notas2.begin() + pos, nota2);

                cout << "Aluno cadastrado com sucesso!" << endl;
            }
        }

        cout << "Deseja excluir algum aluno (s/n)? ";
        cin >> excluir;

        if (excluir == 's' || excluir == 'S') {
            if (nomes.empty()) {
                cout << "Não ha alunos para excluir." << endl;
            } else {
                string nome;
                cout << "Informe o nome do aluno que sera excluido: ";
                cin >> nome;

                auto it = find(nomes.begin(), nomes.end(), nome);

                if (it != nomes.end()) {
                    int pos = it - nomes.begin();
                    nomes.erase(nomes.begin() + pos);
                    notas1.erase(notas1.begin() + pos);
                    notas2.erase(notas2.begin() + pos);
                    cout << "Aluno excluido com sucesso!" << endl;
                } else {
                    cout << "Aluno nao encontrado." << endl;
                }
            }
        }

        cout << "Deseja alterar alguma nota (s/n)? ";
        cin >> alterar;

        if (alterar == 's' || alterar == 'S') {
            if (nomes.empty()) {
                cout << "Nao ha alunos para alterar." << endl;
            } else {
                string nome;
                cout << "Informe o nome do aluno que sera alterado: ";
                cin >> nome;

                auto it = find(nomes.begin(), nomes.end(), nome);

                if (it != nomes.end()) {
                    int opcao;
                    int pos = it - nomes.begin();
                    cout << "\nNotas de " << *it << " - Nota 1: " << notas1[pos] << " - Nota 2: " << notas2[pos] << endl;

                    do {
                        cout << "\nAlterar a primeira nota (1)" << endl;
                        cout << "Segunda nota (2)" << endl;
                        cout << "Ou nenhuma (0)" << endl;
                        cout << "Selecione: ";
                        cin >> opcao;

                        if (opcao == 1) {
                            cout << "Informe a nova primeira nota: ";
                            cin >> notas1[pos];
                        } else if (opcao == 2) {
                            cout << "Informe a nova segunda nota: ";
                            cin >> notas2[pos];
                        } else if (opcao == 0) {
                            break;
                        } else {
                            cout << "Opção Inválida." << endl;
                        }
                    } while (true);

                    cout << "Notas atualizadas com sucesso!" << endl;
                } else {
                    cout << "Aluno nao encontrado." << endl;
                }
            }
        }

    } while ((incluir == 's' || incluir == 'S') || (excluir == 's' || excluir == 'S') || (alterar == 's' || alterar == 'S'));

    cout << "\nLista de Alunos Ordenada:" << endl;
    for (int i = 0; i < nomes.size(); ++i) {
        string situacao;
        float media = (notas1[i] + notas2[i]) / 2.0;

        if(media >= 7){
            situacao = "APROVADO";
        }
        else if (media < 7){
            situacao = "REPROVADO";
        }

        cout << "Aluno: " << nomes[i] << " - Nota 1: " << notas1[i] << " - Nota 2: " << notas2[i] << " - Media das Notas: " << media << " - Situacao: " << situacao << endl;
    }

    return 0;
}