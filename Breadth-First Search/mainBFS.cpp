#include "BFS.h"

int main(){
	ifstream fin;
	fin.open("data2.txt");
	string line;
	
	int adjacent;
	int numNodes=0;
	tempInt tempInts[50];
	int i = 0;
	int j = 0;
	while(getline(fin, line)){
		j=0;
		stringstream separator(line);
		separator>>tempInts[i].data;
		while(separator>>adjacent){
			tempInts[i].child[j++] = adjacent;
			tempInts[i].childSize++;
		}
		i++;
		numNodes++;
	}
	fin.close();
	node* nodes[numNodes];
	for(i = 0; i < numNodes; i++){
		nodes[i] = new node;
	}
	for(i = 0; i < numNodes; i++){
		nodes[i]->data = tempInts[i].data;
	}
	for(i = 0; i < numNodes; i++){
		nodes[i]->childSize = tempInts[i].childSize;
		for(j = 0; j < tempInts[i].childSize; j++){
			for(int k = 0; k < numNodes; k++){
				if(tempInts[i].child[j] == nodes[k]->data){
					nodes[i]->child[j] = nodes[k];
				}
			}
		}
	}

	bfs(nodes);
	ofstream fout;
	fout.open("out2.txt");
	for(i = 0; i < numNodes; i++){
		if(nodes[i]->visit == 0){
			cout << "Graph is not connected" << endl;
			fout << "Graph is not connected" << endl;
			return 0;
		}
	}
	cout << "Graph is connected" << endl;
	fout << "Graph is connected" << endl;
	return 0;
}