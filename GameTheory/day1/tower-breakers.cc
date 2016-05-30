#include <iostream>
#define MAXN 1000003

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        if(m == 1) {
            cout << 2 << '\n';
        } else {
            cout << (2 - (n%2)) << '\n';
        }
    }
    return 0;
}
