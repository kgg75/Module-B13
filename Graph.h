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
        void findMinDistancesFloyd(const int allowableLength);

    private:
        int matrix[SIZE][SIZE]; // ìàòðèöà ñìåæíîñòè
        int vertexes[SIZE]; // õðàíèëèùå âåðøèí
        std::string verticesNames[SIZE]; // õðàíèëèùå èì¸í âåðøèí
        int vertexCount; // êîëè÷åñòâî äîáàâëåííûõ âåðøèí
        bool edgeExists(int v1, int v2);
        bool vertexExists(int vnumber);
};
