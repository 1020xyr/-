#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

void func() {
	string tar,example,output;
	cin >> tar;
	transform(tar.begin(), tar.end(), tar.begin(), ::tolower);	// ת��ΪСд��ע��::.��ȷ�����ռ�
	int len = tar.size();
	char tmp[100];
	while (gets(tmp)) {										    // ��ȡ����
		example = tmp;											// exampleΪȫ��Сд���ַ�����outputΪ�����ַ���
		output = example;
		transform(example.begin(), example.end(), example.begin(), ::tolower);
		int index;
		while ((index = example.find(tar)) != string::npos) {	// ��������ҵ�
			example.erase(index, len);
			output.erase(index, len);
		}
		while ((index = example.find(' ')) != string::npos) {
			example.erase(index, 1);
			output.erase(index, 1);
		}
		cout << output << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
