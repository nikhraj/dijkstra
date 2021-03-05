#include <bits/stdc++.h>
using namespace std;
unordered_map <int,vector <pair<int,int>>> m;

void path(int i,vector <int> &parent)
{
    if(parent[i]==-1)
    {
        cout<<i<<" ";
        return;
    }
    path(parent[i],parent);
    cout<<i<<" ";
}

vector <int> dijkstra(int n,int src)
{
    vector <int> dist(n,INT_MAX);
    vector <bool> vis(n,0);
    vector <int> parent(n,-1);
    dist[src]=0;
    set <pair <int,int>> q;
    //priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    //q.push({0,src});
    q.insert({0,src});

    while(!q.empty())
    {
        int u = q.begin()->second;
       // auto pair = q.top().second;
       //q.pop();
        q.erase(q.begin());
        //cout<<u<<" ";
        vis[u]=true;
        for(auto p:m[u])
        {
            int v = p.first;
            int w = p.second;
            if(!vis[v])
            {
                if(dist[v]>dist[u]+w)
                {
                    parent[v]=u;
                    //cout<<"1 ";
                    dist[v]=dist[u]+w;
                    //q.push({dist[v],v});
                    q.insert({dist[v],v});
                }
            }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout << "Min Distance from source to vertex "<< i <<" is : "<<(dist[i]==INT_MAX?-1:dist[i])<<endl;
        cout<<"Path is : ";
        path(i,parent);
        cout<<endl;
    }

    return dist;
}



int main() {
    int edges,vertices;
    ifstream input;
    input.open("input1.txt");
    input>>edges>>vertices;
    
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        input>>u>>v>>w;
        //cout<<u<<" "<<v<<" "<<w<<endl;
        m[u].push_back({v,w});
    }
    int src;
    input>>src;
    auto ans=dijkstra(vertices,src);

    return 0;
}