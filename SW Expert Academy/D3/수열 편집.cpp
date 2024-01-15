#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, L;
vector<int> vec;

int main(int argc, char** argv){
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		cin >> N >> M >> L;
		for(int i = 0 ; i < N; i++){
			int num; 
			cin >> num;
			vec.push_back(num);
		}
	
		while(M--){
			char op;
			int pos, num;
			cin >> op;
			if(op =='I'){
				cin >> pos >> num;
				vec.insert(vec.begin() + pos, num);
			}
			else if(op =='D'){
				cin >> pos;
				vec.erase(vec.begin() + pos);
			}
			else if (op =='C'){
				cin >> pos >> num;
				vec[pos] = num;
			}
		}
		cout << "#" << test_case<<" " << ((vec.size() < L) ? -1 : vec[L]) <<"\n";
	}
	return 0;
}
