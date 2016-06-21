
class Solution {
public:
    bool VerifySequenceOfBST(vector<int> sequence) {
        if (!sequence.size()) return false;
        return judge(sequence, 0, sequence.size() - 1);
    }

    bool judge(vector<int>& s, int l, int r) {
        if (l >= r) return true;
        int i = r;
        while (i > l && s[i - 1] > s[r]) { i--; }
        for (int j = i - 1; j >= l; --j) {
            if (s[j] > s[r]) {
                return false;
            }
        }
        return judge(s, l, i - 1) && judge(s, i, r - 1);
    }
};
