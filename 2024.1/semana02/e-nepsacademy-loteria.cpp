/* Neps Academy - Loteria */
#include <algorithm>
#include <iostream>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

int main() {
    FASTIO;
    unsigned aposta[6] = {0}, pontos = 0, num;

    for (int i = 0; i < 6; cin >> aposta[i++])
        ;
    sort(aposta, aposta + 6);

    for (int i = 0; i < 6; i++) {
        cin >> num;
        if (binary_search(aposta, aposta + 6, num)) {
            pontos++;
        }
    }

    if (pontos < 3)
        cout << "azar\n";
    else if (pontos == 3)
        cout << "terno\n";
    else if (pontos == 4)
        cout << "quadra\n";
    else if (pontos == 5)
        cout << "quina\n";
    else if (pontos >= 6)
        cout << "sena\n";
    return 0;
}
