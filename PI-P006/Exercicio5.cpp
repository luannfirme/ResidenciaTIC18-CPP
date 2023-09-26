#include <cstdio>
#include <iostream>

using namespace std ;

int main(void) {

    double x, y, z;

    cout << "digite um numero de ponto flutuante (x): ";
    scanf("%lf", &x);
    cout << "digite um numero de ponto flutuante (y): ";
    scanf("%lf", &y);
    cout << endl;

    z = x + y;
    printf("a soma de x + y e: %.2lf\n", z);

    z = (x + y) / 2;
    printf("a media de x + y e: %.2lf\n", z);

    z = x * y;
    printf("a media de x + y e: %.2lf\n", z);

    z = (x > y) ? x : y;
    printf("a maior valor entre x e y e: %.2lf\n", z);

    z = (x < y) ? x : y;
    printf("a menor valor entre x e y e: %.2lf\n", z);

    cout << endl;
    
    return 0;
}
