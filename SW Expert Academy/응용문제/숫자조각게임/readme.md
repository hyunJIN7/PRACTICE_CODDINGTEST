# hash vector unique
- 초기 자료 구조만 잘 잡으면 된다.
- 블럭의 해시 값을 어떤 식으로 표현할 것인가 - 간단하게 블럭에서 min 값 빼서 표현하면 된다.
- map<> 으로 블럭 해시값 정보 접근하기 보다. 어차피 1<<15 이게 최대값이다. [1<<15]백터 배열 선언해서 접근하면 더 빠를 듯 하다.
