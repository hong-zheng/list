//#define _CRT_SRCURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//void swap(int tree[],int i,int j){
//	int tmp = tree[i];
//	tree[i] = tree[j];
//	tree[j] = tmp;
//}
//void heapify(int tree[],int n,int i){
//	if (i>=n){
//		return;
//	}
//	int c1 = 2 * i + 1;
//	int c2 = 2 * i + 2;
//	int max = i;
//	if ( c1<n && tree[c1] > tree[max]){
//		max = c1;
//	}
//	if ( c2<n && tree[c2] > tree[max] ){
//		max = c2;
//	}
//	if ( i != max){
//		swap(tree,i,max);
//		heapify(tree,n,max);
//	}
//}
//void buildTree(int tree[],int n){
//	int last_node = n - 1;
//	int parent = (last_node - 1) / 2;
//	for (int i = parent; i >= 0;i--){
//		heapify(tree,n,i);
//	}
//}
//void heapSort(int tree[],int n){
//	buildTree(tree,n);
//	for (int i = n - 1; i >= 0;i--){
//		swap(tree,i,0);
//		heapify(tree,i,0);
//	}
//}
//int main(){
//
//	int tree[] = {34,5,6,7,8,0,21,0,9,4,3,8,2,7,57,83,2,91,46};
//	int len = sizeof(tree) / sizeof(tree[0]);
//	heapSort(tree,len);
//	for (int i = 0; i < len;i++){
//		printf("%d ",tree[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//
//
////
////#pragma once
////
////
/////*
////	���������
////	���������->��&��&��
////	��<��<�� ����
////	��>��>�� ����
////
////	ÿһ�����������������
////*/
////template<class T>
////class Tree{
////
////	struct Node{
////		T		pBuff;
////		Node*   pLeft;
////		Node*   pRight;
////	};
////	Node* pRoot;
////
////public:
////	Tree(){pRoot = NULL};
////	~Tree(){ 
////		if(pRoot)
////		_clear();
////		pRoot = NULL;
////	}
////	// ��ӽ��
////	void insert(Tree*);
////
////private:
////	// �ݹ鵽��ײ㣬һ��������ͷ�
////	_clear(){
////	
////	}
////};