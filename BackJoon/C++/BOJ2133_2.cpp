//���ڵ�, ���� ����� �����ϸ� �Ʒ��� ���� �� ���� �� ���� 
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int d[31]={1,0,3};
	scanf("%d",&n);
	if(n%2==1) {
		printf("0"); return 0;
	}
	for(int i =4 ; i <=n ;i+=2){
		d[i] = d[i-2]*4 - d[i-4];
	}
	printf("%d",d[n]);
	return 0;
}
