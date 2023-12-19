#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
};

class headNode {
public:
    Node* head;

public:
    headNode() {
        head = NULL;
    }
    void insert(int x) {
        Node* newnode = new Node();
        newnode->data = x;
        newnode->right = head;
        head = newnode;
    }

    void DFS(headNode* arr, bool* TF) {
        Node* check = this->head;
        while (check) {
            int v = check->data;
            if (TF[v] == false) {
                aDFS(arr, TF, v);
            }
            check = check->right;
        }
    }
    void aDFS(headNode* arr, bool* TF, int v) {
        TF[v] = true;
        Node* next = arr[v].head;
        while (next) {
            int k = next->data;
            if (TF[k] == false) {
                aDFS(arr, TF, k);
            }
            next = next->right;
        }
    }
};

int main() {
    int V;
    int E;
    cin >> V >> E;
    bool* TF = new bool[V + 1];
    headNode* arr = new headNode[V + 1];
    int x, y;
    for (int i = 1; i <= V; ++i)
        TF[i] = false;
    for (int i = 1; i <= E; ++i) {
        cin >> x;
        cin >> y;
        arr[x].insert(y);
        arr[y].insert(x);
    }

    //웜 바이러스 확인
    TF[1] = true;

    arr[1].DFS(arr, TF);

    int sum = 0;
    for (int i = 2; i <= V; ++i) {
        if (TF[i]) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}