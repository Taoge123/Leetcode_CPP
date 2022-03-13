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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table.count(target - nums[i])) {
                // for (auto x : table)
                //   cout << x.first << " - " << x.second << endl;
                // cout << target - nums[i];
                return {i, table[target - nums[i]]};
            }
            table[nums[i]] = i;
        }
        return {};
    }
};


class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            table[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (table.count(complement) && table[complement] != i) {
                res.push_back(i);
                res.push_back(table[complement]);;
                break;
            }
        }
        return res;
    }
};

