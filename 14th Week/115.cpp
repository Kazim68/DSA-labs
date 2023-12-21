#include <iostream>
using namespace std;

// problem 1
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        unordered_map<string, int> dnas;
        string temp = "";

        for (int i = 0; i + 10 <= s.length(); i++)
        {
            temp = s.substr(i, 10);
            if (dnas.find(temp) != dnas.end() && !dnas[temp])
            {
                res.push_back(temp);
                dnas[temp]++;
            }
            else if (dnas.find(temp) == dnas.end())
            {
                dnas[temp] = 0;
            }
        }

        return res;
    }
};

// problem 2
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagrams;
        string temp;

        for (int i = 0; i < strs.size(); i++)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            anagrams[temp].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto it = anagrams.begin(); it != anagrams.end(); it++)
        {
            res.push_back(it->second);
        }

        return res;
    }
};