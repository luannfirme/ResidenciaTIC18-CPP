#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Aluno {
    int matricula;
    float notas[3];
};

int main() {

    vector<Aluno> alunos;

    char continuar;

    do {
        Aluno aluno;

        cout << "Informe a matricula do aluno: ";
        cin >> aluno.matricula;

        cout << "Informe as notas do aluno: ";
        for (int i = 0; i < 3; ++i) {
            cin >> aluno.notas[i];
        }

        alunos.push_back(aluno);

        cout << "Aluno cadastrado com sucesso!" << endl;

        cout << "Deseja cadastrar outro aluno (s/n)? ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    for (const Aluno& aluno : alunos) {
        float somaNotas = 0.0;
        for (int i = 0; i < 3; ++i) {
            somaNotas += aluno.notas[i];
        }
        float media = somaNotas / 3.0;

        cout << "MATRICULA   " <<  "  NOTA1  " << "    NOTA2  " << "    NOTA3  " << "  MEDIA  " << endl;
        cout << "==================================================" << endl;
        cout << fixed << setprecision(1);
        cout << aluno.matricula << "      ";
        for (int i = 0; i < 3; ++i) {
            cout << aluno.notas[i];
            if (i < 2) {
                cout << "        ";
            }
        }
        cout << fixed << setprecision(1);
        cout << "      " << media << endl;
        cout << endl;
    }

    return 0;
}
