#include "Graph.h"
#define MAXNODES 50
#define infinity 32767

int any (int vector[MAXNODES]){
	for (int i = 0; i < MAXNODES; i++){
		if (vector[i] == 1){
			return 1;
		}
	}
	return 0;
}
//===Este eh o algoritmo de Ford-Fulkerson=====================================================================================================

void maxflow(int cap[][MAXNODES],int s,int t,int flow[][MAXNODES],int *ptotflow){
	int pred, nd, i, x;
	int precede[MAXNODES], improve[MAXNODES];
	int endpath[MAXNODES], forward[MAXNODES], onpath[MAXNODES];

	for (nd = 0; nd < MAXNODES; ++nd )
		for(i = 0; i < MAXNODES; ++i)
			flow[nd][i] = 0;
	*ptotflow = 0;

	do {//tentativa de achar um caminho de s para t========================================================================================
		for(nd = 0; nd < MAXNODES; ++nd){
			endpath[nd] = false;
			onpath[nd] = false;
		}
		endpath[s] = true;
		onpath[s] = true;
		improve[s] = infinity;
		while ((onpath[t]== false)&&(any(endpath) == true)){
			for(nd == 0; endpath[nd] == false; nd++);
			endpath[nd] = false;
			for (i = 0;i < MAXNODES; ++i){
				if ((flow[nd][i] < cap[nd][i]) && (onpath[i] == false)){
					onpath[i] = true;
					endpath[i] = true;
					precede[i] = nd;
					forward[nd] = true;
					x = cap[nd][i] - flow[nd][i];
					improve[i] = (improve[nd] < x) ? improve[nd] : x;
				}
				if ((flow[i][nd] > 0) && (onpath[i] == false)) {
					onpath[i] = true;
					endpath[i] = true;
					precede[i] = nd;
					forward[nd] = false;
					improve[i] = (improve[nd] < flow [i][nd]) ? improve[nd] : flow[i][nd];
				}
			}


		}
		if (onpath[t] = true){
			x = improve[t];
			*ptotflow += x;
			nd = t;
			while(nd != s){
				pred = precede[nd];
				(forward[pred] == true) ? (flow[pred][nd] += x) : (flow[nd][pred] -= x);
				nd = pred;

			}
		}
	} while(onpath[t] == true);
}

int main(){

}
