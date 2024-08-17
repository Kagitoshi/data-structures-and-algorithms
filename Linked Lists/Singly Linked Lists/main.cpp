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
    Linked list head -> 4 -> 2 -> 5 -> null
    Output: 3 cannot be found in the linked list.
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

    std::cout << "\n\nA node containing \"" << dataToFind << "\" could not be\n"
              << "found. Therefore, a new node with the data \""
              << dataToAddAfterFoundData << "\" has not been added.\n\n";
}

/*
    The following function searches for a node containing data that has been
    passed through the argument and deletes it.

    A new node is created using the "head" node as a starting point.

    If it does not find it or the list is empty, a string is
    outputted stating that fact.

    If it is not empty, it first searches the node the current node is pointing to. If that node
    contains the data that is being request to delete, it then points the current node to the whatever
    the next node if pointing to.

    If that node doesn't contain the data, the new node then becomes the node the current node is
    pointing to until it finds the data or hits a nullptr, which then a string is outputted
    stating that fact.

    By using the keyword \"delete\", it will free up the memory that is being used to store
    that node. If it is not deleted, the memory will not be freed and the application will
    begin to leak memory.

    There is another keyword called \"free\" that does the same thing but should be used when you allocated
    memory before for the variable.
    e.g. When using \"malloc\" to allocate the memory, free should be used when you wish to free that
    memory up for the OS.

    e.g. Current linked list head -> 4 -> 2 -> 6 -> 5 -> null
    deleteElement(6)
    New linked list head -> 4 -> 2 -> 5 -> null

    Current linked list head -> 4 -> 2 -> 5 -> null
    deleteElement(6)
    Linked list head -> 4 -> 2 -> 5 -> null
    Output: 6 cannot be found in the linked list.

 */
template <typename T>
void linkedList<T>::deleteElement(T dataToDelete)
{
    Node<T>* searchForNodeToDelete{};
    searchForNodeToDelete = head;

    if(searchForNodeToDelete == nullptr)
    {
        std::cout << "\n\nUnable to delete \"" << dataToDelete << "\" from the linked list,\n"
                  << "because the linked list is empty.\n\n";
    }

    while(searchForNodeToDelete -> next != nullptr)
    {
        if(searchForNodeToDelete -> next -> data == dataToDelete)
        {
            Node<T>* nodeToDelete{searchForNodeToDelete -> next};
            searchForNodeToDelete -> next = searchForNodeToDelete -> next -> next;

            delete nodeToDelete;
            return;
        }

        else
        {
            searchForNodeToDelete = searchForNodeToDelete -> next;
        }
    }

    std::cout << "\n\nThe data you wish to delete, \"" << dataToDelete
              << "\" could not be found in the linked list.\n\n";
}

/*
    Lastly, we have the function to that prints the node's data to the console.

    In this case, it also prints which number node it is along with the node's data.

    If the link it is empty, it will notify the user.
 */

template <typename T>
void linkedList<T>::display()
{
    Node<T>* currentNode{head};

    if(currentNode == nullptr)
    {
        std::cout << "\n\nThe linked list is currently empty.\n\n";
    }

    int i{0};

    while(currentNode != nullptr)
    {
        std::cout << "Number " << ++i << " node contains the data " << currentNode -> data << ".\n";
        currentNode = currentNode -> next;
    }

    std::cout << "\n";
}


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
              << "Let's start with red, orange, and yellow.\n"
              << "So that means each node should contain a string and a pointer\n"
              << "to the next node containing different data until we reach\n"
              << "a \"null\" pointer. Let's first test out the \"addElementFirst\" function."
              << "We will add them in the order of \"yellow orange red\", which means the order in the linked list"
              << "should be \"red orange yellow\" \n\n";

    linkedList<std::string> colors;

    colors.display();

    colors.addElementFirst("yellow");
    colors.addElementFirst("orange");
    colors.addElementFirst("red");
    colors.display();

    std::cout << "Next let's try out the \"addElementEnd\" function.\n"
              << "We will add 3 colors in the following order \"green blue violet\".\n"
              << "So, it should show up at the end of the list in the following order:\n"
              << "\"green blue violet\", which will be appended to the list we already created.\n\n";

    colors.addElementEnd("green");
    colors.addElementEnd("blue");
    colors.addElementEnd("violet");
    colors.display();

    std::cout << "Now let's try out the \"addElementAfter\" function. Which should add a node\n"
              << "containing specified data after finding a node with data we are looking for.\n"
              << "Let's look for \"blue\" and add a node containing \"indigo\".\n"
              << "When we print the linked list indigo should appear after blue.\n\n";

    colors.addElementAfter("blue", "indigo");
    colors.display();

    std::cout << "Now let's try out the \"deleteElement\" function. Which should delete a node\n"
              << "containing specified data.\n"
              << "Let's first add a color to remove, so we will add \"pink\" after the node containing \"indigo\".\n"
              << "Let print it to see that it worked first.\n\n";

    colors.addElementAfter("indigo", "pink");
    colors.display();

    std::cout << "Now let's delete pink and print the list to see if it worked.\n\n";

    colors.deleteElement("pink");
    colors.display();

    std::cout << "That did it! The color pink is no longer in the list and it has been properly deleted.\n"
              << "If it was not properly deleted, the node with the color pink will no free up the memory\n"
              << "that it is using back to the OS. This will cause a memory leak in the application.\n\n"
              << "This concludes the linked lists introduction. Next we will explore a doubly linked list.\n\n";

    return 0;
}
