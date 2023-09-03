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

    char incluir, excluir;

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

    } while ((incluir == 's' || incluir == 'S') || (excluir == 's' || excluir == 'S'));

    cout << "\nLista de Alunos Ordenada:" << endl;
    for (int i = 0; i < nomes.size(); ++i) {
        float media = (notas1[i] + notas2[i]) / 2.0;

        cout << "Aluno: " << nomes[i] << " - Nota 1: " << notas1[i] << " - Nota 2: " << notas2[i] << " - Media das Notas: " << media << endl;
    }

    return 0;
}