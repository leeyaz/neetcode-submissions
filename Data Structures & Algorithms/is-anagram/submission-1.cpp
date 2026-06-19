class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for (char c : s) {
            s_map[c]++;
        }

        for (char c : t) {
            t_map[c]++;
        }

        for (auto& pair : s_map) {
            if (t_map[pair.first] != pair.second) return false;
        }

        return true;
    }
};
