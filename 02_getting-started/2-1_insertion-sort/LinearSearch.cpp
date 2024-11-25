#include <iostream>

using namespace std;

void LinearSearch(int &A[], int &v) {
	for (int i = 0; i < n; i++) {
		if (A[i] == v) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "NIL" << endl;
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i+++) cin >> A[i];
	int v;
	cin >> v;
	LinearSearch(A, v);
	return 0;
}