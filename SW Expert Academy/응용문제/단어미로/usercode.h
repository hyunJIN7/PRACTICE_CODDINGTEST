#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <tuple>
#include <set>

#define MAX_N 30000
using namespace std;
typedef long long ll;

unordered_map<ll, int> wid; //word 해시값, id 값

unordered_map<int, set<ll>> st[5]; //부분 해시값, 해당하는 word 해시값
char words[MAX_N][12];
int dlen[MAX_N][3];

int curr_room_id;

void init()
{
	for (int i = 0; i < 5; i++) {
		st[i].clear();
		st[i].reserve(50000);
	}
	wid.clear();
	wid.reserve(50000);
}

//원래 해시값 앞쪽에 곱하지만 뭐 이거 상관 없으니까
inline int hf2(char* s) {
	return s[0] + 32 * s[1];
}

inline int hf4(char* s) {
	return s[0] + 32 * s[1] + 32 * 32 * s[2] + 32 * 32 * 32 * s[3];
}

inline int hm(char* s) {
	return s[4] + 32 * s[5] + 32 * 32 * s[6];
}

inline int hb2(char* s) {
	return s[9] + 32 * s[10];
}

inline int hb4(char* s) {
	return s[7] + 32 * s[8] + 32 * 32 * s[9] + 32 * 32 * 32 * s[10];
}

inline ll hall(char* s) {
	ll ret = 0;
	for (int i = 0; i < 11; i++) {
		ret = ret * 32 + s[i];
	}
	return ret;
}

void addRoom(int id, char mWord[], int mDirLen[])
{
	--id;
	for (int i = 0; i < 11; i++) words[id][i] = (mWord[i]-'a' + 1);
	for (int i = 0; i < 3; i++) dlen[id][i] = mDirLen[i];

	ll hash_all = hall(words[id]);
	wid[hash_all] = id;

	//대칭이루게
	st[0][hf2(words[id])].insert(hash_all);
	st[1][hf4(words[id])].insert(hash_all);
	st[2][hm(words[id])].insert(hash_all);
	st[3][hb4(words[id])].insert(hash_all);
	st[4][hb2(words[id])].insert(hash_all);
}

void setCurrent(char mWord[])
{
	for (int i = 0; i < 11; i++) mWord[i] -= 'a' - 1;
	curr_room_id = wid[hall(mWord)];
}

pair<int, int> get_type(int id, int dir) {
	int type = dlen[id][dir];
	if (dir == 0) {
		if (type == 2) return { 0, hf2(words[id]) };
		else return { 1, hf4(words[id]) };
	}
	else if (dir == 1) {
		return { 2, hm(words[id]) };
	}
	else {
		if (type == 4) return { 3, hb4(words[id]) };
		else return { 4, hb2(words[id]) };
	}
}

int moveDir(int mDir)
{
	int type, target_hash; //해시 값만 뭔지 찾는 것 
	tie(type, target_hash) = get_type(curr_room_id , mDir);

	// 대칭으로 문자열 앞에 2개랑 뒤에 2개가 같은 문자열 찾기
	set<ll> &s = st[4 - type][target_hash];
	if (s.empty()) return 0;
	
	auto it = s.begin();
	int next_id = wid[*it];
	if (next_id == curr_room_id) { 
		it++;
		if (it == s.end()) return 0;
		next_id = wid[*it];
	}
	return (curr_room_id = next_id) + 1;
}

void changeWord(char mWord[], char mChgWord[], int mChgLen[])
{
	for (int i = 0; i < 11; i++) {
		mWord[i] -= 'a' - 1;
		mChgWord[i] -= 'a' - 1;
	} 
	ll hash_all = hall(mWord);
	int id = wid[hash_all];
	st[0][hf2(mWord)].erase(hash_all);
	st[1][hf4(mWord)].erase(hash_all);
	st[2][hm(mWord)].erase(hash_all);
	st[3][hb4(mWord)].erase(hash_all);
	st[4][hb2(mWord)].erase(hash_all);

	for (int i = 0; i < 11; i++) words[id][i] = mChgWord[i];
	for (int i = 0; i < 3; i++) dlen[id][i] = mChgLen[i];
	hash_all = hall(mChgWord);
	wid[hash_all] = id;

	st[0][hf2(mChgWord)].insert(hash_all);
	st[1][hf4(mChgWord)].insert(hash_all);
	st[2][hm(mChgWord)].insert(hash_all);
	st[3][hb4(mChgWord)].insert(hash_all);
	st[4][hb2(mChgWord)].insert(hash_all);
}
