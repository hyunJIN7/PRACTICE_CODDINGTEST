#include <bits/stdc++.h>

using namespace std;

int main(){
	int ans = 0;
	char c[100001];
	scanf("%s",c);
	for(int i = 0 ,sticks=0, len = strlen(c); i < len ; i++){		
		if( *(c+i)== '('){
			if(*(c+i+1)== ')' ){
				//�������� ��� 
				ans += sticks;
				i++;
			}
			else{ // (( �� ���  : ���� ���� 
				sticks++;
				ans++;
			}
		}
		else{// ) �������ƴ� ���� �� 
			sticks--; 
		}
	}
	printf("%d",ans);
	return 0;
}
