/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid

*/

#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

bool ValidParentheses(std::string);

int main(int argc, char const *argv[])
{   
    bool flag = ValidParentheses("((");
    
    std::cout<<flag<<std::endl;


    return 0;
}

bool ValidParentheses(std::string s)
{
        std::stack<char> stack_;
    bool flag = true;

    if(s.size() == 0)
        return true;

    else if(s.size() %2 != 0)
        return false;


    for(int i = 0; i<s.size();i++)
    {
       
        if(s[i] == '(')
            stack_.push(')');
        else if(s[i] == '[')
            stack_.push(']');
        else if(s[i] == '{')
            stack_.push('}');
        
        else if (stack_.empty() || stack_.top() != s[i])
        {
            return false;
        }
        else
            stack_.pop();
          
   
    }
    
    if(stack_.size() == 0)
        return true;
    else
        return false;
}