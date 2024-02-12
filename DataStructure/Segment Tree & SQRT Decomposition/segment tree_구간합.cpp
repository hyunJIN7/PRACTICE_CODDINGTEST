#include <iostream>

using namespace std;

int arr[] = {1,2,3,4,5,6,7,8,9};
//트리 초기화 
int init(int* tree, int node, int s, int e){
	//s&e : arr의 시작 끝 인덱스
	if (s == e) return tree[node] = arr[s];
	
	//재귀로 반 나눠 초기화 
	int m = (s + e) / 2;
	int a = init(tree, node * 2, s ,m);
	int b = init(tree, node * 2 + 1, m + 1, e);
	return tree[node] = a + b;
}

//쿼리 sum 수행  
int query(int *tree, int node, int ts, int te, int qs, int qe){
	// qs,qe : arr의 쿼리 구간
	// ts,te : tree 구간
	
	//ts,te 구간의 값을 node 인덱스에 저장되어 있음
	// tree[node]의 값은 : arr에서 ts,te 구간의 합  
	 
	//case 1 : 트리 구간이 질이 구간에 포함
	if(qs <= ts && te <= qe) return tree[node];
	
	//case 2 : 트리 구간과 질의 구간이 전혀 겹치지 않음 
	if(te < qs || qe < ts) return 0;  //아예 엇갈림  
	
	//case 3 : 일부 겹침
	int m =  (ts + te) / 2;
	int a = query(tree, node * 2, ts, m, qs, qe); // 왼쪽 탐색
	int b = query(tree, node * 2 + 1, m + 1, te, qs, qe); 
	
	return a + b;
}

int update(int *tree, int node, int s, int e, int ii, int value){
	// ii : 수정할 arr 인덱스 
	// value : 갱신할 값 
	// s, e 트리 인덱스 같은데, 그니까 크기는 arr과 같은 누적합 배열 인덱스 
	// node는 세그 트리 노드 번호 
		
	//범위 밖 
	if(ii < s || e < ii) return tree[node]; 
	
	tree[node] += value;
	if(s == e) return tree[node];
	
	int m = (s + e) / 2;
	int a = update(tree, node * 2, s , m, ii, value);
	int b = update(tree, node * 2 + 1, m + 1, e, ii, value);
	return tree[node] = a + b; 
} 


int main(){
	int N = sizeof(arr) / sizeof(arr[0]); // 배열 크기 
	int segTree[N * 4] = ();
	init(segTree, 1 , 0 , N-1);
	
	//쿼리  
	query(segTree, 1, 1, N, 1, 5); //0 ~ 4의 합 
	query(segTree, 1, 1, N, 2, 4); // 1~3 합  
	query(segTree, 1, 1, N, 9, 10);
	query(segTree, 1, 1, N, 7, 10);
	
	
	// 갱신 결과
	update(segTree, 1, 1, N, 5, 100); // 인덱스 4 변경 + 100  
}
