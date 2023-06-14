#include <bits/stdc++.h>
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 21

using namespace std;

int N;
int arrS[MAX], arrJ[MAX];//ü��, ��� 
int ans = 0; 

void Bruteforce(int index,int strength, int joy){
	if( index == N ){
		ans = (ans < joy) ? joy : ans;
		return;
	}  

	//�λ� ���Ѵ�. 
	Bruteforce(index+1,strength,joy );
	
	
	//�λ� �Ѵ�.
	strength -= arrS[index];
	joy += arrJ[index];
	if(strength > 0 ){
		Bruteforce(index+1 , strength , joy );		
	} 

}

int main(){
	Fastio;
	cin>>N;
	for(int i = 0 ; i < N; i++ ) cin>>arrS[i];
	for(int i = 0 ; i < N; i++ ) cin>>arrJ[i];

	Bruteforce(0,100,0);
	cout<<ans;
}
