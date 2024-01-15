#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

int N, M;
vector<int> vec;

int main(int argc, char** argv){
	int T = 10;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		cin >> N;
		for(int i = 0 ; i < N; i++){
			int num; 
			cin >> num;
			vec.push_back(num);
		}
		cin >> M;
		while(M--){
			char op;
			int pos, cnt;
			cin >> op;
			if(op =='I'){
				cin >> pos >> cnt;
				int arr[cnt];
				for(int i = 0 ; i < cnt; i++) cin >> arr[i];
				vec.insert(vec.begin() + pos, arr, arr + cnt);
			}
			else if(op =='D'){
				cin >> pos >> cnt;
				vec.erase(vec.begin() + pos, vec.begin() + pos + cnt);
			}
			else if (op =='A'){
				cin >> cnt;
				for(int i = 0 ; i < cnt; i++){
					int num;
					cin >> num;
					vec.push_back(num);
				}
			}
		}
		
		cout << "#" << test_case<<" ";
		for(int i = 0 ; i < 10 && i < vec.size(); i++)
			cout << vec[i] <<" ";
		cout << "\n";
	}
	return 0;
}
