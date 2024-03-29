#include <iostream>
#include <stack>

std::string reverseString(const std::string& userString)
{
    std::stack<char> stringStack{};

    for(const char& i : userString)
    {
        stringStack.push(i);
    }

    std::string reversedString{""};

    while(!stringStack.empty())
    {
        reversedString += stringStack.top();
        stringStack.pop();
    }

    return reversedString;
}

bool checkBrackets(const std::string& userString)
{

    std::stack<char> bracketStack{};

    for(const char& i: userString)
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
              << "seeing if we can reverse a string, then we see\n"
              << "if the brackets in a string have a opening and closing pair.\n"
              << "Please enter your string that you would like to reverse and check.\n";

    std::string userString{};
    std::getline(std::cin, userString);

    std::cout << "First let's reverse the string: \n"
              << reverseString(userString) << '\n'
              << "\nNice! Now let's check for the opening and closing brackets.\n\n";

    if (checkBrackets(userString))
    {
        std::cout << "All of the brackets are accounted for. Nice!\n\n";
        return 0;
    }
    else
    {
        return 1;
    }
}
