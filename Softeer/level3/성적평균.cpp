#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
  int N, K;
  cin >> N >> K;
  double score[N + 1] = {0,};
  for(int i = 1; i <= N ; i++){
    cin >> score[i];
    score[i] += score[i-1];
  } 
  
  while(K--){
    int from, to;
    cin >> from >> to;
    cout<<fixed;
    cout.precision(2);
    cout << (score[to] - score[from-1]) / (to - from + 1) << "\n";
  }

   return 0;
}
