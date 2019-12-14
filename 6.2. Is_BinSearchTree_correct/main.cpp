/// task 6.2

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;
using std::pair;
using std::make_pair;
struct NodeInfo;

struct Node {
    int value;
    Node* left;
    Node* right;
    explicit Node(int _value) :
            value(_value),
            left(nullptr),
            right(nullptr) {}
};

class Tree {
public:
    explicit Tree() : root(nullptr) {}
    ~Tree();
    void Add(int value);
    bool IsCorrect() const;

    friend void BuildTree(Tree &tree, vector<NodeInfo> &nodes);

private:
    Node* root;
    mutable vector<int> order;
    void inOrder(Node* node) const;
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

void Tree::Add(int value) {
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
    order.clear();
    inOrder(root);
    for (int i = 1; i < order.size(); ++i) {
        if (order[i] < order[i-1]) {
            return false;
        }
    }
    return true;
}

void Tree::inOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    if (node->left != nullptr) {
        inOrder(node->left);
    }
    order.push_back(node->value);
    if (node->right != nullptr) {
        inOrder(node->right);
    }
}



struct NodeInfo {
    int value;
    int leftIndex;
    int rightIndex;
    explicit NodeInfo(int _value, int _leftIndex, int _rightIndex) :
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
    int value, left, right;
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
