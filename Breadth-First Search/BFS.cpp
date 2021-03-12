#include "BFS.h"

void bfs(node* nodes[]){
	queue<node*> Q;
	Q.push(nodes[1]); //Starting with node 2
	nodes[1]->visit = 1;
	while(Q.size() > 0){
		node* x = Q.front();
		Q.pop();
		for(int i = 0; i < x->childSize; i++){
			if(x->child[i]->visit == 0){
				x->child[i]->visit = 1;
				Q.push(x->child[i]);
			}
		}
	}
}