

# Usercode
```cpp
using namespace std;
struct user {
	int income;
	int pid;
};

user data[100002];
int size = 0;

void swap(user& a, user& b) {
	user tmp;
	tmp.income = a.income;
	tmp.pid = a.pid;
	a.income = b.income;
	a.pid = b.pid;
	b.income = tmp.income;
	b.pid = tmp.pid;
}

bool cmp(int a, int b) {
	if (data[a].income == data[b].income) return data[a].pid < data[b].pid;
	return data[a].income > data[b].income;
}

void push(int uid, int income) { // 횟수, 값 
	user& ret = data[++size];
	ret.income = income;
	ret.pid = uid;

	int index = size;
	int parent = index / 2;
	while (parent && cmp(index, parent)) {
		swap(data[index], data[parent]);
		index /= 2;
		parent = index / 2;
	}
}

void pop() {
	if (size == 0) return;

	data[1].income = data[size].income;
	data[1].pid = data[size--].pid;

	int index = 1;
	int large = 1;
	int left = index * 2;
	int right = index * 2 + 1;
	while (true) {
		if (left <= size && cmp(left, large)) large = left;
		if (right <= size && cmp(right, large)) large = right;

		if (index == large) break;

		swap(data[index], data[large]);
		index = large;
		left = index * 2;
		right = index * 2 + 1;
	}
}

void init()
{
	size = 0;
}

void addUser(int uID, int income)
{
	push(uID, income);
}

int getTop10(int result[10])
{
	user topUser[10];
	int cnt = 0;
	int curr_size = size;
	for (int i = 0; i < 10 && i < curr_size; i++) {
		result[i] = data[1].pid;
		topUser[i] = data[1];
		pop();
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		addUser(topUser[i].pid, topUser[i].income);
	}
	return cnt;
}
```
