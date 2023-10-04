#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SomenteData{
    public:
    int dia, mes, ano;
};

class Paciente
{
    string Nome;
    SomenteData DataDeMorte;

    public:
        void setNome(string _nome){
            Nome = _nome;
        };

        void setDataMorte(SomenteData _dataMorte){
            DataDeMorte = _dataMorte;
        };

        string getNome(){
            return Nome;
        };

        SomenteData getDataDaMorte(){
            return DataDeMorte;
        };
};

class Mausoleu
{
    string Localizacao;
    vector<Paciente> Moradores;  

    public:
        void setLocalizacao(string _localizacao){
            Localizacao = _localizacao;
        };

        void setMorador(Paciente _paciente){
            Moradores.push_back(_paciente);
        };

        string getLocalizacao(){
            return Localizacao;
        };

        void listarMoradores(){
            for(Paciente p:Moradores){
                cout << p.getNome() << endl;
            }
        };
};

int main (void){

    Paciente p1, p2;
    string nome;

    cout << "Digite o nome do falecido: ";
    getline(cin, nome);
    p1.setNome(nome);

    p2.setNome("Pedro Feliz");

    cout << p1.getNome() << endl;
    cout << p2.getNome() << endl;

    Mausoleu m1;
    m1.setLocalizacao("Quadra 2, espaco 4");
    cout << m1.getLocalizacao() << endl;

    m1.setMorador(p1);
    m1.setMorador(p2);
    m1.listarMoradores();

    return 0;
}