#include <iostream>

using namespace std ;

int main(void) {

    double raio;

    cout << "digite o raio de um circulo: ";
    cin >> raio;
    cout << endl;

    double diametro = 2 * raio;
    double circunferencia = 2 * 3.14159265358979323846 * raio;
    double area = 3.14159265358979323846 * raio * raio;


    cout << "Diametro: " << diametro << endl;
    cout << "Circunferencia: " << circunferencia << endl;
    cout << "Area: " << area << endl;
    cout << endl;
    
    return 0;
}
