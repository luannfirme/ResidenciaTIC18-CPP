#include <iostream>
#include <math.h>

using namespace std ;

int main(void) {
    int aux, coun, Max=100, div;

    cout << " Os numeros primos de 1 ate 100 sao: " << endl;

    for(aux=2 ; aux<=Max ; aux++){
        div=0;

        for(coun=2; coun<=sqrt(aux); coun++)
            if(aux%coun==0)
            div++;

        if(!div) 
            cout << aux << " ";
        
    }

    cout << endl;

    return 0;
}