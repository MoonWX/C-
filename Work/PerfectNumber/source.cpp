#include<iostream>
using namespace std;
long long int perfect_number(long long int);
auto main() -> int
{
	long long int m, n;
	cout << "Please input m,n: ";
	cin >> m >> n;
	int cnt = 0;
	cout << "Perfect number in [" << m << "," << n << "]:";
	while (m <= n) {
		if (perfect_number(m))
			cout << " " << m;
		m++;
	}
}
long long int perfect_number(long long int n)
{
	long long int i, sum = 0, ret = 0;
	for (i = 1; i < n; i++) {
		if (n % i == 0)sum += i;
	}
	if (sum == n)ret = 1;
	return ret;
}