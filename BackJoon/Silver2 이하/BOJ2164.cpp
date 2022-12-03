#include <iostream>
#include <queue>

using namespace std;
int N,ans;
queue<int> q;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N; 
    for(int i = 1 ; i <= N ;i++){
        q.push(i);
    }
    
    
    
    while(!q.empty()){
        if(q.size() == 1) {
            ans = q.front();
            break;
        }
        q.pop();
        int second = q.front();
        q.pop();
        q.push(second);

        
    }

    cout<<ans;
    return 0;
}
