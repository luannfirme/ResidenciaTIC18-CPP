#include <iostream>
#include <vector>
#include <string>

using namespace std;

void maxmin (int vetor[], int n, int &maximo, int &minimo){
    maximo = vetor[0];
    minimo = vetor[0];
    for(int i = 0; i < n; i++){
        if(maximo < vetor[i]){
            maximo = vetor[i];
        }
        if(minimo > vetor[i]){
            maximo = vetor[i];
        }
    }
}
int main(void){
   int vet[] = { 1,3,5,7,10},  maximo, minimo;
   
    maxmin(vet,5, maximo,minimo);
    cout << endl << endl ;
    cout << "Maior valor : " << maximo << " e Menor valor: "<< minimo << endl;
    cout << endl << endl ;

    return 0 ;
}