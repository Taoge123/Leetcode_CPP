//
// Created by Tony Cheng on 3/10/22.
//

#include <iostream> // header in standard library
#include <vector>
#include <stack>
#include <stdlib.h>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthese;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') parenthese.push(s[i]);
            else {
                if (parenthese.empty()) return false;
                if (s[i] == ')' && parenthese.top() != '(') return false;
                if (s[i] == ']' && parenthese.top() != '[') return false;
                if (s[i] == '}' && parenthese.top() != '{') return false;
                parenthese.pop();
            }
        }
        return parenthese.empty();
    }
};




