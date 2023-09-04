#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (void){

float nota1[5];
float nota2[5];
string aluno;
vector<string> alunos;
int x = 0;
int a;

for(int i = 0; i <5; i++){
    cout << "Informe o nome de um aluno: ";
    cin >> aluno;

    alunos.push_back(aluno);

    cout << "Informe a primeira nota: ";
    cin >> nota1[i];

    cout << "Informe a segunda nota: ";
    cin >> nota2[i];
}

cout << "Posicao do aluno que voce deseja localizar: ";
cin >> a;

cout << "Aluno: " << alunos.at(a) << endl;

return 0;
}