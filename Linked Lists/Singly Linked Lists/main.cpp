#include <iostream>

/*
    Creating a template typename, so I can use the list for different types.
    Of course the types will be grouped together. So I can't mix a
    linked list of different types of data.

    To create a singly linked list, we start by creating a struct or a class that
    contains a data type(int, char, string, etc.) and a pointer, that
    will point to the next node. In this case since I am using a template typename,
    the data type that is contained within the node will depend on the construction
    of the data type upon creation.
*/
template <typename T>
struct Node
{
    T data;
    Node* next;
};

template <typename T>
class linkedList
{
private:
    Node<T>* head;

public:
    linkedList()
    {
        head = nullptr;
    }

    void addElementFirst(T dataToAddAtFirstNode);
    void addElementEnd(T dataToAddAtLastNode);
    void addElementAfter(T dataToFind, T dataToAddAfterFoundData);
    void deleteElement(T dataToDelete);
    void display();
};
/*
    Add a Node with Data to the front of the Linked list.

    It will add the data in the argument and push all the other
    data down.

    e.g. Current linked list head -> 4 -> 2 -> 5 -> null
    addElementFirst(6)
    New linked list head -> 6 -> 4 -> 2 -> 5 -> null
 */
template <typename T>
void linkedList<T>::addElementFirst(T dataToAddAtFirstNode)
{
    Node<T>* newNode{new Node<T>};
    newNode -> data = dataToAddAtFirstNode;
    newNode -> next = head;
    head = newNode;
}

/*
    Add a Node with Data to the end of the Linked list.

    If the head is pointing to null. It will add the new node
    and the new node will "next" pointer will be pointing to null
    and the head will be pointing to the new node.

    Else, it will iterate through the whole list until it finds the
    node with a "next" pointing to a nullptr.
    Then it will point the new pointer to null and the old

    e.g. Current linked list head -> 4 -> 2 -> 5 -> null
    addElementFirst(6)
    New linked list head -> 4 -> 2 -> 5 -> 6 -> null
*/
template <typename T>
void linkedList<T>::addElementEnd(T dataToAddAtLastNode)
{
    Node<T>* newNode{new Node<T>};
    Node<T>* temp{new Node<T>};

    temp = head;
    newNode -> data = dataToAddAtLastNode;

    if(temp == nullptr)
    {
        newNode -> next = nullptr;
        head = newNode;
        return;
    }
    while(temp -> next != nullptr)
    {
        temp = temp -> next;
    }

    newNode -> next = nullptr;
    temp -> next = newNode;
}

/*
    The following function will search through the list for
    and check the data in each node until it matches the data
    you want to add a node after.

    After finding it, it will point the new node to the "next" pointer
    from the found node, then it will point the found node to the new node.

    If it cannot find the data that is being searched, a string will output
    stating that the data being searched for cannot be found and do nothing
    with the new data.

    e.g. Current linked list head -> 4 -> 2 -> 5 -> null
    addElementAfter(2, 6)
    New linked list head -> 4 -> 2 -> 6 -> 5 -> null

    Current linked list head -> 4 -> 2 -> 5 -> null
    addElementAfter(3, 6)
    New linked list head -> 4 -> 2 -> 5 -> null
    Output: 6 cannot be found in the linked list.
 */
template <typename T>
void linkedList<T>::addElementAfter(T dataToFind, T dataToAddAfterFoundData)
{
    Node<T>* nodeToSearch{new Node<T>};
    nodeToSearch = head;

    while(nodeToSearch != nullptr)
    {
        if(nodeToSearch -> data == dataToFind)
        {
            Node<T>* newNode{new Node<T>};
            newNode -> data = dataToAddAfterFoundData;
            newNode -> next = nodeToSearch -> next;

            nodeToSearch -> next = newNode;
            return;
        }
        nodeToSearch = nodeToSearch -> next;
    }

    if(nodeToSearch == nullptr)
    {
        std::cout << "\n\nA node containing \"" << dataToFind << "\" could not be\n"
                  << "found. Therefore, a new node with the data \""
                  << dataToAddAfterFoundData << "\" has not been added.\n\n";
    }
}

/*
    The following function searches for a node containing data that has been
    passed through the argument and deletes it.

    If it does not find it or the list is empty, a string is
    outputted stating that fact.

    If it does find it, it
 */


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
