#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
class Vertex
{
private:
    T m_data{};
    std::unordered_map<Vertex*, int> m_vertices{};

public:
    Vertex(T data)
          : m_data{ data }
    {
        std::cout << "Created a new vertex. The data in the vertex is: " << data << '\n';
    }
    void addAdjacentVertex(Vertex* adjacentVertex, int weight)
    {
        this->m_vertices[adjacentVertex] = weight;
        std::cout << adjacentVertex->m_data << " has been added with a weight of " << weight << ".\n";
    }

    void dijkstraShortestPath(Vertex startingCity, Vertex finalDestination)
    {
        std::unordered_map<T, int> cheapestPricesTable {};
        std::unordered_map<T, T> cheapestPreviousStopoverCityTable {};

        std::vector<Vertex*> unvisitedCities{&startingCity};

        std::unordered_map<T, bool> visitedCities {};

        cheapestPricesTable[startingCity.m_data] = 0;

        Vertex* currentCity {&startingCity};

        while (true)
        {
            visitedCities[currentCity->m_data] = true;
            unvisitedCities.erase(std::remove(unvisitedCities.begin(), unvisitedCities.end(),
                                              currentCity), unvisitedCities.end());

            for(auto i : currentCity->m_vertices)
            {
                if(visitedCities.find(i.first->m_data) == visitedCities.end() &&
                   std::find(unvisitedCities.begin(), unvisitedCities.end(), i.first) == unvisitedCities.end())
                {
                    unvisitedCities.push_back(i.first);
                }
                else
                {}

                int priceThroughCurrentCity {cheapestPricesTable[currentCity->m_data] + i.second};

                if(cheapestPricesTable.find(i.first->m_data) == cheapestPricesTable.end())
                {
                    cheapestPricesTable[i.first->m_data] = priceThroughCurrentCity;
                    cheapestPreviousStopoverCityTable[i.first->m_data] = currentCity->m_data;
                }
                else
                {
                    if(priceThroughCurrentCity < cheapestPricesTable[i.first->m_data])
                    {
                        cheapestPricesTable[i.first->m_data] = priceThroughCurrentCity;
                        cheapestPreviousStopoverCityTable[i.first->m_data] = currentCity->m_data;
                    }
                    else
                    {}
                }

            }

            if(!unvisitedCities.empty())
            {
                currentCity = unvisitedCities[0];

                for(auto i : unvisitedCities)
                {
                    if(cheapestPricesTable[i->m_data] < cheapestPricesTable[currentCity->m_data])
                    {
                        currentCity = i;
                    }
                    else
                    {}
                }
            }
            else
            {
                break;
            }
        }

        std::vector<T> shortestPath{};

        T currentCityName {finalDestination.m_data};

        while (currentCityName != startingCity.m_data)
        {
            shortestPath.push_back(currentCityName);

            currentCityName = cheapestPreviousStopoverCityTable[currentCityName];
        }

        shortestPath.push_back(startingCity.m_data);

        std::cout << "The cheapest path from " << startingCity.m_data << " to " << finalDestination.m_data << '\n'
                  << "costs $" << cheapestPricesTable[finalDestination.m_data] << " and the path is as follows: \n";


        for(int i{static_cast<int>(shortestPath.size() -1)}; i >= 0; --i)
        {
            if(i == 0)
            {
                std::cout << shortestPath[i] << '\n\n';
            }
            else
            {
                std::cout << shortestPath[i] << " -> ";
            }
        }

        std::cout << "Enjoy your flight!\n\n";
    }
};




int main()
{
    std::cout << "Time to learn about weighted graphs!\n"
              << "So, we will start by using hash tables to represent the adjacent vertices.\n"
              << "Let's add two vertices and call them \"dallas\" and \"toronto\".\n\n";

    Vertex<std::string> dallas {"dallas"};
    Vertex<std::string> toronto {"toronto"};

    std::cout << "Now, let's add them to each other as adjacent vertices and give them a weight\n"
              << "that symbolizes a cost of a ticket to fly from itself to the other vertex.\n\n";

    dallas.addAdjacentVertex(&toronto, 138);
    toronto.addAdjacentVertex(&dallas, 216);

    std::cout << "Cool. Weighted graphs are useful for all types of datasets and some with powerful algorithms.\n"
              << "We can use one of these algorithms to helps us solve the \"The Shortest Path\" problem.\n"
              << "While it is useful to see the shortest distance between cities we can also use it to see\n"
              << "what is the cheapest flight route to get from one place to another.\n"
              << "To find out the cheapest(shortest in other problems) path is to use \"Dijkstra's Algorithm\"\n"
              << "Networking people might of heard of the algorithm before concerning Routing.\n"
              << "Good part about setting this algorithm up is when we are done setting it up, we will not only\n"
              << "know the cheapest path from two cities but all known cities.\n\n"
              << "So, we will use this algorithm to find the cheapest path from \"Atlanta\" to \"El Paso'\"\n"
              << "The Algorithm will start at the Alanta vertex and as we discover new cites, we will add them to\n"
              << "Atlanta's hash table and record the cheapest price from Atlanta to these cites.\n"
              << "The hash table should also include it's own city with a price of zero of course. Since, you are\n"
              << "already there. So Alanta will be in its own hashmap with a weight of 0.\n"
              << "We will create a function that would not only show us the cheapest price but of course list\n"
              << "all of the cities we have to stop on the way.\n\n"
              << "Let's explain the steps of the algorithm. Interchange city for Vertex and price for weigh:\n"
              << "1. We visit the starting city, making it our current city.\n\n"
              << "2. We check the prices from the current city to each of its adjacent cities.\n\n"
              << "3. If the price to an adjacent city from the starting city is cheaper than the price currently is\n"
              << "in the cheapestPricesTable or it isn't in there yet:\n"
              << "  a. We update the cheapestPricesTable to reflect the cheaper price.\n"
              << "  b. We update the cheapestPreviousStopoverCityTable, making the adjacent city the key and the\n"
              << "     current city the value.\n\n"
              << "4. Then, we visit whichever unvisited city has the cheapest price from the starting city, making it\n"
              << "the current city.\n"
              << "5. We repeat steps 2 through 4 until we have visited every known city.\n"
              << "始めましょう!!\n\n";

    Vertex<std::string> atlanta {"Atlanta"};
    Vertex<std::string> boston {"Boston"};
    Vertex<std::string> chicago {"Chicago"};
    Vertex<std::string> denver {"Denver"};
    Vertex<std::string> elPaso {"El Paso"};

    atlanta.addAdjacentVertex(&boston, 100);
    atlanta.addAdjacentVertex(&denver, 160);
    boston.addAdjacentVertex(&chicago, 120);
    boston.addAdjacentVertex(&denver, 180);
    chicago.addAdjacentVertex(&elPaso, 80);
    denver.addAdjacentVertex(&chicago, 40);
    denver.addAdjacentVertex(&elPaso, 140);
    elPaso.addAdjacentVertex(&boston, 100);

    atlanta.dijkstraShortestPath(atlanta, elPaso);

}
