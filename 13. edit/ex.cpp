#include<iostream>
#include<fstream>

using namespace std;

int** create_matrix(int n, int m) {
    int **v = new int*[n];

    for (int i=0; i<n; i++)
        v[i] = new int[m]{0};

    return v;
}

void delete_matrix(int** v, int n, int m) {
    for (int i=0; i<n; i++)
        delete[] v[i];
    
    delete[] v;
}

int edit(string x, int n, string y, int m) {
    int** v = create_matrix(n + 1, m + 1);
    
    // Righe
    for (int i=0; i < n + 1; i++)
        v[i][0] = i;
    
    // Colonne
    for (int i=0; i < m + 1; i++)
        v[0][i] = i;
    
    // EDIT
    for (int i=1; i < n + 1; i++)
        for (int j=1; j < m + 1; j++)
            x[i-1] == y[j-1] ? v[i][j] = v[i-1][j-1] // Prev diagonal value + 1
                : v[i][j] = min(min(v[i-1][j], v[i][j-1]), v[i-1][j-1]) + 1; // Min between left or top
    
    // Free
    int length = v[n][m];
    delete_matrix(v, n, m);
    return length;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i < 100; i++){
        int m, n;
        string x, y;
        in >> m >> n >> x >> y;
        out << edit(x, m, y, n) << endl;
    }
}