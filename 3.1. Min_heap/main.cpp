/// task 3.1

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

template <typename T>
class Heap {
private:
    vector<T> data;
    vector<pair<int,int>> swappedIndexes;
    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index] >= data[parent]) {
                return;
            }
            std::swap(data[index], data[parent]);
            index = parent;
        }

    }
    void siftDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        /// Ищем меньшего сына, если такой есть
        int least = index;
        if (left < data.size() && data[left] < data[index]) {
            least = left;
        }
        if (right < data.size() && data[right] < data[least]) {
            least = right;
        }
        /// Если меньший сын есть, то проталкиваем корень в него
        if (least != index) {
            std::swap(data[index], data[least]);
            swappedIndexes.emplace_back(std::make_pair(index, least));
            siftDown(least);
        }
    }

public:
    explicit Heap() = default;
    explicit Heap(vector<T>& array) : data(array) {
        for (int i = data.size() / 2 - 1; i >= 0; --i ) {
            siftDown(i);
        }
    }
    void Pop() {
        data[0] = data[data.size() - 1];
        data.erase(data.end());
        siftDown(0);
    }
    T Top() {
        return data[0];
    }
    void Push(T value) {
        data.emplace_back(value);
        siftUp(data.size() - 1);
    }
    bool IsEmpty() {
        return data.empty();
    }
    void PrintSwappedIndexes() const {
        std::cout << swappedIndexes.size() << std::endl;
        for (const auto& item : swappedIndexes) {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    vector<int> vector(n);
    for (int& item : vector) {
        std::cin >> item;
    }
    Heap<int> heap(vector);
    heap.PrintSwappedIndexes();

    return 0;
}
