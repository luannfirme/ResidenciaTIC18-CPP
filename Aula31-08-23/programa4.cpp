#include <iostream>
#include <math.h>

using namespace std;

int main (void){

    float nota = 0, s;
    int c = 0;

    while (c < 10)
    {
        cout << "Digite uma nota: ";
        cin >> s;
        
        nota += s;

        c++;

    }

    float media = nota / c;

    cout << "A media: " << media << endl;

    return 0;
}