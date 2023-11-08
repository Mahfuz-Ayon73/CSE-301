#include<bits/stdc++.h>

const int N = 1e9+10;

using namespace std;

int parent[N];
int size[N];

void make(int vertex)
{
   parent[vertex] = vertex;
   size[vertex] = 1;
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

int find_parent(int vertex)
{
    if(parent[vertex] == vertex)  return vertex;

    return parent[vertex] = find_parent(parent[vertex]);
}

int main()
{
    int n,k ,interconnected_component=0;
    cin >> n >> k;

    for(int i=0;i<n;i++)
    {
        make(i);
    }

    while(k--)
    {
        int u , v;
        cin >> u >> v;
        union_set(u,v);
    }

    for(int i=0;i<n;i++)
    {
        if(find_parent(i) == i) interconnected_component++;
    }

    cout << interconnected_component;
}