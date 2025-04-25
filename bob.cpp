#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> mp;
const int N = 3333, M = 1e9 + 7;
int total_steps = 0;

inline int walk(int steps) {
    printf("walk %d\n", steps);
    total_steps += steps;
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

bool check(int x) {
    if (mp.count(x)) {
        printf("guess %d\n", total_steps - mp[x]);
        fflush(stdout);
        exit(0);
    } else {
        mp[x] = total_steps;
        return false;
    }
}

void work() {
    int m = 0;
    for (int i = 1; i <= N; i++) {
        int x = walk(rand() % M + 1);
        m = max(m, x);
        if (i == N) {
            total_steps = 0;
            check(x);
        }
    }
    for (int i = 1; i <= N; i++) {
        check(walk(1));
    }
    check(walk(m));
    for (int i = 1; i <= N; i++) {
        check(walk(N));
    }
}

int main() {
    srand(114514);
    work();
    return 0;
}
