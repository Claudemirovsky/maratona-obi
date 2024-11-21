#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

int main() {
    FASTIO;

    unordered_map<unsigned, unsigned> tralhas;
    unsigned tam, linha, col, num, soma, skip = 0, excluido_linha = 0,
                                         excluido_val = 0, esperado = 0;
    cin >> tam;
    unsigned matriz[tam][tam],
        *colsum = (unsigned *)calloc(tam, sizeof(unsigned));

    for (linha = 0; linha < tam; linha++) {
        soma = 0;
        for (col = 0; col < tam; col++) {
            cin >> num;
            soma += num;
            matriz[linha][col] = num;
            colsum[col] += num;
        }

        if (skip)
            continue;
        auto item = tralhas.find(soma);
        if (item != tralhas.end()) {
            esperado = soma;
            if (tralhas.size() >= 2) {
                skip = 1;
                tralhas.erase(item);
                excluido_linha = tralhas.begin()->second;
                excluido_val = tralhas.begin()->first;
            }
        } else {
            tralhas.insert({soma, linha});
            excluido_linha = linha;
            excluido_val = soma;
        }
    }

    for (col = 0; col < tam && colsum[col] == esperado; col++)
        ;
    free(colsum);
    num = matriz[excluido_linha][col];
    cout << num + (esperado - excluido_val) << " " << num << "\n";
    return 0;
}
