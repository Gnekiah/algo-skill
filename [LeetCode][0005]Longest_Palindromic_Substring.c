/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example 2:
 * 
 * Input: "cbbd"
 * Output: "bb"
 * */

#include <string.h>

char* longestPalindrome(char* s) {
    int len = strlen(s), max = 1;
    char* iter = s;

    if (len == 0)
        return s;
    for (int i = 0; i < len - 1; i++) {
        int a = i, b = i + 1, m = 2;
        char* it = NULL;
        if (s[a] == s[b]) {
            it = &s[a];
            for (a--, b++; a >= 0 && b < len; a--, b++) {
                if (s[a] == s[b]) {
                    m += 2;
                    it = &s[a];
                }
                else
                    break;
            }
            if (m > max) {
                max = m;
                iter = it;
            }
        } 

        a = i - 1, b = i + 1, m = 3;
        if (a < 0 || b >= len)
            continue;
        
        if (s[a] == s[b]) {
            it = &s[a];
            for (a--, b++; a >= 0 && b < len; a--, b++) {
                if (s[a] == s[b]) {
                    m += 2;
                    it = &s[a];
                }
                else
                    break;
            }
            if (m > max) {
                max = m;
                iter = it;
            }
        }
    }
    iter[max] = '\0';
    return iter;
}
