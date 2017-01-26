#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    long int n, l;
    std::cin >> n >> l;
    if (l == 1) {
        std::cout << 1 << endl;
        return 0;
    }
    long int size = n*l;

    std::vector< std::pair<long int, long int> > nass(size);

    for (long int i = 0; i < n; ++i) {
        for (long int j = 0; j < l; ++j) {
            long int s;
            std::cin >> s;
            nass[i * l + j] = std::make_pair(s, j);
        }
    }

    std::sort(nass.begin(), nass.end());

    long int max_price = 1;
    long int price = 1;

    for (long int i = 1; i < size; ++i) {
        if (nass[i].first == nass[i-1].first && (nass[i].second == nass[i-1].second || nass[i].second == nass[i-1].second+1)) {
            if (nass[i].second == nass[i-1].second+1)
                ++price;
        } else {
            max_price = std::max(max_price, price);
            price = 1;
        }
    }

    max_price = std::max(max_price, price);
    std::cout << max_price << endl;

    return 0;
}
