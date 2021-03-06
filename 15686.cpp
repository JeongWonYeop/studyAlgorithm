#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <string>
#include <cstring>
using namespace std;
int N, M; // 2<= N <= 50, 1<= M <=13
int board[51][51] = { 0, };
int check[51][51] = { 0, };
int checked[51][51] = { 0, }; // 1이 표시됐는지 여부
bool visited[13];
vector <int> check_home;
typedef pair <int, int> PairInt;
vector <PairInt> vec2;
vector <PairInt> vec1;
vector <int> result;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int M_sum = 0;
int N_cnt = 0;
int ans = 987654321;
/*
	00 01
	10 11
	우,좌,상,하

	BFS를 통해서 진행했을 때, 1의 개수만큼 모두 2에 도달했을 때. M보다 2개수가 적을 때. 
	BFS를 통해서 진행했을 때, 1의 개수만큼 모두 2에 도달했을 때. M보다 2개수가 더 많을 때. 
		백트래킹 이용해서, 2개수 C M   -->  최소의 합

	각각의 집을 번호로 표시해두기.
	그래서 해당 집에서 출발한 것이 2에 닿으면 체크되게.
	
	--------------------------------

	반대로 치킨집을 먼저 선택하고 치킨집에서 집으로 BFS 하는 방법.
	해당 집의 좌표에 닿으면 해당 좌표 checked 해서 중복으로 체크되는일 없게.
	만약에 체크된 것의 개수가 집의 개수와 같다면, BFS가 종료.




*/


void enter() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				vec2.push_back({ i,j });
				board[i][j] = 0;
			}
			if (board[i][j] == 1) {
				vec1.push_back({ i,j });
			}
		}
	}

}

void debug() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << check[i][j] << " ";
		}cout << endl;
	}
	cout << endl;
}

void chi_to_home(int cnt) {
	



}

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}
int abs(int a) {
	if (a < 0) return a * -1;
	else return a;
}

int distance(PairInt a, PairInt b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int cnt,int selected) {
	if (selected == M) {
		int tempResult = 0;
		for (int i = 0; i < vec1.size(); i++) {//당연히 모두 연산돼야되는 부분
			int dist = 987654321;
			for (int j = 0; j < vec2.size(); j++) { // 선택된 치킨집만 연산돼야함.
				if(visited[j])
					dist = min(dist,distance(vec1[i], vec2[j]));
			}
			tempResult += dist;
			
		}
		ans = min(ans, tempResult);		
		return;
	}
	if (cnt == vec2.size()) return;
	//프렌차이즈 선정
	visited[cnt] = true;
	DFS(cnt + 1, selected + 1);
	//프랜차이즈 선정X
	visited[cnt] = false;
	DFS(cnt + 1, selected);

}

int main() {
	enter();
	DFS(0, 0);
	cout << ans;
}