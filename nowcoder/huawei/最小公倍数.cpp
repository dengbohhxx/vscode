#include<iostream>
using namespace std;
int gcd(int A, int B)
{
	if (A%B == 0)
		return B;
	else
		return gcd(B, A %B);
}
int main()
{
	int m = 0, n = 0;
	while (cin >> m >> n)
	{
		int d = gcd(m, n);
		if (d == 1)
			cout << m*n << endl;
		else if (d == ((m > n) ? n : m))
			cout << d << endl;
		else
			cout << m*n / d << endl;
	}
	return 0;
}