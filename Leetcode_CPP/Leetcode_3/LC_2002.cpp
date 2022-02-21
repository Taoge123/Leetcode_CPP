
//
// Created by Tony Cheng on 2/20/22.
//
#include <iostream> // header in standard library
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int n = s.length();
        string a = "", b = "";
        int res = 1;
        dfs(s, 0, a, b, res);
        return res;
    }

    void dfs(string& s, int i, string &a, string &b, int &res) {
        int n = s.length();
        if (isPal(a) && isPal(b)) {
            res = max(res, (int)a.length() * (int)b.length());
        }
        if (i >= n) return;

        dfs(s, i+1, a, b, res);
        a += s[i];
        dfs(s, i+1, a, b, res);
        a.pop_back();
        b += s[i];
        dfs(s, i+1, a, b, res);
        b.pop_back();
    }


    bool isPal(string &a) {
        int i = 0, j = a.length() - 1;
        while (i <= j) {
            if (a[i] != a[j]) return false;
            i++;
            j--;
        }
        return true;
    }

};
