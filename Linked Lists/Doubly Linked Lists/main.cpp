#include <iostream>

/*
    Creating a template typename, so I can use the list for different types.
    Of course the types will be grouped together. So I can't mix a
    linked list of different types of data.

    To create a doubly linked list, we start by creating a struct or a class that
    contains a data type(int, char, string, etc.) and a pointer, that
    will point to the next node and to the previous node. In this case since I am using a template typename,
    the data type that is contained within the node will depend on the construction
    of the data type upon creation.
*/
template <typename T>
struct Node
{
    T data {};
    Node* next {};
    Node* previous {};
};

template <typename T>
class linkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int numberOfNodesInList{0};

public:
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    //Modifying Functions
    void addElementFirst(T dataToAddAtFirstNode);
    void addElementEnd(T dataToAddAtLastNode);
    void addElementAfter(T dataToFind, T dataToAddAfterFoundData);
    void deleteElement(T dataToDelete);

    //Display Functions
    void display();
    void displayBackwards();
    void printNodeCount();
};
/*
    Add a Node with Data to the front of the Linked list.

    It will add the data in the argument and push all the other
    data down, while making the new node the head.

    If the list is empty the element that is being added should be the
    head and tail of the list.

    e.g. Current linked list head -> 4 -> 2 -> 5 -> null
    head = 4
    tail = 5

    addElementFirst(6)
    New linked list head -> 6 -> 4 -> 2 -> 5 -> null
    head = 6
    tail = 5
 */
template <typename T>
void linkedList<T>::addElementFirst(T dataToAddAtFirstNode)
{
    Node<T>* newNode{new Node<T>};
    newNode -> data = dataToAddAtFirstNode;

    //This should check if the list is empty and if it is, it will make
    //the first element the head and tail of the list.
    if(head != nullptr)
    {
        newNode -> next = head;
        newNode -> previous = nullptr;
        head -> previous = newNode;
        head = newNode;

        numberOfNodesInList++;
    }
    else
    {
        head = newNode;
        tail = newNode;

        numberOfNodesInList++;
    }
}

/*
    Add a Node with Data to the end of the Linked list.

    Unlike, a singly-link list, we do not need to iterate
    through the whole list to find the last node.

    We can easily add a node to the end of the list since we track it,
    with the tail node.

    So, we first check if the tail exists, if it does not,
    it usually means the list is empty, and we add the new node.
    We will also make it our head and tail node.

    e.g. Current linked list head -> 4 -> 2 -> 5 -> null
    head = 4
    tail = 5

    addElementFirst(6)
    New linked list head -> 4 -> 2 -> 5 -> 6 -> null
    head = 4
    tail = 6
*/
template <typename T>
void linkedList<T>::addElementEnd(T dataToAddAtLastNode)
{
    Node<T>* newNode{new Node<T>};
    newNode -> data = dataToAddAtLastNode;

    //This should check if the list is empty and if it is, it will make
    //the first element the head and tail of the list.
    if(tail != nullptr)
    {
        newNode -> next = nullptr;
        newNode -> previous = tail;
        tail -> next = newNode;
        tail = newNode;

        numberOfNodesInList++;
    }
    else
    {
        head = newNode;
        tail = newNode;

        numberOfNodesInList++;
    }
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

    Since we are searching, that means we have to iterate through
    the list, but since we are tracking the tail as well,
    let's check that node first. If it is the tail then we can
    quickly make it the tail but running the dataToAddAtLastNode function above.

    e.g. Current linked list head -> 4 -> 2 -> 5 -> null
    head = 4
    tail = 5
    addElementAfter(2, 6)
    New linked list head -> 4 -> 2 -> 6 -> 5 -> null

    Current linked list head -> 4 -> 2 -> 5 -> null
    addElementAfter(3, 6)
    Linked list head -> 4 -> 2 -> 5 -> null
    head = 4
    tail = 5
    Output: 3 cannot be found in the linked list.
 */
template <typename T>
void linkedList<T>::addElementAfter(T dataToFind, T dataToAddAfterFoundData)
{
    if(tail -> data == dataToFind)
    {
        addElementEnd(dataToAddAfterFoundData);

        return;
    }
    else
    {}

    Node<T>* nodeToSearch{head};

    while(nodeToSearch != tail)
    {
        if(nodeToSearch -> data == dataToFind)
        {
            Node<T>* newNode{new Node<T>};
            newNode -> data = dataToAddAfterFoundData;
            newNode -> next = nodeToSearch -> next;
            newNode -> previous = nodeToSearch;

            nodeToSearch -> next -> previous = newNode;
            nodeToSearch -> next = newNode;

            numberOfNodesInList++;
            
            return;
        }
        else
        {}
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

    Also, since we are tracking the head, tail, next, and previous elements. We have to be careful,
    to properly ensure the head and tail elements are being properly handled. So, if we delete the head,
    the head's next node needs to become the head and the previous element pointing to a nullptr.
    Vice versa goes for the tail node as well with the next element pointing to a nullptr.

    There is another keyword called \"free\" that does the same thing but should be used when you allocated
    memory before for the variable.
    e.g. When using \"malloc\" to allocate the memory, free should be used when you wish to free that
    memory up for the OS.

    e.g. Current linked list head -> 4 -> 2 -> 6 -> 5 -> null
    deleteElement(6)
    head = 4
    tail = 5
    New linked list head -> 4 -> 2 -> 5 -> null
    head = 4
    tail = 5

    Current linked list head -> 4 -> 2 -> 5 -> null
    head = 4
    tail = 5
    deleteElement(6)
    Linked list head -> 4 -> 2 -> 5 -> null
    head = 4
    tail = 5
    Output: 6 cannot be found in the linked list.

 */
template <typename T>
void linkedList<T>::deleteElement(T dataToDelete)
{
    if(head == nullptr)
    {
        std::cout << "\n\nUnable to delete \"" << dataToDelete << "\" from the linked list,\n"
                  << "because the linked list is empty.\n" 
                  << "There are " << numberOfNodesInList << "in the list.\n\n";
    }
    else if(head -> data == dataToDelete)
    {
        if(head == tail)
        {
            /*
                Since the head and tail are the same node deleting
                just the head will free the memory for the
                head and tail pointers. If you attempt to delete
                both the head and tail when they are pointing
                to the same memory address, there will be an error since there is no address
                that the tail is assigned to.
             */
            delete head;
            
            //Be sure to reassign the head and tail to null pointers.
            head = nullptr;
            tail = nullptr;
            std::cout << "Deleted " << dataToDelete << ".\n"
                      << "It was the only node in the list. The list should be empty.\n\n";
        }
        else
        {
            head -> next  = head;
            delete head -> previous;
            head -> previous = nullptr;

            std::cout << "Deleted " << dataToDelete << ".\n"
                      << "It was the head node of the list. \n"
                      << "The new head is now " << head -> data << ".\n";
        }

        numberOfNodesInList--;

        return;
    }
    else if(tail -> data == dataToDelete)
    {
        tail -> previous = tail;
        delete tail -> next;
        tail -> next = nullptr;

        std::cout << "Deleted " << dataToDelete << ".\n"
                  << "It was the tail node of the list. \n"
                  << "The new tail is now " << tail -> data << ".\n";

        numberOfNodesInList--;
        return;
    }
    else
    {}

    Node<T>* searchForNodeToDelete{head -> next};

    while(searchForNodeToDelete -> next != tail)
    {
        if(searchForNodeToDelete -> next -> data == dataToDelete)
        {

            searchForNodeToDelete -> next = searchForNodeToDelete -> next -> next;
            delete searchForNodeToDelete -> next -> previous;
            searchForNodeToDelete -> next -> previous = searchForNodeToDelete;

            numberOfNodesInList--;

            return;
        }

        else
        {
            searchForNodeToDelete = searchForNodeToDelete -> next;
        }
    }

    std::cout << "\n\nThe data you wish to delete, \"" << dataToDelete
              << "\" could not be found in the linked list.\n"
              << "There are currently "<< numberOfNodesInList << " nodes in the list.\n\n";
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
        std::cout << "\n\nThe linked list is currently empty.\n"
                  << "There are currently "<< numberOfNodesInList << " nodes in the list.\n\n";
        return;
    }
    else
    {}

    int i{0};

    while(currentNode != nullptr)
    {
        std::cout << "\n";
        std::cout << "********* Node #" << ++i << " - " << currentNode -> data <<  " *********\n\n";

        if(currentNode -> previous == nullptr)
        {
            std::cout << "Previous Node: NULL POINTER\n";
        }
        else
        {
            std::cout << "Previous Node: " << currentNode -> previous -> data << '\n';
        }

        if(currentNode -> next == nullptr)
        {
            std::cout << "Next Node    : NULL POINTER\n";
        }
        else
        {
            std::cout << "Next Node    : " << currentNode -> next -> data << '\n';
        }

        currentNode = currentNode -> next;
    }

    std::cout << "\n********* END OF LIST *********\n\n"
              << "There is a total of "<< numberOfNodesInList << " nodes in the list.\n\n"
              << "The current list's head and tail nodes are:\n"
              << "Head Node: " << head -> data << '\n'
              << "Tail Node: " << tail -> data << '\n';

    std::cout << '\n';
}


/*
    Same as the display function above except we are going to bring it in reverse order.
    Starting from the tail to the head of the list.
*/
template <typename T>
void linkedList<T>::displayBackwards()
{
    Node<T>* currentNode{tail};

    if(currentNode == nullptr)
    {
        std::cout << "\n\nThe linked list is currently empty.\n"
                  << "There is a total of "<< numberOfNodesInList << " nodes in the list.\n\n";
        return;
    }
    else
    {}

    int i{numberOfNodesInList};

    while(currentNode != nullptr)
    {
        std::cout << "\n";
        std::cout << "********* Node #" << i-- << " - " << currentNode -> data <<  " *********\n\n";

        if(currentNode -> next == nullptr)
        {
            std::cout << "Next Node    : NULL POINTER\n";
        }
        else
        {
            std::cout << "Next Node    : " << currentNode -> next -> data << '\n';
        }

        if(currentNode -> previous == nullptr)
        {
            std::cout << "Previous Node: NULL POINTER\n";
        }
        else
        {
            std::cout << "Previous Node: " << currentNode -> previous -> data << '\n';
        }

        currentNode = currentNode -> previous;
    }

    std::cout << "\n********* END OF LIST *********\n\n"
              << "There is a total of "<< numberOfNodesInList << " nodes in the list.\n\n"
              << "The current list's head and tail nodes are:\n"
              << "Head Node: " << head -> data << '\n'
              << "Tail Node: " << tail -> data << '\n';

    std::cout << '\n';
}

//A maybe handy function to print how many members are in the list.
template <typename T>
void linkedList<T>::printNodeCount()
{
    if(numberOfNodesInList)
    {
        std::cout << "There are currently " << numberOfNodesInList << " nodes in the list.\n\n";
    }
    else
    {
        std::cout << "The list is empty!\n"
                  << "There are " << numberOfNodesInList << " nodes in the list.\n\n";
    }
}

int main()
{
    std::cout << "Let's explore the world of \"Doubly Linked Lists\"!\n"
              << "There are 4 classic operations when exploring linked lists.\n"
              << "Reading, searching, insertion, and deletion.\n\n"
              << "Arrays and linked lists are similar, as they are\n"
              << "data structures that are a list of things. Numbers, strings, etc...\n"
              << "Let's start exploring them and learn the differences between them.\n\n"
              << "Before we start with classic operations, let's create our linked list.\n"
              << "I will create 3 nodes. The data will be the name of colors.\n"
              << "Let's start with red, orange, and yellow.\n"
              << "So that means each node should contain a string and a pointer\n"
              << "to the next and previous nodes containing different data until we reach the last node with\n"
              << " \"null\" pointer. Unlike a singly-linked list we are also tracking the\n"
              << "head of the list, which is the first node and the tail of the list which\n"
              << "is the last node. We will keep track of them as we display the list.\n\n"
              << "Also, unlike last the singly-linked list, let's try somethings first.\n\n"
              << "You know... for educational purposes. Let's start by creating the list and\n"
              << "checking if it is empty.";

    linkedList<std::string> colors;

    colors.display();

    std::cout << "The list is empty as you can see.\n"
              << "Let's us first try to see what happens we add only one color.\n"
              << "Then, we will print it to see what the head and tail elements are.\n"
              << "We can also check to see if it tracks the head and tail correctly.\n"
              << "Next, we will delete it to see if it can handle it being the only node to delete.\n"
              << "Also, at the same time, we can try adding the element by using our addElementLast\n"
              << "function to see if it works correctly when there is an empty list.\n\n";

    colors.addElementEnd("aquamarine");
    colors.display();

    std::cout << "GREAT! The list only contains a single node holding aquamarine as the data\n."
              << "It also shows that the node's previous and next elements are pointing to null pointers.\n"
              << "Lastly, the head and tail node are also the same. Which is perfect.\n\n"
              << "It looks so happy... OK, I am done looking at its face. Let's delete it!!\n\n"
              << "The explanation of the delete function will come later, but if it works correctly,\n"
              << "we should see that when we run the display function it should show the list being empty.\n\n";


    colors.deleteElement("aquamarine");
    colors.display();

    std::cout << "That worked!. The node was deleted. By doing that we freed up the memory that node was taking\n."
              << "and we reassigned the head and tail nodes to null pointers.\n"
              << "We don't want any nasty memory leaks. With that being done, let's start!\n\n"
              << "Let's start like we did the singly-linked list and use the \"addElementFirst\" function.\n"
              << "We will add them in the order of \"yellow orange red\", which means the order in the linked list"
              << "should be \"red orange yellow\" \n\n";

    colors.addElementFirst("yellow");
    colors.addElementFirst("orange");
    colors.addElementFirst("red");
    colors.display();

    std::cout << "Next let's try out the \"addElementEnd\" function.\n"
              << "We will add 3 colors in the following order \"green blue violet\".\n"
              << "So, it should show up at the end of the list in the following order:\n"
              << "\"green blue violet\", which will be appended to the list we already created.\n"
              << "Also, the great part of this function is now it works in constant time or for \n"
              << "us nerdy types, O(1). Since, since we are keeping track of the tail, we always knows\n"
              << "where the end of the list is. This is great addition to this list\n"
              << "The reason why is because in a singly-linked list, if we wish to add an node to the end\n"
              << "we would have to iterate through the whole list till we reached the last node then add it.\n"
              << "That would take place in linear time or O(N). If this was an array it would be done in\n"
              << "constant time. Which when it came to adding an something to the end, arrays had a great\n"
              << "advantage in terms of time complexity. With that weakness now gone, doubly-linked list\n"
              << "now stands equal to arrays in terms of adding data to the end. But, of course, lists\n"
              << "still beats arrays in time complexity in terms of inserting and deleting at the\n"
              << "beginning and end of the list. Array's will still have the advantage of reading since that\n"
              << "can be done in constant time and with linked list it will still need to be iterated through.\n\n"
              << "OK. Enough with the praising and nerdy stuff. Let's run the addElementEnd function.\n\n";

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
              << "Let's see if we can utilize the power of a doubly linked list further.\n"
              << "Let's display our list again.. But backwards!\n\n";

    colors.displayBackwards();

    std::cout << "That was great! We were able to ensure our \"previous\" member of our nodes.\n"
              << "works correctly. Also, with the addition of a node count variable in the linked list class\n"
              << "we are able to keep count of the nodes to ensure we can number them when displaying backwards.\n"
              << "It isn't required but it is a nice to have, plus you can run a function like this: \n\n";

    colors.printNodeCount();

    std::cout << "Pretty handy right. We can get a count of the nodes in the list without iterating through the list.\n"
              << "This concludes the out introduction to doubly linked list.\n\n";

    return 0;
}
