#include <cstdio>
#include <vector>
#include <cassert>
#define MAXN 103
#define LIMIT 1000001

using namespace std;
int gnd[LIMIT];
void sieve() {
    gnd[1] = 0;
    for(int i = 1; i < LIMIT; i++) {
        for(int d = i*2; d < LIMIT; d += i) {
            gnd[d] = max(gnd[i] + 1, gnd[d]);
        }
    }
}

int main() {
    sieve();
    int t, n, temp;
    scanf("%d", &t);
    while(t--) {
        int res = 0;
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &temp);
            res ^= gnd[temp];
        }
        printf("%d\n", (res == 0 ? 2 : 1));
    }
    return 0;
}
