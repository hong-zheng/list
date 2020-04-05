#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



// 顺序表
//	优点：随机访问，尾插尾删O(1) 连续结构实现简单
//	缺点：其他位置插入删除O(n),有增容代价
//  适合场景：适合频繁访问的场景

// 链表：双向链表
// 优点：任意位置插入删除O(1)
// 缺点：不支持随机访问，实现相对复杂，非连续结构
// 适用场景：频繁插入删除的场景


// 双向带头循环链表
typedef int Type;

typedef struct Node{
	Type _data;
	struct Node* _next;
	struct Node* _prev;
}Node;
typedef struct List{
	Node* _header;
}List;





Node* createNode(Type data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_prev = node->_next = NULL;
	return node;
}

void listInit(List* lst){
	// 创建一个头节点，构成循环结构
	lst->_header = createNode(0);
	lst->_header->_next = lst->_header;
	lst->_header->_prev = lst->_header;
}
// 尾插
void listPushBack(List* lst, Type data){
	Node* node = createNode(data);
	Node* last = lst->_header->_prev;
	// last node _header
	last->_next = node;
	node->_prev = last;

	node->_next = lst->_header;
	lst->_header->_prev = node;
}
void listPopBack(List* lst){
	Node *last, *prev;
	// 注意：不可删头
	if (lst->_header->_next == lst->_header){
		return;
	}
	last = lst->_header->_prev;
	prev = last->_prev;

	prev->_next = lst->_header;
	lst->_header->_prev = prev;
	free(last);
}


void listPushFront(List* lst, Type data){
	Node* front = lst->_header;
	Node* node = createNode(data);

	node->_next = front;
	front->_prev = lst->_header;

	node->_prev = lst->_header;
	lst->_header->_next = node;

}
void listPopFront(List* lst){

}
void listInsert( Node* pos,Type data){

}

void listErase(Node* pos){
	// 删除当前位置的节点
	// 注意：header 不能删除
	Node* prev = pos->_prev;
	Node* next = pos->_next;
	if ( pos == next){
		return;
	}
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}
void listDestory(List* lst){
	Node* cur = lst->_header->_next;
	while ( cur != lst->_header ){

	}
}

void display(List* lst){
	if (NULL == lst){
		return;
	}
	Node* head = lst->_header;
	Node* cur = lst->_header->_next;
	while (cur != head){
		printf("%d ",cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void test(){
	List lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	listPushBack(&lst, 6);
	display(&lst);
	listPopBack(&lst);
	display(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	display(&lst);
}
int maina(){
	test();

	system("pause");
	return 0;
}



// 顺序表实现栈
typedef int Type;
typedef struct Stack{
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void stackInit(Stack* st,size_t n){
	st->_capacity = n;
	st->_array = (Type*)malloc(st->_capacity*sizeof(Type));
	st->_size = 0;
}
void stackPush(Stack* st, Type data){
	// 检查容量
	if ( st->_capacity == st->_size){
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array,st->_capacity);
	}
	// 尾插
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st){
	if (NULL == st){
		return;
	}
	if (st->_size){
		--st->_size;
	}
}
Type stackTop(Stack* st){

	return st->_array[st->_size-1];
}
size_t stackSize(Stack* st){
	return st->_size;
}
int stackEmpty(Stack* st){
	if (st->_size == 0){
		return 1;
	}
	return 0;
}
void stackDestory(Stack* st){
	free(st->_array);
	st->_array = NULL;
	st->_capacity = st->_size = 0;
}
//void Print(int arr[], int length){
//	for (int i = 0; i<length; i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int piv(int* arr,int l,int h){
//	int cur = arr[l];
//	while (l<h){
//		while (l<h && arr[h]>=cur){
//			h--;
//		}
//		arr[l] = arr[h];
//		while (l<h && arr[l]<cur){
//			l++;
//		}
//		arr[h] = arr[l];
//	}
//	arr[l] = cur;
//	return l;
//}
//void QSort(int* arr,int l ,int h){
//	if (l<h){
//		int m = piv(arr,l,h);
//		QSort(arr, l, m - 1);
//		QSort(arr, m+1, h);
//	}
//}
//void QSORT(int* arr,int length){
//	QSort(arr,0,length-1);
//}
//int main(){
//	int arr1[] = { 210, 110, 1, 22, 111, 214, 56, 1332, 152, 111, 214, 56, 1332, 152, 2422, 349, 77, 78, 79, 88, 98, 111, 123, 344 };
//	int len1 = sizeof(arr1) / sizeof(arr1[0]);
//	Print(arr1, len1);
//	QSORT(arr1, len1);
//	Print(arr1, len1);
//	system("pause");
//	return 0;
//}
////// 快速排序
////// 单次分割，返回中间位置
////int piv(int* arr, int l, int h){
////	int indx = arr[l];
////	while (l<h){
////		while (l<h && arr[h] >= indx){
////			h--;
////		}
////		arr[l] = arr[h];
////		while (l<h && arr[l] < indx){
////			l++;
////		}
////		arr[h] = arr[l];
////	}
////	arr[l] = indx;
////	return l;
////}
////// 递归排序
////void QSort(int* arr, int l, int h){
////	if (l<h){
////		int m = piv(arr, l, h);
////		QSort(arr, l, m - 1);
////		QSort(arr, m + 1, h);
////	}
////}
////void QSORT(int* arr, int len){
////	QSort(arr, 0, len - 1);
////}
//
//// insertSort
////void insertSort(int* arr,int length){
////	for (int i = 1; i < length;i++){
////		if (arr[i] < arr[i-1]){
////			int cur = arr[i];
////			int j = 0;
////			for (j = i - 1; j >= 0 && cur < arr[j];j--){
////				arr[j + 1] = arr[j];
////			}
////			arr[j + 1] = cur;
////		}
////	}
////}
////void shellSort(int* arr,int length){
////	int step = length / 2;
////	while (step>=1){
////		for (int i = step; i < length;i++){
////			for (int j = 1; j < length;j++){
////				if (arr[j] < arr[j-1]){
////					int k = 0;
////					int cur = arr[j];
////					for (k = j - step; k >= 0 && arr[k] > cur;k-=step){
////						arr[k + step] = arr[k];
////					}
////					arr[k + step] = cur;
////				}
////			}
////		}
////		step /= 2;
////	}
//////}
////#define MAXNUM 2422
////void radix(int* arr,int length){
////	int tmp[MAXNUM+1];
////	memset(tmp,0,sizeof(int)*(MAXNUM+1));
////	for (int i = 0; i < length;i++){
////		tmp[arr[i]]++;
////	}
////	for (int i = 0; i < MAXNUM + 1;i++){
////		while (tmp[i]--){
////			printf("%d ",i);
////		}
////	}
////	printf("\n");
////}
////#define LEN 24
////void bucketSort(int* arr,int len){
////	for (int i = 1; i < MAXNUM;i*=10){
////		int tmp[10][LEN];
////		memset(tmp,-1,sizeof(int)*10*LEN);
////		for (int j = 0; j < len;j++){
////			int m = arr[j] / i % 10;
////			tmp[m][j] = arr[j];
////		}
////		int k = 0;
////		for (int i = 0; i < 10;i++){
////			for (int j = 0; j < len;j++){
////				if (-1!=tmp[i][j]){
////					arr[k++] = tmp[i][j];
////				}
////			}
////		}
////	}
////}
////void merge(int* arr,int l,int m,int r){
////	int len = r - l + 1;
////	int left = l;
////	int right = m + 1;
////	int k = 0;
////	int* newArr = (int*)malloc(sizeof(int)*len);
////	while (left<=m && right<=r){
////		if (arr[left] < arr[right]){
////			newArr[k++] = arr[left++];
////		}
////		else{
////			newArr[k++] = arr[right++];
////		}
////	}
////	while (left<=m){
////		newArr[k++] = arr[left++];
////	}
////	while (right<=r){
////		newArr[k++] = arr[right++];
////	}
////	memcpy(arr+l,newArr, sizeof(int)*len);
////	free(newArr);
////	newArr = NULL;
////}
////void chaifen(int* arr,int l,int r){
////	if (l == r){
////		return;
////	}
////	int m = l + (r - l) / 2;
////	chaifen(arr,l,m);
////	chaifen(arr,m+1,r);
////	merge(arr,l,m,r);
////}
////void MERGE(int* arr,int length){
////	chaifen(arr,0,length-1);
////}
////void select(int* arr,int length){
////	for (int i = 0; i < length;i++){
////		int cur = arr[i];
////		int flag = -1;
////		for (int j = i + 1; j < length;j++){
////			if (arr[j] < cur){
////				cur = arr[j];
////				flag = j;
////			}
////		}
////		if (flag>=0){
////			arr[flag] = arr[i];
////			arr[i] = cur;
////		}
////	}
////}
////void bubble(int* arr,int length){
////	for (int i = 0; i < length - 1;i++){
////		for (int j = 0; j < length-i-1;j++){
////			if (arr[j+1] > arr[j]){
////				int tmp = arr[j];
////				arr[j] = arr[j+1];
////				arr[j + 1] = tmp;
////			}
////		}
////	}
////}
////
//
//
//
////void selectSort(int* arr, int length){
////	for (int i = 0; i < length; i++){
////		int cur = arr[i];
////		int flag = -1;
////
////		for (int j = i + 1; j < length; j++){
////			if (arr[j] < cur){
////				cur = arr[j];
////				flag = j;
////			}
////		}
////		if (flag >= 0){
////			arr[flag] = arr[i];
////			arr[i] = cur;
////		}
////	}
////}
////	int arr[] = { 1, 2, 3, 45, 66, 75, 77, 78, 79, 88, 98, 111, 123, 344 };
////	printf("%d\n", half_find(arr, sizeof(arr) / sizeof(arr[0]), 88));
////	//binnary_find(arr,sizeof(arr)/sizeof(arr[0]),88);
//
//// 链表中间位置可以用两个快慢指针，就可以解决s
////void insert_sort(int* arr,int length){
////	for (int i = 1; i < length;i++){
////		if (arr[i] < arr[i-1]){
////			int j = 0;
////			int tmp = arr[i];
////			for (j = i - 1; j >= 0 && arr[j] > tmp;j--){
////				arr[j + 1] = arr[j];
////			}
////			arr[j + 1] = tmp;
////		}
////	}
////}
////void shellSort(int* arr,int len){
////	int step = len / 2;
////	while (step>=1){
////		for (int k = step; k < len;k++){
////			for (int i = 1; i < len;i++){
////				if (arr[i] < arr[i-1]){
////					int j = 0;
////					int tmp = arr[i];
////					for (j = i - step; j >= 0 && arr[j] > tmp;j-=step){
////						arr[j + step] = arr[j];
////					}
////					arr[j + step] = tmp;
////				}
////			}
////		}
////		step /= 2;
////	}
////}
////#define MAXNUM 2422
////void radix_sort(int* arr,int length){
////	int tmp[MAXNUM+1];
////	memset(tmp,0,sizeof(int)*(MAXNUM+1));
////	for (int i = 0; i < length;i++){
////		tmp[arr[i]]++;
////	}
////	for (int i = 0; i < MAXNUM + 1;i++){
////		while (tmp[i]--){
////			printf("%d ",i);
////		}
////	}
////	printf("\n");
////}
//////
////#define LENGTH 24
////void bucketSort(int* arr,int length){
////	for (int i = 1; i < MAXNUM;i*=10){
////		int tmp[10][LENGTH];
////		memset(tmp, -1, sizeof(int)*LENGTH * 10);
////		for (int j = 0; j < length;j++){
////			int m = arr[j] / i % 10;
////			tmp[m][j] = arr[j];
////		}
////		int k = 0;
////		for (int i = 0; i < length;i++){
////			for (int j = 0; j < length;j++){
////				if (-1 != tmp[i][j]){
////					arr[k++] = tmp[i][j];
////				}
////			}
////		}
////	}
////}
//
////
////void mergesort(int* arr,int l,int m,int r){
////	int len = r - l + 1;
////	int left = l;
////	int right = m + 1;
////	int k = 0;
////	int* newArr = (int*)malloc(sizeof(int)*len);
////	while (left<=m && right<=r){
////		if (arr[left] < arr[right]){
////			newArr[k++] = arr[left++];
////		}
////		else
////		{
////			newArr[k++] = arr[right++];
////		}
////	}
////	while (left <= m){
////		newArr[k++] = arr[left++];
////	}
////	while (right<=r){
////		newArr[k++] = arr[right++];
////	}
////	memcpy(arr+l,newArr,sizeof(int)*len);
////	free(newArr);
////	newArr = NULL;
////}
////void chaifen(int* arr,int l,int r){
////	if (l == r){
////		return;
////	}
////	int m = l + (r-l) / 2;
////	chaifen(arr, l, m);
////	chaifen(arr, m+1, r);
////	mergesort(arr,l,m,r);
////}
////void MERGE(int* arr,int len){
////	chaifen(arr,0,len-1);
////}
////void bubbleSort(int* arr,int length){
////	for (int i = 0; i < length-1;i++){
////		for (int j = 0; j < length-i-1;j++){
////			if (arr[j+1] < arr[j]){
////				int tmp = arr[j];
////				arr[j] = arr[j+1];
////				arr[j + 1] = tmp;
////			}
////		}
////	}
////}
//
//
//
//
//// 选择排序
////void selectSort(int* arr,int length){
////	for (int i = 0; i < length;i++){
////		int cur = arr[i];
////		int j = 0;
////		int flag = -1;
////		int k = 0;
////		for (j = i + 1; j < length;j++){
////			if (arr[j] < cur){
////				flag = j;
////				cur = arr[j];
////			}
////		}
////		if (flag > 0){
////			arr[flag] = arr[i];
////			arr[i] = cur;
////		}
////	}
////}
//
////// 插入排序
////void  insert_sort(int* arr, int length){
////	for (int i = 1; i < length; i++){
////		if (arr[i] < arr[i - 1]){
////			int j = 0;
////			int tmp = arr[i];
////			for (j = i - 1; j >= 0 && arr[j] > tmp; j--){
////				arr[j + 1] = arr[j];
////			}
////			arr[j + 1] = tmp;
////		}
////	}
////}
////// 希尔排序
////void shell_sort(int* arr, int length){
////	int step = length / 2;
////	while (step >= 1){
////		for (int k = step; k < length; k++){
////			for (int i = 1; i < length; i++){
////				if (arr[i] < arr[i - 1]){
////					int j = 0;
////					int tmp = arr[i];
////					for (j = i - step; j >= 0 && arr[j] > tmp; j -= step){
////						arr[j + step] = arr[j];
////					}
////					arr[j + step] = tmp;
////				}
////			}
////		}
////		step /= 2;
////	}
////}
////
//////基数排序
////#define MAXNUM 2422
////void radix(int* arr, int len){
////	int tmp[MAXNUM + 1];
////	memset(tmp, 0, sizeof(int)*(MAXNUM + 1));
////	for (int i = 0; i < len; i++){
////		tmp[arr[i]]++;
////	}
////	for (int i = 0; i < MAXNUM + 1; i++){
////		while (tmp[i]--){
////			printf("%d ", i);
////		}
////	}
////	printf("\n");
////}
////// bucket
////#define LEN 19
////void bucket_sort(int* arr, int len){
////	for (int i = 1; i < MAXNUM; i *= 10){
////		int tmp[10][LEN];
////		memset(tmp, -1, sizeof(int)*LEN * 10);
////		for (int j = 0; j < len; j++){
////			int m = arr[j] / i % 10;
////			tmp[m][j] = arr[j];
////		}
////		int  k = 0;
////		for (int i = 0; i < 10; i++){
////			for (int j = 0; j < len; j++){
////				if (-1 != tmp[i][j]){
////					arr[k++] = tmp[i][j];
////				}
////			}
////		}
////	}
////}
////// merge_sort
////void merge_sort(int* arr, int l, int m, int r){
////	int len = r - l + 1;
////	int* newArr = (int*)malloc(sizeof(int)*len);
////	int left = l;
////	int right = m + 1;
////	int k = 0;
////	while (left <= m && right <= r){
////		if (arr[left] < arr[right]){
////			newArr[k++] = arr[left++];
////		}
////		else{
////			newArr[k++] = arr[right++];
////		}
////	}
////	while (left <= m){
////		newArr[k++] = arr[left++];
////	}
////	while (right <= r){
////		newArr[k++] = arr[right++];
////	}
////	memcpy(arr + l, newArr, sizeof(int)*len);
////	free(newArr);
////	newArr = NULL;
////}
////
////void chaifen(int* arr, int l, int r){
////	if (l == r){
////		return;
////	}
////	int m = l + (r - l) / 2;
////	chaifen(arr, l, m);
////	chaifen(arr, m + 1, r);
////	merge_sort(arr, l, m, r);
////}
////void MAIN(int* arr, int len){
////	chaifen(arr, 0, len - 1);
////}
//
//
////反转一个单链表。
////示例 :
////输入 : 1->2->3->4->5->NULL
////输出 : 5->4->3->2->1->NULL
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     struct ListNode *next;
//* };
//*/
////struct ListNode* reverseList(struct ListNode* head){
////	//根据头插实现操作
////	struct ListNode* newHead = NULL;
////	struct ListNode* next = NULL;
////	struct ListNode* cur = head;
////	while (cur){
////		next = cur->next;
////		cur->next = newHead;
////		newHead = cur;
////		cur = next;
////	}
////	return newHead;
////}
//
////void PrintInt(int n){
////	if (n == 0){
////		printf("%d\n", n);
////	}
////	else{
////		//函数递归的顺序，可以用嵌套来理解
////		PrintInt(n - 1);
////		printf("%d\n", n);
////	}
////}
//
////void move(char A, char B){
////	count++;
////	printf("%c -> %c\n", A, B);
////}
////void hanoi(int n, char one, char two, char three){
////	if (1 == n){
////		move(one, three);
////	}
////	else{
////		hanoi(n - 1, one, three, two);
////		move(one, three);
////		hanoi(n - 1, two, one, three);
////	}
////}
////void move(char A, char B){
////	count++;
////	printf("%c -> %c\n", A, B);
////}
////void hanoi(int n, char one, char two, char three){
////	if (1 == n){
////		move(one, three);
////	}
////	else{
////		hanoi(n - 1, one, three, two);
////		move(one, three);
////		hanoi(n - 1, two, one, three);
////	}
////}
////void Print(int arr[], int length){
////	for (int i = 0; i<length; i++){
////		printf("%d ", arr[i]);
////	}
////	printf("\n");
////}
////int halffind(int* arr,int l,int r,int findData){
////	int mid = l + (r - l) / 2; // 中间的下标
////	if (l == r){
////		return -1;
////	}
////	if (findData == arr[mid]){
////		return mid;
////	}
////	if (findData > arr[mid]){
////		return halffind(arr,mid+1,r,findData);
////	}
////	if (findData < arr[mid]){
////		return   halffind(arr,1,mid,findData);
////	}
////}
////// 二分法
////// findData 需要查找的数据
////int half_find(int* arr,int len,int findData){
////	return halffind(arr,0,len-1,findData);
////}
////int main(){
////	int arr[] = { 1, 2, 3, 45, 66, 75, 77, 78, 79, 88, 98, 111, 123, 344 };
////	printf("%d\n", half_find(arr, sizeof(arr) / sizeof(arr[0]), 88));
////	//int arr1[] = { 210, 110, 1, 22, 111, 214, 56, 1332, 152, 2422, 349, 77, 78, 79, 88, 98, 111, 123, 344 };
////	//int len1 = sizeof(arr1) / sizeof(arr1[0]);
////	//Print(arr1, len1);
////	//Print(arr1, len1);
////	//binnary_find(arr,sizeof(arr)/sizeof(arr[0]),88);
////	system("pause");
////	return 0;
////}
//
////// 二分查找，有序数组，通过二分的方式来找到数据
//////{1,2,3,45,66,75,77,77,88,98,111,123,344}
////void binnary_find(int* arr,int len,int key){
////	int left = 0;
////	int right = len - 1;
////	int mid = 0;
////	while (left<=right){
////		mid = left + (right - left) / 2;
////		if (arr[mid] == key){
////			printf("%d\n", arr[mid]);
////			break;
////		}else if (arr[mid] > key){
////			right = mid;
////		}else{
////			left = mid;
////		}
////	}
////}
////// 插入排序
////void insert_sort(int* arr,int length){
////	for (int i = 1; i < length;i++){
////		if (arr[i] < arr[i-1]){
////			int j = 0;
////			int tmp = arr[i];
////			for (j = i - 1; j >= 0 && tmp < arr[j];j--){
////				arr[j + 1] = arr[j];
////			}
////			arr[j + 1] = tmp;
////		}
////	}
////}
////// 希尔排序
////void shellSort(int* arr,int length){
////	int step = length / 2;
////	while (step>=1){
////		for (int k = step; k < length;k++){
////			for (int i = 1; i < length;i++){
////				if (arr[i] < arr[i-1]){
////					int j = 0;
////					int tmp = arr[i];
////					for (j = i-step; j >= 0 && arr[j] > tmp; j -= step){
////						arr[j + step] = arr[j];
////					}
////					arr[j + step] = tmp;
////				}
////			}
////		}
////		step /= 2;
////	}
////}
////// radix
////#define MAX 2422
////void radixSort(int* arr,int length){
////	int tmp[MAX + 1];
////	memset(tmp,0,sizeof(int)*(MAX+1));
////	for (int i = 0; i < length;i++){
////		tmp[arr[i]]++;
////	}
////	for (int i = 0; i < MAX + 1;i++){
////		while (tmp[i]--){
////			printf("%d ",i);
////		}
////	}
////	printf("\n");
////}
////// bucket
////#define LENGTH 11
////void bucket_sort(int* arr,int length){
////	for (int i = 1; i < MAX;i*=10){
////		int tmp[10][LENGTH];
////		memset(tmp, -1, sizeof(int) * 10 * LENGTH);
////		for (int j = 0; j < length;j++){
////			int m = arr[j] / i % 10;
////			tmp[m][j] = arr[j];
////		}
////		int  k = 0;
////		for (int i = 0; i < length;i++){
////			for (int j = 0; j < length;j++){
////				if (-1 != tmp[i][j]){
////					arr[k++] = tmp[i][j];
////				}
////			}
////		}
////	}
////}
////// bubble
////void bubble_sort(int arr[],int length){
////	for (int i = 0; i < length-1;i++){
////		for (int j = 0; j < length - i - 1;j++){
////			if (arr[j+1] < arr[j]){
////				int tmp = arr[j];
////				arr[j] = arr[j+1];
////				arr[j+1] = tmp;
////			}
////		}
////	}
////}
////// 归并排序
////// 先合并
////void merge_sort(int arr[],int l,int m,int r){
////	int len = r - l + 1;
////	int left = l;
////	int right = m + 1;
////	int* newArr = (int*)malloc(sizeof(int)*len);
////	int k = 0;
////	while (left <= m && right<= r){
////		if (arr[left] < arr[right]){
////			newArr[k++] = arr[left++];
////		}
////		else{
////			newArr[k++] = arr[right++];
////		}
////	}
////	while (left <= m){
////		newArr[k++] = arr[left++];
////	}
////	while (right<=r){
////		newArr[k++] = arr[right++];
////	}
////	memcpy(arr+l,newArr,sizeof(int)*len);
////	free(newArr);
////	newArr = NULL;
////}
////// 分组
////void chaifen(int* arr,int l,int r){
////	if (l == r){
////		return;
////	}
////	int m = l + (r - l) / 2;
////	chaifen(arr, l, m);
////	chaifen(arr, m+1, r);
////	merge_sort(arr,l,m,r);
////}
////void MERGE(int* arr, int len){
////	chaifen(arr,0,len-1);
////}
//
////// 合并,将左右两边 都有序的数组合并为一个全局有序的数组
////void mergeSort(int* arr, int l, int m, int r){
////	int len = r - l + 1;
////	int* newArr = (int*)malloc(len*sizeof(int));
////	int left = l;
////	int right = m + 1;
////	int k = 0;
////	while (left <= m && right <= r){
////		if (arr[left] < arr[right]){
////			newArr[k++] = arr[left++];
////		}
////		else{
////			newArr[k++] = arr[right++];
////		}
////	}
////	while (left <= m){
////		newArr[k++] = arr[left++];
////	}
////	while (right <= r){
////		newArr[k++] = arr[right++];
////	}
////	memcpy(arr + l, newArr, sizeof(int)*len);
////	free(newArr);
////	newArr = NULL;
////}
//////拆分，将一个整数组拆分为两个数组，递归拆分
////void chaifen(int* arr, int l, int r){
////	if (l == r){
////		return;
////	}
////	int m = l + (r - l) / 2;
////	chaifen(arr, l, m);
////	chaifen(arr, m + 1, r);
////	mergeSort(arr, l, m, r);
////}
////void MERGESORT(int* arr, int length){
////	chaifen(arr, 0, length - 1);
////}
////int main(){
////	int nums2[] = { 1, 2, 4, 5, 6, 7 };
////	//int num2 = 6;
////	//int nums1[] = { 1,1,2,3,0,0,0,0,0,0};
////	//int num1 = 4;
////	////merge(nums1, sizeof(nums1) / sizeof(nums1[0]), num1, nums2, sizeof(nums1) / sizeof(nums1[0]), num2);
////	//Print(nums1, sizeof(nums1) / sizeof(nums1[0]));
////
////	int arr[] = { 210, 110, 1, 22, 111, 214, 56, 1332, 152, 2422, 349 };
////	int length = sizeof(arr) / sizeof(arr[0]);
////	Print(arr, length);
////	MERGESORT(arr, length);
////	//MERGRSORT(arr,length);
////	Print(arr, length);
////	//int sum = 100133;
////	//int count = 0;
////	//for (int i = 1; i<=sum; i *= 10){
////	//	count++;
////	//}
////	//printf("%d ",count);
////	system("pause");
////	return 0;
////}
//
//
//////#define _CRT_SRCURE_NO_WARNINGS 1
//////#include<stdio.h>
//////#include<stdlib.h>
//////#include<string.h>
//////void Print(int arr[], int length){
//////	for (int i = 0; i < length; i++){
//////		printf("%d ", arr[i]);
//////	}
//////	printf("\n");
//////}
//////// 合并,将左右两边 都有序的数组合并为一个全局有序的数组
//////void mergeSort(int* arr,int l,int m,int r){
//////	int len = r - l + 1;
//////	int* newArr = (int*)malloc(len*sizeof(int));
//////	int left = l;
//////	int right = m + 1;
//////	int k = 0;
//////	while (left <= m && right<=r){
//////		if (arr[left] < arr[right]){
//////			newArr[k++] = arr[left++];
//////		}
//////		else{
//////			newArr[k++] = arr[right++];
//////		}
//////	}
//////	while (left <= m){
//////		newArr[k++] = arr[left++];
//////	}
//////	while (right<=r){
//////		newArr[k++] = arr[right++];
//////	}
//////	memcpy(arr+l,newArr,sizeof(int)*len);
//////	free(newArr);
//////	newArr = NULL;
//////}
////////拆分，将一个整数组拆分为两个数组，递归拆分
//////void chaifen(int* arr,int l,int r){
//////	if (l == r){
//////		return;
//////	}
//////	int m = l + (r - l) / 2;
//////	chaifen(arr, l, m);
//////	chaifen(arr, m+1, r);
//////	mergeSort(arr,l,m,r);
//////}
//////void MERGESORT(int* arr, int length){
//////	chaifen(arr, 0, length - 1);
//////}
//////int main(){
//////	int nums2[] = { 1,2,4,5,6,7};
//////	//int num2 = 6;
//////	//int nums1[] = { 1,1,2,3,0,0,0,0,0,0};
//////	//int num1 = 4;
//////	////merge(nums1, sizeof(nums1) / sizeof(nums1[0]), num1, nums2, sizeof(nums1) / sizeof(nums1[0]), num2);
//////	//Print(nums1, sizeof(nums1) / sizeof(nums1[0]));
//////
//////	int arr[] = { 210, 110, 1,22, 111, 214, 56,1332, 152, 2422, 349 };
//////	int length = sizeof(arr) / sizeof(arr[0]);
//////	Print(arr, length);
//////	MERGESORT(arr, length);
//////	//MERGRSORT(arr,length);
//////	Print(arr, length);
//////	//int sum = 100133;
//////	//int count = 0;
//////	//for (int i = 1; i<=sum; i *= 10){
//////	//	count++;
//////	//}
//////	//printf("%d ",count);
//////	system("pause");
//////	return 0;
//////}
//////
//////// 归并排序首先是将数组分而治之
//////// 合并两半有序数组,合并之后为有序的数组
////////// l       m         r
////////// 1 3 4 5 7 3 4 5 8 9
////////void mergeArr(int* arr, int l, int m, int r){
////////	int len = r - l + 1;
////////	// 该数组有序存放有序数组
////////	int* newArr = (int*)malloc(sizeof(int)*len);
////////	int left = l;
////////	int right = m + 1;
////////	int k = 0;// 记录新数组
////////	while (left <= m && right <= r){
////////		if (arr[left] < arr[right]){
////////			newArr[k++] = arr[left++];
////////		}
////////		else{
////////			newArr[k++] = arr[right++];
////////		}
////////	}
////////	while (right <= r){
////////		newArr[k++] = arr[right++];
////////	}
////////	while (left <= m){
////////		newArr[k++] = arr[left++];
////////	}
////////	memcpy(arr + l, newArr, sizeof(int)*len);
////////	free(newArr);
////////	newArr = NULL;
////////}
//////////拆分数组
////////void chaifen(int* arr, int l, int r){
////////	if (l == r){
////////		return;
////////	}
////////	int m = l + (r - l) / 2;
////////	chaifen(arr, l, m);
////////	chaifen(arr, m + 1, r);
////////	mergeArr(arr, l, m, r);
////////}
////////void mergeSort(int* arr, int length){
////////	chaifen(arr, 0, length - 1);
////////}
////////// l       m         r
////////// 1 3 5 7 9 0 2 5 7 8 
////////// 合并
////////void merge_sort(int* arr, int l, int m, int r){
////////	// 左边的一半 [l,m]
////////	// 右边的一半 [m+1,r]
////////	// 需要临时数组
////////	// r-l+1
////////	// left=l  right=m+1
////////	//比较left和right所在数据，谁小谁移动
////////	// 只有对有序数组才能合并
////////	// 对左右两边都是有序的数组
////////	// 1、准备临时数组
////////	int len = r - l + 1;
////////	int* pTemp = (int*)malloc(len*sizeof(int));
////////	int k = 0; //临时数组的下标
////////	int left = l; // 左边数组第一个元素下标
////////	int right = m + 1;// 右边数组第一个元素下标
////////	// 2、数据依序从原来数组中放入临时数组
////////	// 2.1循环放完一半
////////	while (left <= m && right <= r){
////////		if (arr[left] < arr[right]){
////////			pTemp[k++] = arr[left++];
////////		}
////////		else
////////		{
////////			pTemp[k++] = arr[right++];
////////		}
////////	}
////////	// 2.2
////////	while (right <= r){
////////		pTemp[k++] = arr[right++];
////////	}
////////	while (left <= m){
////////		pTemp[k++] = arr[left++];
////////	}
////////	// 3、数据从临时数组拷贝回原数组，释放临时数组
////////	memcpy(arr + l, pTemp, sizeof(int)*len);
////////	free(pTemp);
////////	pTemp = NULL;
////////
////////}
////////
//////////把一个数组拆成两等份
////////void mergeSort(int* arr, int l, int r){
////////	if (l == r){
////////		return;
////////	}
////////	int m = l + (r - l) / 2;
////////	mergeSort(arr, l, m); // 拆左边
////////	mergeSort(arr, m + 1, r); // 拆右边
////////	merge_sort(arr, l, m, r); // 合并
////////}
////////void MERGRSORT(int* arr, int len){
////////	mergeSort(arr, 0, len - 1);
////////}
//////// 拆半 分治
//////// 二分查找 归并排序
//////
//////
//////// 树：各种程序，底层,例如：文件系统（多分支树状结构）
//////// 森林:多棵树
//////// 树具备递归性 
//////// 根：第一个结点 第一颗子树
//////// 层 ：同层结点到根的距离相等
////////路径长度：找到某个结点经过几次寻址
//////// 高度: 最远叶子结点的距离
//////// N叉树
////////// 链表就是一个1叉树
////////void bucket_sort(int arr[], int length){
////////	for (int i = 1; i < MAXNUM; i *= 10){
////////		int tmp[10][NUM];
////////		memset(tmp, -1, sizeof(int) * 10 * NUM);
////////		// 根据元素情况入桶
////////		for (int j = 0; j < length; j++){
////////			int m = arr[j] / i % 10;
////////			tmp[m][j] = arr[j];
////////		}
////////		// 出桶
////////		int k = 0;
////////		for (int i = 0; i < 10; i++){
////////			for (int j = 0; j < NUM; j++){
////////				if (-1 != tmp[i][j]){
////////					arr[k++] = tmp[i][j];
////////				}
////////			}
////////		}
////////	}
////////}
////////void bubble_sort(int arr[], int length){
////////	for (int i = 0; i < length - 1; i++){
////////		for (int j = 0; j < length - i - 1; j++){
////////			if (arr[j + 1] < arr[j]){
////////				int tmp = arr[j];
////////				arr[j] = arr[j + 1];
////////				arr[j + 1] = tmp;
////////			}
////////		}
////////	}
////////}
//////////[]
//////////2
////////int removeElement(int* nums, int numsSize, int val){
////////	int k = 0;
////////	for (int i = 0; i<numsSize - k; i++){
////////		if (val == nums[i]){
////////			for (int j = i + 1; j<numsSize - k; j++){
////////				nums[j - 1] = nums[j];
////////			}
////////			i--;
////////			k++;
////////		}
////////	}
////////	return numsSize - k;
////////}
//////////int nums1[] = { 1, 2, 3, 0, 0, 0 };
//////////int num1 = 3;
//////////int nums2[] = { 2, 5, 6 };
////////////int num2 = 3;
//////////void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
//////////	while (m>0 && n>0){
//////////		if (nums1[m - 1] >= nums2[n - 1]){
//////////			nums1[nums1Size - 1] = nums1[m - 1];
//////////			nums1Size--;
//////////			m--;
//////////		}
//////////		if (nums1[m - 1] < nums2[n - 1]){
//////////			nums1[nums1Size - 1] = nums2[n - 1];
//////////			nums1Size--;
//////////			n--;
//////////		}
//////////	}
//////////	if (n>0){
//////////		// memcpy(nums1,nums2,sizeof(int)*nums1Size);
//////////		for (int i = 0; i<nums1Size; i++){
//////////			nums1[i] = nums2[i];
//////////		}
//////////	}
//////////}
//////////[2, 0]
//////////1
//////////[1]
//////////1
////////void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
////////	int* newnums = (int*)malloc(sizeof(int)*(m + n));
////////	int i = 0;
////////	int j = 0;
////////	int k = 0;
////////	while (i<m && j<n){
////////		if (nums1[i] >= nums2[j]){
////////			newnums[k] = nums2[j];
////////			k++;
////////			j++;
////////		}
////////		if (nums1[i] < nums2[j]){
////////			newnums[k] = nums1[i];
////////			k++;
////////			i++;
////////		}
////////	}
////////	if (i<m){
////////		memcpy(newnums + k, nums1 + i, sizeof(int)*(m - i));
////////	}
////////	if (j<n){
////////		memcpy(newnums + k, nums2 + j, sizeof(int)*(n - j));
////////	}
////////	memcpy(nums1, newnums, sizeof(int)*(m + n));
////////	free(newnums);
////////}
////////void rotate(int* nums, int numsSize, int k){
////////	k = k%numsSize;
////////	for (int i = 0; i<k; i++){
////////		int bbjj = nums[numsSize - 1];
////////		for (int j = numsSize - 2; j >= 0; j--){
////////			nums[j + 1] = nums[j];
////////		}
////////		nums[0] = bbjj;
////////	}
////////}
////////}
//////////    bubble
////////void insert_sort(int arr[], int length){
////////	for (int i = 1; i < length; i++){
////////		if (arr[i] < arr[i - 1]){
////////			int j = 0;
////////			int tmp = arr[i];
////////			for (j = i - 1; j >= 0 && arr[j] > tmp; j--){
////////				arr[j + 1] = arr[j];
////////			}
////////			arr[j + 1] = tmp;
////////		}
////////	}
////////}
////////void shell_sort(int arr[], int length){
////////	int step = length / 2;
////////	while (step >= 1){
////////		for (int k = step; k < length; k++){
////////			for (int i = 1; i < length; i++){
////////				if (arr[i] < arr[i - 1]){
////////					int j = 0;
////////					int tmp = arr[i];
////////					for (j = i - step; j >= 0 && arr[j] > tmp; j -= step){
////////						arr[j + step] = arr[j];
////////					}
////////					arr[j + step] = tmp;
////////				}
////////			}
////////		}
////////		step /= 2;
////////	}
////////}
////////#define MAX (623+1)
////////void radix_sort(int arr[], int length){
////////	int tmp[MAX] = { 0 };
////////	for (int i = 0; i < length; i++){
////////		tmp[arr[i]]++;
////////	}
////////	for (int i = 0; i < MAX; i++){
////////		while (tmp[i]--){
////////			printf("%d ", i);
////////		}
////////	}
////////}
////////#define MAXNUM 623
////////#define NUM 13