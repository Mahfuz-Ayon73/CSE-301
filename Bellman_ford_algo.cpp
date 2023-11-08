#include<bits/stdc++.h>

#define N 100

const int INF = 1e5+10;

using namespace std;

void Bellman_ford(vector<pair<int,pair<int,int>>> &graph,int v)
{
    int parent[v];
    int cost_parent[v];

    vector<int> value(v,INT_MAX);

    parent[0] = -1;
    cost_parent[0] = 0;
    value[0] = 0;

    bool updated;
    for(int i=0;i<v-1;i++)
    {
        updated = false;
        for(int j=0;j<graph.size();j++)
        {
            int u , v , wt;
            u = graph[j].second.first;
            v = graph[j].second.second;
            wt = graph[j].first;

            //cout << " u , v , wt :" << u << v << wt << endl;

            if(value[v] > value[u] + wt and value[u] != INT_MAX)
            {
                value[v] = value[u] + wt;
                parent[v] = u;
                cost_parent[v] = value[v];
                updated = true;
            }
            
        }
        if(updated == false)
              break;
    }

    for(int i=0;i<graph.size() and updated == true ;i++)
    {
          int u , v , wt;
          u = graph[i].second.first;
          v = graph[i].second.second;
          wt = graph[i].first;

          if(value[v] > value[u] + wt and value[u] != INT_MAX)
          {
            cout << "the graph has a negative cycle\n";
            return;
          }
    }

    for(int i=1;i<v;i++)
    {
        cout << "U->V :" << parent[i] << " -> " << i << " cost to reach :" << parent[i] <<" from source 0 = "<< value[i] <<"\n";
        
    }
}
int main()
{
   freopen("Bellman_input.txt","r",stdin);

   int v , e;
   cin >> v >> e;
   
   vector<pair<int,pair<int,int>>> graph;

   for(int i=0;i<e;i++)
   {
     int wt,src,des;
     cin >> src >> des >> wt;

     graph.push_back({wt,{src,des}});
   }

   Bellman_ford(graph,v);
} 