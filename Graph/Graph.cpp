// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "PathDfs.h"
#include "PathBfs.h"
#include <iostream>
#include <ctime>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
/*1.������ɱߵ����ݵ���ͼʵ����Ȼ��������ʽڵ�������ڽӵ�*/
	int N = 20;
	int M = 100;
	srand( time(NULL) );

	// Sparse Graph
	SparseGraph  g1(N , false);
	for( int i = 0 ; i < M ; i ++ ){
		int a = rand()%N;
		int b = rand()%N;
		g1.addEdge( a , b );
	}
	// O(E)
	for( int v = 0 ; v < N ; v ++ ){
		cout<<v<<" : ";
		SparseGraph::adjIterator adj( g1 , v );
		for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
			cout<<w<<" ";
		cout<<endl;
	}
	cout<<endl;

	// Dense Graph
	DenseGraph g2(N , false);
	for( int i = 0 ; i < M ; i ++ ){
		int a = rand()%N;
		int b = rand()%N;
		g2.addEdge( a , b );
	}
	// O(V^2)
	for( int v = 0 ; v < N ; v ++ ){
		cout<<v<<" : ";
		DenseGraph::adjIterator adj( g2 , v );
		for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
			cout<<w<<" ";
		cout<<endl;
	}
	system("pause");

/*2.ʹ�ö����ཫͼ���ı�Ϣ����ʵ����Ȼ���ӡʵ�����ڽӱ��ڽӾ���*/
	SparseGraph G1(13, false);
	ReadGraph<SparseGraph> readGraph1(G1, "testG1.txt");
	G1.show();
	DenseGraph G2(13, false);
	ReadGraph<DenseGraph> readGraph2(G2, "testG1.txt");
	G2.show();
	system("pause");

/*3.��ͼʵ�����е���ͨ�����������ж����������Ƿ���ͨ*/
	SparseGraph sparseG1 = SparseGraph(13, false);
	ReadGraph<SparseGraph> readGraph3(sparseG1, "testG1.txt");
	Component<SparseGraph> component1(sparseG1);
	cout<<"TestG1.txt, Component Count: "<<component1.count()<<endl;
	cout<<endl;
	system("pause");

/*4.��ͼʵ������������·��*/
	SparseGraph g_Dfs = SparseGraph(13, false);
	ReadGraph<SparseGraph> readGraph_Dfs(g_Dfs, "testG1.txt");
	g_Dfs.show();
	cout<<endl;

	PathDfs<SparseGraph> dfs(g_Dfs,0);
	cout<<"DFS : ";
	dfs.showPath(6);
	system("pause");

/*5.��ͼʵ������������·��(���)*/
	SparseGraph g_Bfs = SparseGraph(13, false);
	ReadGraph<SparseGraph> readGraphg_Bfs(g_Bfs, "testG1.txt");
	g_Bfs.show();
	cout<<endl;

	PathBfs<SparseGraph> bfs(g_Bfs,0);
	cout<<"BFS : ";
	bfs.showPath(6);
	system("pause");
	return 0;
}

