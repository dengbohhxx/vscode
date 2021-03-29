class Solution {
public:
    string convertToTitle(int columnNumber) {
        char c[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        string res;
        while (columnNumber > 0) {
            columnNumber--;//依次获取 26 进制逻辑上的个位、十位、百位…（虽然在 26 进制中不这么叫）
            res += c[columnNumber % 26];
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};