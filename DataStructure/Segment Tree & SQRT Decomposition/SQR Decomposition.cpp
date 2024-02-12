// 이건 인덱스 0 부터 시작  
#include <iostream>

using namespace std;

long long query(int lo, int hi){
	long long ret = 0;
	
	// 구간 안맞는 경우, 왼족 걸친 것 원소 다 더하기   
	while(lo % sz != 0 && lo <= hi){
		ret += A[lo++];
	}
	
	while( (hi + 1) % sz != 0 && lo <= hi){
		ret += A[hi--];
	}
	
	while(lo <= hi){
		ret += bucket[ lo / sz ];
		lo += sz;
	}
	return ret;
}

void update(int pos, long long val){
	// 원래 원소 값과 갱신할 값읠 차이 계산 
	long long diff = val - A[pos];
	//기존 원소 새로운 값으로 대체 
	A[pos] = val;
	// 기존 원소가 속해있는 묶음에 갱신으로 인해 생기는 만큼 차이 더해줌
	bucket[pos / sz] += diff; 
}
 
