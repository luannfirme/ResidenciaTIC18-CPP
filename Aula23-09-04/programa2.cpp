#include <iostream>
#include <string>

using namespace std;

int main (void){

string nome;
string sobrenome;
string nomeCompleto;

cout << "Informe o nome: ";
cin >> nome;

cout << "Informe o sobrenome: ";
cin >> sobrenome;

if(sobrenome.at(0) != ' ')
 nomeCompleto = nome + " " + sobrenome;

else
nomeCompleto = nome + sobrenome;

cout << "Nome completo: " << nomeCompleto << endl;

return 0;
}