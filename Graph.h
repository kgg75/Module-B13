#pragma once
#include <string>

#define SIZE 10

class Graph {
    public:
        Graph();
        void addVertex(int _vnumber);
        void addVertex(int _vnumber, std::string _name);
        void addEdge(int v1, int v2, int weight = 1);
        void removeVertex(int vnumber);
        void removeEdge(int v1, int v2);
        void depth(int start);
        void width(int start);
        int findPathCount(int from, int to);
        int findMinWayDFS(int from, int to);
        void findMinDistanceDecstr(int fromVert);
        void findMinDistancesFloyd(int (&weights)[][SIZE]);
        //void findMinDistancesFloyd(int (*weights)[SIZE][SIZE]);
        int getVertexCount();
    private:
        int matrix[SIZE][SIZE]; // матрица смежности

        int vertexes[SIZE]; // хранилище вершин
        std::string verticesNames[SIZE]; // хранилище имён вершин
        int vertexCount; // количество добавленных вершин
        void depthInner(int current, bool visited[]);
        void depthInnerMod(int current, int to, int& pathsCount, bool visited[]);
        void depthInnerMod2(int current, int to, int& currentWay, int& minWay, bool visited[]);
        bool edgeExists(int v1, int v2);
        bool vertexExists(int vnumber);
};