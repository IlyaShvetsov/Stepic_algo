/// task 5.3

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::string;
using std::vector;

class SubstringFinder {
public:
    explicit SubstringFinder(string _pattern);
    void getAnswer(const string &text); /// show all appearances of the pattern in the main string

private:
    string pattern;
    vector<int> pattern_z;

    void find_z(std::vector <int>& ans, const string &text); // find Z-function for the main string
    void find_pattern_z(); /// find Z-function for the pattern
};

SubstringFinder::SubstringFinder(string _pattern) :
        pattern_z(pattern.size()),
        pattern(std::move(_pattern))
{}

void SubstringFinder::find_pattern_z() {
    int left = 0, right = 0;
    for (int i = 1; i < pattern.size(); ++i) {
        if (i <= right) {
            pattern_z[i] = std::min(right - i + 1, pattern_z[i - left]);
        } else {
            pattern_z[i] = 0;
        }
        while (i + pattern_z[i] < pattern.size() && pattern[pattern_z[i]] == pattern[i + pattern_z[i]]) {
            ++pattern_z[i];
        }
        if (i + pattern_z[i] - 1 > right) {
            left = i;
            right = i + pattern_z[i] - 1;
        }
    }
}

void SubstringFinder::find_z(vector<int>& answer, const string &text) {
    int left = 0, right = 0, z = 0;
    for (int i = 1; i <= text.size(); ++i) {
        if (i <= right) {
            z = std::min(right - i + 1, pattern_z[i - left]);
        } else {
            z = 0;
        }
        while (i + z <= text.size() && pattern[z] == text[i + z - 1]) {
            ++z;
        }
        if (i + z - 1 > right) {
            left = i;
            right = i + z - 1;
        }
        if (z == pattern.size()) {
            answer.push_back(i - 1);
        }
    }
}

void SubstringFinder::getAnswer(const string &text) {
    vector<int> answer;
    find_pattern_z();
    find_z(answer, text);
    for(int item : answer) {
        std::cout << item << ' ';
    }
}

int main() {
    string pattern, text;
    std::cin >> pattern >> text;
    SubstringFinder substringFinder(pattern);
    substringFinder.getAnswer(text);

    return 0;
}
