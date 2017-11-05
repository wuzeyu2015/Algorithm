#include "stdafx.h"
#include<iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>
#include <stdio.h>
using namespace std;

namespace UF1{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->id = new int[n];
			for(int i = 0; i < n; i++){
				id[i] = i;
			}
		}
		~UnionFind(){
			delete [] id;
		}
		//�ϲ�p��qԪ�����ڵ���������O(n)
		void UnionElements(int p, int q){
			int pID = find(p);
			int qID = find(q);
			if (pID == qID)
				return;
			for(int i = 0; i < count; i++){
				if(id[i] == qID)
					id[i] = pID;
			}
		}
		//����Ԫ�����ڼ���O(1)
		int find(int p){
			assert(p >=0 && p < count);
			return id[p];
		}

		//�Ƿ���ͬһ������O(1)
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//Ԫ�ظ���
		int* id;//����i���Ǽ����е�Ԫ�أ�����ֵparent[i]����Ԫ�����ڼ���
	};
}
namespace UF2{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
		}
		~UnionFind(){
			delete [] parent;
		}
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			parent[pRoot] = qRoot;
		}
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p)
				p = parent[p];
			return p;
		}

		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//Ԫ�ظ���
		int* parent;//����i���Ǽ����е�Ԫ�أ�����ֵparent[i]�Ǹ��ڵ�Ԫ�أ�parent[i] == i��ʱ�򣬱�ʾ�Ѿ�������ڵ㣨���ڼ��ϣ�
	};
}
namespace UF3{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->size = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				size[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] size;
		}
		//�ϲ�p��qԪ�����ڵ���������
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(size[pRoot] > size[qRoot]){
				parent[qRoot] = pRoot;
				size[pRoot] += size[qRoot];
			}
			else{
				parent[pRoot] = qRoot;
				size[qRoot] += size[pRoot];
			}
		}
		//����Ԫ�����ڼ���
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p)
				p = parent[p];
			return p;
		}

		//�Ƿ���ͬһ������
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//Ԫ�ظ���
		int* parent;//����i���Ǽ����е�Ԫ�أ�����ֵparent[i]�Ǹ��ڵ�Ԫ�أ�parent[root] == root��ʱ��root��ʾ���ڵ㣨���ڼ��ϣ�
		int* size;//size[root]��������ϵ�Ԫ�ظ������ϲ���ʱ��С���������ڴ󼯺ϸ��ڵ��¿����Ż������
	};
}
namespace UF4{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->rank = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				rank[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] rank;
		}
		//�ϲ�p��qԪ�����ڵ���������
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else if(rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else{
				//�������������ͬ������£��ϲ������ȲŻ��ԭ������1
				parent[qRoot] = pRoot;
				rank[pRoot] += 1;
			}
		}
		//����Ԫ�����ڼ���
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p)
				p = parent[p];
			return p;
		}

		//�Ƿ���ͬһ������
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//Ԫ�ظ���
		int* parent;//����i���Ǽ����е�Ԫ�أ�����ֵparent[i]�Ǹ��ڵ�Ԫ�أ�parent[root] == root��ʱ��root��ʾ���ڵ㣨���ڼ��ϣ�
		int* rank;//rank[root]��������ϵ���ȣ��ϲ���ʱ��ǳ�ļ������ӵ�����ļ��ϵĸ��ڵ�
	};
}
namespace UF5{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->rank = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				rank[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] rank;
		}
		//�ϲ�p��qԪ�����ڵ���������
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else if(rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else{
				//�������������ͬ������£��ϲ������ȲŻ��ԭ������1
				parent[qRoot] = pRoot;
				rank[pRoot] += 1;
			}
		}
		//����Ԫ��p���ڼ��ϣ������н���·��ѹ��
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p){
				parent[p] = parent[parent[p]]; 
					p = parent[p];
			}

			return p;
		}

		//�Ƿ���ͬһ������
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//Ԫ�ظ���
		int* parent;//����i���Ǽ����е�Ԫ�أ�����ֵparent[i]�Ǹ��ڵ�Ԫ�أ�parent[root] == root��ʱ��root��ʾ���ڵ㣨���ڼ��ϣ�
		int* rank;//rank[root]��������ϵ���ȣ��ϲ���ʱ��ǳ�ļ������ӵ�����ļ��ϵĸ��ڵ�
	};
}
namespace UF6{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->rank = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				rank[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] rank;
		}
		//�ϲ�p��qԪ�����ڵ���������
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else if(rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else{
				//�������������ͬ������£��ϲ������ȲŻ��ԭ������1
				parent[qRoot] = pRoot;
				rank[pRoot] += 1;
			}
		}
		//����Ԫ��p���ڼ��ϣ������н���·��ѹ��(ÿ���ڵ㶼�ݹ����ӵ����ڵ�)
		int find(int p){
			assert(p >=0 && p < count);
			if(parent[p] != p){
				parent[p] = find(parent[p]);
			}
			return parent[p];
		}

		//�Ƿ���ͬһ������
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//Ԫ�ظ���
		int* parent;//����i���Ǽ����е�Ԫ�أ�����ֵparent[i]�Ǹ��ڵ�Ԫ�أ�parent[root] == root��ʱ��root��ʾ���ڵ㣨���ڼ��ϣ�
		int* rank;//rank[root]��������ϵ���ȣ��ϲ���ʱ��ǳ�ļ������ӵ�����ļ��ϵĸ��ڵ�
	};
}
namespace UnionFindTestHelper{
	void testUF1(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF1::UnionFind uf1 = UF1::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF1, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF2(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF2::UnionFind uf1 = UF2::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF2, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF3(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF3::UnionFind uf1 = UF3::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF3, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF4(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF4::UnionFind uf1 = UF4::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF4, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF5(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF5::UnionFind uf1 = UF5::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF5, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF6(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF6::UnionFind uf1 = UF6::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF6, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
}
