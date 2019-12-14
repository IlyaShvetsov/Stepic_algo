/// task 6.5

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    int n, left, right, k;
    std::cin >> s >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> left >> right >> k;
        std::string newString = s.substr(left, right-left+1);
        s.replace(left, right-left+1,"");
        s.insert(k, newString);
    }
    std::cout << s << std::endl;

    return 0;
}
