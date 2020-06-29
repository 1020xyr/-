#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct bigInteger {
	int digit[1000];
	int size;
	bigInteger() {
		for (int i = 0;i < 1000;i++) {
			digit[i] = 0;
		}
		size = 0;
	}
	void set(int x) {			//�趨��ʼֵ
		do {
			int t = x % 1000;
			digit[size] = t;
			size++;
			x = x / 1000;
		} while (x != 0);
	}
	void output() {				// ���bigInteger
		for (int i = size - 1;i >= 0;i--) {
			if (i == size - 1) {
				printf("%d", digit[i]);
			}
			else {
				printf("%3d", digit[i]);
			}
		}
		printf("\n");
	}
	bigInteger operator * (int x)const {	
		bigInteger res;
		int carry = 0;						// ��λ
		for (int i = 0;i < size;i++) {
			int tmp = x * digit[i] + carry;
			carry = tmp / 1000;
			tmp = tmp % 1000;
			res.digit[res.size] = tmp;
			res.size++;
		}
		while (carry != 0) {
			int t = carry % 1000;
			carry = carry / 1000;
			res.digit[res.size] = t;
			res.size++;
		}
		return res;
	}
	bigInteger operator / (int x)const {
		bigInteger res;
		int remainer = 0;							// ����
		for (int i = size - 1;i >= 0;i--) {
			int sum = remainer * 1000 + digit[i];
			remainer = sum % x;
			res.digit[i] = sum / x;
		}
		for (int i = 0;i < size ;i++) {				// �ҵ����һλ��Ϊ0��λ��
			if (res.digit[i] != 0) {
				res.size = i;
			}
		}
		res.size++;									// ��������λ��+1��
		return res;
	}
	int operator %(int x) const {
		int remainer = 0;
		for (int i = size - 1;i >= 0;i--) {
			remainer = (remainer * 1000 + digit[i]) % x;
		}
		return remainer;
	}
	bigInteger operator +(const bigInteger& A) const {
		bigInteger res;
		int carry = 0;								 // ��λ
		int max = size > A.size ? size : A.size;
		for (int i = 0;i < max;i++) {
			int sum = digit[i] + A.digit[i] + carry;
			carry = sum / 1000;
			res.digit[res.size] = sum % 1000;
			res.size++;
		}
		if (carry != 0) {
			res.digit[res.size] = carry;
			res.size++;
		}
		return res;
	}
};

void func() {
	int m, n;
	while (cin >> m >> n) {
		string x;
		cin >> x;
		bigInteger a, b;
		a.set(0);		// ����m������ת��������ʮ������
		b.set(1);		// Ȩ��
		int len = x.length();
		for (int i = len-1;i >=0;i--) {				// �ӵ�λ����λ
			int t;
			if (x[i] >= '0' && x[i] <= '9') {
				t = x[i] - '0';
			}
			else {
				t = x[i] - 'A' + 10;
			}
			a = a + b * t;
			b = b * m;
		}
		char ans[10000];
		int size = 0;
		do {
			int t = a % n;
			if (t < 10) {
				ans[size] = t + '0';
			}
			else {
				ans[size] = t - 10 + 'a';
			}
			size++;
			a = a / n;
		} while (a.digit[0] != 0 || a.size != 1);			// ���a��=0

		for (int i = size - 1;i >= 0;i--) {
			cout << ans[i];
		}
		cout << endl;
	}
}
int main(){
	func();
	return 0;
}
