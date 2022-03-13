//
// Created by Tony Cheng on 3/10/22.
//

#include <iostream> // header in standard library
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        vector<string> table{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, table, 0, "", res);
        return res;
    }

    void dfs(string& digits, vector<string>& table, int pos, string path, vector<string>& res) {
        if (pos == digits.size()) {
            res.push_back(path);
            return;
        }
        string s = table[digits[pos] - '0'];
        for (int i = 0; i < s.size(); i++) {
            dfs(digits, table, pos + 1, path + s[i], res);
        }
    }
};


