#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Vertex {
    vector<Edge> adjacent;
    int dis = INT_MAX;
    int closed = 0;
    int pre = -1;
};

class Graph {
    vector<Vertex> nodes;
    int n;

public:
    Graph(int n, vector<vector<int>> &edges) : nodes(n) {
        this->n = n;
        for (auto &vec: edges) {
            int from = vec[0];
            int to = vec[1];
            int weight = vec[2];
            nodes[from].adjacent.push_back({.to = to, .weight = weight});
        }
    }

    [[nodiscard]] int Vex() const {
        return n;
    }

    vector<Edge> &getEdges(int v) {
        return nodes[v].adjacent;
    }


    void setClosed(int v) {
        nodes[v].closed = 1;
    }

    [[nodiscard]] bool isClosed(int v) const {
        return nodes[v].closed;
    }

    void setDistance(int v, int d) {
        nodes[v].dis = d;
    }

    int getDistance(int v) {
        return nodes[v].dis;
    }

    void setPre(int v, int pre) {
        nodes[v].pre = pre;
    }

    int getPre(int v) {
        return nodes[v].pre;
    }
};

/**
 *  狄杰斯特拉算法
 *  适用范围:没有负权重的图, 可以有环,有向无向图均可
 *  求解问题:单源最短路径
 *  时间复杂度：V^2
 *
 *
 * **/

class Dijkstra {
public:
    int start;
    Graph *g;

    Dijkstra(int start, Graph *g) : start(start), g(g) {}

    void print(int v) const {
        if (g->getPre(v) != -1) {
            print(g->getPre(v));
        }
        cout << v << "\t";
    }

    void print() const {
        for (int i = 0; i < g->Vex(); i++) {
            cout << i << " node:[from 0 path]" << "\t";
            print(i);
            cout << endl;
        }
    }

    void traversal() const {
        g->setDistance(start, 0);
        for (int k = 0; k < g->Vex(); k++) {
            // 在open list 里面找一个最小的
            int v = -1;
            for (int i = 0; i < g->Vex(); i++) {
                if (g->isClosed(i) || g->getDistance(i) == INT_MAX) {
                    continue;
                }
                if (v == -1 || g->getDistance(i) < g->getDistance(v)) {
                    v = i;
                }
            }
            // open list 找不到节点
            if (-1 == v) {
                break;
            }
            // 添加到close list
            g->setClosed(v);
            for (auto &adj: g->getEdges(v)) {
                int to = adj.to;
                int weight = adj.weight;
                int distance = g->getDistance(v) + weight;
                if (g->isClosed(to)) {
                    continue;
                }
                if (g->getDistance(to) > distance) {
                    g->setDistance(to, distance);
                    g->setPre(to, v);
                }
            }
        }
        print();
    }
};

int main() {
    vector<vector<int>> data = {
            {0, 1, 2},
            {1, 2, 2},
            {2, 3, 1},
            {3, 4, 2},
            {0, 4, 3},
    };
    auto g = new Graph(5, data);
    Dijkstra dj(0, g);
    dj.traversal();
}