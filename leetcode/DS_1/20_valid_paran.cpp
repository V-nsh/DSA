#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool check(char a, char b)
    {
        return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
    }
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0)
            return false;

        stack<char> st;
        for (auto i : s)
        {
            if (i == '(' || i == '{' || i == '[')
                st.push(i);
            else
            {
                if (!st.empty() && check(st.top(), i))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        printf("yes");
        return st.empty();
    }
};