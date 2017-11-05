#ifndef _READ_GRAPH_H
#define _READ_GRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template <typename Graph>

class ReadGraph{
public:
	ReadGraph(Graph& G, const string& filename){
		//�ļ�I/O����������ȡ��һ�У���ͱ�������Ϣ
		ifstream file(filename);
		assert( file.is_open() );
		string line;
		int V, E;
		getline(file, line);
		stringstream ss(line);
		ss >>V >> E;

		assert( V == G.V() );
		//��ȡ���бߵ���Ϣ
		for( int i = 0 ; i < E ; i ++ ){
			assert( getline(file, line) );
			stringstream ss(line);

			int a,b;
			ss>>a>>b;
			assert( a >= 0 && a < V );
			assert( b >= 0 && b < V );
			//ΪͼG��ӱ�
			G.addEdge( a , b );
		}
		file.close();
	}
};
#endif //_READ_GRAPH_H
