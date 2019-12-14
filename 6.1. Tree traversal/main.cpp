/// task 6.1

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;
using std::pair;
using std::make_pair;
struct NodeInfo;

struct Node {
    size_t value;
    Node* left;
    Node* right;
    explicit Node(size_t _value) :
            value(_value),
            left(nullptr),
            right(nullptr) {}
};

class Tree {
public:
    explicit Tree() : root(nullptr) {}
    ~Tree();

    void Add(int value);
    void PrintInOrder() const { printInOrder(root); std::cout << std::endl; }
    void PrintPreOrder() const { printPreOrder(root); std::cout << std::endl; }
    void PrintPostOrder() const { printPostOrder(root); std::cout << std::endl; }

    friend void BuildTree(Tree &tree, vector<NodeInfo> &nodes);

private:
    Node* root;

    void printInOrder(Node* node) const;
    void printPreOrder(Node* node) const;
    void printPostOrder(Node* node) const;
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

void Tree::printInOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    if (node->left != nullptr) {
        printInOrder(node->left);
    }
    std::cout << node->value << " ";
    if (node->right != nullptr) {
        printInOrder(node->right);
    }
}

void Tree::printPreOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << " ";
    if (node->left != nullptr) {
        printPreOrder(node->left);
    }
    if (node->right != nullptr) {
        printPreOrder(node->right);
    }
}

void Tree::printPostOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    if (node->left != nullptr) {
        printPostOrder(node->left);
    }
    if (node->right != nullptr) {
        printPostOrder(node->right);
    }
    std::cout << node->value << " ";
}



struct NodeInfo {
    size_t value;
    int leftIndex;
    int rightIndex;
    explicit NodeInfo(size_t _value, int _leftIndex, int _rightIndex) :
            value(_value), leftIndex(_leftIndex), rightIndex(_rightIndex) {}
};

void BuildTree(Tree &tree, vector<NodeInfo> &nodes) {
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
    tree.PrintInOrder();
    tree.PrintPreOrder();
    tree.PrintPostOrder();

    return 0;
}
