/*
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * Example 2:
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 *              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * */


int lengthOfLongestSubstring(char* s) {
    int x[256] = { -1 };    // can not set to -1 on some compiler
    for (int i=0; i<256; i++) x[i] = -1;
    int longest = 0, pos = -1, i = -1;
    while(s[++i]) {
        pos = x[s[i]] > pos ? x[s[i]] : pos;
        x[s[i]] = i;
        longest = longest < (i-pos) ? i-pos : longest;
    }
    return longest;
}

