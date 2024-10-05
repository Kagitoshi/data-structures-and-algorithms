#include <iostream>
#include <vector>

//Heaps are structured using vectors instead of nodes like trees/linked-list
template<typename T>
class MaxHeap
{
private:
    int _size{};
    std::vector<T> dataHeap{};

public:

    std::vector<T> getFirstElement()
   {
       return dataHeap.first;
   }

   std::vector<T> getLastElement()
   {
       return dataHeap.last;
   }

   /*Transversing through a heap. We are storing data in a vector
    * but we transverse it like a tree. To find the left and right child
    * of any node, we use the following formula:
    *
    * Left child node  : (index * 2) + 1
    * Right child node : (index * 2) + 2
    * */
   int leftChildIndex(int index)
   {
       return (index * 2) + 1;
   }

   int rightChildIndex(int index)
   {
       return (index * 2) + 2;
   }

   /*To find the parent index of a node, we use the following formula:
    * Parent node : (index - 1) / 2
    *
    * Since it is using integers for division it will round down instead
    * of returning a number with a decimal concerning odd numbers. e.g:
    *
    * 3/2 will return 1 it will not return 1.5.
    * */

   int parentIndex(int index)
   {
       return (index - 1) / 2;
   }

    void insertData(T dataToInsert)
    {
       //Add the new node to the back of the vector
        dataHeap.push_back(dataToInsert);

        //Keep track of the new node's index in the vector
        int newNodeIndex{static_cast<int>(dataHeap.size() -1)};

        /*If the new node is not in the root position, and
         *it's greater than its parent node, swap the data and update
         * the new node's index
         * */
        while (newNodeIndex > 0 &&
        dataHeap[newNodeIndex] > dataHeap[parentIndex(newNodeIndex)])
        {
            //Swap new node and parent node(data)
            std::swap(dataHeap[newNodeIndex], dataHeap[parentIndex(newNodeIndex)]);

            //Update the new node's index
            newNodeIndex = parentIndex(newNodeIndex);
        }

        //Once the while loop has completed, the node should be in its proper place.
        //Also Let's update our index size.
        _size++;
    }

    bool hasGreaterChild(int index)
    {
       return (dataHeap[leftChildIndex(index)] && dataHeap[leftChildIndex(index)] > dataHeap[index]) ||
               (dataHeap[rightChildIndex(index)] && dataHeap[rightChildIndex(index)] > dataHeap[index]);
    }

    int getGreaterChildIndex(int index)
    {
       if(!dataHeap[rightChildIndex(index)])
       {
           return leftChildIndex(index);
       }
       else
       {
       }

       if(dataHeap[rightChildIndex(index)] > dataHeap[leftChildIndex(index)])
       {
           return rightChildIndex(index);
       }
       else
       {
           return leftChildIndex(index);
       }
    }

    void deleteNode()
    {
       /*We only delete the root, always.
        * So let's pop off the last node of the heap and make that
        * the new root node.
        * */
       dataHeap[0] = dataHeap[_size - 1];

       dataHeap.pop_back();
       //Update our vector size.
        _size--;

       //Let's keep track of that node that is now the root.
       int poppedNodeIndex{0};

       /*Next we use the trickle down algorithm to bring the largest node to the top.
        * We run a while loop, and it will swap nodes with the larger of the two children
        * until it is in the proper spot. We will also keep track of the larger child's
        * index, so we can use it to update the new location of the popped Node.
        * */
       while(hasGreaterChild(poppedNodeIndex))
       {
           //Save index of the larger child
           int largerChildIndex{getGreaterChildIndex(poppedNodeIndex)};

           //Swap Nodes.
           std::swap(dataHeap[poppedNodeIndex], dataHeap[largerChildIndex]);

           //Update the index of the popped node.
           poppedNodeIndex = largerChildIndex;
       }

    }

    void displayHeap()
    {
       int layerNumber{1};
       int heapSize{_size};

       for(int i {0}; i < _size;)
       {
           std::cout << "Layer #" << layerNumber << ": ";

           int layerSize{i * 2};

           while((i <= layerSize) && i < _size)
           {
               std::cout << dataHeap[i] << ' ';

               ++i;
           }

           std::cout << '\n';

           ++layerNumber;
       }
    }

};


int main()
{
    std::cout << "Let's make our Max heap.\n";

    MaxHeap<int> numbers;

    numbers.insertData(3);
    numbers.insertData(25);
    numbers.insertData(8);
    numbers.insertData(12);
    numbers.insertData(100);
    numbers.insertData(88);
    numbers.insertData(87);
    numbers.insertData(16);
    numbers.insertData(86);
    numbers.insertData(50);
    numbers.insertData(2);
    numbers.insertData(15);
    numbers.insertData(69);
    numbers.insertData(7);
    numbers.insertData(254);
    numbers.insertData(1);



    std::cout << "We made a max heap!\n";
    numbers.displayHeap();

    std::cout << "Let's try deleting from it.\n";

    numbers.deleteNode();

    std::cout << "Let's print out the nodes!\n";

    return 0;
}
