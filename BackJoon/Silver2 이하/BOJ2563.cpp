#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,sum=0;
	bool area[100][100]={0,};
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int x,y;
		cin >> x>>y;
		for(int i = y ; i<y+10;i++){
			for(int j = x ; j <x+10; j++){
				if(!area[i][j]){
					area[i][j]=true;
					sum++;
				}	
			}
		}
	}	
	cout<<sum;
	
}

//결국 넓이 계산으로 푸는 것이 아닌  색종이 영역에 공백이 아닌 1로 표시 후
// 카운트하면 쉽게 풀린다. 
