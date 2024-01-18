#include<iostream>
#include <vector>
#include <utility>
#include <tuple>

#define MAX_N 10
using namespace std;

int N, K; 
int arr[10];
int ans;

typedef pair<int,int> pii;

class PairMinHeap{
	vector<pii> data;
//	size_t size = 0;
public:
	//index 0 부터 시작해서 좀 고쳐야해!!  
	PairMinHeap(){
		data.clear();
	}

	void clear(){ data.clear();}
	bool empty(){return data.empty();}	
	int getSize(){return data.size();}
	
	int getParent(int idx){return (idx - 1) / 2;}
	int getLeft(int idx){return idx * 2 + 1;}
	int getRight(int idx){return idx * 2 + 2;}
	
	void swap(pii& a, pii& b){		
		pii tmp = a;
		a = b;
		b = tmp;
	}
	
	void push(pii x){ // 횟수, 값  
		data.push_back(x);
		int index = data.size()-1;
		while(index > 0 && cmp(data[index], data[getParent(index)])){
			swap( data[index], data[getParent(index)] );
			index = getParent(index);
		}		
	}
	
	pii top(){
		if(!data.empty()) return data[0];	
	}
	
	void pop(){ 
		if(data.empty()) return;
		
		data[0] = data.back();
		data.pop_back();
		
		//아래로 내려야해  
		int index = 0;
		int small = 0;
		int left = getLeft(index);
		int right = getRight(index);
		
		while(true){
			if(left < data.size() && cmp(data[left], data[small])) small = left;
			if(right < data.size() && cmp(data[right], data[small])) small = right;
			
			if(index == small) break;
			
			swap(data[index], data[small]);
			index = small;
			left = getLeft(index);
			right = getRight(index);	
		}
	}
	bool cmp(pii& a, pii& b){
//		return a < b;
		if(a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;

	for(int test_case = 1; test_case <= T; ++test_case)
	{	
		PairMinHeap pmh = PairMinHeap();
		cin >> N;
		for(int i = 0 ; i < N; i++) cin >> arr[i];
		cin >> K;
		ans = K;

		pmh.push({0 , K});
		
		while(!pmh.empty()){
			int cnt, num ;
			tie(cnt, num) = pmh.top();
			pmh.pop();

			if(!num){
				ans = cnt;
				break;
			}
			
			for(int i = 0 ; i < N ; i++){
				pmh.push({cnt + num % arr[i] , num / arr[i]});
			}	
		}	
		cout << "#"<<test_case<<" "<< ans<<"\n";
	}
	return 0;
}
