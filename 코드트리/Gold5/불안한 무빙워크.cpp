#include <iostream>

using namespace std;

int N,K;
int moving[201];
int peopole[201];
int startIndex,endIndex;
int ckt=0; // 안정성 0 개수
int ans=0;

void Input(){
    cin>>N>>K;
    startIndex=0;
    endIndex=N-1;
    N*=2;
    for(int i = 0 ; i < N ; i++) cin>>moving[i];
}

void Solution(){
    //무빙워크 회전
    startIndex=(startIndex+N-1)%N;
    endIndex=(endIndex+N-1)%N;    


    if(peopole[endIndex]) // 무빙 워크 끝에 사람 있으면 내려 
        peopole[endIndex] = 0; 

    //무빙워크 위 사람들 한칸씩 이동 
    for(int i = endIndex ; i != startIndex ; i=(i+N-1)%N){
        if(!peopole[i] && moving[i]){
            int j = (i+N-1)%N; //이전 칸
            if(peopole[j] ) {
                
                peopole[i] = 1;
                peopole[j] = 0;
                moving[i]--;
                if(!moving[i]) ckt++;
            }
        }
    }

    if(peopole[endIndex]) // 무빙 워크 끝에 사람 있으면 내려, 여기 또 해주는게 중요!! 
        peopole[endIndex] = 0; 

    //시작 칸 사람 없으면 올리기
    if(!peopole[startIndex] && moving[startIndex]){
        peopole[startIndex]=1;
        moving[startIndex]--;
        if(!moving[startIndex]) ckt++;
    }

}

void Solve(){
    Input();
    while(ckt < K){
        Solution();
        ans++;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    Solve();

    return 0;
}
