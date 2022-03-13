//
// Created by Tony Cheng on 3/10/22.
//

#include <iostream> // header in standard library
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {

        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> table;

        for (int i = 0; i < n; i++) {
            if (table.count(s[i]) && table[s[i]] > left) {
                left = table[s[i]];
            }
            table[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

