#ifndef _PATHBFS_H
#define _PATHBFS_H

#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
using namespace std;


template <typename Graph>
class PathBfs{

private:
	Graph &G;
	bool *visited;//�����¼�ڵ��Ƿ��Ѿ�������
	int *from;	  //from[i]���i����һ���ڵ�
	int s;		  //·����ʼ��
	int *order;	  //order[i]�ڵ�i����Ȩ����

public:

	PathBfs(Graph &graph, int s):G(graph){

		// �㷨��ʼ��
		assert( s >= 0 && s < graph.V() );
		this->s = s;
		visited = new bool[graph.V()];
		from = new int[graph.V()];
		order = new int[graph.V()];
		for( int i = 0 ; i < graph.V() ; i ++ ){
			visited[i] = false;
			from[i] = -1;
			order[i] = -1;
		}

		queue<int> q;
		// ����ͼ���·���㷨
		q.push( s );
		visited[s] = true;
		order[s] = 0;
		while( !q.empty() ){
			int v = q.front();
			q.pop();
			Graph::adjIterator adj(G, v);
			for( int i = adj.begin() ; !adj.end() ; i = adj.next() )
				if( !visited[i] ){
					q.push(i);//�Ѿ���ӵĽڵ㲻���ظ���ӣ���֤��ÿ���ڵ��¼·����Ψһ�ԣ����������
					visited[i] = true;
					from[i] = v;//��¼i����һ���ڵ�
					order[i] = order[v] + 1;//��¼i��s�ľ���
				}
		}
	}
	~PathBfs(){
		delete []visited;
		delete []from;
		delete []order;
	}

	bool hasPath(int w){
		assert( w >= 0 && w < G.V() );
		return visited[w];
	}
	void FindPath(int w, vector<int> &vec){
		assert( w >= 0 && w < G.V() );
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
	int length(int w){
		assert( w >= 0 && w < G.V() );
		return order[w];
	}
};

#endif //_PATHBFS_H
