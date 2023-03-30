//참고 https://steady-life.tistory.com/61
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int,pair<int,int>> m;//번호,추천수,시간 

/*
pair 비교 : first 비교 후 판가름 나지 않는 경우 second 비교 
*/
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,r,student;
	cin>>n>>r;
	for(int i = 0 ;i < r ; i++){
		cin>>student;
        
        if(m.find(student) == m.end()){ // map에 새로 추가하는 경우  
        	if(m.size() >= n){ // 빈자리 없으면 지우고  
        		int studentID = m.begin()->first;//map의 첫번째 학생 
	        	pair<int,int> record = m.begin()->second; // <추천수 , 시간> 
	        	
	        	for(auto it : m){
	        		if(it.second < record){ // 추천수 가장 작고 먼저 들오온 학생 찾기. 
	        			studentID = it.first;
	        			record = it.second;
					}        		
				}
			
				m.erase(studentID);
//				cout<<"--- id "<<studentID<<endl; 
			}
			// 학생 추가 
			m[student].first=1;
        	m[student].second= i ;
        	
        	
		}
		else{ // map에 이미 있는 경우  
			m[student].first++;
		}
       
	}
	
	for(auto it : m){
		cout<< it.first<<" ";
	}

		
}
