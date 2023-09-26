#include <iostream>
#include <stdio.h>

using namespace std ;

int main(void) {

    char ch1,ch2,ch3 ; 

    cout << "digite dois caracteres:" << endl;
    cin >> ch1 >> ch2;
    cout << endl;

    ch3 = ch1 -1;
    cout << "ch3 em decimal subtraido de ch1 e: " << int(ch3) << endl; 
    cout << "ch3 em octadecimal subtraido de ch1 e: " << oct << (int)ch3 << endl ;   
    cout << "ch3 em hexadecimal subtraido de ch1 e: " << hex << (int)ch3 << endl;

    if(int(ch3) < 0 && int(ch3) > 127)
        ch3 = '_';

    cout << "ch3 em caractere subtraido de ch1 e: " << ch3 << endl;
    cout << endl;



    ch3 = ch2 -1;
    cout << "ch3 em decimal subtraido de ch2 e: " << int(ch3) << endl; 
    cout << "ch3 em octadecimal subtraido de ch2 e: " << oct << (int)ch3 << endl ;   
    cout << "ch3 em hexadecimal subtraido de ch2 e: " << hex << (int)ch3 << endl;

    if(int(ch3) < 0 && int(ch3) > 127)
        ch3 = '_';

    cout << "ch3 em caractere subtraido de ch2 e: " << ch3 << endl;
    cout << endl;

    ch3 = (int)ch1 >= 65 &&  (int)ch1 <= 90 ? 'A'  : ' ';
    cout << "o valor de ch3 verificando ch1 e: " << ch3 << endl;
    cout << endl;
    
    ch3 = (int)ch2 >= 97 &&  (int)ch2 <= 122 ? 'a'  : ' ';
    cout << "o valor de ch3 verificando ch2 e: " << ch3 << endl;
    cout << endl;

    ch3 = ((int)ch1 >= 48 &&  (int)ch1 <= 57) || ((int)ch2 >= 48 &&  (int)ch2 <= 57) ? '1'  : ' ';
    cout << "o valor de ch3 verificando ch2 e ch1 e: " << ch3 << endl;
    cout << endl;

    return 0;
}

