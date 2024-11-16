#ifndef LCS_
#define LCS_

#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

namespace algorithms
{

    // Given a string s, return the indices correspoding to the longest common substring.
    // The indices are 1-indexed and with respect to the first string
    // Time complexity: O(n*m), where n and m are the sizes of the strings
    // Space complexity: O(m), where m is the size of the second string
    pair<int, int> longestCommonSubstring(string s1, string s2)
    {
        // Vector to size of the longest common substring
        vector<int> dp(s2.size() + 1, 0);
        int maxLen = 0;
        pair<int, int> ans = {-1, -1}; // 0-indexed

        for (int i = 0; i < s1.size(); i++)
        {
            // Initialize vector for the current row.
            vector<int> nextRow(s2.size() + 1, 0);
            for (int j = 0; j < s2.size(); j++)
            {
                // If the characters match, it means that the substring is extended by 1
                if (s1[i] == s2[j])
                {
                    nextRow[j + 1] = dp[j] + 1;
                    // Update the max length and the indices, if needed
                    if (nextRow[j + 1] > maxLen)
                    {
                        maxLen = nextRow[j + 1];
                        ans = {i - maxLen + 1, i};
                    }
                }
            }
            // Update dp vector
            dp = nextRow;
        }

        // Throw exception if no common substring is found
        if (ans.first == -1 || ans.second == -1)
            throw std::invalid_argument("No se encontró un substring común");

        // 1-indexed
        return {ans.first + 1, ans.second + 1};
    }
};

// tests con el archivo transmission1.txt y transmission2.txt
namespace test
{
    void lcs_test()
    {
        string test = FileReader::readFile("transmission1.txt");
        string test2 = FileReader::readFile("transmission2.txt");

        pair<int, int> indices = algorithms::longestCommonSubstring(test, test2);

        cout << indices.first << " " << indices.second << " " << test.substr(indices.first - 1, indices.second - indices.first + 1) << endl;
    }
}

#endif