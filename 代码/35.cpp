#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int p, q;
	int weight;
	node(int p1, int q1, int w1) {
		p = p1;
		q = q1;
		weight = w1;
	}
	node(){
		p = 0;
		q = 0;
		weight =0;
	}
};
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

void unions(node n) {							// ���ӽڵ�
	int pRoot = findRoot(n.p);
	int qRoot = findRoot(n.q);
	if (pRoot != qRoot) {
		village[pRoot] = qRoot;
		sum += n.weight;
	}
}
bool compare(node n1, node n2) {				// �ȽϺ���
	return n1.weight < n2.weight;
}

void func() {
	int n;
	while (cin >> n && n != 0) {
		int len = n * (n - 1) / 2;
		vector<node> tmp(len);
		for (int i = 0;i < len;i++) {			// �������룬�õ���-Ȩ������
			int p, q, weight;
			cin >> p >> q >> weight;
			tmp[i] = node(p, q, weight);
		}
		sort(tmp.begin(), tmp.end(), compare);	// ��Ȩ�ش�С��������
		sum = 0;	
		for (int i = 1;i <= n;i++) {			// ��ʼ��
			village[i] = i;
		}
		for (int i = 0;i < len;i++) {
			unions(tmp[i]);
		}
		cout << sum << endl;
	}
}
int main() {
	func();
	return 0;
}
