#include<iostream>
#include<queue>
using namespace std;
struct state {
	int capacity[3];									// Ϊ�˷��㸳ֵ �ֱ��ʾ��������������
	int cnt;
	state(int s1, int m1, int n1, int cnt1) {
		capacity[0] = s1;
		capacity[1] = m1;
		capacity[2] = n1;
		cnt = cnt1;
	}
};
int go[][2] = {											// ���ĸ�ƿ�ӵ����ĸ�ƿ��
	 0,1,
	 0,2,
	 1,0,
	 1,2,
	 2,0,
	 2,1
};
const int maxn = 101;
bool marked[maxn][maxn][maxn];
queue<state> Q;
int S, M, N;
int MaxCapacity[3];										// 3���������������
void printState(state st) {
	cout << st.capacity[0] << " " << st.capacity[1] << " " << st.capacity[2];
	cout << " " << st.cnt << endl;
}
void add(int from, int to, state st) {
	state st1 = st;										// ����֮���״̬
	if (st1.capacity[from] == 0) return;				// ���ǰһ��ƿ���ǿյ�
	if (st1.capacity[to] == MaxCapacity[to]) return;	// �����һ��ƿ��������
	int sum = st1.capacity[from] + st1.capacity[to];	
		if (sum <= MaxCapacity[to]) {					// ǰһ��ƿȫ�������һ��ƿ��
			st1.capacity[to] = sum;
			st1.capacity[from] = 0;
		}
		else {											// ����Ϊֹ
			st1.capacity[to] = MaxCapacity[to];
			st1.capacity[from] = sum - MaxCapacity[to];
		}
		st1.cnt++;
		int s = st1.capacity[0];
		int m = st1.capacity[1];
		int n = st1.capacity[2];
		if (!marked[s][m][n]) {
			marked[s][m][n] = true;
			Q.push(st1);
		}
}
void func() {
	while (cin >> S >> M >> N) {
		if (S + M + N == 0) {
			break;
		}
		if (M == N) {								// ������������Ⱦ�Ϊ����ƿ��һ��,�����һ�������ﵹ����
			cout << 1 << endl;
			continue;
		}
		if (S % 2 != 0) {							// ����ƿΪ���������ܾ���
			cout << "NO" << endl;
			continue;
		}
		if (M < N) {								// ����M����N�������ж��Ƿ�ɹ� (һ����M���Ϳ���ƿ��һ�룩
			int tmp = M;
			M = N;
			N = tmp;
		}
		MaxCapacity[0] = S;							// �����±� 0 ����ƿ 1 M���� 2 N����
		MaxCapacity[1] = M;							// ���±����ɱ���ܶ����ƴ���
		MaxCapacity[2] = N;
		for (int i = 0;i <= S;i++) {
			for (int j = 0;j <= M;j++) {
				for (int k = 0;k <= N;k++) {
					marked[i][j][k] = false;
				}
			}
		}
		while (!Q.empty()) Q.pop();					// ��ն���
		Q.push(state(S, 0, 0, 0));
		marked[S][0][0] = true;
		int flag = false;							// ��¼�Ƿ��ҵ��������ֿ���ƿ
		while (!Q.empty()) {
			state st = Q.front();
			Q.pop();
			int m = st.capacity[1];
			int n = st.capacity[2];	
			if (m == S / 2 && n == 0) {				// ���ֵ�Ψһ����
				cout << st.cnt << endl;
				flag = true;
				break;
			}
			for (int i = 0;i < 6;i++) {				// ö���������
				add(go[i][0], go[i][1], st);
			}
		}
		if (flag == false) {
			cout << "NO" << endl;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	func();
	return 0;
}
