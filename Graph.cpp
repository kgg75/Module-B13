#include <iostream>
#include "Graph.h"


Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}

// äîáàâëåíèå âåðøèíû
void Graph::addVertex(int _vnumber) {
    vertexes[vertexCount++] = _vnumber;
}

void Graph::addVertex(int _vnumber, std::string _name) {
    vertexes[vertexCount] = _vnumber;
    verticesNames[vertexCount] = _name;
    vertexCount++;
}

// äîáàâëåíèå ðåáðà
void Graph::addEdge(int v1, int v2, int weight) {
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

// óäàëåíèå âåðøèíû
void Graph::removeVertex(int vnumber) {
    for (int i = 0; i < vertexCount; i++) {
        if (vertexes[i] == vnumber) {
            for (int j = i; j < vertexCount - 1; j++)
                vertexes[j] = vertexes[j + 1];
            for (int j = 0; j < vertexCount; j++) {
                matrix[j][i] = 0;
                matrix[i][j] = 0;
            }
            break;
        }
    }

    vertexCount--;
}

// óäàëåíèå ðåáðà
void Graph::removeEdge(int v1, int v2) {
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}


/* Äëÿ ïðîâåðêè, ñóùåñòâóåò ëè ðåáðî, íóæíî ïîñìîòðåòü çíà÷åíèå ýëåìåíòà ìàòðèöû ñìåæíîñòè ñ èíäåêñàìè íîìåðîâ âåðøèí (åñëè åñòü ðåáðî, îí îòëè÷åí îò 0).*/
bool Graph::edgeExists(int v1, int v2) {
    return matrix[v1][v2] != 0;
}

/*Äëÿ ïðîâåðêè, ñóùåñòâóåò ëè âåðøèíà, íóæíî ïðîâåðèòü, åñòü ëè åå íîìåð â ìàññèâå vertexes.*/
bool Graph::vertexExists(int vnumber) {
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == vnumber)
            return true;
    return false;
}

#define VERYBIGINT 1'000'000'000 // î÷åíü áîëüøîå ÷èñëî

void Graph::findMinDistancesFloyd(const int allowableLength) {
    int weights[SIZE][SIZE]; // ìàòðèöà ïóòåé
    // èíèöèàëèçàöè ìàòðèöû
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j)
                weights[i][j] = 0; // ïóòü äî ñàìîé ñåáÿ ðàâåí 0
            else {
                if (!edgeExists(i, j))
                    weights[i][j] = VERYBIGINT; // åñëè ðåáðà íåò
                else
                    weights[i][j] = matrix[i][j]; // åñëè ðåáðî åñòü
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) { // èòåðàöèè ïî k
        int ck = vertexes[k]; // âîçüìåì íîìåð âåðøèíû
        for (int i = 0; i < vertexCount; i++) {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++) {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // ïåðåñ÷åò ììàòðèöû ïóòåé
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    for (int i = 0; i < vertexCount; i++)
        for (int j = i; j < vertexCount; j++)
            if (weights[i][j] != 0)
                if (weights[i][j] <= allowableLength)
                    std::cout << "V" << i << " -> V" << j << " = " << weights[i][j] << '\n';
                else
                    std::cout << "V" << i << " -> V" << j << " - don't know each other\n";
}




