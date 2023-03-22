#include <iostream>


 
using namespace std;
int N;
int input[20];
bool check[20*100000+10];//N최대 20 , 100000개, 여분  


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < N;) cin>>input[i++];

	//부분 집합의 개수를 비트마스크로 나타냄
	// 총 나올 수 있는 경우의 수 
	for(int i = 0 ; i < (1<<N) ; i++ ){ //만들 수 있는 최대 경우의 수가 2^N(1<<N)이니까 
		
		int sum=0;
		for(int j = 0; j<N ;j++){
			
			cout << i <<"  "<< (1<<j)<< "   "; 
			if( i & (1<<j) ){
				sum+=input[j];
				cout<<sum<<endl;
			} 
			//i에 j번째 인자가 있는지  
			else cout<<endl;
		}
		check[sum]=true;
				
	}
	
	for(int i=1 ; i <=2000000; i++){
		if(!check[i]){
			cout<<i;
			break;
		}
	}
	
}
