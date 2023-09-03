#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    int limiteAlunos;
    cout << "Informe o numero limite de alunos: ";
    cin >> limiteAlunos;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    for (int i = 1; i <= limiteAlunos; ++i) {
        string nome;
        float nota1, nota2;

        cout << "Informe o nome do aluno " << i << ": ";
        cout << "Informe o nome do aluno " << i << ": ";
        cin >> nome;

        cout << "Informe a primeira nota do aluno " << i << ": ";
        cin >> nota1;

        cout << "Informe a segunda nota do aluno " << i << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);

        cout << "Aluno cadastrado com sucesso!" << endl;
    }

    cout << "\nLista de Alunos e Notas:" << endl;
    for (int i = 0; i < nomes.size(); ++i) {
        float media = (notas1[i] + notas2[i]) / 2.0;

        cout << "Aluno: " << nomes[i] << " - Nota 1: " << notas1[i] << " - Nota 2: " << notas2[i] << " - Media das Notas: " << media << endl;
    }

    return 0;
}