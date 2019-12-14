/// task 5.2

#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::string;

struct Node {
    string value;
    Node *next;

    explicit Node(string str) :
            value(std::move(str)), next(nullptr) {}
};

class SimpleHashTable {
public:
    explicit SimpleHashTable(size_t _size) : size(_size) {
        data = new Node*[size];
    }
    ~SimpleHashTable() {
        for (int i = 0; i < size; ++i) {
            if (data[i] != nullptr) {
                deleteNode(data[i]);
            }
        }
        delete[] data;
    }

    void Add(const string &str);
    void Delete(const string &str);
    bool Find(const string &str) const;
    void Check(int i) const;

private:
    size_t size;
    Node** data;

    static const size_t p = 1000000007;
    static const size_t x = 263;

    size_t getHash(const string &str) const;
    void deleteNode(Node* node);
    static size_t pow(size_t degree) {
        size_t result = 1;
        for (int i = 0; i < degree; ++i) {
            result = (result*x)%p;
        }
        return result;
    }
};

void SimpleHashTable::Add(const string &str) {
    if (Find(str)) {
        return;
    }
    auto hash = getHash(str);
    if (data[hash] == nullptr) {
        data[hash] = new Node(str);
    } else {
        auto tmp = data[hash];
        data[hash] = new Node(str);
        data[hash]->next = tmp;
    }
}

void SimpleHashTable::Delete(const string &str) {
    auto hash = getHash(str);
    auto cur = data[hash];
    if (cur == nullptr) {
        return;
    }
    if (cur->value == str) {
        data[hash] = cur->next;
        delete cur;
        return;
    }
    auto prev = cur;
    cur = cur->next;
    while (cur != nullptr) {
        if (cur->value == str) {
            prev->next = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

bool SimpleHashTable::Find(const string &str) const {
    auto hash = getHash(str);
    auto cur = data[hash];
    while (cur != nullptr) {
        if (cur->value == str) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void SimpleHashTable::Check(int i) const {
    auto cur = data[i];
    while (cur != nullptr) {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << std::endl;
}

size_t SimpleHashTable::getHash(const string &str) const {
    size_t hash = 0;
    for (int i = 0; i < str.size(); ++i) {
        hash += str[i]*pow(i);
        hash %= p;
    }
    return hash%size;
}

void SimpleHashTable::deleteNode(Node *node) {
    if (node->next != nullptr) {
        deleteNode(node->next);
    }
    delete node;
}


int main() {
    size_t m, n;
    cin >> m >> n;
    SimpleHashTable hashTable(m);

    for (int i = 0; i < n; ++i) {
        std::string request;
        std::string value;
        cin >> request;
        if (request == "add") {
            cin >> value;
            hashTable.Add(value);
        }
        if (request == "del") {
            cin >> value;
            hashTable.Delete(value);
        }
        if (request == "find") {
            cin >> value;
            cout << (hashTable.Find(value) ? "yes" : "no") << std::endl;
        }
        if (request == "check") {
            int index;
            cin >> index;
            hashTable.Check(index);
        }
    }

    return 0;
}
