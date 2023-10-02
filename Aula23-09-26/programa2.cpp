#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Ponto
{
    public:
        float x, y;
};

class Poligono
{
    public:
        vector<Ponto> Pontos;
};

int main (void){
    Poligono poli;
    cout << "Criando um poligono" << endl;
    char sn;
    do{
        cout << "Digite as coordenadas do ponto: ";
        Ponto p;
        cin >> p.x >> p.y;
        poli.Pontos.push_back(p);
        cout << "Deseja inserir mais pontos? <s/n>: ";
        cin >> sn;
    }while(sn != 'n');

    cout << endl;
    cout << "As coordenadas digitadas foram:" << endl;
    for (Ponto p:poli.Pontos)
        cout << "("<< p.x <<"," << p.y << ") ";

    cout << endl;

    float per = 0;
    vector<Ponto>::iterator it2;
    Ponto p1;
    Ponto p2;

    for(auto it = poli.Pontos.begin(); it != poli.Pontos.end() - 1; it++){
        it2 = it;
        advance(it2, 1);
        p1 = *it;
        p2 = *it2;
        per += sqrt(pow(p1.x-p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    it2 = poli.Pontos.begin();
    p1 = *it2;
    per += sqrt(pow(p1.x-p2.x, 2) + pow(p1.y - p2.y, 2));

    cout << "Perimetro calculado: " << per << endl;

    return 0;
}