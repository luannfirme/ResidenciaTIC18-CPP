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

for(int i = 0; i <5; i++){
    cout << "Informe o nome de um aluno: ";
    cin >> aluno;

    alunos.push_back(aluno);

    cout << "Informe a primeira nota: ";
    cin >> nota1[i];

    cout << "Informe a segunda nota: ";
    cin >> nota2[i];
}


for(auto it = alunos.begin(); it != alunos.end(); it++){
    float media = (nota1[x] + nota2[x]) / 2;

    cout << "Aluno: " << *it << " Primeira Nota: " << nota1[x] << " Segunda Nota: " << nota2[x] << " Media: " << media << endl;
    x++;
}

return 0;
}