#pragma once
class stampProblem
{
public:
	stampProblem();
	~stampProblem();

	void execute();	
	int dls(int begin, int count, int value);
	int getInfo(int ans[]);
	void compare();
	void init();


private:

	int stampsnumber;
	int stamps[200];
	int now[4];
	int cur[4];
	bool tie, none;

};

