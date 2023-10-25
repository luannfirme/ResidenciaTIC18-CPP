#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    vector<int> imagem(640 * 480);
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(0, 255);
    
    generate(imagem.begin(), imagem.end(), [&]() { return dist(gen); });

    vector<int> histograma(256, 0);
    for (int pixel : imagem) {
        histograma[pixel]++;
    }

    for (int i = 0; i < 256; i++) {
        cout << i << ": " << string(histograma[i], '*') << endl;
    }

    return 0;
}
