
#include <iostream>
using namespace std;

int main() {
    int n, e, total = 0, edges = 0;
    int u[20], v[20], w[20], parent[10];

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++)
        cin >> u[i] >> v[i] >> w[i];

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (w[j] > w[j + 1]) {
                swap(w[j], w[j + 1]);
                swap(u[j], u[j + 1]);
                swap(v[j], v[j + 1]);
            }

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "Edges in MST:\n";

    for (int i = 0; i < e && edges < n - 1; i++) {
        int a = u[i], b = v[i];

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b) {
            cout << u[i] << " - " << v[i]
                 << " : " << w[i] << endl;

            total += w[i];
            parent[a] = b;
            edges++;
        }
    }

    if (edges == n - 1)
        cout << "Minimum cost = " << total;
    else
        cout << "MST not possible";

    return 0;
}
