#include<iostream>
using namespace std;
int perfectNumber(int);
int main()
{
	int m, n;
	cout << "Please input m,n: ";
	cin >> m >> n;
	int cnt = 0;
	cout << "Perfect number in [" << m << "," << n << "]:";
	while (m <= n) {
		if (perfectNumber(m))
			cout << " " << m;
		m++;
	}
}
int perfectNumber(int n)
{
	int i, sum = 0, ret = 0;
	for (i = 1; i < n; i++) {
		if (n % i == 0)sum += i;
	}
	if (sum == n)ret = 1;
	return ret;
}