#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
    link: https://www.lintcode.com/problem/659/description
    The problem is to write an algorithm to encode and then decode a list of strings.
    Input: ["leet","code","love","you"]
    Output: ["leet","code","love","you"]
    Explanation:
    One possible encode method is: "leet:;code:;love:;you"

    and then decode the same to the list.
    we are not allowed to store any data related to the strings, i.e we cannot store the length of the strings.
    one way could be to store the number in front of the string followed by a delimiter, like 4#leet4#code
    so even if the string starts with an integer or delimiter itself it won't be an issue.
*/
class Solution
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        // write your code here
        string res = "";
        for (auto str : strs)
        {
            string len = to_string(str.size());
            res = res + len + "#" + str;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        // write your code here
        vector<string> res;
        string temp = "";
        int count = 0;
        for (int i = 0; i < str.size();)
        {
            if (isdigit(str[i]))
            {
                count = str[i] - 48;
                i += 2;
            }
            while (count > 0)
            {
                temp += str[i];
                count--;
                i++;
            }
            res.push_back(temp);
            temp = "";
        }

        return res;
    }
};

int main()
{
    string s = "";
    vector<string> strs = {"leet", "code", "love", "you"};
    vector<string> res;
    Solution sol;
    s = sol.encode(strs);
    cout << s << endl;
    res = sol.decode(s);
    for (auto s : res)
    {
        cout << s;
    }
    cout << endl;

    return 0;
}