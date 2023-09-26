#include <iostream>

using namespace std ;

int main(void) {

    double x, y;

    cout << "Digite a coordenada x: ";
    cin >> x;
    cout << "Digite a coordenada y: ";
    cin >> y;

    string quadrante = (x > 0) ? ((y > 0) ? "Primeiro Quadrante" : "Quarto Quadrante") : ((y > 0) ? "Segundo Quadrante" : "Terceiro Quadrante");

    if (x == 0 && y != 0) {
        quadrante = "Eixo Y";
    } else if (x != 0 && y == 0) {
        quadrante = "Eixo X";
    } else if (x == 0 && y == 0) {
        quadrante = "Origem";
    }

    cout << "O ponto (" << x << ", " << y << ") está no " << quadrante << "." << endl;

    return 0;
}