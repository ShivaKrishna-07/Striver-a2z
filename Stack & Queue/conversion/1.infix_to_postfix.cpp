

// GFG - Infix to Postfix


int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s)
{
    // Your code here
    int n = s.length();
    stack<char> st;
    string result;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'B') || (ch >= '0' && ch <= '9'))
        {
            result += ch;
        }
        else if (ch == '(')
        {
            st.push('(');
        }
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(ch) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}