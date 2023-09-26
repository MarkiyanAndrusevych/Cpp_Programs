#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Структура, що представляє ребро в графі
struct Edge {
    int dest; // Кінцева вершина ребра
    int weight; // Вага ребра
};

// Структура, що представляє вершину в графі
struct Vertex {
    vector<Edge> edges; // Список ребер, що виходять з вершини
    int distance; // Відстань від вершини до стартової вершини в алгоритмі Дейкстри
    int prev; // Попередня вершина на шляху від стартової до поточної вершини
    bool visited; // Позначає, чи була відвідана вершина в алгоритмі
};

// Клас, що представляє граф
class Graph {
private:
    vector<Vertex> vertices; // Список вершин графа
public:
    // Додавання вершини до графа
    void addVertex() {
        Vertex v;
        v.distance = INT_MAX; // Встановлюємо відстань до стартової вершини як нескінченність
        v.prev = -1; // Попередня вершина на шляху відсутня
        v.visited = false; // Вершина не відвідана
        vertices.push_back(v);
    }

    // Додавання ребра до графа
    void addEdge(int src, int dest, int weight) {
        Edge e = { dest, weight };
        vertices[src].edges.push_back(e);
    }

    // Реалізація алгоритму Дейкстри
    void dijkstra(int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Мінімальна черга з вершинами, що треба обробити
        vertices[start].distance = 0; // Відстань до стартової вершини дорівнює нулю
        pq.push(make_pair(0, start)); // Додаємо стартову вершину до черги

        while (!pq.empty()) {
            int u = pq.top().second; // Беремо вершину з мінімальною відстанню до стартової
            pq.pop();
            // Обходимо всі ребра, що виходять з поточної вершини
            for (int i = 0; i < vertices[u].edges.size(); i++) {
                int v = vertices[u].edges[i].dest;
                int weight = vertices[u].edges[i].weight;

                // Якщо нова відстань до вершини v коротша за попередню
                if (vertices[u].distance + weight < vertices[v].distance) {
                    vertices[v].distance = vertices[u].distance + weight; // Оновлюємо відстань до вершини v
                    vertices[v].prev = u; // Встановлюємо попередню вершину на шляху від стартової до v
                    pq.push(make_pair(vertices[v].distance, v)); // Додаємо вершину v до черги з новою відстанню до стартової
                }
            }
        }
    }

// Повертає найкоротший шлях від стартової вершини до кінцевої
    vector<int> getShortestPath(int dest) {
        vector<int> path;

        // Якщо кінцева вершина досяжна
        if (vertices[dest].distance < INT_MAX) {
            // Додаємо кінцеву вершину до шляху
            path.push_back(dest);

            // Проходимо по попереднім вершинам на шляху від кінцевої до стартової
            int prev = vertices[dest].prev;
            while (prev != -1) {
                path.push_back(prev);
                prev = vertices[prev].prev;
            }
        }

        // Реверсуємо шлях, щоб він був від стартової до кінцевої вершини
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    Graph g;
    // Додавання вершин до графа
    for (int i = 0; i < 5; i++) {
        g.addVertex();
    }

// Додавання ребер до графа
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 4, 4);

// Запуск алгоритму Дейкстри
    g.dijkstra(0);

// Виведення найкоротшого шляху до кожної вершини
    for (int i = 0; i < 5; i++) {
        vector<int> path = g.getShortestPath(i);
        cout << "Shortest path to vertex " << i << ": ";
        if (path.size() > 0) {
            for (int j = 0;
                 j < path.size(); j++) {
                cout << path[j];
                if (j < path.size() - 1) {
                    cout << " -> ";
                }
            }
        } else {
            cout << "Unreachable";
        }
        cout << endl;
    }
    return 0;
}

