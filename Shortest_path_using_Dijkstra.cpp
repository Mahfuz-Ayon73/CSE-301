#include<bits/stdc++.h>

const int N = 100;
const int INF = 1e9+10;

using namespace std;

vector<pair<int,int>> graph[N];

void Dijkstra(int source)
{
   vector<int> dist(N,INF);
   vector<int> vis(N,0);

   set<pair<int,int>> st;

   st.insert({0,source});
   dist[source] = 0;

   while(st.size() > 0)
   {
     auto node = *st.begin();

     int v = node.second;
     int v_dist = node.first;

     st.erase(st.begin());

     if(vis[v] == 1) continue;
     vis[v] = 1;
     for(auto child : graph[v])
     {
        int child_v = child.first;
        int child_wt = child.second;

        if(dist[v] + child_wt < dist[child_v])
        {
           dist[child_v] = dist[v] + child_wt;
           st.insert({dist[child_v],child_v});
        }
     }

   }

   for(int i=0;i<6;i++)
   {
      cout << source <<" "<< i << " " << dist[i] << endl;
   }
}
int main()
{
   freopen("dijkstra_input.txt","r",stdin);
   int n , m , source;
   cin >> n >> m >> source;

   for(int i=0;i<m;i++)
   {
     int x , y , weight;

     cin >> x >> y >> weight;

     graph[x].push_back({y,weight});

   }

   Dijkstra(source);
   
   

   
}