#include <iostream>

using namespace std ;

int main(void) {
    int num, div;

    cout << "Digite um numero inteiro: ";
    cin >> num;

     for (div = 1; div <= num; div++)
    {
        if(num % div == 0)
        {
            cout << "Divisivel por: : " << div << endl;
        }
    }
    return 0;
}