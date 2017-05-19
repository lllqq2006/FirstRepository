#include "stampProblem.h"
#include "iostream"
using namespace std;

stampProblem::stampProblem()
{
	stampsnumber = 0;
}

stampProblem::~stampProblem()
{
}

void stampProblem::init()
{
	tie = false;
	none = true;
	for (int i = 0; i < 4; i++)
	{
		now[i] = 0;
		cur[i] = 0;
	}
}

int stampProblem::getInfo(int ans[])
{
	int a = 1;
	int b = 1;
	if (ans[0] == 0)
	{
		return 0;
	}
	int c = stamps[ans[0]];

	for (int i = 1; i < 4 && ans[i] > 0; i++)
	{
		if (ans[i] != ans[i - 1]) a++;
		b++;
		c = c > stamps[ans[i]] ? c : stamps[ans[i]];
	}

	return 1000 * a + 100 * (10 - b) + c;
}

void stampProblem::compare()
{
	int a = getInfo(now);
	int b = getInfo(cur);
	if (a == b)
	{
		tie = true;
	}
	if (b > a)
	{
		tie = false;
		for (int i = 0; i < 4; i++)
		{
			now[i] = cur[i];
		}
	}
}

int stampProblem::dls(int begin, int count, int value)
{
	if (value == 0)
	{
		compare();
		none = false;
		return 1;
	}
	if (value < 0)
	{
		return 0;
	}
	if (count >= 4)
	{
		return 0;
	}

	count++;
	for (int i = begin; i < stampsnumber; i++)
	{
		cur[count - 1] = i;
		dls(i, count, value - stamps[i]);
		cur[count - 1] = 0;
	}
	return 0;
}

void stampProblem::execute()
{
	do
	{
		int input;
		stampsnumber = 1;
		while (cin >> input && input != 0)
		{
			stamps[stampsnumber] = input;
			stampsnumber++;
		}
		while (cin >> input && input != 0)
		{
			init();
			dls(1, 0, input);
			if (tie) {
				cout << input << " (" << getInfo(now) / 1000 << "): " << "tie" << endl;
			}
			else if (none) {
				cout << input << " ---- none" << endl;
			}
			else {
				cout << input << " (" << getInfo(now) / 1000 << "):";
				for (int i = 0; i < 4 && now[i] > 0; i++) {
					cout << " " << stamps[now[i]];
				}
				cout << endl;
			}
		}
	} while (getchar() != EOF);
}