/* Author: Jeremy Kracy */
/* EUID: jek0138 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>

using namespace std;


struct node {
	int data = 0;
	node* child[50];
	int childSize = 0;
	int visit = 0;
};
struct tempInt {
	int child[50] = {0};
	int childSize = 0;
	int data = 0;
};

void bfs(node* nodes[]);