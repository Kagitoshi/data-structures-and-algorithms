#include <iostream>

template <typename T>
struct TreeNode
{
    T data{};
    TreeNode* leftNode{nullptr};
    TreeNode* rightNode{nullptr};
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root{nullptr};

    void checkNodeChildren(TreeNode<T>* nodeToCheck)
    {
        if(!nodeToCheck->leftNode)
        {
            std::cout << "The left child is       : Null\n";
        }
        else
        {
            std::cout << "The left child is       : " << nodeToCheck->leftNode->data << '\n';
        }

        if(!nodeToCheck->rightNode)
        {
            std::cout << "The right child is      : Null\n";
        }
        else
        {
            std::cout << "The right child is      : " << nodeToCheck->rightNode->data << '\n';
        }
    }

public:
    BinaryTree()
            = default;

    void printRoot()
    {
        std::cout << "The root is " << root->data << ".\n\n";
    }

    void addToTree(T dataToAdd, TreeNode<T>* currentNode = nullptr) {
        if(!root)
        {
            TreeNode<T>* nodeToAdd{new TreeNode<T>};
            nodeToAdd->data = dataToAdd;

            root = nodeToAdd;
            return;
        }
        else if(!currentNode)
        {
            currentNode = root;
        }

        //Base Case
        if(dataToAdd < currentNode->data)
        {
            if(!currentNode->leftNode)
            {
                TreeNode<T>* nodeToAdd{new TreeNode<T>};
                nodeToAdd->data = dataToAdd;

                currentNode->leftNode = nodeToAdd;

                std::cout << "A node containing the following data has been added to the left of "
                          << currentNode->data << ":\n"
                          << dataToAdd << '\n';
                return;
            }
            else
            {
                addToTree(dataToAdd, currentNode->leftNode);
                return;
            }
        }
        else if (dataToAdd > currentNode->data)
        {
            if(!currentNode->rightNode)
            {
                TreeNode<T>* nodeToAdd{new TreeNode<T>};
                nodeToAdd->data = dataToAdd;

                currentNode->rightNode = nodeToAdd;

                std::cout << "A node containing the following data has been added to the right of "
                          << currentNode->data << ":\n"
                          << dataToAdd << '\n';

                return;
            }
            else
            {
                addToTree(dataToAdd, currentNode->rightNode);
                return;
            }
        }
        else
        {
            std::cout << "A Tree node with the data " << dataToAdd << " already exist.\n"
                      << "A new node has not been added.\n\n";

            return;
        }
    }

    void printTree(TreeNode<T>* currentNode = nullptr) {
        if(!currentNode)
        {
            currentNode = root;
        }
        else
        {
        }

        if(currentNode->leftNode)
        {
            printTree(currentNode->leftNode);
        }
        else
        {
        }

        std::cout << "The current node contains " << currentNode->data << '\n';

        if(currentNode->rightNode)
        {
            printTree(currentNode->rightNode);
        }
        else
        {
        }
    }

    void searchForValue(T dataToFind, TreeNode<T>* currentNode = nullptr)
    {
        if(!currentNode)
        {
            if(!root)
            {
                std::cout << "The list is empty.\n";
                return;
            }
            else if(dataToFind == root->data)
            {
                std::cout << "The data " << dataToFind << " has been located.\n"
                          << "It is the root of the tree.\n";

                checkNodeChildren(root);

                return;
            }
            else
            {
                currentNode = root;
            }
        }
        else
        {
        }

        if(dataToFind < currentNode->data)
        {
            if(!currentNode->leftNode)
            {
                std::cout << "The data " << dataToFind << " was not located in the tree.\n";

                return;
            }
            else if(dataToFind == currentNode->leftNode->data)
            {
                std::cout << "The data " << dataToFind << " has been located.\n"
                          << "It is the left child of : " << currentNode->data << '\n';

                checkNodeChildren(currentNode->leftNode);
                return;
            }
            else
            {
                searchForValue(dataToFind, currentNode->leftNode);

                return;
            }

        }
        else
        {
            if(!currentNode->rightNode)
            {
                std::cout << "The data " << dataToFind << " was not located in the tree.\n";

                return;
            }
            else if(dataToFind == currentNode->rightNode->data)
            {
                std::cout << "The data " << dataToFind << " has been located.\n"
                          << "It is the right child of : " << currentNode->data << '\n';

                checkNodeChildren(currentNode->rightNode);

                return;
            }
            else
            {
                searchForValue(dataToFind, currentNode->rightNode);

                return;
            }
        }

    }
};

int main()
{
    std::cout << "Let's make a tree.\n";

    BinaryTree<int> numbers;
    numbers.addToTree(5);
    numbers.printRoot();

    numbers.printTree();

    std::cout << "Let's add some numbers to the tree. 2 3 6 7\n";

    numbers.addToTree(3);
    numbers.addToTree(2);
    numbers.addToTree(9);
    numbers.addToTree(7);
    numbers.addToTree(6);

    std::cout << "Printing the tree in order:\n";
    numbers.printTree();

    std::cout << "Let's check the tree for the numbers 8.\n";
    numbers.searchForValue(8);

    std::cout << "It isn't there of course. Let's add it and check again.\n";
    numbers.addToTree(8);
    numbers.searchForValue(8);

    std::cout << "Nice.\n";

    return 0;
}
