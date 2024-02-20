#include <cstring>
#include <deque>
#define MAX_N 300
#define OFFSET 'a'
using namespace std;

int cnt[MAX_N+1][26];
deque<char> dp[MAX_N+1];
int H, W; // 메모장 크기
int Y, X; // 문자열 새로 추가할 다음 위치, 빈 위치 
int total_cnt;


void init(int h, int w, char mStr[])
{
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i <= MAX_N; i++) dp[i].clear(); 
	H = h, W = w;
	Y = X = 0;
	total_cnt = 0;
	while (mStr[total_cnt])
	{
		dp[total_cnt / W].push_back(mStr[total_cnt]);
		cnt[total_cnt / W][mStr[total_cnt] - OFFSET]++;
		++total_cnt;
	}
}

void insert(char mChar)
{
	//현재 커서 위치에 넣고
	dp[Y].insert(dp[Y].begin() + X , mChar);
	cnt[Y][mChar - OFFSET]++;
	
	// 한줄에 W 최대 넘으면 다음 줄로 넘기기
	for (int i = Y; dp[i].size() > W; i++) {
		char c = dp[i].back();
		cnt[i][c - OFFSET]--;		
		dp[i].pop_back();

		//다음 줄에 넣기
		dp[i + 1].push_front(c);
		cnt[i + 1][c - OFFSET]++;
	}

	total_cnt++; 
	X = (++X) % W;
	if (!X) ++Y; // 줄넘어갔나 확인
}

char moveCursor(int mRow, int mCol)
{
	--mRow, --mCol;
	if (mRow * W + mCol >= total_cnt) {
		Y = total_cnt / W;
		X = total_cnt % W;
		return '$';
	} 
	Y = mRow, X = mCol;
	return dp[Y][X];
}

int countCharacter(char mChar)
{
	int sum = 0;
	//커서 라인만 갯수 따로 
	for (int i = X; i < dp[Y].size(); i++) {
		sum += dp[Y][i] == mChar;
	}
	//뒷줄 
	int end_line = total_cnt / W;
	for (int i = Y + 1; i <= end_line; i++) {
		sum += cnt[i][mChar - OFFSET];
	}
	return sum;
}
