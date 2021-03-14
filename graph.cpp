// Clone of a graph
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL)
            return NULL ;
        
        map<Node* , Node*>m;
        queue<Node*>q;
        q.push(node);
        Node * temp=node;
        Node *u=node;
        
        Node *clone=new Node();
        m[temp]=clone;
        m[temp]->val=temp->val;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            vector<Node *> v=temp->neighbors;
            int n=v.size();
            for(int i=0;i<n; i++){
                if(m[v[i]]==NULL){
                    clone=new Node();
                    q.push(v[i]);
                    clone->val=v[i]->val;
                    m[v[i]]=clone;
                    
                }
                 m[temp]->neighbors.push_back(m[v[i]]);
            }
            
           
            
            
        }
       
        return m[u];
    }
};

//  Question :DFS
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
class Graph{
    int V;
    list<int>* adj;
    public:
    Graph(int v){
        V=v;
        adj=new list<int> [V];
        
    }
    void add_edge(int v, int w){
        adj[v].push_back(w);
        
    }
    void DFSutil(int v, bool visited[]){
        visited[v]=true;
            cout<<v<<" ";
            
        
        for(auto i=adj[v].begin();i!=adj[v].end();i++){
            if(visited[*i]==false)
            DFSutil(*i, visited);
        }
        
    }
    void DFS(){
        bool* visited= new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
            
        }
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                DFSutil(i, visited);
                
            }
        }
}};
int main()
{
   Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
 
    cout << "Following is Depth First Traversal \n";
    g.DFS();

    return 0;
}
// Question BFS


#include <bits/stdc++.h>

using namespace std;
class Graph{
    int V;
    list<int>* adj;
    public:
    Graph(int v){
        V=v;
        adj=new list<int> [V];
        
    }
    void add_edge(int v, int w){
        adj[v].push_back(w);
        
    }
    void BFSUtil(int v, bool visited[], queue<int> &q){
       
        q.push(v);
        visited[v]=true;
        while(!q.empty()){
            int temp=q.front();
           
            cout<<temp<<" ";
            q.pop();
            for(auto i=adj[temp].begin() ; i!=adj[temp].end(); i++){
                if(visited[*i]==false)
                {
                    q.push(*i);
                    visited[*i]=true;
                    
                }
            }
        }
    }
    
    void BFS(){
        bool* visited= new bool[V];
        for(int i=0;i<V;i++){
        visited[i]=false;
            
        }
        
        queue <int> q;
        for(int i=0;i<V;i++){
            if (visited[i]==false)
            BFSUtil(i, visited, q);
            
        }
}};
int main()
{
   Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
 
    cout << "Following is BFS \n";
    
    g.BFS();

    return 0;
}
//Bipartited graph
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
# define V 4

bool isBipartitedUtil(vector<vector<int>>&G, int i, vector<int>&color)
{
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        //self loop
        if (G[f][f]==1)
        return false;
        for(int i=0;i<V; i++){
            
            if(G[f][i]==1){
                if(color[i]==-1)
                {
                    color[i]=1-color[f];
                    q.push(i);
                }
                else{
                    if(color[f]==color[i]){
                        return false;
                        
                    }
                }
            }
            
        }
    }
    return true;
}
bool isBipartited(vector<vector <int>> &G ){
   vector<int> color(V,-1);
  for(int i=0;i<V;i++){
      if (color[i]==false)
      if(isBipartitedUtil(G,i, color)==false)
      return false;
      
      
  }
  return true;
  
}


    int main()
{
    vector<vector<int>> G = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
 
    isBipartited(G) ? cout << "Yes" : cout << "No";
    return 0;
}

