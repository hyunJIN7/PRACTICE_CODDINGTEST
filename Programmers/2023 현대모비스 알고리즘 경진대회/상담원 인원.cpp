/*
- 먼저 k개 상담 유형에 따라 대기 목록 만들고
- 해당 유형에 1~N명의 상담원이 배치되었을 때 대기 시간 구하기 
- 이후 모둔 유형에 1명씩 기본 상담 인원 배치하고 다음 1명 추가할 유형 찾기
- 이때 1명 추가했을 때 대기 시간이 많이 줄어드는 유형에 상담 인원 추가하기 

*/

#include <cstring>
#include <string>
#include <vector>
#include <tuple>
#include <climits>
#include <algorithm>

#define MAX_K 5
#define MAX_N 20

using namespace std;

vector<pair<int,int> > wait_list[MAX_K + 1]; //굳이 필요 없을 지도 
int wait_time[MAX_K + 1][MAX_N + 1]= {0,};

void SearchWaitTime(int k, int n){
    // 대기할 필요 없으니   
    if(wait_list[k].size() <= n ) return;
    
    // k 유형에 n명 배치할때 대기 시간 
    vector<int> counselor(n);//n명 상담사  상담 끝나는 시간
    
    for(int i = 0 ; i < wait_list[k].size(); i++){
        int start,term;
        tie(start, term) = wait_list[k][i];
        
        // 먼저 끝나는 상담사 찾기
        int min_idx, min_time = INT_MAX;
        for(int j = 0 ; j < n; j++)
            if(counselor[j] < min_time)
                min_idx = j, min_time = counselor[j];
        
        // 기다려야 하는 경우
        // 상담 시간 갱신
        if(start < min_time){
            wait_time[k][n] += min_time - start;
            counselor[min_idx] += term;
        }
        else counselor[min_idx] = start + term;
        
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;

    for(int i = 0 ; i < reqs.size(); i++){
        int s = reqs[i][0],d=reqs[i][1],t=reqs[i][2];
        wait_list[t].push_back({s,d});
    }
    
    // i 유형에 j명 배치할때 대기 시간 
    for(int i = 1 ; i <= k; i++)
        for(int j = 1; j <= n ; j++)
            SearchWaitTime(i,j);
    
    int num_counselor[k+1];
    fill(num_counselor,num_counselor + k + 1, 1);
    for(int i = 1 ; i <= n - k ; i++ ){ // 최소 1명씩 있고 남은 인원 배치 
        // 감소 폭 가장 큰 상담 유형 
        int max_time = 0,max_k;
        
        for(int j = 1 ; j <= k ; j++ ){ // 상담 유형 
            //현재 k의 상담사 수 
            int curr_cnt = num_counselor[j];
            int dt = wait_time[j][curr_cnt] - wait_time[j][curr_cnt + 1];
            if(max_time < dt) // 인원 증가 대상
                max_time = dt,max_k = j;
        }
        num_counselor[max_k]++;    
    }
    
    for(int i = 1 ; i <= k ; i++){
        answer += wait_time[i][ num_counselor[i] ];
    }
    
    
    return answer;
}
