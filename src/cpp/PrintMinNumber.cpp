class Solution {
public:

    static string itos(int x) {
    	return (x > 9 ? itos(x / 10) : "") + char(x % 10 + '0');
	}

	static bool cmp(int a, int b) {
    	return itos(a) + itos(b) < itos(b) + itos(a);
	}

    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string s = "";
        for (int i = 0; i < numbers.size(); ++i) {
            s += itos(numbers[i]);
        }
        return s;
    }

};
