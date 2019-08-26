#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int HP = 0, SP = 0, N = 0;
int *A = NULL;
int res = 9999999;

int run(int hp, int sp, int n, int cnt) {
    cnt++;

    int _hp=hp, _sp=sp, _n=n;
    for (int i=0; i < 3; i++) {
        if (i=0) {
            _hp = hp + HP * 0.2;
            _hp = _hp > HP ? HP : _hp;
            _sp = sp;
            _n = n;
        }
        if (i=1) {
            _n = n-1;
            _sp = sp + 1 > SP ? SP : sp+1;
            _hp = hp;
        }
        if (i=2 && sp > 0) {
            _n = n - A[sp];
            _sp = 0;
            _hp = hp;
        }
        _hp -= _n;
        int __sp = _sp + _n%3;
        _sp = __sp > SP ? SP : __sp;

        if (_n <= 0)
            return cnt;
        if (_hp <= 0)
            return -1;

        int ret = run(_hp, _sp, _n, cnt);
        if (ret > 0)
            res = ret < res ? ret : res;
    }
    return -1;
}

int main() {
    std::string line;

    getline(std::cin, line);
    std::stringstream in1(line);
    in1 >> HP >> SP >> N;

    A = new int[SP];

    getline(std::cin, line);
    std::stringstream in2(line);
    int i=0, k=0;
    while(in2 >> k) {
        A[i++] = k;
    }

    run(HP, 0, N, 0);

    if (res == 9999999)
        std::cout << "Loss";
    else
        std::cout << res;

    return 0;
}

