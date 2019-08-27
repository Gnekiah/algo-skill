bool _isMatch(char* s, char* m, char* f) {
    if (!m[0] && !s[0])
        return true;
    if (!m[0] && s[0])
        return false;
    if (f[0]) {
        if (m[0] == '.' || m[0] == s[0])
            return _isMatch(s + 1, m + 1, f + 1);
        else
            return false;
    }
    if (m[0] == '.') {
        for (int i = 0; i == 0 || s[i-1]; i++)
            if (_isMatch(s + i, m + 1, f + 1))
                return true;
        return false;
    }
    else {
        for (int i = 0; i == 0 || (s[i-1] && m[0] == s[i-1]); i++) {
            if (_isMatch(s + i, m + 1, f + 1))
                return true;
        }
        return false;
    }
    return false;
}

bool isMatch(char* s, char* p) {
    int fm = 0;
    char m[1024], f[1024], ss[1024];
    strcpy_s(ss, s);
    for (int i = 0; p[i]; i++) {
        if (p[i] != '*') {
            m[fm] = p[i];
            f[fm] = true;
            fm++;
        }
        else
            f[fm - 1] = false;
    }
    m[fm] = '\0';
    return _isMatch(ss, m, f);
}
