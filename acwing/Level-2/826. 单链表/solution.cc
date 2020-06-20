#include <iostream>

using namespace std;

const int N = 100010;
const int dummy = 0;
int ne[N], val[N], idx;

void init() {
    ne[dummy] = -1;
    idx = 1;
}

void insert_next(int k, int x) {
    val[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    ++idx;
}

void delete_next(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    init();
    int m;
    cin >> m;
    while (m--) {
        char op;
        cin >> op;
        if (op == 'H') {
            int x;
            cin >> x;
            insert_next(dummy, x);
        } else if (op == 'D') {
            int k;
            cin >> k;
            delete_next(k);
        } else {
            int k, x;
            cin >> k >> x;
            insert_next(k, x);
        }
    }

    for (int i = ne[dummy]; i != -1; i = ne[i]) {
        cout << val[i] << ' ';
    }

    return 0;
}
