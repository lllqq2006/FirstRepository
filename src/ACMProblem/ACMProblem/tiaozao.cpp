// ACMProblem.cpp : Defines the entry poi64 for the console application.
//
#include "iostream"
using namespace std;

typedef long long i64;
i64 PrimeFactor[10000];
i64 cur[10000];
i64 M, N, per;
int num;

i64 power(i64 M, i64 N)
{
	i64 result = 1;
	for (int i = 0; i < N; i++)
	{
		result *= M;
	}
	return result;
}

void sum_factor(i64 m)
{
	num = 0;
	i64 t = m;
	for (int i = 2; i*i <= t; i++)
	{
		if (t%i == 0)PrimeFactor[num++] = i;
		while (t%i == 0)t /= i;
	}
	if (t != 1) PrimeFactor[num++] = t;
}

void dfs(int a, int b, int c)
{
	if (b == c)
	{
		i64 t = M;
		for (int i = 0; i<c; i++)
		{
			t /= cur[i];
		}
		per += power(t, N);
	}
	else
	{
		for (int i = a; i<num; i++)
		{
			cur[b] = PrimeFactor[i];
			dfs(i + 1, b + 1, c);
		}
	}
}

int excute()
{
	do
	{
		cin >> N;
		cin >> M;

		num = 0;
		sum_factor(M);

		i64 res = power(M, N);

		for (int i = 1; i <= num; i++)
		{
			per = 0;
			dfs(0, 0, i);
			if (i % 2 == 1)
			{
				res -= per;
			}
			else
			{
				res += per;
			}
		}


		cout << res << endl;

	} while (getchar() != EOF);

	return 1;
}
