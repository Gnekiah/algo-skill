/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * Example 2:
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * */


char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    if (strsSize == 0) {
        char* ret = (char*)malloc(sizeof(char));
        ret[0] = '\0';
        return ret;
    }
    if (strsSize == 1)
        return strs[0];
    for (; strs[0][i]; i++)
        for (int j = 1; j < strsSize; j++)
            if (strs[0][i] != strs[j][i])
                goto out;
out:
    strs[0][i] = '\0';
    return strs[0];
}
