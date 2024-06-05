#include <iostream>

//To create a singly linked list, we start by creating a struct or a class that
//contains a data type(int, char, string, etc.) and a pointer, that
//will point to the next node.
struct Node
{
    std::string colors;
    Node* next;
};

int main()
{
    std::cout << "Let's explore the world of \"Singly Linked Lists\"!\n"
              << "There are 4 classic operations when exploring linked lists.\n"
              << "Reading, searching, insertion, and deletion.\n\n"
              << "Although, arrays and linked lists are similar, as they are\n"
              << "data structures that area list of things. Numbers, strings, etc...\n"
              << "Let's start exploring them and learn the differences between them.\n\n"
              << "Before we start with classic operations, let's create out linked list.\n"
              << "I will create 3 nodes. The data will be the name of colors.\n"
              << "Let's start with blue, green, and red in that order.\n"
              << "So that means each node should contain a string and a pointer\n"
              << "to the next node containing different data until we reach\n"
              << "a \"null\" pointer.\n\n";





    return 0;
}
