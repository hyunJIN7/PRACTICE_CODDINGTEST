#include <iostream>


 
using namespace std;
int N;
int input[20];
bool check[20*100000+10];//N�ִ� 20 , 100000��, ����  


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < N;) cin>>input[i++];

	//�κ� ������ ������ ��Ʈ����ũ�� ��Ÿ��
	// �� ���� �� �ִ� ����� �� 
	for(int i = 0 ; i < (1<<N) ; i++ ){ //���� �� �ִ� �ִ� ����� ���� 2^N(1<<N)�̴ϱ� 
		
		int sum=0;
		for(int j = 0; j<N ;j++){
			
			cout << i <<"  "<< (1<<j)<< "   "; 
			if( i & (1<<j) ){
				sum+=input[j];
				cout<<sum<<endl;
			} 
			//i�� j��° ���ڰ� �ִ���  
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
