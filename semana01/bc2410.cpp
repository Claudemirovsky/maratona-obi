/* beecrowd - 2410 */
#include <iostream>
#include <set>

#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

int main() {
    FASTIO;

    set<unsigned> alunos;
    unsigned linhas, fdp;
    cin >> linhas;
    while (linhas--) {
        cin >> fdp;
        alunos.insert(fdp);
    }
    cout << alunos.size() << '\n';
    return 0;
}
