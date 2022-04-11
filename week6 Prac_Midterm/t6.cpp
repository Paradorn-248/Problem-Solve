#include <bits/stdc++.h>
using namespace std;
int n, ar[100005];
int visit[100005], cnt = 0;

void re(int now, int first)
{
	if (now == first)
		return;
	visit[now] = 1;
	re(ar[now], first);
}
int main()
{
	scanf("%d", &n);
	for (int a = 1; a <= n; a++)
	{
		scanf("%d", &ar[a]);
	}
	for (int a = 1; a <= n; a++)
	{
		if (!visit[a])
		{
			re(ar[a], a);
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}