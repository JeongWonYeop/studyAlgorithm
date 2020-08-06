#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
int N;
int board[20][20] = { 0, };
int checked[20][20] = { 0, };
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

/*
00 01
10 11
	기울이기
		방식 : 나이브
		시간제한 : O(10^8)
	합치기
		방식 : 나이브
		시간제한 : O(10^8)
	다섯번만에 얻을 수 있는 가장 큰블록 출력
		방식 : 백트래킹
		시간제한 : O(10^8)
*/
/*
	좌,우,위,아래 순서로.
	0 1 2 3
*/

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void moveblock(int x,int y,int orient) {

	int nx = x + dx[orient];
	int ny = y + dy[orient];
	if (nx < 0 || nx >= N||ny < 0 || ny >= N) {
		return;
	}
	else if (board[nx][ny] == board[x][y] && checked[nx][ny]!=1 && checked[x][y] !=1) {
		board[nx][ny] = board[x][y] * 2;
		board[x][y] = 0;
		checked[nx][ny] = 1;
		moveblock(nx, ny, orient);
	}
	else if (board[nx][ny] == 0) {
		if (checked[x][y] == 1) {
			checked[nx][ny] = 1;
			checked[x][y] = 0;
		}
		board[nx][ny] = board[x][y];
		board[x][y] = 0;
		moveblock(nx, ny, orient);
	}
}

void tilt(int orient) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			checked[i][j] = 0;
		}
	}
	if (orient == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[j][i] == 0) continue;
				else moveblock(j,i, orient);
			}
		}
	}
	else if (orient == 1) {
		for (int i = N-1; i >=0; i--) {
			for (int j = 0; j < N; j++) {
				if (board[j][i] == 0) continue;
				else moveblock(j, i, orient);
			}
		}
	}
	else if (orient == 2) {
		for (int i =0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) continue;
				else moveblock(i, j, orient);
			}
		}
	}
	else {
		for (int i = N-1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) continue;
				else moveblock(i, j, orient);
			}
		}
	}
}

void enter() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}
int maxinFive(int cnt,int arr[][20]) {
	//초기상태
	//00000부터
	//33333까지

}

int main() {
	int ans = 0;
	enter();
		
	maxinFive(1, board);
	
	//보드 초기화

	
	system("pause");
}