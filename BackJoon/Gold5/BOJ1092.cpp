//https://gglifer-cs.tistory.com/196
#include <bits/stdc++.h>
using namespace std;
int cnt_crane,cnt_box; 
vector<int> cranes,boxes;
int result=0;
void Input(){
	cin>>cnt_crane;
	for(int i = 0,tmp ; i < cnt_crane; i++){
		cin>>tmp;
		cranes.push_back(tmp);
	}
	
	cin>>cnt_box;
	for(int i = 0,tmp ; i < cnt_box; i++){
		cin>>tmp;
		boxes.push_back(tmp);
	} 
}

void Solution(){
	if(boxes[0]>cranes[0]){
		result=-1;return;
	}
	while(boxes.size()!=0){
		for(int c : cranes){
			for(int i = 0 ; i <boxes.size();i++){
				if(boxes[i]<= c){
					boxes.erase(boxes.begin()+i);
					break;
				
				}
			}
		}
		result++;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	Input();
	sort(cranes.begin(),cranes.end(),greater<int>());
	sort(boxes.begin(),boxes.end(),greater<int>());	
	
	Solution();
	cout<<result;

}
