/// task 6.3

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;
using std::pair;
using std::make_pair;
struct NodeInfo;

struct Node {
    int64_t value;
    int64_t maxValueInTree;
    int64_t minValueInTree;
    Node* left;
    Node* right;
    explicit Node(int64_t _value) :
            value(_value),
            maxValueInTree(INT64_MIN),
            minValueInTree(INT64_MAX),
            left(nullptr),
            right(nullptr) {}
};

class Tree {
public:
    explicit Tree() : root(nullptr) {}
    ~Tree();
    void Add(int64_t value);
    bool IsCorrect() const;

    friend void BuildTree(Tree &tree, vector<NodeInfo> &nodes);

private:
    Node* root;
    pair<int64_t, int64_t> fillDescendantsInfo(Node* node) const;
    bool isCorrect(Node* node) const;
};

Tree::~Tree() {
    if (root == nullptr) {
        return;
    }
    Node* current = root;
    stack<Node*> nodes;
    nodes.push(current);
    while (!nodes.empty()) {
        current = nodes.top();
        nodes.pop();
        Node *left = current->left;
        Node *right = current->right;
        delete current;
        if (right != nullptr) {
            nodes.push(right);
        }
        if (left != nullptr) {
            nodes.push(left);
        }
    }
}

void Tree::Add(int64_t value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    auto tmp = root;
    while (value != tmp->value) {
        if (value > tmp->value) {
            if (tmp->right == nullptr) {
                tmp->right = new Node(value);
                return;
            } else {
                tmp = tmp->right;
            }
        } else {
            if (tmp->left== nullptr) {
                tmp->left = new Node(value);
                return;
            } else {
                tmp = tmp->left;
            }
        }
    }
}

bool Tree::IsCorrect() const {
    if (root == nullptr) {
        return true;
    }
    fillDescendantsInfo(root);
    return isCorrect(root);
}

bool Tree::isCorrect(Node* node) const {
    if (node == nullptr) {
        return true;
    }
    bool leftCorrect = isCorrect(node->left);
    bool rightCorrect = isCorrect(node->right);
    if (node->left != nullptr) {
        if (node->value <= node->left->maxValueInTree) {
            return false;
        }
    }
    if (node->right != nullptr) {
        if (node->value > node->right->minValueInTree) {
            return false;
        }
    }
    return leftCorrect && rightCorrect;
}

pair<int64_t, int64_t> Tree::fillDescendantsInfo(Node* node) const {
    node->minValueInTree = node->value;
    node->maxValueInTree = node->value;
    if (node->left != nullptr) {
        auto tmp = fillDescendantsInfo(node->left);
        node->minValueInTree = std::min(node->minValueInTree, tmp.first);
        node->maxValueInTree = std::max(node->maxValueInTree, tmp.second);
    }
    if (node->right != nullptr) {
        auto tmp = fillDescendantsInfo(node->right);
        node->minValueInTree = std::min(node->minValueInTree, tmp.first);
        node->maxValueInTree = std::max(node->maxValueInTree, tmp.second);
    }
    return make_pair(node->minValueInTree, node->maxValueInTree);
}



struct NodeInfo {
    int64_t value;
    int64_t leftIndex;
    int64_t rightIndex;
    explicit NodeInfo(int64_t _value, int64_t _leftIndex, int64_t _rightIndex) :
            value(_value), leftIndex(_leftIndex), rightIndex(_rightIndex) {}
};

void BuildTree(Tree &tree, vector<NodeInfo> &nodes) {
    if (nodes.empty()) {
        return;
    }
    tree.root = new Node(nodes[0].value);
    stack<pair<Node*, NodeInfo>> stack;
    stack.push(make_pair(tree.root, nodes[0]));
    while (!stack.empty()) {
        auto current = stack.top();
        NodeInfo nodeInfo = current.second;
        Node* node = current.first;
        stack.pop();
        if (nodeInfo.leftIndex != -1) {
            node->left = new Node(nodes[nodeInfo.leftIndex].value);
            stack.push(make_pair(node->left, nodes[nodeInfo.leftIndex]));
        }
        if (nodeInfo.rightIndex != -1) {
            node->right = new Node(nodes[nodeInfo.rightIndex].value);
            stack.push(make_pair(node->right, nodes[nodeInfo.rightIndex]));
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int64_t value, left, right;
    vector<NodeInfo> nodes;
    for (int i = 0; i < n; ++i) {
        std::cin >> value >> left >> right;
        nodes.emplace_back(NodeInfo(value, left, right));
    }

    Tree tree;
    BuildTree(tree, nodes);
    std::cout << (tree.IsCorrect() ? "CORRECT" : "INCORRECT") << std::endl;

    return 0;
}
