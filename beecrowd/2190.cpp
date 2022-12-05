#include <bits/stdc++.h>

using namespace std;

vector<int> id, sizes;

int find (int p){                   
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void unionn(int p, int N){
    p = find(p);
    N = find(N);
    if(p == N) return;
    if(sizes[p] > sizes[N]) 
        swap(p,N);
    id[p] = N;  
    sizes[N] += sizes[p];
}

int main() {
    int test = 0;
    while(true){
        int N, M;
        cin >> N >> M;
        
        if(N == 0)
            break;

        id = vector<int> (N+2);
        sizes = vector<int>(N+2, 1);

        iota(id.begin(), id.end(), 0);

        vector<tuple<int,int,int>> S;

        while(M--){ 
            int x, y, z;
            cin >> x >> y >> z;
            S.emplace_back(z,x,y);
        }

        sort(S.begin(), S.end());      //Ordena por pesos

        cout << "Teste " << ++test << endl;
        for(auto[z,x,y]:S){           // Algoritimo de Kruskal
            if(find(x) != find(y)){   // id[x] !=  id[y]
                unionn(x, y);         // Adiciona aresta na árvore
                if(x > y) swap(x,y);
                
                cout << x << ' ' << y << endl;
            }
        }
    }
    return 0;
}