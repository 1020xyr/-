#include<iostream>
#include<vector>

using namespace std;

struct Edge {
	int to;
	int cost;
};

vector<Edge> edge[101];
bool marked[101];
int dist[101];

// ������������k�� dist[i]<=dist[k] + k��i�ľ���
void func() {
	int n, m;
	while (cin >> n >> m) {
		if (m == 0 && n == 0) {
			break;
		}
		for (int i = 1;i <= n;i++) {			// ��ʼ��
			marked[i] = false;
			dist[i] = -1;
			edge[i].clear();
		}
		for (int i = 0;i < m;i++) {				// ��������
			int p, q, cost;
			cin >> p >> q >> cost;
			Edge tmp;
			tmp.cost = cost;
			tmp.to = q;
			edge[p].push_back(tmp);
			tmp.to = p;
			edge[q].push_back(tmp);
		}
		marked[1] = true;
		dist[1] = 0;

		int v = 1;
		for (int i = 0;i < n - 1;i++) {
			for (int j = 0;j < edge[v].size();j++) {		// ˢ��dist����
				int to = edge[v][j].to;
				int cost = edge[v][j].cost;
				if (marked[to]) continue;
				int newDist = dist[v] + cost;
				if (dist[to] == -1 || newDist < dist[to]) {
					dist[to] = newDist;
				}
			}

			int min = 100000000;
			for (int j = 1;j <= n;j++) {					// ѡ��dist������С��ֵ��δ��ǣ�
				if (marked[j] || dist[j] == -1) continue;
				if (min > dist[j]) {
					min = dist[j];
					v = j;
				}
			}
			marked[v] = true;
		}
		cout << dist[n] << endl;
	}
}

int main() {
	func();
	return 0;
}