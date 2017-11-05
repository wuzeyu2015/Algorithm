#ifndef _SPARSEGRAPH_H
#define _SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class SparseGraph{
public:
	//����һ��ӵ��n���㣬��Ϊ�գ��ߵ������Կ�ѡ��ͼ
	SparseGraph(int n, bool directed){
		this->directed = directed;
		this->n = n;
		this->m = 0;
		for(int i = 0; i < n; i++){
			g.push_back(vector<int>());
		}
	}
	~SparseGraph(){
	}
	//[0, n)��Χ��������֮�����һ����
	void addEdge(int v, int w){
		assert( v >= 0 && v < n);
		assert( w >= 0 && w < n);

		g[v].push_back(w);
		//�Ի�������²����ظ�push
		if(!directed && v != w)
			g[w].push_back(v);

		m++;
	}
	//����ڽӾ����ڽӱ��hasEdge���Ӷ�����ˣ�����addEdge���治����ƽ�бߣ���������û��ƽ�б������
	bool hasEdge(int v, int w){
		assert( v >= 0 && v < n);
		assert( w >= 0 && w < n);
		for(int i = 0; i < g[v].size(); i++){
			if(g[v][i] == w)
				return true;
		}
			return false;
	}

	int V(){
		return n;
	}
	int E(){
		return m;
	}

	void show(){

		for( int i = 0 ; i < n ; i ++ ){
			cout<<"vertex "<<i<<":\t";
			for( int j = 0 ; j < g[i].size() ; j ++ )
				cout<<g[i][j]<<"\t";
			cout<<endl;
		}
	}
private:
	int n;//������
	int m;//����
	bool directed;//�Ƿ�������ͼ
	vector<vector<int>> g;//�ڽӱ�洢��ʽ���ʺ�ϡ��ͼ����g[i]�����ʾi������������Щ����
///////////////////////////////////////////////////////////////
public:
	class adjIterator{

		int index;
		int v;
		SparseGraph& G;

	public:
		adjIterator(SparseGraph& graph, int v):G(graph){
			this->v = v;
			index = 0;
		}
		~adjIterator(){
		}
		int begin(){
			if(G.g[v].size())
				return G.g[v][0];
			return -1;
		}
		int next(){
			if(++index < G.g[v].size())
			return G.g[v][index];			
		}
		bool end(){
			return (index >= G.g[v].size());
		}
	};
};

#endif _SPARSEGRAPH_H
//1�������Ҫ�ж�ƽ�б�������ֲ�����addEdge��������жϵ���������ģ����Կ���ȫ�������֮�����ƽ�бߵ�ͳһ����