class Solution {
public:
    int lengthOfLastWord(string s) {
        int curIdx = s.length() - 1;
        while (curIdx >= 0 && s[curIdx] == ' ')
            curIdx--;
        int length = 0;
        while (curIdx >= 0 && s[curIdx] != ' ') {
            ++length;
            --curIdx;
        }
        return length;
    }
};