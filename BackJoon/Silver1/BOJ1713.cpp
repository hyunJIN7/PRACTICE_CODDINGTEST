//���� https://steady-life.tistory.com/61
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int,pair<int,int>> m;//��ȣ,��õ��,�ð� 

/*
pair �� : first �� �� �ǰ��� ���� �ʴ� ��� second �� 
*/
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,r,student;
	cin>>n>>r;
	for(int i = 0 ;i < r ; i++){
		cin>>student;
        
        if(m.find(student) == m.end()){ // map�� ���� �߰��ϴ� ���  
        	if(m.size() >= n){ // ���ڸ� ������ �����  
        		int studentID = m.begin()->first;//map�� ù��° �л� 
	        	pair<int,int> record = m.begin()->second; // <��õ�� , �ð�> 
	        	
	        	for(auto it : m){
	        		if(it.second < record){ // ��õ�� ���� �۰� ���� ����� �л� ã��. 
	        			studentID = it.first;
	        			record = it.second;
					}        		
				}
			
				m.erase(studentID);
//				cout<<"--- id "<<studentID<<endl; 
			}
			// �л� �߰� 
			m[student].first=1;
        	m[student].second= i ;
        	
        	
		}
		else{ // map�� �̹� �ִ� ���  
			m[student].first++;
		}
       
	}
	
	for(auto it : m){
		cout<< it.first<<" ";
	}

		
}
