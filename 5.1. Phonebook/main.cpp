/// task 5.1

#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;

int main() {
    int n;
    cin >> n;
    std::unordered_map<std::string, std::string> phonebook;
    for (int i = 0; i < n; ++i) {
        std::string request;
        std::string number;
        std::string name;
        cin >> request;
        if (request == "add") {
            cin >> number >> name;
            phonebook[number] = name;
        }
        if (request == "del") {
            cin >> number;
            phonebook.erase(number);
        }
        if (request == "find") {
            cin >> number;
            cout << (phonebook.count(number) ? phonebook[number] : "not found") << std::endl;
        }
    }

    return 0;
}
