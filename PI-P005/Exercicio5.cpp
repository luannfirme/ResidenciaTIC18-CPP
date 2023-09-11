#include <iostream>

using namespace std;

int main(void){
    unsigned char informacaoGenetica;
    int geneEspecifico;

    cout << "Informe a informacao genetica da planta (um valor entre 0 e 255): ";
    cin >> informacaoGenetica;

    int genesPresentes = 0;
    for (int i = 0; i < 8; ++i) {
        if ((informacaoGenetica & (1 << i)) != 0) {
            genesPresentes++;
        }
    }

    cout << "Genes presentes na planta: " << genesPresentes << endl;

    cout << "Informe o gene especifico que voce deseja verificar (um valor entre 1 e 8): ";
    cin >> geneEspecifico;

    if (geneEspecifico >= 1 && geneEspecifico <= 8) {
        bool presente = (informacaoGenetica & (1 << (geneEspecifico - 1))) != 0;
        cout << "O gene " << geneEspecifico << " esta presente nesta planta: " << (presente ? "Sim" : "Nao") << endl;
    } else {
        cout << "Valor do gene especifico invalido. Deve estar entre 1 e 8." << endl;
    }

    return 0;
}