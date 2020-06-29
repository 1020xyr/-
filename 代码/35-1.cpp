#include<iostream>
#include<algorithm>

using namespace std;

struct Edge { 
	int a, b;									//����������ı��
	int cost;									//�ñߵ�Ȩֵ
}edge[6000];

int village[120];
int sum;										// ������Ȩ��֮��
int findRoot(int p) {							// �ҵ����ڵ�
	if (village[p] == p) {
		return p;
	}
	else {
		int tmp = findRoot(village[p]);
		village[p] = tmp;
		return tmp;
	}
}

void unions(Edge e) {							// ���ӽڵ�
	int pRoot = findRoot(e.a);
	int qRoot = findRoot(e.b);
	if (pRoot != qRoot) {
		village[pRoot] = qRoot;
		sum += e.cost;
	}
}
bool compare(Edge e1, Edge e2) {				// �ȽϺ���
	return e1.cost < e2.cost;
}

void func() {
	int n;
	while (cin >> n && n != 0) {
		int len = n * (n - 1) / 2;
		for (int i = 0;i < len;i++) {			// �������룬�õ���-Ȩ������
			cin >>edge[i].a>> edge[i].b >> edge[i].cost;
		}
		sort(edge + 1, edge + 1 + n * (n - 1) / 2,compare);
		sum = 0;
		for (int i = 1;i <= n;i++) {			// ��ʼ��
			village[i] = i;
		}
		for (int i = 0;i < len;i++) {
			unions(edge[i]);
		}
		cout << sum << endl;
	}
}
int main() {
	func();
	return 0;
}
