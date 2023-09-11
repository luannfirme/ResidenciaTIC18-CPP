#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void){
    double x, y, z;

    cout << "Digite o valor de x (coordenada x): ";
    cin >> x;
    cout << "Digite o valor de y (coordenada y): ";
    cin >> y;

    double fx = 5 * x + 2;
    if (y > fx) {
        cout << "O ponto (" << x << ", " << y << ") esta acima da curva." << endl;
    } else if (y < fx) {
        cout << "O ponto (" << x << ", " << y << ") esta abaixo da curva." << endl;
    } else {
        cout << "O ponto (" << x << ", " << y << ") esta sobre a curva." << endl;
    }

    z = sqrt(x * x + y * y);
    cout << "Distancia euclidiana do ponto (" << x << ", " << y << ") ao centro de coordenadas: " << z << endl;

    z = x * y;
    cout << "Produto de x e y em notacao cientifica: " << scientific << z << endl;

    return 0;
}