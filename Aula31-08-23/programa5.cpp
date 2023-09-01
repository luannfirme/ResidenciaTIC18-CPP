#include <iostream>
#include <math.h>

using namespace std;

int main (void){

    int c, temperatura, maiortemperatura = 0;


    for (c = 0; c < 5; c++)
    {
        cout << "Informe a temperatura do mes "<< c + 1 << ": ";
        cin >> temperatura;

        if(temperatura > maiortemperatura)
            maiortemperatura = temperatura;

    }

    cout << "A maior temperatura foi: "<< maiortemperatura << endl;

    return 0;
}