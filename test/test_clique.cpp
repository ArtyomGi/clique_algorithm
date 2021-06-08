#include "Graph.h"

#include <gtest.h>

TEST(CliqueTest, CanCreateGraphWithZeroVertices)
{
    ASSERT_NO_THROW(Graph G(0));
}

TEST(CliqueTest, CanCreateGraphWithPositiveVerticesNumber)
{
    ASSERT_NO_THROW(Graph G(6));
}

TEST(CliqueTest, NoVerticesInEmptyGraph)
{
    Graph G(0);
    std::set<Vertex> expVert;

    EXPECT_EQ(expVert, G.vertices());
}

TEST(CliqueTest, CorrectVerticesInGraph)
{
    Graph G(5);
    std::set<Vertex> expVert({ 1, 2, 3, 4, 5 });

    EXPECT_EQ(expVert, G.vertices());
}

TEST(CliqueTest, CorrectEdgesInclusion)
{
    Graph G(4);
    std::set<Vertex> AdjOf1({ 2 });
    std::set<Vertex> AdjOf2({ 1, 3 });
    std::set<Vertex> AdjOf3({ 2 });
    std::set<Vertex> AdjOf4({ });

    G.addEdge(1, 2);
    G.addEdge(2, 3);

    EXPECT_EQ(AdjOf1, G.Adj(1));
    EXPECT_EQ(AdjOf2, G.Adj(2));
    EXPECT_EQ(AdjOf3, G.Adj(3));
    EXPECT_EQ(AdjOf4, G.Adj(4));
}

TEST(CliqueTest, ThrowsWhenAddingIncorrectEdge)
{
    Graph G(5);

    ASSERT_ANY_THROW(G.addEdge(3, 6));
}

TEST(CliqueTest, EmptyCliqueInEmptyGraph)
{
    Graph G(0);
    std::set<std::set<Vertex>> expCliques = { { } };

    EXPECT_EQ(expCliques, G.cliques());
}

TEST(CliqueTest, CliquesInDisconnectedGraph)
{
    Graph G(3);
    std::set<std::set<Vertex>> expCliques = { { 1 }, { 2 }, { 3 } };

    EXPECT_EQ(expCliques, G.cliques());
}

TEST(CliqueTest, CliquesIn2Graph)
{
    Graph G(2);
    std::set<std::set<Vertex>> expCliques = { { 1, 2 } };

    G.addEdge(1, 2);

    EXPECT_EQ(expCliques, G.cliques());
}

TEST(CliqueTest, CliquesIn5Graph)
{
    Graph G(5);
    std::set<std::set<Vertex>> expCliques = { { 1, 2, 3 }, { 2, 3, 4 }, { 4, 5 } };

    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 4);
    G.addEdge(4, 5);

    EXPECT_EQ(expCliques, G.cliques());
}

TEST(CliqueTest, CliquesIn6Graph)
{
    Graph G(6);
    std::set<std::set<Vertex>> expCliques = { { 1, 2, 3 }, { 3, 5, 6 }, { 2, 4 } };

    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 5);
    G.addEdge(3, 6);
    G.addEdge(5, 6);

    EXPECT_EQ(expCliques, G.cliques());
}

TEST(CliqueTest, CliquesInCompleteGraph)
{
    Graph G(4);
    std::set<std::set<Vertex>> expCliques = { { 1, 2, 3, 4 } };

    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(1, 4);
    G.addEdge(1, 3);
    G.addEdge(2, 4);

    EXPECT_EQ(expCliques, G.cliques());
}

TEST(CliqueTest, CliquesIn2ConnectedCompleteGraphs)
{
    Graph G(5);
    std::set<std::set<Vertex>> expCliques = { { 1, 2, 3 }, { 3, 4, 5 } };

    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(1, 3);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(3, 5);

    EXPECT_EQ(expCliques, G.cliques());
}

TEST(CliqueTest, CliquesInGraphWith2Components)
{
    Graph G(4);
    std::set<std::set<Vertex>> expCliques = { { 1 }, { 2, 3, 4 } };

    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(2, 4);

    EXPECT_EQ(expCliques, G.cliques());
}
