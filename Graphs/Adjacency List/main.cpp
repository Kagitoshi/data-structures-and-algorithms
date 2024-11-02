#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

template <typename T>
class Vertex
{
private:
    T m_data{};
    std::vector<Vertex*> m_neighbors;
    //    std::vector<std::reference_wrapper<Vertex>> m_neighbors;

    void dfsTraverse(Vertex& start, Vertex& vertexToFind, std::unordered_map<T, bool>& visited, int nodesAway = 0)
    {
        if(start.m_data == vertexToFind.m_data)
        {
            std::cout << vertexToFind.m_data << " was found.\n"
                      << "Here are the neighbors: \n";

            for(Vertex* i : vertexToFind.m_neighbors)
            {
                std::cout << i->m_data << '\n';
            }

            std::cout << "From the starting point, it was " << nodesAway << " nodes away.\n";
            return;
        }
        else
        {}

        visited[start.m_data] = true;

        std::cout << "Current Vertex: " << start.m_data << "\n";

        for(Vertex* i : start.m_neighbors)
        {
            std::cout << "Current Vertex: " << start.m_data << "\n";
            if(visited.find(i->m_data) != visited.end())
            {
                std::cout << "Already visited " << i->m_data << '\n';
            }

            else
            {
                ++nodesAway;
                dfsTraverse(*i, vertexToFind, visited, nodesAway);
                --nodesAway;
            }
        }

        if(visited.find(vertexToFind.m_data) != visited.end())
        {
        }
        else
        {
            std::cout << vertexToFind.m_data << " is not cannot be reached depth-wise, through this vertex.\n";
            return;
        }
    }

public:
    Vertex(T data)
          : m_data{ data }
    {
        std::cout << "Created a new Vertex. The value in the value in the vertex is: " << data << '\n';
    }
    bool operator == (const Vertex& vertex) const
    {
        return m_data == vertex.m_data;
    }

    void addNeighbor(Vertex& self, Vertex& neighbor)
    {
        for(Vertex*i : self.m_neighbors)
        {
            if(i->m_data == neighbor.m_data)
            {
                std::cout << neighbor.m_data << " is already " << self.m_data <<"'s neighbor.\n";
                return;
            }
        }

        self.m_neighbors.push_back(&neighbor);
        std::cout << neighbor.m_data  << " was added as " << this->m_data << "'s neighbor.\n";

        addNeighbor(neighbor, self);
    }


    void dfsTraverse(Vertex& start, Vertex& vertexToFind)
    {
        std::unordered_map<T, bool> visited{};

        dfsTraverse(start, vertexToFind, visited);
    }

};





int main()
{
    std::cout << "Time to learn about graphs!\n"
              << "As per the book we will use an approach known as the \"Adjacency List\" implementation.\n"
              << "Later, the book suggests we look into another approach called the \"Adjacency Matrix\"\n"
              << "The differences is that the list just uses a simple list in form of an array\n"
              << "to store a vertex's adjacent vertices and the matrix uses a two-dimensional array.\n"
              << "As reminder let me note the graph jargon and other notes from the book.\n\n"
              << "All trees are graphs, not all graphs are trees.\n"
              << "Tree nodes all connect in some sort of way. Graphs can be disconnected.\n"
              << "Graphs can also be implemented used hash tables.As per the book we will use a class.\n"
              << "Each node in a graph is called a \"vertex\".\n"
              << "The lines between the vertices are called \"edges\".\n"
              << "When vertices are connected by an edge they are adjacent to each other and they are\n"
              << "called \"neighbors\".\n"
              << "When all the vertices are connected in someway, this is called a \"Connected Graph\".\n"
              << "When relationships or being neighbors are not mutual, this is called a \"Directed Graph\".\n\n"
              << "OK... That was a lot and should be a readme file instead. All well, let's start.\n"
              << "We will start by making a class that holds a value and adjacent vertices.\n"
              << "Let's add a Vector with the value of \"alice\".\n\n";

    Vertex<std::string> alice{"alice"};

    std::cout << "Great. Now, let's create a bunch more Vectors.\n\n";


    Vertex<std::string> bob {"bob"};
    Vertex<std::string> fred {"fred"};
    Vertex<std::string> helen {"helen"};
    Vertex<std::string> candy {"candy"};
    Vertex<std::string> elaine {"elaine"};
    Vertex<std::string> derek {"derek"};
    Vertex<std::string> gina {"gina"};
    Vertex<std::string> irena {"irena"};

    std::cout << "Now let's add them as neighbors as it is in the book.\n"
              << "Alice's neighbors are: Bob, Candy, Derek, and Elaine.\n"
              << "Bob's neighbors are: Alice and Fred.\n"
              << "Fred's neighbors are: Bob and Helen.\n"
              << "Helen's neighbors are: Fred and Candy.\n"
              << "Candy's neighbors are: Helen and Alice.\n"
              << "Derek's neighbors are: Alice, Elaine, and Gina.\n"
              << "Elaine's neighbors are: Derek and Alice.\n"
              << "Gina's neighbors are: Derek and Irena.\n"
              << "Irena's neighbor is: Gina.\n\n"
              << "Since out function to add neighbors is recursive, each time we add a neighbor the\n"
              << "neighbor also runs the same function to add the first vector to it's neighbors.\n"
              << "Before doing so, it checks to see if that neighbor is there first, if so it returns without adding\n"
              << "anything to its neighbors. This can be done much faster with a set or map of some sort with a \n"
              << "0(N) lookup time. But, I am following the book to learn different ways to solve things.\n\n."
              << "Also, a lot of the code below is redundant, since all adds are mutual thanks to the\n"
              << "recursive function, but I just want to also do this to check for bugs and/or errors.\n\n";

    alice.addNeighbor(alice, bob);
    alice.addNeighbor(alice, candy);
    alice.addNeighbor(alice, derek);
    alice.addNeighbor(alice, elaine);
    std::cout << "\n\n";

    bob.addNeighbor(bob, alice);
    bob.addNeighbor(bob, fred);
    std::cout << "\n\n";

    fred.addNeighbor(fred, bob);
    fred.addNeighbor(fred, helen);
    std::cout << "\n\n";

    helen.addNeighbor(helen, fred);
    helen.addNeighbor(helen, candy);
    std::cout << "\n\n";

    candy.addNeighbor(candy, helen);
    candy.addNeighbor(candy, alice);
    std::cout << "\n\n";

    derek.addNeighbor(derek, alice);
    derek.addNeighbor(derek, elaine);
    derek.addNeighbor(derek, gina);
    std::cout << "\n\n";

    elaine.addNeighbor(elaine, alice);
    elaine.addNeighbor(elaine, derek);
    std::cout << "\n\n";

    gina.addNeighbor(gina, derek);
    gina.addNeighbor(gina, irena);
    std::cout << "\n\n";

    irena.addNeighbor(irena, gina);
    std::cout << "\n\n";

    std::cout << "Now that we set up our neighbors, let's implement a Depth-First Search(DFS) function.\n"
              << "We will start at \"Alice\" and look for \"Irena\"\n";

    alice.dfsTraverse(alice, irena);

    return 0;

}
