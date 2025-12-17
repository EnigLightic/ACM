#include <iostream>
#include <vector>

using namespace std;

struct EdgeNode {
    int adjvex;   
    int weight;    
    EdgeNode* next;
};

struct VNode {
    char data;          
    EdgeNode* firstEdge; 
};

const int MAX_V = 15;
VNode adjList[MAX_V];
int n, m;

void insertEdge(int u, int v, int w) {
    EdgeNode* newNode = new EdgeNode;
    newNode->adjvex = v;
    newNode->weight = w;
    newNode->next = adjList[u].firstEdge;
    adjList[u].firstEdge = newNode;
}

void printGraph() {
    cout << "邻接表为：" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "list[" << i << "]->";
        EdgeNode* curr = adjList[i].firstEdge;
        while (curr) {
            cout << curr->adjvex << ":" << curr->weight << "->";
            curr = curr->next;
        }
        cout << "end" << endl;
    }
}

int checkEdgeExists(int u, int v) {
    if (u >= n) return 0;
    EdgeNode* curr = adjList[u].firstEdge;
    while (curr) {
        if (curr->adjvex == v) return 1;
        curr = curr->next;
    }
    return 0;
}

void deleteVertex(int delIndex) {
    cout << "待删除的顶点信息为 " << adjList[delIndex].data << endl;

    for (int i = 0; i < n; ++i) {
        if (i == delIndex) continue; 
        EdgeNode* curr = adjList[i].firstEdge;
        EdgeNode* prev = nullptr;
        while (curr) {
            if (curr->adjvex == delIndex) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    adjList[i].firstEdge = curr->next;
                }
                EdgeNode* temp = curr;
                curr = curr->next;
                delete temp;
                m--;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    EdgeNode* curr = adjList[delIndex].firstEdge;
    while (curr) {
        EdgeNode* temp = curr;
        curr = curr->next;
        delete temp;
        m--;
    }
    adjList[delIndex].firstEdge = nullptr; // 置空

    if (delIndex != n - 1) {
        int lastIndex = n - 1;
        adjList[delIndex] = adjList[lastIndex];
        adjList[lastIndex].firstEdge = nullptr; 
        adjList[lastIndex].data = 0;

        for (int i = 0; i < n - 1; ++i) { // 此时n还没减，但只需遍历到前n-1个
             
            EdgeNode* e = adjList[i].firstEdge;
            while(e) {
                if(e->adjvex == lastIndex) {
                    e->adjvex = delIndex;
                }
                e = e->next;
            }
        }
    }
    
    n--;
}

int main() {
    int kMaxVertex;
    if (!(cin >> kMaxVertex)) return 0;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> adjList[i].data;
        adjList[i].firstEdge = nullptr;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        insertEdge(u, v, w);
    }

    int checkU1, checkV1, checkU2, checkV2;
    cin >> checkU1 >> checkV1;
    cin >> checkU2 >> checkV2;

    int firstAdjCheckV;
    cin >> firstAdjCheckV;

    int delV;
    cin >> delV;


    printGraph();
    cout << "顶点数 = " << n << endl;

    cout << "<" << checkU1 << ", " << checkV1 << "> 的存在性 = " << checkEdgeExists(checkU1, checkV1) << endl;
    cout << "<" << checkU2 << ", " << checkV2 << "> 的存在性 = " << checkEdgeExists(checkU2, checkV2) << endl;

    if (adjList[firstAdjCheckV].firstEdge) {
        cout << "顶点" << firstAdjCheckV << "的第一个邻接点 = " << adjList[firstAdjCheckV].firstEdge->adjvex << endl;
    } else {
    }

    deleteVertex(delV);

    cout << "当前顶点数 = " << n << endl;
    cout << "当前边数 = " << m << endl;
    for (int i = 0; i < n; ++i) {
        cout << adjList[i].data;
    }
    cout << endl;
    printGraph();

    return 0;
}
