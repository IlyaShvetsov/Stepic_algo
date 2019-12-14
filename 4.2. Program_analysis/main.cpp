/// task 4.2

#include <iostream>
#include <vector>

using std::vector;

class DSU {
public:
    explicit DSU(size_t size) : rank(size), parents(size) {
        for (size_t i = 0; i < size; ++i) {
            MakeSet(i);
        }
    }

    void MakeSet(int x) {
        parents[x] = x;
    }

    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (rank[x] < rank[y]) {
            parents[x] = y;
        } else {
            parents[y] = x;
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
        }
    }

    int Find(int x) {
        if (parents[x] == x) {
            return x;
        }
        return parents[x] = Find(parents[x]);
    }

private:
    vector<int> parents;
    vector<int> rank;
};

int main() {
    size_t n, e, d;
    int a, b;
    std::cin >> n >> e >> d;
    DSU dsu(n);

    for (size_t i = 0; i < e; ++i) {
        std::cin >> a >> b;
        dsu.Unite(a-1, b-1);
    }

    bool correct = true;
    for (size_t i = 0; i < d; ++i) {
        std::cin >> a >> b;
        if (dsu.Find(a-1) == dsu.Find(b-1)) {
            correct = false;
        }
    }

    std::cout << correct << std::endl;
    return 0;
}
