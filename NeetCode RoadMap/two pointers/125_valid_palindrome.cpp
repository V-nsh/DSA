#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.size() == 1)
        {
            return true;
        }

        vector<char> strs;

        for (char st : s)
        {
            if (isalnum(st))
            {
                st = tolower(st);
                strs.push_back(st);
            }
        }

        int front = 0, back = strs.size() - 1;

        while (front < back)
        {
            if (strs[front] != strs[back])
            {
                return false;
            }
            else
            {
                front++;
                back--;
            }
        }

        return true;
    }

public:
    bool isValidPalindrome(string s)
    {
        int front = 0, back = s.size() - 1;
        while (front < back)
        {
            while (!isalnum(s[front]) && front < back)
            {
                front++;
            }

            while (!isalnum(s[back]) && front < back)
            {
                back--;
            }

            if (tolower(s[front]) != tolower(s[back]))
            {
                return false;
            }

            front++;
            back--;
        }
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    cout << sol.isValidPalindrome(s) << endl;

    return 0;
}