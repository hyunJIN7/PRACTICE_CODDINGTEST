#include <bits/stdc++.h> // stoi Çì´õ string 
#define MAX 6

using namespace std;

int N;
string plan[MAX][MAX];
bool check[MAX][MAX]={0,};


string arr[10];
set<int> ans;

int Calc(int a,int b, string op){
	if(op=="+") return a+b;
	if(op=="-") return a-b;
	return a*b;
}

void DFS(int y, int x, int index_arr){
//	cout<<y<<" "<<x<<" "<<index_arr<<endl;
	if(y==N-1 && x==N-1 && index_arr== 2*N-2){
	
		arr[index_arr] = plan[y][x];
		int num=stoi(arr[0]);
		for(int i = 0 ; i < N-1 ; i++){
			num = Calc(num , stoi(arr[(i+1)*2]), arr[i*2+1]) ;
			
		}
		ans.insert(num);
//		cout<<"!!!!!    "<<num  <<"  \n";	
		return;
	}
	
	if(y < 0 || y>= N || x<0 || x>N ||index_arr >= 2*N-1 ) return;
	
	arr[index_arr] = plan[y][x];
	DFS(y+1, x, index_arr+1);
	DFS(y, x+1, index_arr+1);
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin>>plan[i][j];
		}
	}
	DFS(0,0,0);
	

	cout<<*ans.rbegin()<<" "<<*ans.begin();
	
}
