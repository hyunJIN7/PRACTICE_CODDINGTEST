#include <bits/stdc++.h>

using namespace std;



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N,W,L;
	int input[1000];
	cin>>N>>W>>L;
	for(int i = 0 ; i < N ; i++) cin>>input[i];
	
	int ans = 0;
	queue<int> Q;
	int weight = 0;
	for(int i = 0 ; i < N ; i++){	
		while(1){
			if(Q.size() == W){//Ʈ���� ���� �����ϸ� 
				weight -= Q.front();
				Q.pop();
			}
			
			if(weight + input[i] <= L) break;
			Q.push(0);
			ans++;
		}
		Q.push(input[i]);
		ans++;
		weight+=input[i];
		
	}
	cout<<ans+W;//������ Ʈ���� Q�� �ְ� �����ϱ� W ���ϱ�  
}
