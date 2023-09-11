#include <iostream>

using namespace std;

int main(void){
    char ch1, ch2, ch3;

    cout << "Digite um caractere: ";
    cin >> ch1;

    string tipo;
    if (isupper(ch1)) {
        tipo = "letra maiuscula";
    } else if (islower(ch1)) {
        tipo = "letra minuscula";
    } else if (isdigit(ch1)) {
        tipo = "digito";
    } else {
        tipo = "outro tipo de caractere";
    }

    cout << "O caractere '" << ch1 << "' e " << tipo << endl << endl;

    ch2 = 81;
    cout << "O caractere correspondente a ch2 e: " << ch2 << endl;
    cout << "O valor decimal de ch2 e: " << static_cast<int>(ch2) << endl;
    cout << "O valor octal de ch2 e: " << oct << static_cast<int>(ch2) << endl;
    cout << "O valor hexadecimal de ch2 e: " << hex << static_cast<int>(ch2) << endl << endl;

    if (isupper(ch2)) {
        ch3 = tolower(ch2);
    } else {
        ch3 = ch2;
    }

    cout << "O caractere correspondente a ch3 e: " << ch3 << endl;
    cout << "O valor decimal de ch3 e: " << static_cast<int>(ch3) << endl;
    cout << "O valor octal de ch3 e: " << oct << static_cast<int>(ch3) << endl;
    cout << "O valor hexadecimal de ch3 e: " << hex << static_cast<int>(ch3) << endl;

    return 0;
}