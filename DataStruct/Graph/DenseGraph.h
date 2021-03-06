#ifndef _DENSEGRAPH_H
#define _DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 稠密图 - 邻接矩阵
class DenseGraph{


private:
	int n, m;
	bool directed;
	vector<vector<bool>> g;//邻接矩阵存储方式（适合稠密图），g[i][j]某两个顶点是否有边

public:

	DenseGraph( int n , bool directed ){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for( int i = 0 ; i < n ; i ++ )
			g.push_back( vector<bool>(n, false) );
	}

	~DenseGraph(){

	}

	int V(){ return n;}
	int E(){ return m;}
	//[0, n)范围两个顶点之间添加一个边
	void addEdge( int v , int w ){

		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );
		//如果有边直接返回
		if( hasEdge( v , w ) )
			return;

		g[v][w] = true;
		if( !directed )//无向图则需要两个方向都有边
			g[w][v] = true;

		m ++;//维护边数
	}
	//判断v、w两个顶点之间是否有边存在
	bool hasEdge( int v , int w ){
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );
		return g[v][w];
	}
	void show(){
		for( int i = 0 ; i < n ; i ++ ){
			for( int j = 0 ; j < n ; j ++ )
				cout<<g[i][j]<<"\t";
			cout<<endl;
		}
	}
///////////////////////////////////////////////
public:
	class adjIterator{
	private:
		DenseGraph &G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph &graph, int v): G(graph){
			this->v = v;
			this->index = -1;
		}

		int begin(){

			index = -1;
			return next();
		}

		int next(){
			for( index += 1 ; index < G.V() ; index ++ )
				if( G.g[v][index] )
					return index;
			return -1;
		}

		bool end(){
			return index >= G.V();
		}
	};
};
#endif _DENSEGRAPH_H
