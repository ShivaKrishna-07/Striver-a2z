

// Leetcode - 232 - Implement Queue using Stacks
// TC - O(1)
// SC - O(2n)

stack<int> input;
stack<int> output;

MyQueue() {}

void push(int x)
{
    input.push(x);
}

int pop()
{
    if (output.empty())
    {
        while (input.size())
        {
            output.push(input.top());
            input.pop();
        }
    }
    int x = output.top();
    output.pop();
    return x;
}

int peek()
{
    if (output.empty())
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }
    return output.top();
}

bool empty()
{
    return !(output.size() || input.size());
}