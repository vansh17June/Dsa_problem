class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int count = 0;
        int i = 0, j = 0, ans = 0, n = s.size();
        while (j < s.size()) {
            while (count != 3 && i < n) {
                char ch = s[i];
                if (ch != 'a' &&ch != 'b' && ch != 'c') {
                    i++;
                    continue;
                }
                mp[ch]++;
                if (mp[ch] == 1) {
                    count++;
                }
                i++;
            }
            if(count==3)
            ans += (n - i+1);
            if (s[j] == 'a' || s[j] == 'b' || s[j] == 'c') {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
            }
            j++;
        }
        return ans;
    }
};
