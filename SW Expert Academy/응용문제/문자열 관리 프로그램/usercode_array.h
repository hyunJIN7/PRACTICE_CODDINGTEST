#include <cstring>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
constexpr int MAX_N = 243004;
constexpr int MAX_WORD_SIZE = 4;
constexpr char OFFSET = 'a';

char str[MAX_N];
bool flip;
int s, e;
int dx;
unordered_map<int, int> m;

void calcHash(int from, int to, int delta) {
	if (to < from) swap(from, to);
	//hash 값은 앞에서부터 연산 
	//delta는 hash 값 증감 표시 

	// s, e : 전체 문자열 인덱스
	// from, to : 연산 필요한 문자열 인덱스 
	for (int i = max(s, from - 3); i <= to; i++) {
		int num = 0;
		for (int j = 0; j < 4 && i + j <= e; j++) {
			num <<= 5;
			num += str[i + j] - OFFSET + 1;
			if (from <= i + j)  // 문자열 추가,삭제 시 관련 부분 값만 해시에 반영하기 위함  
				m[num] += delta;
		}
	}
}

void init(char mStr[])
{
	str[0] = { 0, };
	m.clear();
	flip = false;
	dx = 1;
	s = e = 120000; //문자열 시작, 끝 인덱스 
	for (int i = 0; mStr[i];) {
		str[e++] = mStr[i++];
	}
	e--;
	calcHash(s, e, 1);
}

void appendWord(char mWord[])
{
	//reverse 상태에선 dx = -1이라 전체 문자열에 뒤집혀 붙여짐.
	int from, to;
	(flip) ? from = to = s - 1 : from = to = e + 1;
	for (int i = 0; mWord[i]; i++) {
		str[to] = mWord[i];
		to += dx;
	}
	to -= dx; //한 칸 더 갔으니 
	flip ? s = to : e = to;
	calcHash(from, to, 1);
}

void cut(int k)
{
	if (flip) {
		calcHash(s, s + k - 1, -1);
		s += k;
	}
	else {
		calcHash(e - k + 1, e, -1);
		e -= k;
	}
}

void reverse()
{
	flip = !flip;
	dx *= -1;
}

int getHash(char* word, int size) {
	int num = 0;
	int i = (flip) ? size - 1 : 0;
	//reverse 상태라면 mWord를 뒤에서부터 해시값 계산 
	for (; word[i]; i += dx) {
		num <<= 5;
		num += word[i] - OFFSET + 1;
	}
	return num;
}

int countOccurrence(char mWord[])
{
	int hash_num = getHash(mWord, strlen(mWord));
	return m[hash_num];
}
