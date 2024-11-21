#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int pessoas_na_fila, pessoas_que_sairam, aux;
    cin >> pessoas_na_fila;
    vector<int> fila, sairam;
    while (pessoas_na_fila--) {
        cin >> aux;
        fila.push_back(aux);
    }
    cin >> pessoas_que_sairam;
    while (pessoas_que_sairam--) {
        cin >> aux;
        sairam.push_back(aux);
    }
    sort(sairam.begin(), sairam.end());

    aux = 0;
    for (int pilantra : fila) {
        if (!binary_search(sairam.begin(), sairam.end(), pilantra)) {
            if (aux++ > 0)
                cout << " ";
            cout << pilantra;
        }
    }
    cout << "\n";
}
