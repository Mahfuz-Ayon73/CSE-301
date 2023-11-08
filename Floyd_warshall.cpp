#include<bits/stdc++.h>

const int INF = 1e9+10;
const int N = 100;

using namespace std;

int dist[N][N];

void initial_dist()
{
   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i == j)
              dist[i][j] = 0;
            else 
              dist[i][j] = INF;
        }
    }
}
int main()
{
    
    int vertex , edges ;

    cin >> vertex >> edges ;

    initial_dist();

    for(int i=0;i<edges;i++)
    {
        int x , y , weight;

        cin >> x >> y >> weight;

        dist[x][y] = weight;
    }

    for(int k = 1;k<= edges;k++)
    {
       for(int i=1;i<=edges;i++)
       {
         for(int j=1;j<=edges;j++)
         {
            dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
         }
       }
    }

    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<edges;j++)
        {
            if(dist[i][j] == INF)
            {
                cout << "I " ;
            }
            else
               cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}