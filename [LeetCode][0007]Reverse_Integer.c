/*
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * Input: 123
 * Output: 321
 * Example 2:
 * 
 * Input: -123
 * Output: -321
 * Example 3:
 * 
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * */


int reverse(int x) {
    long long ret = 0;
    int max = pow(2, 31) - 1, min = 0 - pow(2, 31);
    while (x) {
        int y = x % 10;
        x /= 10;
        ret = ret * 10 + y;
        if (ret > max || ret < min)
            return 0;
    }
    return ret;
}
