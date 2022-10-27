#include<iostream>
#include<cmath>
using namespace std;
int isPrime(int);
int main()
{
    int m, n;
    cout << "Please input m,n: ";
    cin >> m >> n;
    int cnt = 0;
    while (m <= n) {
        if (isPrime(m))cnt++;
        m++;
    }
    cout << "Count=" << cnt;
}
int isPrime(int n)
{
    int count = 0;
    int i;
    if (n == 2)count = 1;
    else {
        for (i = 2; i < sqrt(n); i++) {
            if (n % i == 0) {
                count = 1;
                break;
            }
        }
    }
    return count;
}