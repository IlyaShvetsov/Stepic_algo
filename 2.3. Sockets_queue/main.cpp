/// task 2.3

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::ostream;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vector) {
    for (auto& item : vector) {
        out << item << std::endl;
    }
    return out;
}

struct Package {
    int arrivalTime;
    int duration;
    int number;
    Package(int _arrivalTime, int _duration, int _number) :
        arrivalTime(_arrivalTime),
        duration(_duration),
        number(_number) {}
};

class PackagesQueue {
private:
    int bufferSize;
    std::queue<Package> buffer;
    vector<int> startTimes;
    int currentTime;

    void process(int endTime) {
        while (!buffer.empty()) {
            auto currPackage = buffer.front();
            int startTime = std::max(currPackage.arrivalTime, currentTime);
            int newTime = startTime + currPackage.duration;
            if (newTime <= endTime) {
                buffer.pop();
                startTimes[currPackage.number] = startTime;
                currentTime = newTime;
            } else {
                break;
            }
        }
    }

public:
    explicit PackagesQueue(int _bufferSize) : bufferSize(_bufferSize), currentTime(0) {}
    const vector<int>& ProcessPackages(const vector<Package>& packages);
};

const vector<int>& PackagesQueue::ProcessPackages(const vector<Package>& packages) {
    startTimes.assign(packages.size(), -1);
    for (const auto& package : packages) {
        process(package.arrivalTime);
        if (buffer.size() < bufferSize) {
            buffer.push(package);
        }
    }
    process(INT32_MAX);
    return startTimes;
}

int main() {
    int bufferSize, n;
    std::cin >> bufferSize >> n;
    PackagesQueue packagesQueue(bufferSize);

    vector<Package> packages;
    for (int i = 0; i < n; ++i) {
        int arrivalTime, duration;
        std::cin >> arrivalTime >> duration;
        packages.emplace_back(Package(arrivalTime, duration, i));
    }

    std::cout << packagesQueue.ProcessPackages(packages);
    return 0;
}
