#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int merge(std::vector<int> &wn) {
    int cnt = 0;
    sort(wn.begin(), wn.end());

    for (int i=wn.size()-2; i >= 0; i--) {
        if (wn[i] == wn[i+1]) {
            wn[i] += wn[i+1];
            std::vector<int>::iterator it = wn.begin()+i+1;
            wn.erase(it);
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n=0, k=0;
    std::vector<int> wn;
    std::string line;

    getline(std::cin, line);
    std::stringstream in1(line);
    in1 >> n;

    getline(std::cin, line);
    std::stringstream in2(line);
    while(in2 >> k)
        wn.push_back(k);

    sort(wn.begin(), wn.end());

    while (merge(wn)) { }
    std::cout << wn.size();

    return 0;
}

