/// task 2.1

#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <string>

using std::string;
using std::map;
using std::set;
using std::stack;

int main() {
    map<char, char> bracketsPairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    set<char> openBrackets = {'(', '[', '{'};
    set<char> closeBrackets = {')', ']', '}'};

    string sequence;
    std::cin >> sequence;

    stack<char> stack;
    int index = 0, firstBracket = 0;
    for (char ch : sequence) {
        index++;
        if (openBrackets.count(ch)) {
            firstBracket = stack.empty() ? index : firstBracket;
            stack.push(ch);
        }
        if (closeBrackets.count(ch)) {
            if (stack.empty()) {
                std::cout << index << std::endl;
                return 0;
            }
            if (bracketsPairs.at(stack.top()) == ch) {
                stack.pop();
            } else {
                std::cout << index << std::endl;
                return 0;
            }
        }
    }

    if (stack.empty()) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << firstBracket << std::endl;
    }
    return 0;
}
