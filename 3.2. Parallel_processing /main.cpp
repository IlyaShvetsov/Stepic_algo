/// task 3.2

#include <iostream>
#include <set>

struct Processor {
    int number;
    size_t time;
    explicit Processor(int _number) : number(_number), time(0) {}
};

bool operator<(const Processor &first, const Processor &second) {
    if (first.time == second.time) {
        return first.number < second.number;
    }
    return first.time < second.time;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::set<Processor> processors;
    for (int i = 0; i < n; ++i) {
        processors.emplace(Processor(i));
    }

    size_t time;
    for (int i = 0; i < m; ++i) {
        std::cin >> time;
        auto node = processors.extract(processors.begin());
        Processor& proc = node.value();
        std::cout << proc.number << " " << proc.time << std::endl;
        proc.time += time;
        processors.insert(std::move(node));
    }

    return 0;
}
