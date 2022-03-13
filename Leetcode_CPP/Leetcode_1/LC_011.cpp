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
    int maxArea(vector<int>& height) {

        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? i++ : j--;
        }
        return res;
    }
};



class Solution2 {
public:
    int maxArea(vector<int>& height) {

        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            while (i < j && h == height[i]) i++;
            while (i < j && h == height[j]) j--;
        }
        return res;

    }
};




