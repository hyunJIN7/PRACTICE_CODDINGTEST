#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;



vector<int> solution(vector<string> maps) {
    vector<int> answer;

    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int H=maps.size(),W=maps[0].length();
    for(int i = 0; i < H; i++){
        for(int j = 0 ; j < W ; j++){
            if(maps[i][j]=='X') continue;
            queue<pair<int,int>> que;
            que.push({i,j});   
            int cnt = maps[i][j]-'0';
            maps[i][j]='X';
            while(!que.empty()){
                auto pos = que.front();
                que.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int ny = pos.first+dy[i], nx = pos.second+dx[i];
                    if(0>ny|| ny>=H || 0>nx||nx>=W) continue;
                    if(maps[ny][nx]=='X') continue;
                    cnt += (maps[ny][nx]-'0');
                    maps[ny][nx]='X';
                    que.push({ny,nx});
                }
            }
            answer.push_back(cnt);
        }
        
    }
    
    if(!answer.size()) answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}
