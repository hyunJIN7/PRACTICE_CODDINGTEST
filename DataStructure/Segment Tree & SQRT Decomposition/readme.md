# Segment Tree
O(log N) : point update, range query

## 구간 트리 개요
- `데이터가 연속적으로 존재`할 때, `특정 구간` 데이터를 효율적으로 계산
- `데이터 집합`이 주어지고, `특정 구간`의 합, 최대, 최소등을 구할 때 좋음
- 트리 구조
### Top Down
- 기본 구현 방식은 Top Down
 -  배열 크기 : 4 * N
 -  lazy propagation은 top down이 더 좋음
 -  ~~top down이 bu 보다 빠른 경우는 배열 크기는 같지만 접근하는 원소의 개수가 훨씬 적은 경우??(정확하게 뭐가 더 빠른지 모르겠다. 이건 pass)~~
### Botton Up 방식이 구현 익숙해지면 더 쉽고 코드도 더 짧고 빠름.(코드에 최적화가 더 빡세게 되어 있어 시간이 더 빠름)
 -  배열 : 2의 거듭 제곱
 -  리프노드 base index = 2 ^ (ceil(logN))이라 생각해도 좋음
 -  
 

# SQRT Decomposition
O(√N) : 쿼리 수행 <br/>
O(1) : 갱신 

## 제곱근 분할 개요
- 원소를 sqrt(square root) 단위로 분할
- 각 그룹의 대표값 가지고 있게 한다.
  - 주어진 query가 sum이면 그룹 합이 대푯값, max 면 max가 대표
