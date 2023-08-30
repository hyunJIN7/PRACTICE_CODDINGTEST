#include<vector>
#include<queue>
#include<utility>

using namespace std;

struct Node{int y,x,cnt;};
int solution(vector<vector<int> > maps)
{
    int H = maps.size(),W = maps[0].size();
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    
    bool visited[100][100]={true,0,};
    queue<Node> que;
    que.push({0,0,1});
    while(!que.empty()){
        Node cur = que.front();
        que.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int ny = cur.y+dy[i], nx =cur.x+dx[i];
            if( ny<0 || ny>=H || nx<0 || nx >=W ) continue;
            if(!maps[ny][nx] || visited[ny][nx]) continue;
            if(ny==H-1 && nx==W-1) return cur.cnt+1; 
            que.push({ny,nx,cur.cnt+1});
            visited[ny][nx] = true;
        } 
    }

    return -1;
}
