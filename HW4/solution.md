Our graph is-

![](1.jpg)

### 1. Prim’s algorithm using adjacency matrix to represent graph and unsorted array for priority queue Q
```
#include <vector>
using namespace std;
# define MAX 99999
#include <random>
int MST[5];
int choose_Vertex(int value_array[], bool mask[])
{
  int min_val = MAX;
  int min_index;
  for (int idx = 0; idx < 5; ++idx){
    if (value_array[idx] < min_val && mask[idx] == false){
      min_val = value_array[idx];
      min_index = idx;
    }
  }
  return min_index;
}

int* prim_adj_matrix(int graph[5][5])
{
  int value_array[5];
  bool mask[5];
  for (int i = 0; i < 5; i++)
  {
    value_array[i] = MAX;
    mask[i] = false;
  }
  value_array[0] = 0;
  MST[0] = -1;
  for (int iter = 0; iter < 4; iter++)
  {
    int u = choose_Vertex(value_array, mask);
    mask[u] = true;
    for (int v = 0; v < 5; v++)
    if (graph[u][v]!=0 && mask[v] == false && graph[u][v] < value_array[v])
    {
      MST[v] = u;
      value_array[v] = graph[u][v];
    }
  }
  return MST;
}
void printMST(int MST[], int weights[5][5])
{
  int weight_mst=0;
  cout<<"Edge \t\tWeight\n";
  int j;
  for (int i = 1; i < 5; i++){
    j=MST[i];
    cout<<j<<" <-> "<<i<<" \t"<<weights[i][j]<<" \n";
    weight_mst=weight_mst+weights[i][MST[i]];
  }
  cout<<"Weight of MST is "<<weight_mst<<endl;
}
int main()
{
  int graph[5][5] = {
    { 0, 3, 6, 9, 0 },
    { 3, 0, 1, 0, 10 },
    { 6, 1, 0, 10, 5 },
    { 9, 0, 10, 0, 20 },
    { 0, 10, 5, 20, 0 }
  };
  int* mst=prim_adj_matrix(graph);
  printMST(mst, graph);
  return 0;
}

```

Output-
```
Edge 		Weight
0 <-> 1 	3
1 <-> 2 	1
0 <-> 3 	9
2 <-> 4 	5
Weight of MST is 18
```

### 2. Prim’s algorithm using adjacency list to represent graph and heap for priority queue Q
```
#include<vector>
#include<list>
#include<algorithm>
#include <queue>
using namespace std;
# define MAX 999999

typedef pair<int, int> integer_Pair;

class Graph_Adjacency_List
{
	int V;
	list< pair<int, int> > *adjacency_List;
public:
	Graph_Adjacency_List(int V){
		this->V = V;
		adjacency_List = new list<integer_Pair> [V];
	};

	void Create_Edge(int u, int v, int w){
		adjacency_List[u].push_back(make_pair(v, w));
		adjacency_List[v].push_back(make_pair(u, w));
	};

	auto primMST(){
		priority_queue< integer_Pair, vector <integer_Pair> , greater<integer_Pair> > pq;
		int start = 0;
		vector<int> values(V, MAX);
		vector<int> parent(V, -1);
		vector<bool> mask(V, false);
		pq.push(make_pair(0, start));
		values[start] = 0;
		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();
			mask[u] = true;
			list< pair<int, int> >::iterator i;
			for (i = adjacency_List[u].begin(); i != adjacency_List[u].end(); ++i)
			{
				int v = (*i).first;
				int weight = (*i).second;
				if (mask[v] == false && values[v] > weight)
				{
					values[v] = weight;
					pq.push(make_pair(values[v], v));
					parent[v] = u;
				}
			}
		}
		return parent;
	};
};

int main()
{
	int V = 5;
	Graph_Adjacency_List graph(V);
	graph.Create_Edge(0, 1, 3);
	graph.Create_Edge(0, 2, 6);
	graph.Create_Edge(0, 3, 9);

	graph.Create_Edge(1, 2, 1);
	graph.Create_Edge(1, 4, 6);

	graph.Create_Edge(2, 3, 10);
	graph.Create_Edge(2, 4, 5);

	graph.Create_Edge(3, 4, 20);
	auto mst=graph.primMST();
	cout<<"Edges"<<endl;
	for (int i = 1; i < V; ++i){
		cout<<mst[i]<<"<->"<<i<<endl;
	}
	return 0;
}

```
Output-
```
Edges
0 <-> 1
1 <-> 2
0 <-> 3
2 <-> 4
```
