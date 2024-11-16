#ifndef KMP_
#define KMP_

#include <iostream>
#include <vector>

using namespace std;

namespace algorithms
{

    /*
        KMP algorithm to check if a text is contained in anotherone
        Params: text (string that could contain a pattern)
                pattern (string that could be contained in text)
                lps (vector of the pattern that could be contained on text)
        Returns: vector (positions where the pattern is contained int text)
        Complexity: O(m + n)
    */
    vector<int> containsText(string &text, string &pattern, vector<int> &lps)
    {
        vector<int> result;
        int i = 0, j = 0;
        while (i < text.length())
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
                if (j == pattern.length())
                {
                    result.push_back(i - pattern.length());
                }
            }
            else if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
        return result;
    }

    /*
        Algorithm to obtain the longest proper prefix vector
        Params: text (string to be preprocessed)
        Returns: vector (vector with longest prefix values)
        Complexity: O(n)
    */
    vector<int> preprocess(string text)
    {
        vector<int> lps(text.size(), 0);
        int j = 0;

        for (int i = 1; i < text.size(); i++)
        {
            if (text[i] == text[j])
            {
                lps[i] = ++j;
            }
            else if (j > 0)
            {
                j = lps[j - 1];
                i--;
            }
        }

        return lps;
    }

};

#endif // KMP