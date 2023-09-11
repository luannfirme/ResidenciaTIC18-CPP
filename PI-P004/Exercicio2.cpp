#include <iostream>

using namespace std;

int main(void){
    
    int x;

    // a & b

    for (x = 0; x < 10; x++){

        char caractere  = '0' + x;
        int decimal  = (int) caractere;

        cout << "'" << caractere << "' - Decimal: " << decimal << ", Octal: " << oct << decimal << ", Hexadecimal: " << dec << hex << decimal << dec << endl;

    }


    // c

    char novoCaractere = 1;
    cout << "Informe um caractere: ";
    cin >> novoCaractere;

    cout << "o valor informado foi: " << novoCaractere << " - Decimal: " << (int) novoCaractere  << ", Octal: " << oct << (int) novoCaractere << dec << ", Hexadecimal: " << hex << (int) novoCaractere << dec << endl;
    

    // d

    wchar_t caractereEspecial = novoCaractere;
    
    cout << "o valor informado foi: " << novoCaractere << " - UTF8:"<< caractereEspecial << " Decimal: " << (int) novoCaractere  << ", Octal: " << oct << (int) novoCaractere << dec << ", Hexadecimal: " << hex << (int) novoCaractere << dec << endl;

    return 0;
}