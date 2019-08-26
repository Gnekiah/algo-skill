/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string s, int numRows);
 * Example 1:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * */


char* convert(char* s, int numRows) {
    int len = strlen(s), p = 0;
    char* ret = (char*)malloc((len + 1) * sizeof(char));
    int offset = numRows == 1 ? 1 : numRows * 2 - 2;

    for (int i = 0; i < numRows; i++) {
        int j = i, o = offset - 2 * j;
        o = o == 0 ? offset : o;
        while (j < len) {
            ret[p++] = s[j];
            j += o;
            o = offset - o;
            o = o == 0 ? offset : o;
        }
    }
    ret[len] = '\0';
    return ret;
}
