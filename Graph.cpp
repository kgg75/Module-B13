#include <iostream>
#include "Graph.h"


Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}

// добавление вершины
void Graph::addVertex(int _vnumber) {
    vertexes[vertexCount++] = _vnumber;
}

void Graph::addVertex(int _vnumber, std::string _name) {
    vertexes[vertexCount] = _vnumber;
    verticesNames[vertexCount] = _name;
    vertexCount++;
}

// добавление ребра
void Graph::addEdge(int v1, int v2, int weight) {
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

// удаление вершины
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

// удаление ребра
void Graph::removeEdge(int v1, int v2) {
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

void Graph::depth(int start) {
    bool visited[SIZE] {0}; // список посещенных вершин
    //for (int i = 0; i < SIZE; i++)
    //    visited[i] = false; // инициализируем как непосещенные
    depthInner(start, visited); // запуск алгоритма 

    std::cout << std::endl;
}

void Graph::depthInner(int current, bool visited[]) {
    std::cout << "v" << current << " -> "; // вывод текущей
    visited[current] = true; // помечаем как посещенную
    for (int i = 0; i < SIZE; i++) {
        if (edgeExists(current, i) && !visited[i])
            depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину
    }
}

/* Для проверки, существует ли ребро, нужно посмотреть значение элемента матрицы смежности с индексами номеров вершин (если есть ребро, он отличен от 0).*/
bool Graph::edgeExists(int v1, int v2) {
    return matrix[v1][v2] != 0;
}

/*Для проверки, существует ли вершина, нужно проверить, есть ли ее номер в массиве vertexes.*/
bool Graph::vertexExists(int vnumber) {
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == vnumber)
            return true;
    return false;
}

int Graph::getVertexCount() {
    return vertexCount;
}


std::string Graph::getVertexName(int _index) {
    return verticesNames[_index];
}


void Graph::width(int start) {
    int queue_to_visit[SIZE]; // очередь вершин для обхода
    int queueCount = 0;

    bool visited[SIZE] {0}; // список посещенных вершин
    //for (int i = 0; i < SIZE; i++)
    //    visited[i] = false;

    queue_to_visit[queueCount++] = start; // кладем в очередь начальную вершину
    while (queueCount > 0) {
        // взятие из очереди вершины
        int current = queue_to_visit[0];
        queueCount--;
        for (int i = 0; i < queueCount; i++) {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;
        std::cout << "v" << current << " -> ";
        // поиск смежных вершин и добавление их в очередь
        for (int i = 0; i < SIZE; i++) {
            bool alreadyAdded = false;
            for (int j = 0; j < queueCount; j++)
                if (queue_to_visit[j] == i) {
                    alreadyAdded = true;
                    break;
                }
            if (!alreadyAdded && edgeExists(current, i) && !visited[i])
                queue_to_visit[queueCount++] = i;
        }
    }
    std::cout << std::endl;
}

int Graph::findPathCount(int from, int to) {
    int pathsCount = 0;
    bool visited[SIZE] {0}; // список посещенных вершин
    //for (int i = 0; i < SIZE; i++)
    //    visited[i] = false; // инициализируем как непосещенные
    depthInnerMod(from, to, pathsCount, visited); // запуск алгоритма 

    return pathsCount;
}

void Graph::depthInnerMod(int current, int to, int& pathsCount, bool visited[]) {
    std::cout << "v" << current << "->"; // вывод текущей
    visited[current] = true; // помечаем как посещенную

    for (int i = 0; i < SIZE; i++) {
        if ((i != current) && edgeExists(current, i) && !visited[i])
            if (i == to) {
                std::cout << "V" << current << "->" << "V" << i << '\n'; // вывод текущей
                pathsCount++;
            }
            else {
                depthInnerMod(i, to, pathsCount, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину
                visited[i] = false;
            }
    }
}


#define VERYBIGINT 1'000'000'000 // очень большое число

void Graph::findMinDistanceDecstr(int fromVert) {
    //const int VERYBIGINT = 1'000'000'000;

    int distances[SIZE];    // = { VERYBIGINT }; // массив меток
    for (int i = 0; i < SIZE; i++) { // инициализация меток
        distances[i] = VERYBIGINT;
    }
    distances[fromVert] = 0;

    bool passed[SIZE];  // = { false }; // признак, что вершина окрашена
    for (int i = 0; i < SIZE; i++) {
        passed[i] = false; // все неокрашены изначально
    }
    // принимаем стартовую вершину за текущую
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while (min_dist != VERYBIGINT) {
        passed[currentVertexNum] = true; // окрашиваем текущую

        for (int i = 0; i < SIZE; i++) {
            // для смежных ребер пересчитываем метки
            if (edgeExists(currentVertexNum, i) && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
                distances[i] = distances[currentVertexNum] + matrix[currentVertexNum][i];
        }
        min_dist = VERYBIGINT;
        for (int i = 0; i < SIZE; i++) {
            // выбираем новую текущую вершину
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist){ // выбор новой вершины
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }

    for (int i = 0; i < vertexCount; i++) { // вывод результата
        std::cout << "V" << i << ": " << distances[vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}


void Graph::findMinDistancesFloyd(int (&weights)[][SIZE]) {
//void Graph::findMinDistancesFloyd(int (*weights)[SIZE][SIZE]) {
    //int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j)
                weights[i][j] = 0; // путь до самой себя равен 0
            else {
                if (!edgeExists(i, j))
                    weights[i][j] = VERYBIGINT; // если ребра нет
                else
                    weights[i][j] = matrix[i][j]; // если ребро есть
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) { // итерации по k
        int ck = vertexes[k]; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++) {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++) {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    /*for (int i = 0; i < vertexCount; i++) {
        // вывод всех минимальных путей от вершины '0'
        std::cout << "V" << i << ": " << weights[0][vertexes[i]] << ", ";
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = i; j < SIZE; j++)
            if (weights[i][j] != 0 && weights[i][j] <= 3)
                std::cout << "V" << i << " -> V" << j << " = " << weights[i][j] << '\n';*/
}


int Graph::findMinWayDFS(int from, int to) {
    int minWay = VERYBIGINT;
    int currentWay = 0;
    bool visited[SIZE]{ 0 }; // список посещенных вершин
    //for (int i = 0; i < SIZE; i++)
    //    visited[i] = false; // инициализируем как непосещенные
    depthInnerMod2(from, to, currentWay, minWay, visited); // запуск алгоритма 

    return minWay;
}


void Graph::depthInnerMod2(int current, int to, int& currentWay, int& minWay, bool visited[]) {
    std::cout << "v" << current << "->"; // вывод текущей
    visited[current] = true; // помечаем как посещенную

    for (int i = 0; i < SIZE; i++) {
        if ((i != current) && edgeExists(current, i) && !visited[i])
            if (i == to) {
                std::cout << "V" << current << "->" << "V" << i << '\n'; // вывод текущей
                currentWay += matrix[current][to];
                if (currentWay < minWay)
                    minWay = currentWay;
                currentWay -= matrix[current][to];
            }
            else {
                currentWay += matrix[current][i];
                depthInnerMod2(i, to, currentWay, minWay, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину
                currentWay -= matrix[current][i]; 
                visited[i] = false;
            }
    }
}


