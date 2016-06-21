class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        Permutation(res, 0, str);
        return res;
    }

    void Permutation(vector<string>& res, int k, string str) {
        if (k == str.size() - 1) {
            res.push_back(str);
        }
        unordered_set<char> us;		//记录出现过的字符
        sort(str.begin() + k, str.end());	//保证按字典序输出
        for (int i = k; i < str.size(); ++i) {
            if (us.find(str[i]) == us.end()) {		//只和没交换过的换
                us.insert(str[i]);
                swap(str[i], str[k]);
                Permutation(res, k+1, str);
                swap(str[i], str[k]);		//复位
            }
        }
    }

};
