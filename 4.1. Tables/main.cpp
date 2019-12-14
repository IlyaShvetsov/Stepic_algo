/// task 4.1

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class DSU {
public:
    explicit DSU(vector<int> &_sizesOfSets) :
            parents(_sizesOfSets.size()),
            rank(_sizesOfSets.size()),
            sizesOfSets(_sizesOfSets) {
        for (size_t i = 0; i < parents.size(); ++i) {
            MakeSet(i);
        }
        maxSize = *std::max_element(sizesOfSets.begin(), sizesOfSets.end());
    }

    void MakeSet(int x) {
        parents[x] = x;
    }

    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        int newSize = sizesOfSets[x] + sizesOfSets[y];
        maxSize = std::max(maxSize, newSize);
        sizesOfSets[x] = newSize;
        sizesOfSets[y] = newSize;
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

    int getMaxSize() const {
        return maxSize;
    }

private:
    vector<int> parents;
    vector<int> rank;
    vector<int> sizesOfSets;
    int maxSize;
};

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<int> tableSizes(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> tableSizes[i];
    }
    DSU dsu(tableSizes);

    int destination, source;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> destination >> source;
        --destination; --source;
        if (dsu.Find(destination) != dsu.Find(source)) {
            dsu.Unite(destination, source);
        }
        std::cout << dsu.getMaxSize() << std::endl;
    }

    return 0;
}
