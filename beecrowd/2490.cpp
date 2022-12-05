#include <bits/stdc++.h>

using namespace std;

#define rest 2
vector<int> id, sizes; //Representantes e tamanhos dos conjuntos

//find com path compression e small to large. 
int find (int p){                   
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void unionn(int p, int q){
    p = find(p);
    q = find(q);
    if(p == q) return;
    if(sizes[p] > sizes[q]) 
        swap(p,q);
    id[p] = q;  
    sizes[q] += sizes[p];
}

int main() {

    cout << std::fixed;              //Formatando cout pra 2 casas decimais
    cout << std::setprecision(2);

    while(true){
    int Q, C;
    double T;
    cin >> Q >> C >> T;
    
    if(Q == 0 and C == 0 and T == 0)   //Fim do input
        break;

    id = vector<int> (Q+2);
    sizes = vector<int>(Q+2, 1);

    iota(id.begin(), id.end(), 0);  //id[1] == 1, id[2] == 2 ...

    vector<tuple<double,int,int>> S;

    while(C--){                     //Constroi o conjunto de cortes.
        int x,y;
        double z;
        cin >> x >> y >> z;
        S.emplace_back(z,x,y);
    }

    sort(S.begin(), S.end());      //Ordena por pesos

    int breaks = 0;
    double mstcost = 0;  
    for(auto[z,x,y]:S){           // Algoritimo de Kruskal
        if(find(x) != find(y)){   // id[x] !=  id[y]
            unionn(x, y);         // Adiciona aresta na árvore
            if(z > T){
                ++breaks;         //Se o tempo for superior ao folego
            }
            mstcost += z;
        }
    }
    cout << (mstcost + rest*breaks) << ' ' << breaks << endl;       //Custo da MST + número de pausas * tempo de descanso.
    }

    return 0;
}