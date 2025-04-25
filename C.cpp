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
    printf("%d\n", steps);
    total_steps += steps;
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

bool check(int x) {
    if (mp.count(x)) {
        fprintf(stderr, "%d\n", total_steps - mp[x]);
        fflush(stdout);
        exit(0);
    } else {
        mp[x] = total_steps;
        return false;
    }
}

void work() {
    int m = 0;
    for (int i = 1; i <= 3333; i++) {
        int x = walk(rand() % N + 1);
        m = max(m, x);
        if (i == 3333) {
            total_steps = 0;
            check(x);
        }
    }
    for (int i = 1; i <= 3333; i++) {
        check(walk(1));
    }
    check(walk(m));
    for (int i = 1; i <= 3333; i++) {
        check(walk(3333));
    }
}

int main() {
    srand(time(0));
    work();
    return 0;
}