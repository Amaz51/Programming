#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class GraphNode {
public:
    int id;
    string type;

    GraphNode(int id, const string& type) : id(id), type(type) {}
};

class Graph {

    int V; 
    vector<list<pair<int, int>>> adjList;

public:
    Graph(int V);
    void addVertex(int id, const string& type);
    void addEdge(int u, int v, int weight);
    void printFLAN();

    friend class MinHeap; 
};

class MinHeap {

    int heapSize;
    vector<int> positions; 
    vector<pair<int, int>> heap; 

public:
    MinHeap(int size);
    ~MinHeap();
    void buildHeap(const vector<int>& keys);
    pair<int, int> extractMin();
    void decreaseKey(int v, int key);
    bool isEmpty() const;
};

Graph::Graph(int V) : V(V) {
    adjList.resize(V);
}

void Graph::addVertex(int id, const string& type) {
    GraphNode node(id, type);
    // store vertices
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight);
}

void Graph::printFLAN() {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    MinHeap minHeap(V); 
    key[0] = 0;
    minHeap.decreaseKey(0, 0); 

    while (!minHeap.isEmpty()) {
        int u = minHeap.extractMin().second;

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!minHeap.isEmpty() && minHeap.extractMin().first > weight) {
                key[v] = weight;
                minHeap.decreaseKey(v, weight);
                parent[v] = u;
            }
        }
    }

    // Print the constructed FLAN
    cout << "FLAN Connections:\n";
    for (int i = 1; i < V; ++i)
        cout << "Connect computer " << parent[i] << " to " << i << " with wire length " << key[i] << "\n";
}

MinHeap::MinHeap(int size) : heapSize(size) {
    positions.resize(size, -1);
    heap.resize(size);
}

MinHeap::~MinHeap() {}

void MinHeap::buildHeap(const vector<int>& keys) {
    for (int i = 0; i < heapSize; ++i) {
        heap[i] = make_pair(keys[i], i);
        positions[i] = i;
    }

    for (int i = (heapSize - 1) / 2; i >= 0; --i) {
        int currentIndex = i;
        while (2 * currentIndex + 1 < heapSize) {
            int leftChild = 2 * currentIndex + 1;
            int rightChild = 2 * currentIndex + 2;
            int smallerChildIndex = leftChild;

            if (rightChild < heapSize && heap[rightChild].first < heap[leftChild].first)
                smallerChildIndex = rightChild;

            if (heap[currentIndex].first < heap[smallerChildIndex].first)
                break;

            swap(heap[currentIndex], heap[smallerChildIndex]);
            swap(positions[heap[currentIndex].second], positions[heap[smallerChildIndex].second]);

            currentIndex = smallerChildIndex;
        }
    }
}

pair<int, int> MinHeap::extractMin() {
    pair<int, int> minNode = heap[0];
    heap[0] = heap[heapSize - 1];
    positions[heap[0].second] = 0;
    --heapSize;

    int currentIndex = 0;
    while (2 * currentIndex + 1 < heapSize) {
        int leftChild = 2 * currentIndex + 1;
        int rightChild = 2 * currentIndex + 2;
        int smallerChildIndex = leftChild;

        if (rightChild < heapSize && heap[rightChild].first < heap[leftChild].first)
            smallerChildIndex = rightChild;

        if (heap[currentIndex].first < heap[smallerChildIndex].first)
            break;

        swap(heap[currentIndex], heap[smallerChildIndex]);
        swap(positions[heap[currentIndex].second], positions[heap[smallerChildIndex].second]);

        currentIndex = smallerChildIndex;
    }

    return minNode;
}

void MinHeap::decreaseKey(int v, int key) {
    int index = positions[v];
    heap[index].first = key;

    while (index > 0 && heap[index].first < heap[(index - 1) / 2].first) {
        swap(heap[index], heap[(index - 1) / 2]);
        swap(positions[heap[index].second], positions[heap[(index - 1) / 2].second]);
        index = (index - 1) / 2;
    }
}

bool MinHeap::isEmpty() const {
    return heapSize == 0;
}

int main() {
    int choice;
    Graph g(0);

    do {
        cout << "\nMenu:\n";
        cout << "1. Input a graph from a file\n";
        cout << "2. Save a graph in a file\n";
        cout << "3. Add a vertex in the existing graph\n";
        cout << "4. Add an edge in the existing graph\n";
        cout << "5. Print the set of edges that covers all the vertices using the algorithm\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            ifstream inputFile("input.txt"); 
            if (!inputFile) {
                cerr << "Error opening the file.\n";
                return 1;
            }

            int V, E;
            inputFile >> V; 
            g = Graph(V);

            // Read vertex information
            for (int i = 0; i < V; ++i) {
                int id;
                string type;
                inputFile >> id >> type;
                g.addVertex(id, type);
            }

            inputFile >> E; // Read the number of edges

            // Read edges and weights from the file
            for (int i = 0; i < E; ++i) {
                int u, v, weight;
                inputFile >> u >> v >> weight;
                g.addEdge(u, v, weight);
            }

            inputFile.close();
            break;
        }
        case 2: {
            // Implement saving the graph to a file
            break;
        }
        case 3: {
            int id;
            string type;
            cout << "Enter the ID and type of the vertex to add: ";
            cin >> id >> type;
            g.addVertex(id, type);
            break;
        }
        case 4: {
            int u, v, weight;
            cout << "Enter the vertices and weight of the edge to add: ";
            cin >> u >> v >> weight;
            g.addEdge(u, v, weight);
            break;
        }
        case 5: {
            g.printFLAN();
            break;
        }
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
