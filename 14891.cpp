#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include <utility>
#include <stdlib.h>
using namespace std;
//int arr[4][8];
string arr[4];
int cnt = 0;
int temp = 0;
int ans = 0;
typedef pair <int, int> PairInt;
vector <PairInt> turn_info;


void debug() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}

	cout << endl;
}

/* 1:시계방향 -1:반시계방향
시계방향
  0 1 2 3 4 5 6 7
[ 1 2 3 4 5 6 7 8 ]
[ 8 1 2 3 4 5 6 7 ]

반시계방향
  0 1 2 3 4 5 6 7
[ 1 2 3 4 5 6 7 8 ]
[ 2 3 4 5 6 7 8 1 ]
*/
void t_turn(int t_n, int orient) {
	if (orient == 1) {
//		cout << t_n + 1 << "번째 톱니바퀴 시계방향" << endl;
		int temp[8];
		for (int i = 0; i < 8; i++) {
			temp[i] = arr[t_n][i];
		}
		for (int i = 1; i < 8; i++) {
			arr[t_n][i] = temp[i - 1];
		}
		arr[t_n][0] = temp[7];
	}
	else {
//		cout <<t_n+1 << "번째 톱니바퀴 반시계방향" << endl;
		temp = arr[t_n][0];
		for (int i = 0; i < 8; i++) {
			if (i == 7) {
				arr[t_n][i] = temp;
				continue;
			}
			arr[t_n][i] = arr[t_n][i + 1];

		}
	}

}

void enter() {/*
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	*/
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	cout << arr[0][1];

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int a, b;
		cin >> a >> b;
		turn_info.push_back({ a-1,b });
	}

}
int reverse(int a) {
	return a * -1;
}
void turn(int first, int next,int pm ,int orient) {
//	debug();

	if (next < 0 || next > 3) return;
	if (pm == 0) {
		if (arr[first][6] != arr[next][2]) {
			int n_next = next - 1;
			turn(next, n_next, 0, reverse(orient));
			t_turn(next, reverse(orient));
		}
		else return;
	}
	else {
		if (arr[first][2] != arr[next][6]) {
			int n_next = next + 1;
			turn(next, n_next, 1,reverse(orient));
			t_turn(next, reverse(orient));
		}
		else return;
	}

}


void start() {
//	debug();
	vector <PairInt> ::iterator v_i = turn_info.begin();
	for (; v_i != turn_info.end(); v_i++) {
		int t_n = (*v_i).first;//톱니바퀴 숫자
		int n_t_n = t_n -1 ;
		turn(t_n, n_t_n,0, (*v_i).second);
		n_t_n = t_n + 1;
		turn(t_n, n_t_n,1, (*v_i).second);
		t_turn(t_n, (*v_i).second);
	}
}


void cal() {
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == '1') {
			if (i == 0) {
				ans = ans + 1;
			}
			else if (i == 1) {
				ans = ans + 2;
			}
			else if (i == 2) {
				ans = ans + 4;
			}
			else {
				ans = ans + 8;
			}
		}

	}

}
// N : 0  S : 1

int main() {
	enter();
	start();
	cal();
	cout << ans;
	system("pause");
}