#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	for(scanf("%*d"); ~scanf("%d %d",&a,&b) ;) 
		printf("%d\n",a*b/__gcd(a,b));
	return 0;
	
	// lcm ���̺귯�� ����...���� �������ϱ� ���ϱ�   
//	ios_base::sync_with_stdio(0);
//	int T, A, B;
//	cin >> T;
//	while (T--)
//		cin >> A >> B, cout << lcm(A, B) << '\n';
} 
