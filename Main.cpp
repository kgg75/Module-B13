#include <iostream>
#include "Graph.h"
#include "Tree.h"

int main() {
    // создаём объект
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
    //g.addEdge(3, 6, 1);
    //g.addEdge(3, 7, 1);
    //g.addEdge(3, 8, 1);
    g.addEdge(5, 8, 1);
    g.addEdge(8, 6, 1);
    g.addEdge(7, 6, 1);

    //g.width(0); std::cout << '\n';
    //g.depth(0);
    //std::cout << '\n' << "pathsCount = " << g.findPathCount(0, 6);
    //std::cout << '\n' << "MinWay = " << g.findMinWayDFS(7, 2);
    
    //int weights[SIZE][SIZE];

    g.findMinDistancesFloyd(3);  // &weights[0][0]);

    /*for (int i = 0; i < SIZE; i++)
        for (int j = i; j < SIZE; j++)
            if (weights[i][j] <= 3)
                std::cout << "V" << i << " -> V" << j << weights[i][j] << ", ";*/

    


    /*g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    g.addEdge(0, 2, 13);
    g.addEdge(0, 4, 21);
    g.addEdge(0, 5, 27);
    g.addEdge(2, 3, 82);
    g.addEdge(2, 4, 77);
    g.addEdge(4, 1, 43);
    g.addEdge(4, 5, 11);
    g.addEdge(5, 1, 38);*/

    //g.findMinDistanceDecstr(4);
    //g.findMinDistancesFloyd();

    /*Tree tree;

    tree.setRoot(2); // задали корень
    tree.addNode(2, 1); // добавляем узлы
    tree.addNode(2, 0);
    tree.addNode(1, 3);
    tree.addNode(1, 4);
    tree.addNode(1, 5);
    tree.addNode(4, 6);
    tree.addNode(4, 7);
    tree.addNode(4, 8);

    tree.print();
    tree.delNode(4);
    tree.print();*/

    /*BinaryTree btree;
    btree.addInt(5);
    btree.addInt(4);
    btree.addInt(-17);
    btree.addInt(-14);
    btree.addInt(20);
    btree.addInt(43);
    btree.addInt(13);
    btree.addInt(11);
    btree.addInt(18);
    btree.addInt(15);
    btree.addInt(19);

    /*btree.print(); std::cout << '\n';
    btree.delInt(-17);
    btree.print(); std::cout << '\n';
    btree.delInt(-14);
    btree.print(); std::cout << '\n';
    btree.delInt(20);
    btree.print(); std::cout << '\n';
    btree.delInt(13);
    btree.print();

    int output_array[20] { 0 };
    btree.symmetricWalk(output_array);*/

    return 0;
}