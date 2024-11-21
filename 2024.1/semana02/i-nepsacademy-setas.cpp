#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

using NPos = pair<int, int>;

struct Seta {
    Seta *nextptr;
    NPos next_idx;

  public:
    Seta(NPos idnxt) {
        this->nextptr = nullptr;
        this->next_idx = idnxt;
    }
    void setNext(Seta *ptr) { this->nextptr = ptr; }
};

int main() {
    FASTIO;
    int size;
    char ch;
    cin >> size;

    vector<Seta *> setas;
    map<NPos, Seta *> setapos;

    for (int y = size; y; y--) {
        for (int x = 0; x < size; x++) {
            cin >> ch;
            int nx = x, ny = y;
            if (ch == 'A')
                ny++;
            else if (ch == 'V')
                ny--;
            else if (ch == '>')
                nx++;
            else if (ch == '<')
                nx--;

            Seta *seta = new Seta({nx, ny});
            setas.push_back(seta);
            setapos.insert({{x, y}, seta});
        }
    }

    for (Seta *s : setas) {
        auto item = setapos.find(s->next_idx);
        if (item != setapos.end()) {
            s->setNext(item->second);
        }
    }

    setapos.clear();

    int unsafe = 0;
    unordered_set<Seta *> accessed;

    for (Seta *s : setas) {
        stack<Seta *> steps;
        steps.push(s);
        if (accessed.find(s) == accessed.end()) {
            Seta *el = s->nextptr;

            for (; el != nullptr; el = el->nextptr) {
                auto it = accessed.find(el);
                steps.push(el);
                if (it != accessed.end()) {
                    break;
                }
                accessed.insert(el);
            }

            if (el && el->nextptr == nullptr)
                steps.pop();

            if (el == nullptr || el->nextptr == nullptr) {
                unsafe += steps.size();
                while (!steps.empty()) {
                    steps.top()->nextptr = nullptr;
                    steps.pop();
                }
            }
        }

        accessed.insert(s);
    }

    cout << (size * size) - unsafe << '\n';

    return 0;
}
