#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
//들어온 때만 보는게 아니라 전체 누적 시간이야!!!!!
int calcFee(int time, vector<int> fees){
    if(time<=fees[0]) return fees[1];
    return fees[1]+((time-fees[0]-1)/fees[2] + 1)*fees[3];
    
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> parkingTime;
    map<string,bool>parkingIn;//in :false, out:true    
    
    for(int i = records.size()-1; i >= 0 ; i--){
        int recT = stoi(records[i].substr(0,2))*60 + stoi(records[i].substr(3,2));
        string car = records[i].substr(6,4);
        string action = records[i].substr(11);
        
        if(action.compare("IN")){ // out이면
            parkingTime[car] +=recT;     
            parkingIn[car]=true;
        }
        else{//in 이면      
            
            parkingTime[car] =  parkingIn[car]? parkingTime[car] - recT:1439 - recT;// out있음 : 없음 
            parkingIn[car]=false;
  
            
        }
        
    }

    
    //answer로 옮기기 
    for(auto e  : parkingTime) { // 주차 누적 시간 베이스로 넣기 
        answer.push_back(calcFee(e.second,fees));
        
    }
    
    
    return answer;
}
