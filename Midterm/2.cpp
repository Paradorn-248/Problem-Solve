#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	int c[k], p[k], w[k], a[n];

	for (int i = 0; i < k; i++)
	{
		cin >> c[i] >> p[i] >> w[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	long result[k];
	for (int i = 0; i < k; i++)
	{
		int count = 1;
		int weight = w[i];
		int ok = 1;

		for (int j = 0; j < n; j++)
		{
			if (a[j] > w[i])
			{
				ok = 0;
				break;
			}
			if (a[j] <= weight)
			{
				weight -= a[j];
			}
			else
			{
				count++;
				weight = w[i] - a[j];
			}
		}

		if (ok)
		{
			result[i] = c[i] + count * p[i];
		}
		else
		{
			result[i] = 0;
		}
	}

	long min = 1e9;
	for (int i = 0; i < k; i++)
	{
		if (result[i] > 0 && result[i] < min)
			min = result[i];
	}

	cout << min << endl;
}