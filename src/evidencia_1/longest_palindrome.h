#ifndef PALINDROME_
#define PALINDROME_

#include "FileReader.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace algorithms
{

// Given a string s, return the indices correspoding to the longest palindrome.
// Time complexity: O(n), where n is the size of the string
// Space complexity: O(n), where n is the size of the string
pair<int, int> longestPalidrome(string s)
{
    // Declaration of necessary variables
    pair<int, int> ans = {0, 0};
    int n = 2 * s.size() + 1;
    vector<int> lenPalndrm(n, 0);
    lenPalndrm[1] = 1;
    int centerIndex = 1;
    int rightIndex = 2;
    int right = 0, left;
    int maxPalLength = 0, maxCenterIndex = 0;
    int start = -1, end = -1, diff = -1;
    for (right = 1; right < n; right++)
    {
        left = 2 * centerIndex - right;
        int diff = rightIndex - right;
        // change right value to mirror value
        if (diff > 0)
        {
            lenPalndrm[right] = min(lenPalndrm[left], diff);
        }
        //increase recorded length of palindrome while bigger palindrome is being found
        while (((right + lenPalndrm[right]) < n &&
                (right - lenPalndrm[right]) > 0) &&
               (((right + lenPalndrm[right] + 1) % 2 == 0) ||
                (s[(right + lenPalndrm[right] + 1) / 2] ==
                 s[(right - lenPalndrm[right] - 1) / 2])))
        {
            lenPalndrm[right]++;
        }
        // shift center if bigger palindrome found
        if (lenPalndrm[right] > lenPalndrm[maxCenterIndex])
        {
            maxCenterIndex = right;
        }
        //shift center and right according to the current palindrome
        if (right + lenPalndrm[right] > rightIndex)
        {
            centerIndex = right;
            rightIndex = right + lenPalndrm[right];
        }
    }
    // Save variables to return value
    ans.first = (maxCenterIndex - lenPalndrm[maxCenterIndex]) / 2 + 1;
    ans.second = ans.first + lenPalndrm[maxCenterIndex] - 1;
    return ans;
}

}; // namespace algorithms


//testing with transmission1 and transmission2
namespace test
{
using namespace algorithms;
int longest_palindrome_test()
{
    string test = FileReader::readFile("transmission1.txt");
    string test2 = FileReader::readFile("transmission2.txt");
    test.erase(std::remove(test.begin(), test.end(), '\n'), test.cend());
    test2.erase(std::remove(test2.begin(), test2.end(), '\n'), test2.cend());

    pair<int, int> indices = longestPalidrome(test);
    pair<int, int> indices2 = longestPalidrome(test2);

    cout << indices.first << " " << indices.second << " "
         << test.substr(indices.first - 1, indices.second - indices.first + 1)
         << endl;
    cout << indices2.first << " " << indices2.second << " "
         << test2.substr(indices2.first - 1,
                         indices2.second - indices2.first + 1)
         << endl;

    return 0;
}
} // namespace test

#endif
