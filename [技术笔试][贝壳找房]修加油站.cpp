#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int n=0, m=0;
int ret = 0;
std::vector<int> wn;
int *ptr = NULL;

int calc_min() {
    int min = 99999;
    for (int i=0; i < m-1; i++) {
        int v = ptr[i] - ptr[i+1];
        if (v < min)
            min = v;
    }
    return min;
}

int next(int p, int i) {
    if (p >= wn.size()-1)
        return 0;
    for (int f = p; f < wn.size(); f++) {
        ptr[i] = wn[f];
        if (i > 0)
            next(f+1, i-1);
        else {
            int v = calc_min();
            if (v > ret)
                ret = v;
        }
    }
    return 0;
}

int main() {
    int k = 0;
    std::string line;

    getline(std::cin, line);
    std::stringstream in1(line);
    in1 >> n >> m;

    ptr = new int[m];

    getline(std::cin, line);
    std::stringstream in2(line);
    while(in2 >> k)
        wn.push_back(k);

    next(0, m-1);

    std::cout << ret;

    return 0;
}

