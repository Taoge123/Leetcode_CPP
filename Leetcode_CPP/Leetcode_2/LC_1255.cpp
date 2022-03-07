//
// Created by Tony Cheng on 3/6/22.
//
#include <iostream> // header in standard library
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int> word_score;
        for (auto &word : words) {
            int sum = 0;
            for (auto &ch : word) sum += score[ch - 'a'];
            word_score.push_back(sum);
        }
        vector<int> count(26, 0);
        for (auto ch : letters) count[ch - 'a']++;
        return dfs(words, word_score, 0, count);
    }


    bool canInclude(string &word, vector<int> &count) {
        vector<int> word_count(26, 0);
        for (auto ch : word) word_count[ch - 'a']++;
        for (int i= 0; i<26; i++) if (word_count[i] > count[i]) return false;
        return true;
    }

    int dfs(vector<string> &words, vector<int> &word_score, int i, vector<int> &count) {
        if (i >= words.size()) return 0;
        int pick = 0;
        if (canInclude(words[i], count)) {
            for (auto ch : words[i]) count[ch - 'a']--;
            pick = dfs(words, word_score, i+1, count) + word_score[i];
            for (auto ch : words[i]) count[ch - 'a']++;
        }
        int no_pick = dfs(words, word_score, i+1, count);
        return max(pick, no_pick);
    }
};