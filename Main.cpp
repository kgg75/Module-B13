#include <iostream>
#include "Graph.h"


int main() {
    Graph g;
    g.addVertex(0, "AAA");
    g.addVertex(1, "BBB");
    g.addVertex(2, "CCC");
    g.addVertex(3, "DDD");
    g.addVertex(4, "EEE");
    g.addVertex(5, "FFF");
    g.addVertex(6, "GGG");
    g.addVertex(7, "HHH");
    g.addVertex(8, "III");

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(4, 3, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(4, 7, 1);
    g.addEdge(5, 8, 1);
    g.addEdge(8, 6, 1);
    g.addEdge(7, 6, 1);

    g.findMinDistancesFloyd(3);

    return 0;
}
