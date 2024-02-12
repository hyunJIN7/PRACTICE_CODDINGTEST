# Segment Tree
O(log N) : point update, range query

## 구간 트리 개요
- `데이터가 연속적으로 존재`할 때, `특정 구간` 데이터를 효율적으로 계산
- `데이터 집합`이 주어지고, `특정 구간`의 합, 최대, 최소등을 구할 때 좋음
- 트리 구조
 

# SQRT Decomposition
O(√N) : 쿼리 수행 <br/>
O(1) : 갱신 

## 제곱근 분할 개요
- 원소를 sqrt(square root) 단위로 분할
- 각 그룹의 대표값 가지고 있게 한다.
  - 주어진 query가 sum이면 그룹 합이 대푯값, max 면 max가 대표
