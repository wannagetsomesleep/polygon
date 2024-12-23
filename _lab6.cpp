#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // Преобразуем wordDict в множество для поиска за O(1)
        unordered_map<string, vector<string>> memo; // Карта мемоизации
        return backtrack(s, wordSet, memo);
    }

private:
    vector<string> backtrack(const string& s, const unordered_set<string>& wordSet, unordered_map<string, vector<string>>& memo) {
        if (memo.find(s) != memo.end()) {
            return memo[s]; // Возвращаем мемоизированный результат, если он доступен
        }
        if (s.empty()) {
            return { "" };
        }

        vector<string> sentences;
        for (int i = 1; i <= s.size(); ++i) {
            string word = s.substr(0, i);
            if (wordSet.find(word) != wordSet.end()) {
                string remaining = s.substr(i);
                vector<string> rest = backtrack(remaining, wordSet, memo);
                for (const string& sentence : rest) {
                    if (sentence.empty()) {
                        sentences.push_back(word);
                    }
                    else {
                        sentences.push_back(word + " " + sentence);
                    }
                }
            }
        }

        memo[s] = sentences; // Мемоизируем результат
        return sentences;
    }
};

