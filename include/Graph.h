#pragma once

#include <set>
#include <vector>

using Vertex = size_t;

class Graph
{
public:
    Graph(size_t n) :
        N(n), graph(N) {}

    void addEdge(Vertex v1, Vertex v2);

    std::set<Vertex> Adj(Vertex u) const;
    std::set<Vertex> vertices() const;

    std::set<std::set<Vertex>> cliques() const;

private:
    size_t N;
    std::vector<std::set<Vertex>> graph;
};

class CliqueAlgorithm
{
public:
    CliqueAlgorithm(const Graph& graph):
        G(graph) {}

    std::set<std::set<Vertex>> calculateCliques();

private:
    void clique(std::set<Vertex> N, std::set<Vertex> D);
    void explore(Vertex vertex, std::set<Vertex>& N, std::set<Vertex>& D);

private:
    const Graph& G;
    std::set<Vertex> S;
    std::set<std::set<Vertex>> cliques;
};
