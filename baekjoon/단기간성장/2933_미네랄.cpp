#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 100
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using Map = vector<vector<char>>;
using Minerals = vector<pair<int, int>>;

int R, C, N;
Map map(MAX, vector<char>(MAX, 'c'));
vector<int> strikes;

queue<pair<int, int>> q; 
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));


void printMap() {
	for (int i = 0; i < R-1; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	for(int j=0; j<C; j++) {
		cout << map[R-1][j];
	}
}

// x,y point의 미네랄이 떨어질 수 있는 최대 거리 반환
int calcFallingDistance(int x, int y) {
	int dist = 0;
	for (int i = y + 1; i < R; i++) {
		// 미네랄 발견
		if (map[i][x] == 'x') {
			if(!visited[i][x]) // 나와 연결된 클러스터 (계산필요없음)
				return R;
			else
				return dist;
		}
		dist++;
	}

	return dist;
}

// map 안의 index이면 true, 벗어나면 false
bool isInIndex(int x, int y) {
	if (0 <= x && x < C && 0 <= y && y < R) {
		return true;
	}
	else {
		return false;
	}
}

// DFS
// x, y point의 미네랄과 연결된 모든 미네랄을 찾아 visited에 marking한다
void markClusteredMinerals(int _x, int _y) {
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	q.push({ _x,_y });
	visited[_y][_x] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInIndex(nx, ny) && map[ny][nx] == 'x' && !visited[ny][nx]) {
				q.push({ nx,ny });
				visited[ny][nx] = true;
			}
		}

		q.pop();
	}
}

// 막대기를 던져서 처음 맞추는 미네랄 부수기
bool strike(int line, bool left) {
	if (left) {
		for (int i = 0; i < C; i++) {
			if (map[R - line][i] == 'x') {
				map[R - line][i] = '.';
				return true;
			}
		}
		return false;
	}
	else {
		for (int i = C - 1; i >= 0; i--) {
			if (map[R - line][i] == 'x') {
				map[R - line][i] = '.';
				return true;
			}
		}
		return false;
	}
}

void solution() {
	bool left = true;
	Minerals airCluster;

	for (int line : strikes) {
		// break one mineral on the line
		bool broken = strike(line, left);
		left = !left;

		// 부서진게 없으면 (변화X) 다음으로 넘어감
		if (!broken) continue;

		// check minerals that clustered from bottom
		for (int j = 0; j < C; j++) {
			if (map[R - 1][j] == 'x') {
				// mark clustered minerals from bottom
                markClusteredMinerals(j, R - 1);
			}
		}
		
		// find cluster that not from bottom(airCluster)
		// marked minerals -> clustered from bottom
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if(map[i][j] == 'x' && !visited[i][j]) {
					airCluster.push_back({j,i});
				}
			}
		}

		// calc maximum distance that airCluster can fall
		int minDist = R;
		for (auto iter : airCluster) {
			minDist = min(minDist, calcFallingDistance(iter.first, iter.second));		
		}

		// move airCluster
		// move lower-height-mineral first
		sort(airCluster.begin(), airCluster.end(), greater<pair<int,int>>());
		for (auto iter : airCluster) {
			map[iter.second][iter.first] = '.';
			map[iter.second + minDist][iter.first] = 'x';
		}

		// reset values and flags
		for(int i=0; i<R; i++)
			fill(visited[i].begin(), visited[i].end(), false);
		airCluster.clear();
	}
}

int main() {
	fastio;

	// input map
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	// input strikes of stick
	cin >> N;
    int line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		strikes.push_back(line);
	}

	solution();

	printMap();


	return 0;
}