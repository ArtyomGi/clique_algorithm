#include "Graph.h"

#include <iostream>
#include <memory>

int main()
{
    using namespace std;

    int N = -1;
    cout << "Enter number of graph vertices: ";
    cin >> N;

    if (N < 0)
    {
        cout << "Number of vertices should be greater or equal 0";
    }
    else
    {
        std::unique_ptr<Graph> g = std::make_unique<Graph>(N);

        try
        {
            int choice = 0;
            do
            {
                cout << "1. Add edge" << endl;
                cout << "2. Calculate cliques" << endl;
                cout << "3. Create new graph" << endl;
                cout << "0. Exit" << endl;

                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    int vertex1 = -1, vertex2 = -1;
                    cout << "Enter first vertex: ";
                    cin >> vertex1;
                    cout << "Enter second vertex: ";
                    cin >> vertex2;

                    if (vertex1 < 1 || vertex2 < 1)
                        cout << "Vertices should be greater than 0";
                    else
                        g->addEdge(vertex1, vertex2);
                    break;
                }

                case 2:
                {
                    auto cliques = g->cliques();

                    if (!cliques.empty())
                    {
                        for (const auto& clique : cliques)
                        {
                            std::cout << "{ ";
                            for (const auto& vertex : clique)
                                std::cout << vertex << " ";
                            std::cout << "}" << std::endl;
                        }
                    }
                    else
                    {
                        cout << "No cliques are found";
                    }
                    break;
                }

                case 3:
                {
                    cout << "Enter number of graph vertices: ";
                    cin >> N;

                    if (N < 0)
                    {
                        cout << "Number of vertices should be greater or equal 0";
                    }
                    else
                    {
                        g = std::make_unique<Graph>(N);
                    }
                    break;
                }

                default:
                    break;
                }
            } while (choice);
        }
        catch (const std::string& error)
        {
            cout << "[Error]: " << error;
        }
    }

    return 0;
}