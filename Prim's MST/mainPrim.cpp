#include <fstream>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h> 
using namespace std;
  
  

int minKey(int key[], bool mstSet[], int size)  
{  
    // Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < size; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  
 
void printMST(int parent[], int graph[50][50], int size)  
{  
	ofstream fout;
	fout.open("output4.txt");
	int sum = 0;
	for(int i = 1; i < size; i++){
		sum += graph[i][parent[i]];
	}
	cout << "The minimum spanning tree has total cost " << sum << " and edges: " << endl;
	fout << "The minimum spanning tree has total cost " << sum << " and edges: " << endl;
	for(int i = 1; i < size; i++){
		cout << "("<<parent[i]+1<<", "<<i+1 << ") ";
		fout << "("<<parent[i]+1<<", "<<i+1 << ") ";
	}
	cout << endl;
	fout.close();
}  
  

void primMST(int graph[50][50], int size)  
{  
    // Array to store constructed MST  
    int parent[size];  
      
    // Key values used to pick minimum weight edge in cut  
    int key[size];  
      
    // To represent set of vertices not yet included in MST  
    bool mstSet[size];  
  
    // Initialize all keys as INFINITE  
    for (int i = 0; i < size; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
 
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have size vertices  
    for (int count = 0; count < size - 1; count++) 
    {  
 
        int u = minKey(key, mstSet, size);  
  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;  
  

        for (int v = 0; v < size; v++)  
  
 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
    // print the constructed MST  
    printMST(parent, graph, size);  
}  

int main(){
	ifstream fin;
	fin.open("data4.txt");
	string line;
	
	int cost;
	int size = 0;
	int costInt[50][50];
	int i = 0;
	int j = 0;
	while(getline(fin, line)){
		j=0;
		stringstream separator(line);
		while(separator>>cost){
			costInt[i][j++] = cost;
		}
		i++;
		size++;
	}
	fin.close();
	primMST(costInt, size);
}