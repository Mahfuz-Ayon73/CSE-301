#include<bits/stdc++.h>

const int N = 100;

using namespace std;

int parent[N];
int size[N];


void make(int vertex)
{
   parent[vertex] = vertex;
   size[vertex] = 1;
}

int find_parent(int vertex)
{
    if(parent[vertex] == vertex)  return parent[vertex];

    return parent[vertex] = find_parent(parent[vertex]);
}

void union_set(int a,int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if(a != b)
    {
        if(size[a] < size[b])
          swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    freopen("graph_input.txt","r",stdin);

    int vertex , edge;
    cin >> vertex >> edge;

    vector<pair<int,pair<int,int>>> graph;
    
    for(int i=0;i<edge;i++)
    {
        int weight , u , v;
        cin >> u >> v >> weight;

        graph.push_back({weight,{u,v}});      
    }

    sort(graph.begin(),graph.end());

    for(int i=1;i<=edge;i++)
    {
        make(i);
    }

    int tree_cost = 0;

    for(auto &it : graph)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(find_parent(u) == find_parent(v)) continue;

        union_set(u,v);

        tree_cost += wt;

        cout << u << " " << v << "\n";
    }
    cout << "total cost : " << tree_cost;
}