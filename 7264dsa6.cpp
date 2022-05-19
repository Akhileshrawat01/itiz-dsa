#include <bits/stdc++.h>
#include <queue>
using namespace std;


class graph{
 
public:

bool *visitedDFS; 
bool *visitedBFS;
bool *visited;
int **edge;

void CreateEdge(int e, int n)
{
    edge = new int*[n];
    for(int i=0; i<n; i++)
    {
        edge[i] = new int[n];
        for(int j=0; j<n; j++)
        edge[i][j] = 0;
    }

    for(int i=0;i<e;i++)
    {
        int x;
        int y;
        cout<<"Enter two vertices to connect\n";
        cin>>x>>y;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }


}

void createGraph(int n)
{
    visitedDFS = new bool[n];
    for(int i=0; i<n; i++)
    visitedDFS[i] = 0;

    visitedBFS = new bool[n];
    for(int i=0; i<n; i++)
    visitedBFS[i] = 0;

      
    cout<<"Enter no of edges\n";
    int e;
    cin>>e;
    CreateEdge(e, n);

}


void dfs(int sv,int n)
{ 
    cout<<sv<<" ";
    visitedDFS[sv] = 1;
    for(int i=0; i<n; i++)
    {
        if(i==sv) continue;
        if(edge[sv][i] == 1 and visitedDFS[i] == 0) 
        {
            dfs(i, n);
        }
    }

}



void bfs(int n, int sv)
{
    
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visitedBFS[sv] = 1;
    while(!pendingNodes.empty())
    {
        int front = pendingNodes.front();
        cout<<front<<" ";
        pendingNodes.pop();
        for(int i=0;i<n;i++) 
        { 
            if(edge[front][i] == 1 and visitedBFS[i]==0)  
            {
                pendingNodes.push(i);
                visitedBFS[i] = 1;

            }

        }

    }

}


void isConnected(int curr, int v)
{
    
    for(int i=0;i<v;i++)
    {
        if(edge[curr][i] == 1 and visited[i] == 0)
        {
            
            visited[i] = 1;
            isConnected(i, v);
            
            
        }
    }


}

void isConnected(int v)
{
    
    visited = new bool[v];
    for(int i=0; i<v; i++)
    visited[i] = 0;

    isConnected(0,v);

      bool flag = true;
	// visited[0] = 1;
    for(int i=0;i<v;i++)
    {
        if(visited[i] == 0)
            flag = false;

    }
    
    
	if(flag) cout<<"connected"<<endl;
    else cout<<"not connected"<<endl;

}



};



int main()
{
    int n;
    graph * g = new graph();

    while(true)
    {
        cout<<"Enter 1 to create graph\nEnter 2 for DFS traversal\nEnter 3 for BFS traversal\nEnter 4 to check connected or not\nEnter -1 to exit\n";
        int c;
        cin>>c;
        if(c==1)
        {
            
        cout<<"Enter no of vertices\n";
        cin>>n;
        g->createGraph(n);

        }

        if(c==2)
        {
            cout<<"DFS\n";
            for(int i=0;i<n;i++)
              { 
                 if(g->visitedDFS[i] == 0)
                    {
                        g->dfs(i, n);
                        cout<<endl;
                     }
              }

            cout<<endl;

        }
        if(c==3)
        {
            cout<<"BFS\n";
            for(int i = 0;i<n;i++)
             {
            if(g->visitedBFS[i]==0)
             {
                g->bfs(n, i);
                cout<<endl;
                }
            }

            cout<<endl;
        }

	if(c==4)
	{
		g->isConnected(n);
    
    
	}

        if(c==-1) break;
    }
  
    
  
}
