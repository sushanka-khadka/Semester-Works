// Floyd-Warshall Algorithm using Dynamic programming approach
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void FloydWarshall(vector <vector <int>> &graph){
	int v = graph.size();	
	vector <vector <int>> dist = graph;	// store shortest path between all pairs
	
	for(int k=0; k<v; k++){
		for(int i=0; i<v; i++){
			for(int j=0; j<v; j++){
				if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j] )
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	cout<<"Shortest Distance Matrix:\n";
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			if(dist[i][j] == INT_MAX)
				cout<<"INF, ";
			else
				cout<<dist[i][j]<<", ";
		}
	}
	cout<<endl;
}

int main(){	
	cout<<"----- Floyd-Warshall's algorithm -----\n";
	vector <vector <int>> graph= {
		{0, 5, INT_MAX, 10},
		{INT_MAX, 0, 3, INT_MAX},
		{INT_MAX, INT_MAX, 0, 1},
		{INT_MAX, INT_MAX, INT_MAX, 0}
	};

/* more examples
	vector<vector<int>> graph = {
        {0, 3, INT_MAX,  INT_MAX},
        {2, 0, INT_MAX, INT_MAX},
        {INT_MAX, 7, 0, 1},
        {6, INT_MAX, INT_MAX, 0}
    };

	vector <vector <int>> graph= {
		{0, 4, 11},
		{6, 0, 2},
		{3, INT_MAX, 0}
	};
*/
	
	FloydWarshall(graph);
	
	return 0;
}