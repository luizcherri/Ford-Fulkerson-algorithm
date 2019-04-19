#ifndef _GRAPH_H_
#define _GRAPH_H_

#define MAXNODES 50
#include <string>
#include <iostream>

using namespace std;

//===ESTRUTURAS================================================================================================================================
typedef struct Node{
	string elem;
} node;

typedef struct Aresta{
	int adj;
	float capacidade;
	float fluxo;
} aresta;

typedef struct Grafo{
	node nodes[MAXNODES];
	aresta arcs[MAXNODES][MAXNODES];
	int cont; //numero de vertices
} grafo;

//===FUNCOES===================================================================================================================================
void criar (grafo G){
	G.cont = 0;
}

void insertNode(grafo G, string st){
	if (G.cont < MAXNODES){
		G.nodes[G.cont].elem = st;
		G.cont++;
	} else {cout << "Grafo cheio.";}
}

int getPosition(grafo G, string elem){
	for (int aux =0; aux < G.cont; aux++){
		if (G.nodes[aux].elem == elem){
			return (aux);
		}
	}
	return(-1);
}

void insertAresta (grafo G, string inicio, string fim,float cap){
	int pos1, pos2;
	pos1 = getPosition(G,inicio);
	pos2 = getPosition(G,fim);
	if ((pos1 != -1)&&(pos2 != -1)){
		G.arcs[pos1][pos2].adj = 1;
		G.arcs[pos1][pos2].capacidade = cap;
	}
}

int areAdjacent(grafo G, string inicio, string fim){
	int pos1, pos2;
	pos1 = getPosition(G,inicio);
	pos2 = getPosition(G,fim);
	if ((pos1 != -1)&&(pos2 != -1)){
		return  (G.arcs[pos1][pos2].adj);
	}else {return 0;}
}
#endif
