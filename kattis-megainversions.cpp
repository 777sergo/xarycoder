#include <iostream>
#define ll long long
#define midd mid+1
#define poss pos*2
using namespace std;

int arr[100005];
int inver[100005];
int outver[100005];
int t[400005];
int arr1[100005];
int prr[100005];

void build(int l, int r, int pos)
{
	t[pos] = 0;
	if (l == r)
	{
		prr[l] = pos;
		return;
	}
	ll mid = (l + r) / 2;
	build(l, mid, poss);
	build(midd, r, poss + 1);
}
int sum(int ql, int qr, int l, int r, int pos)
{
	if (l == ql && r == qr)
	{
		return t[pos];
	}
	ll mid = (l + r) / 2;
	if (qr <= mid)
	{
		return sum(ql, qr, l, mid, poss);
	}
	if (ql > mid)
	{
		return sum(ql, qr, midd, r, poss + 1);
	}
	return sum(ql, mid, l, mid, poss) + sum(midd, qr, midd, r, poss + 1);
}
void update(int pos)
{
	while (pos)
	{
		t[pos]++;
		pos /= 2;
	}
}
int main()
{
	int i, j, k, m, n;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr1[arr[i] - 1]++;
		inver[i] = sum(arr[i], n - 1, 0, n - 1, 1);
		update(prr[arr[i] - 1]);
	}
	for (i = 0; i < n; i++)
	{
		arr1[i] = 0;
	}
	build(0, n - 1, 1);
	for (i = n - 1; i >= 0; i--)
	{
		arr1[arr[i] - 1]++;
		outver[i] = sum(0, arr[i] - 2, 0, n - 1, 1);
		update(prr[arr[i] - 1]);
	}
	ll res = 0;
	for (i = 0; i < n; i++)
	{
		res += inver[i] * outver[i];
	}
	cout << res;

	return 0;
}