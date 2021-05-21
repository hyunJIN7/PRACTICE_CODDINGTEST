#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,ans=0;
	scanf("%d %d",&n,&k);
	if(k>=n) {
		printf("0\n");
		return 0;
	}
	vector<int>sensor,dist;
	for(int i = 0,loc ; i < n ;i++) {
		scanf("%d",&loc);
		sensor.push_back(loc);	
	}
	sort(sensor.begin(),sensor.end()); // ���� ��ġ ���� 
	sensor.erase(unique(sensor.begin(),sensor.end()),sensor.end());//�ߺ�����
	
	for(int i = 0 ; i < sensor.size()-1;i++){
		dist.push_back(sensor[i+1]-sensor[i]);
	} 
	sort(dist.rbegin(),dist.rend());
	for(int i =k-1;i<dist.size();i++){
		ans+=dist[i];
	}
	printf("%d\n",ans);
} 
/*
 ������ ��ġ������� ���븦 �����
 ���� ������ �Ÿ��� ����
 ���밡 �� ����Ǿ� �ִ� �����Ѵ���
 �� ���� ������ ������ ��� k���� ���븦 ����°���
 �׷��� ���� �� ���� ���� �Ÿ� ���ؼ� ���� ���� ���� ��
 ���� �� ������ k-1�� ���� �� ���� �͵��� ���� ���ϸ� ��  
 */
