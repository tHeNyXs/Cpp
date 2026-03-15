#include <iostream>
#include <vector>
using namespace std;
class Graph
{
private:
    vector<vector<int>> adjMatrix;
    int numVertices;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }
    void addEdge(int i, int j)
    { // สําหรับกราฟแบบไมมีทิศทาง เราจะเพิ่มคาทั้งสองดาน
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }
    void displayMatrix()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.displayMatrix();
    return 0;
}