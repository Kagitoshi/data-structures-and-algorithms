#include <iostream>
#include <vector>

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
              << "Since, we are following the book we will call it \"friends\".\n";

    return 0;
}
