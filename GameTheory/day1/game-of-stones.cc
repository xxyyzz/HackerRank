#include <iostream>
#include <vector>
#define MAXN 103

using namespace std;
bool win[MAXN];
vector<int> s = {2, 3, 5};

void go() {
    win[0] = false;
    for(int i = 1; i < MAXN; i++) {
        win[i] = false;
        for(auto &elem: s) {
            if(elem > i)    break;
            win[i] |= !win[i - elem];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    go();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(win[n]) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}
