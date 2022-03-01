#include <bits/stdc++.h>
using namespace std;
char s[1005];
int ar[1005][30][30];

int cal(int now, int last)
{
	int cal = min(abs(now - last), abs(26 + last - now));
	return min(cal, abs(now + 26 - last));
}

int main()
{
	int n, yao;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		yao = 0;
		for (int a = 0; s[a] != '\0'; a++)
		{
			yao++;
		}
		for (int m = 0; m <= yao; m++)
		{
			for (int a = 1; a <= 26; a++)
			{
				for (int b = 1; b <= 26; b++)
				{
					ar[m][a][b] = 1e2;
				}
			}
		}
		ar[0][1][1] = 0;
		for (int a = 0; s[a] != '\0'; a++)
		{
			int cur = s[a] - 'A' + 1;
			// printf("%d =%d\n",cur,cal(cur,1));
			for (int b = 1; b <= 26; b++)
			{
				for (int c = 1; c <= 26; c++)
				{
					ar[a + 1][b][cur] = min(ar[a + 1][b][cur], ar[a][b][c] + cal(c, cur));
					ar[a + 1][cur][b] = min(ar[a + 1][cur][b], ar[a][c][b] + cal(c, cur));
					// printf("%d %d %d----%d\n",a+1,b,cur,ar[a+1][b][cur]);
				}
			}

		}
		int ans = 1e9;
		for (int a = 1; a <= 26; a++)
		{
			for (int b = 1; b <= 26; b++)
			{
				ans = min(ans, ar[yao][a][b]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
