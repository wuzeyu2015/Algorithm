#ifndef _PATHDFS_H
#define _PATHDFS_H

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;


template <typename Graph>
class PathDfs{

private:
	Graph &G;
	bool *visited;//�����¼�ڵ��Ƿ��Ѿ�������
	int *from;	  //from[i]���i����һ���ڵ�
	int s;		  //·����ʼ��

	void dfs( int v ){
		visited[v] = true;
		Graph::adjIterator itor(G, v);
		for(int i = itor.begin(); !itor.end(); i = itor.next()){
			if( !visited[i] ){
				from[i] = v;//��¼i����һ���ڵ�
				dfs(i);		
			}
		}
	}
public:
	PathDfs(Graph &graph, int s): G(graph){
		visited = new bool[G.V()];
		from = new int[G.V()];
		this->s = s;
		for(int i = 0; i < G.V(); i++){
			visited[i] = false;
			from[i] = -1;
		}
			dfs(s);//��ȡs�������ڵ���ͨ�����������е��from��Ϣ
}

	~PathDfs(){
		delete []visited;
		delete []from;
	}

	bool hasPath(int w){
		assert( w >= 0 && w < G.V() );
		return visited[w];
	}
	void FindPath(int w, vector<int> &vec){

		stack<int> s;

		int p = w;
		while( p != -1 ){
			s.push(p);
			p = from[p];
		}

		vec.clear();
		while( !s.empty() ){
			vec.push_back( s.top() );
			s.pop();
		}
	}
	void showPath(int w){
		vector<int> vec;
		FindPath( w , vec );
		for( int i = 0 ; i < vec.size() ; i ++ ){
			cout<<vec[i];
			if( i == vec.size() - 1 )
				cout<<endl;
			else
				cout<<" -> ";
		}
	}
};

#endif //_PATHDFS_H
