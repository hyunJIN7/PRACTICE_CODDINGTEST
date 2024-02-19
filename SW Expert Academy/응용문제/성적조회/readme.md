# Set
만능 set
문제 읽을 때 그냥 읽지 말고 정신 차리고 읽자..<br/>
반드시 들어오는 값, 분류의 기준이 되는 값이 문제 읽다보면 알아서 잘 강조해주고 있다.
-> 이 포인트를 놓치지 말자. (놓치니 코드가 드러워진다.)

## 학년, 성별 별 set + map 하나
- 코드가 깔끔하게 나온다.-
- 619ms, 14,924kb



## 전체 다 담은 set 2개 + map 하나
- 맨 처음 생각한 방식인데
- 성별로 각각 set 만든 후 set 안에 학년 > 성적 > id 값 기준으로 정렬해서 찾으려고 했는데... 오ㅑ 틀리냐... 
```cpp
#include <set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#define MAX_SCORE 300001  
#define MAX_ID 10000000001
using namespace std;

struct Student {
	int id; 
	int grade;
	int score;
	/// <summary>
	/// 학년 먼저 비교해야해!!!
	/// </summary>
	/// <param name="val"></param>
	/// <returns></returns>
	bool operator < (const Student& val) const{
		if (grade != val.grade) return grade < val.grade;
		if (score != val.score) return score < val.score;
		return id < val.id;
	}
};

static bool cmp(const Student& a, const Student& b) {
	if (a.grade != b.grade) return a.grade < b.grade;
	if (a.score != b.score) return a.score < b.score;
	return a.id < b.id;
}

set<Student> db[2]; // 성별 따로 , 성별은 분리해야해 애매해서.
unordered_map<int, tuple<int, int, int> > id_db; //성별, 학년, 점수

void init() {
	db[0].clear();
	db[1].clear();
	id_db.clear();
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	int gender = mGender[0] == 'f';
	db[gender].insert({ mId,mGrade,mScore });
	id_db[mId] = make_tuple(gender, mGrade,mScore);
	//auto cmp = [](const Student& a, const Student& b) {
	//	if (a.score != b.score) return a.score < b.score;
	//	if (a.grade != b.grade) return a.grade < b.grade;
	//	return a.id < b.id;
	//};
	auto it = lower_bound(db[gender].begin(), db[gender].end(),Student{ 0, mGrade + 1,0 },cmp);
	//다음 학년으로 검색해서 이전 학년의 끝 위치로 이동 
	if (it == db[gender].begin()) return it->id;
	return (--it)->id; // 해당 학년에 학생이 없을 린 없어.
}

int remove(int mId) {
	//remove에서 set 2개로만 id 에 해당하는 원소 찾으려고 했는데 실패
	// 새로 cmp 정의해서 기존 set에서 찾아봐도 이미 set이 기존 cmp로 정렬된 상태라
	// 원하는 값 새로운 cmp 기준으로 찾기 힘들다.
	// map이 최선으로 보인다.
	// lower_bound도 원래는 set.lower_bound(찾는값) 이렇게 찾는 게 뭐 일반적? 아무튼
	// 정확값 아닌 일부 빈값으로 찾을 경우
	// cmp 안주면 내가 set 정렬한 조건이 아닌 lower_bound 내부 정렬 기준으로 찾는다.
	// cmp 넣어주려면 이 방법 뿐. 아니면 set 원소 순서 바꾸던가.
	int gender, grade, score;
	tie(gender, grade, score) = id_db[mId];
	auto it = db[gender].lower_bound({ mId,grade,score });
	if (it == db[gender].end()) {
		printf("!! 못찾음\n");
		return 0;
	}
	id_db.erase(mId);
	db[gender].erase(it);
	it = db[gender].lower_bound({ 0,grade,0 });//  lower_bound(db[gender].begin(), db[gender].end(), Student{ 0, grade,0 }, cmp);
	if (it == db[gender].end() || it->grade != grade) return 0; //해당 학년에 학생이 없어 다른 학년 나올 수도
	return it->id;
}


int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	int id = 0, score = MAX_SCORE;

	// 다른 학년 나오면 패스 해야해.
	for (int i = 0; i < mGenderCnt; i++) { // 성별
		int gender = mGender[i][0] == 'f';
		for (int j = 0; j < mGradeCnt; j++) { // 학년 
			int grade = mGrade[j];
			auto it = lower_bound(db[gender].begin(), db[gender].end(), Student{ 0,grade, mScore }, cmp);
			if (it == db[gender].end() || it->grade != grade) continue;
			if (it->score < score) {
				score = it->score;
				id = it->id;
			}
			else if (it->score == score) id = min(id, it->id);
		}
	}
	return id;
}
```
