/// task 6.4

#include <iostream>
#include <string>

using namespace std;

struct CNode {
    int64_t data;
    CNode* left;
    CNode* right;
    int64_t height;
    int64_t count;
    int64_t sum;

    explicit CNode(int64_t key) :
            data(key),
            left(nullptr),
            right(nullptr),
            height(1),
            count(1),
            sum(key) {}
};

class AVL_Tree {
public:
    AVL_Tree() : root(nullptr) {}
    ~AVL_Tree() { DFS_Destr(root); }

    int64_t Insert(int64_t key);
    void DeleteByKey(int64_t key);
    bool Find(int64_t key) const;
    int64_t Sum(int64_t left, int64_t right) const;
    
    void Show() const;

private:
    CNode* root;

    int64_t height(CNode* p);
    int64_t bfactor(CNode* p);
    void fixheight(CNode* p);
    CNode* rotateRight(CNode* p);
    CNode* rotateLeft(CNode* q);
    CNode* balance(CNode* p);
    int64_t getCount(CNode* p);
    CNode* remove_min(CNode* p);
    CNode* findmin(CNode* p);

    CNode* Ins(CNode* node, int64_t key, int64_t& index);
    CNode* deleteByKey(CNode* node, int64_t key);

    void DFS_Destr(CNode* node);
    void print64_tAsTree(CNode* node, int64_t currentLevel) const;

    int64_t sum(CNode* node, int64_t left, int64_t right) const;
};

int64_t AVL_Tree::Insert(int64_t key) {
    /// если в дереве уже имеется такой ключ, выходим
    if (Find(key)) {
        return -1;
    }
    int64_t index = 0;
    root = Ins(root, key, index);
    return index;
}

void AVL_Tree::DeleteByKey(int64_t key) {
    if (Find(key)) {
        root = deleteByKey(root, key);
    }
}

bool AVL_Tree::Find(int64_t key) const {
    CNode* current = root;

    while (true) {
        if (current == nullptr) {
            return false;
        }
        if (current->data == key) {
            return true;
        }
        if (current->data > key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

int64_t AVL_Tree::Sum(int64_t left, int64_t right) const {
    return sum(root, left, right);
}



CNode* AVL_Tree::deleteByKey(CNode* node, int64_t key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->data) {
        node->sum -= key;
        node->left = deleteByKey(node->left, key);
        return balance(node);
    }

    if (key > node->data) {
        node->sum -= key;
        node->right = deleteByKey(node->right, key);
        return balance(node);
    }

    CNode *left = node->left;
    CNode *right = node->right;
    delete node;
    if (!right) {
        return left;
    }
    CNode *min = findmin(right);
    min->right = remove_min(right);
    min->left = left;

    min->sum = min->data;
    if (min->left != nullptr) {
        min->sum += min->left->sum;
    }
    if (min->right != nullptr) {
        min->sum += min->right->sum;
    }

    return balance(min);
}

/// вставка ключа k в дерево с корнем node
CNode* AVL_Tree::Ins(CNode* node, int64_t key, int64_t& index) {
    if (node == nullptr) {
        return new CNode(key);
    }
    node->sum += key;
    if (key < node->data) {
        index += getCount(node->right) + 1;
        node->left = Ins(node->left, key, index);
    } else {
        node->right = Ins(node->right, key, index);
    }
    return balance(node);
}

CNode* AVL_Tree::findmin(CNode* p) {
    return p->left != nullptr ? findmin(p->left) : p;
}

CNode* AVL_Tree::remove_min(CNode* p) {
    if (p->left == nullptr) {
        return p->right;
    }
    p->left = remove_min(p->left);

    p->sum = p->data;
    if (p->left != nullptr) {
        p->sum += p->left->sum;
    }
    if (p->right != nullptr) {
        p->sum += p->right->sum;
    }

    p = balance(p);
    return p;
}

int64_t AVL_Tree::height(CNode* p) {
    return p ? p->height : 0;
}

int64_t AVL_Tree::bfactor(CNode* p) {
    return height(p->right) - height(p->left);
}

void AVL_Tree::fixheight(CNode* p) {
    int64_t hl = height(p->left);
    int64_t hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
    p->count = getCount(p->left) + getCount(p->right) + 1;
}

int64_t AVL_Tree::getCount(CNode* p) {
    return p == nullptr ? 0 : p->count;
}

/// правый поворот вокруг p
CNode* AVL_Tree::rotateRight(CNode* p) {
    CNode* q = p->left;
    p->left = q->right;
    q->right = p;

    p->sum -= q->data;
    if (q->left != nullptr) {
        p->sum -= q->left->sum;
    }
    q->sum += p->data;
    if (p->right != nullptr) {
        q->sum += p->right->sum;
    }

    fixheight(p);
    fixheight(q);
    return q;
}

/// левый поворот вокруг q
CNode* AVL_Tree::rotateLeft(CNode* q) {
    CNode* p = q->right;
    q->right = p->left;
    p->left = q;

    p->sum += q->data;
    if (q->left != nullptr) {
        p->sum += q->left->sum;
    }
    q->sum -= p->data;
    if (p->right != nullptr) {
        q->sum -= p->right->sum;
    }

    fixheight(q);
    fixheight(p);
    return p;
}

/// балансировка узла p
CNode* AVL_Tree::balance(CNode* p) {
    fixheight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0) {
            p->right = rotateRight(p->right);
        }
        return rotateLeft(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0) {
            p->left = rotateLeft(p->left);
        }
        return rotateRight(p);
    }
    return p;
}

int64_t AVL_Tree::sum(CNode* node, int64_t left, int64_t right) const {
    if (node == nullptr) {
        return 0;
    }
    if (node->data < left) {
        return sum(node->right, left, right);
    }
    if (node->data > right) {
        return sum(node->left, left, right);
    }

    int64_t finalSum = node->sum;

    /// обрезаем всё, что справа
    CNode* current = node;
    while (current != nullptr) {
        if (current->data > right) {
            finalSum -= current->data;
            if (current->right != nullptr) {
                finalSum -= current->right->sum;
            }
            current = current->left;
        } else {
            current = current->right;
        }
    }

    /// обрезаем всё, что слева
    current = node;
    while (current != nullptr) {
        if (current->data < left) {
            finalSum -= current->data;
            if (current->left != nullptr) {
                finalSum -= current->left->sum;
            }
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return finalSum;
}

void AVL_Tree::DFS_Destr(CNode* node) {
    if (node == nullptr) {
        return;
    }
    DFS_Destr(node->left);
    DFS_Destr(node->right);
    delete node;
}



///  Вывод

void AVL_Tree::Show() const {
    print64_tAsTree(root, 0);
}

void AVL_Tree::print64_tAsTree(CNode* node, int64_t currentLevel) const {
    if (node == nullptr) {
        return;
    }
    print64_tAsTree(node->right, currentLevel + 1);
    cout << string(currentLevel, '\t') << node->data << " " << node->count << endl;
    print64_tAsTree(node->left, currentLevel + 1);
}

///



int main() {
    const int64_t x = 1000 * 1000 * 1000 + 1;
    int64_t n, key, first, second, lastSum = 0;
    char instruction;
    AVL_Tree tree;
    cin >> n;
    for (int64_t i = 0; i < n; ++i) {
        cin >> instruction;
        if (instruction == '+') {
            cin >> key;
            key = (key + lastSum) % x;
            tree.Insert(key);
        }
        if (instruction == '-') {
            cin >> key;
            key = (key + lastSum) % x;
            tree.DeleteByKey(key);
        }
        if (instruction == '?') {
            cin >> key;
            key = (key + lastSum) % x;
            cout << (tree.Find(key) ? "Found" : "Not found") << endl;
        }
        if (instruction == 's') {
            cin >> first >> second;
            first = (first + lastSum) % x;
            second = (second + lastSum) % x;
            lastSum = tree.Sum(first, second);
            cout << lastSum << endl;
        }
    }
    return 0;
}