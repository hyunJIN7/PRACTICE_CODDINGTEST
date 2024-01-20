# User Code

```cpp
#include <array>
#include <algorithm>

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
#define UNIT 5

using namespace std;

struct Directory {
	long long name;
	array<int, 30> ch; // 자식의 index가 들어간다.
	int ch_cnt; //바로 하위 폴더 수
	int sub; //본인 제외 하위 폴더 수
	int par;//상위 폴더 인덱스
	Directory() {};
	Directory(long long name) {
		this->name = name;
		ch_cnt = 0;
		sub = 0;
		par = -1;
	}
};

Directory directory[50008];
int ptr = -1; //directory index
int root = 0;

int path_to_index(char path[PATH_MAXLEN + 1]) {
	// TODO :dir의 index반환 
	// 일단 다음 / 까지 현재 이름이라도 만들어 
	int parent = root;

	for (int i = 1; path[i];) { // 0 : / 건너뛰고 
		long long curr_name = 0;
		int j = i;

		while (path[j] != '/') {
			curr_name <<= UNIT;
			curr_name += (path[j] - 'a' + 1);
			j++;
		}
		//이름 한 세트 완성 후
		//부모 노드에서 현재 이름 찾기, 이분탐색으로
		int left = 0, right = directory[parent].ch_cnt - 1;
		int mid = 0; // 찾은 내 위치 
		while (left <= right) {
			mid = (left + right) / 2;
			if (directory[directory[parent].ch[mid]].name == curr_name) break;
			else if (directory[directory[parent].ch[mid]].name < curr_name) left = mid + 1;
			else right = mid - 1;
		}
		parent = directory[parent].ch[mid];
		i = j+1;
	}
	return parent;
}


void chage_sub_cnt(int idx, int dx) {
	
	while (idx != -1) {
		directory[idx].sub += dx;
		idx = directory[idx].par;
	}
}

int new_dir(long long name) { //해당 dir의 indx 반환
	directory[++ptr].name = name;
	directory[ptr].ch_cnt = 0;
	directory[ptr].sub = 0;
	directory[ptr].par = -1;
	return ptr;
}

void insertion(array<int,30> &ch, int &ch_cnt,int ch_idx) {
	//부모 인덱스나, 부모 dir 주는 대신 이렇게 주는게 좀 더 빠를 듯 
	//일단 맨 뒤에 넣고 앞으로 비교하며 넣기 
	// 이름 기준 오름 차순으로 index 넣어주기 
	
	ch[ch_cnt] = ch_idx;
	ch_cnt++;
	for (int i = ch_cnt - 1; i; i--) {
		if (directory[ch[i - 1]].name  > directory[ch[i]].name ) 
			swap(ch[i], ch[i - 1]);
		else break;
	}
}

void init(int n) {
	ptr = -1;
	root = new_dir(0); //root "/" 생성
	directory[root].par = -1;
	//ptr = -1;
	//부모 0으로 해야하나?
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
	long long new_name = 0;
	for (int i = 0; name[i]; i++) { //TODO " 조건 바꾸기
		new_name <<= UNIT; // UNIT = 5 
		new_name += (name[i] - 'a' + 1); //TODO :0부터 시작 1 더해?
	}
	int new_idx = new_dir(new_name);
	int par_idx = path_to_index(path);
	directory[new_idx].par = par_idx;
	//이제 부모 노드 자식 목록에 넣고
	insertion(directory[par_idx].ch, directory[par_idx].ch_cnt, new_idx);
	// sub 개수 올려주기 위해 chage sub 부르고 
	chage_sub_cnt(par_idx, 1); //
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
	//간선 끊기
	//1번 제약 때문에 이걸 실행해도 ptr 땡겨주고 그럴 필요가 없는건가봐.
	int idx = path_to_index(path);
	int par_idx = directory[idx].par;
	
	// 형제 중 내 위치 찾고 땡겨주고
	// dir 이름 기준 오름차순으로 정렬된 상태 
	int left = 0, right = directory[par_idx].ch_cnt - 1;
	int mid = 0; // 부모 ch에서 내 위치 
	while (left <= right) {
		mid = (left + right) / 2;
		long long mid_name = directory[directory[par_idx].ch[mid]].name;
		if (mid_name == directory[idx].name) break;
		else if (mid_name < directory[idx].name) left = mid + 1;
		else right = mid - 1;
	}
	//TODO : 안바뀜
	while(mid < directory[par_idx].ch_cnt - 1) {
		directory[par_idx].ch[mid] = directory[par_idx].ch[mid+1];
		mid++;
	}
	directory[par_idx].ch_cnt--;
	//부모 노드랑 현재 sub 수 관리 
	chage_sub_cnt(par_idx, -directory[idx].sub-1);
}

int deep_copy(int origin) {
	int new_idx = new_dir(directory[origin].name);
	directory[new_idx].ch_cnt = directory[origin].ch_cnt;
	directory[new_idx].sub = directory[origin].sub;
	directory[new_idx].par = -1;
	for (int i = 0; i < directory[new_idx].ch_cnt; i++) {
		int ch_idx = deep_copy(directory[origin].ch[i]);
		directory[ch_idx].par = new_idx;
		directory[new_idx].ch[i] = ch_idx;
		//TODO : !!!!!!!!!!!!!
	}
	return new_idx;
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	int idx = path_to_index(srcPath);
	int par_idx = path_to_index(dstPath);

	//idx 하위 자식들 가면서 node 만드록 연결하고 
	//부모 연결
	int new_idx = deep_copy(idx);//new_dir(directory[idx].name);
	directory[new_idx].par = par_idx;
	insertion(directory[par_idx].ch, directory[par_idx].ch_cnt, new_idx);
	chage_sub_cnt(par_idx, directory[idx].sub + 1);
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	int idx = path_to_index(srcPath);
	int par_idx = path_to_index(dstPath);
	cmd_rm(srcPath);
	insertion(directory[par_idx].ch ,directory[par_idx].ch_cnt, idx);
	chage_sub_cnt(par_idx, directory[idx].sub + 1);
	directory[idx].par = par_idx;
	//원래 간선 끊기
	//cmd_rm(srcPath);
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
	return directory[path_to_index(path)].sub;
}
```
