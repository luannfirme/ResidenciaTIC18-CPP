#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main(void){

    // a
    float menorValorFloat = numeric_limits<float>::min();
    float maiorValorFloat = numeric_limits<float>::max();

    cout << "Menor valor em float: " << menorValorFloat << endl;
    cout << "Maior valor em float: " << maiorValorFloat << endl;

    // b
    // float pif = 3.14159265358979323846264338327950288;
    float pif = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461;

    // c
    cout << "Valor de pif com 2 casas decimais: " << fixed << setprecision(2) << pif << endl;
    cout << "Valor de pif com 4 casas decimais: " << fixed << setprecision(4) << pif << endl;
    cout << "Valor de pif com 8 casas decimais: " << fixed << setprecision(8) << pif << endl;
    cout << "Valor de pif com 16 casas decimais: " << fixed << setprecision(16) << pif << endl;

    // d
    double pid = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461;

    cout << "Valor de pid com 2 casas decimais: " << fixed << setprecision(2) << pid << endl;
    cout << "Valor de pid com 4 casas decimais: " << fixed << setprecision(4) << pid << endl;
    cout << "Valor de pid com 8 casas decimais: " << fixed << setprecision(8) << pid << endl;
    cout << "Valor de pid com 16 casas decimais: " << fixed << setprecision(16) << pid << endl;

    // e

    /*
    * É possível obervar que a partir de 8 casas decimais os valores apresentados são diferentes
    * Enquanto pif apresenta '3.14159274' pid apresenta '3.14159265'
    */

    // f
    double d = 1.0 / 3.0;
    long double ld = 1.0 / 3.0;

    cout << "Resultado em double: " << setprecision(20) << d << endl;
    cout << "Resultado em long double: " << setprecision(20) << ld << endl;
    

    return 0;
}