/// task 2.2

#include <iostream>
#include <vector>
using std::vector;

class ListGraph {
private:
    vector<vector<int>> vertices;
public:
    explicit ListGraph(int verticesCount) : vertices(verticesCount) {}

    const vector<int>& GetNextVertices(int vertex) const {
        return vertices[vertex];
    }

    void AddEdge(int from, int to) {
        vertices[from].push_back(to);
    }
};

class Tree : public ListGraph {
private:
    int root;

    int getSubtreeHeight(int subTreeRoot) const;

public:
    explicit Tree(int verticesCount) : ListGraph(verticesCount), root(-1) {}

    void SetRoot(int _root) {
        root = _root;
    }

    int GetHeight() const;
};

int Tree::GetHeight() const {
    if (root == -1) {
        return -1;
    }
    return getSubtreeHeight(root);
}

int Tree::getSubtreeHeight(int subTreeRoot) const {
    int height = 1;
    auto vertices = GetNextVertices(subTreeRoot);
    for (auto vertex : vertices) {
        height = std::max(height, getSubtreeHeight(vertex) + 1);
    }
    return height;
}

int main() {
    int n;
    std::cin >> n;
    Tree tree(n);

    for (int vertex = 0; vertex < n; ++vertex) {
        int parent;
        std::cin >> parent;
        if (parent == -1) {
            tree.SetRoot(vertex);
        } else {
            tree.AddEdge(parent, vertex);
        }
    }

    std::cout << tree.GetHeight();
    return 0;
}
