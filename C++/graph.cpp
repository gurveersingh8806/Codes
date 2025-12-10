#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:

    unordered_map<int,list<int>> adj;

    void addedge(int u, int v, bool direction){

        adj[u].push_back(v);

        if(direction == 0)
        adj[v].push_back(u);

    }

    void print(){
        for(auto i:adj){
            cout << i.first << " - ";
            for(int j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

void bfs(unordered_map<int,bool> &visited, int node,unordered_map<int,list<int>> &adj, vector<int> &ans){

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){

        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);

        for(auto i:adj[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] =1;
            }
        }


    }
}

void dfs(unordered_map<int,bool> &visited, int node,unordered_map<int,list<int>> &adj, vector<int> &ans){

    ans.push_back(node);
    visited[node]=1;

    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(visited,i,adj,ans);
        }
    }
}

int main(){
    int n,m;
    cin >> n>> m;

    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >>v;
        g.addedge(u,v,0);
    }

    vector<int> ans;

    unordered_map<int,bool> visited;

    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(visited,i,g.adj,ans);
    }

    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;
    
}
