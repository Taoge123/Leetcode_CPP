//
// Created by Tony Cheng on 2/20/22.
//

#include <iostream> // header in standard library
#include <vector>
#include <string>
#include <stdlib.h>



using namespace std;


class Solution {
    int m, n;
public:

    bool dfs(const vector<vector<int>>& grid, int u, vector<bool>& visited, vector<int>& girls) {
        for (int v = 0; v < n; v++) {
            if (grid[u][v] == 0 || visited[v]) {
                continue;
            }
            visited[v] = true;
            if (girls[v] < 0 || dfs(grid, girls[v], visited, girls)) {
                girls[v] = u;
                return true;
            }
        }
        return false;
    }


    int maximumInvitations(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // cout << m << n;
        vector<int> girls(n, -1);
        int count = 0;

        for (int u = 0; u < m; u++) {
            // vector<bool> visited(n, false);
            vector<bool> visited(n, false);
            if (dfs(grid, u, visited, girls)) {
                count++;
            }
        }
        return count;
    }
};


