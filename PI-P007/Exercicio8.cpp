#include <iostream>

using namespace std ;

int main(void) {
    int altura;
    char asterisco = '*';

    cout << "Digite a altura do padrao: ";
    cin >> altura;
    cout << endl;

    cout << "a:" << endl;
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= altura; j++) {
            cout << asterisco << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "b:" << endl;
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            cout << asterisco << " ";
        }
        cout << endl;
    }

    cout << endl;
    
    cout << "c:" << endl;
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= altura; j++) {
            if (i == 1 || i == altura || j == 1 || j == altura) {
                cout << asterisco << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}