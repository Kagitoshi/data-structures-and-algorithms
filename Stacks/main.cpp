#include <iostream>
#include <stack>

bool checkBrackets(const std::string& testString)
{

    std::stack<char> bracketStack{};

    for(const char& i: testString)
    {
        if( i == '(' || i == '[' || i == '{' || i == ')' || i == ']' || i == '}')
        {
            if( i == '(' || i == '[' || i == '{')
            {
                bracketStack.push(i);
            }
            else if (i == ')')
            {
                if(bracketStack.empty())
                {
                    std::cout << "The stack is empty, so the bracket '" << i << "' doesn't have an opening bracket.\n\n";
                    return false;
                }
                else if(bracketStack.top() == '(')
                {
                    bracketStack.pop();
                }
                else
                {
                    std::cout << i << " is missing the opening bracket '('.\n"
                              << "The opening bracket currently is: " << bracketStack.top() << "\n\n";
                    return false;
                }
            }
            else if (i == ']')
            {
                if(bracketStack.empty())
                {
                    std::cout << "The stack is empty, so the bracket '" << i << "' doesn't have an opening bracket.\n\n";
                    return false;
                }
                else if (bracketStack.top() == '[')
                {
                    bracketStack.pop();
                }
                else
                {
                    std::cout << i << " is missing the opening bracket '['.\n"
                              << "The opening bracket currently is: " << bracketStack.top() << "\n\n";
                    return false;
                }
            }
            else if (i == '}')
            {
                if(bracketStack.empty())
                {
                    std::cout << "The stack is empty, so the bracket '" << i << "' doesn't have an opening bracket.\n\n";
                    return false;
                }
                else if (bracketStack.top() == '{')
                {
                    bracketStack.pop();
                }
                else
                {
                    std::cout << i << " is missing the opening bracket '{'.\n"
                              << "The opening bracket currently is: " << bracketStack.top() << "\n\n";
                    return false;
                }
            }
        }
        else
        {
            ;
        }
    }

    if (!bracketStack.empty())
    {
        std::cout << "The stack isn't empty. The opening bracket(s) "
                  << "still left in the stack is/are the following:\n";

        while(!bracketStack.empty())
        {
            std::cout << bracketStack.top() << ' ';
            bracketStack.pop();
        }

        std::cout << "\n\n";
        return false;
    }
    else
    {
        return true;
    }
}



int main()
{
    std::cout << "Let's practice using a stack data structure by\n"
              << "checking if brackets in a string have a opening and closing pair.\n\n";

    std::string testString{"( var x = y: [1, 2, 3,] } )"};

    if (checkBrackets(testString))
    {
        std::cout << "All of the brackets are accounted for. Nice!\n\n";
        return 0;
    }
    else
    {
        return 1;
    }
}
