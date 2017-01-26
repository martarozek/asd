#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 1 << endl;
        return 0;
    }

    std::vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i];
    }

    std::sort(xs.begin(), xs.end());

    int l = 1;
    int max_l = 1;
    for (int i = 1; i < n; ++i) {
        if (xs[i] == xs[i-1] || xs[i] == xs[i-1] + 1) {
            ++l;
        } else {
            max_l = std::max(l, max_l);
            l = 1;
        }
    }

    max_l = std::max(l, max_l);
    std::cout << max_l << endl;
}
