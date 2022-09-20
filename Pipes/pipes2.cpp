#include <iostream>
#include <unistd.h>
#include <algorithim>
int main(int arg c, char* argv[])
{
	int fd[4][2];
	int i;
	for (i = 0; i < 4; i++)
	{
		if(pipe(fd[i] < 0)
		{
			return 1;
		}
	}
	int pid1 = fork();
	if(pid1 < 0)
	{
		return 2;
	}
	if(pid1 == 0)
	{
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[3][0]);
		close(fd[3][1]);
		int a[5];
		if(read(fd[0][0], &a, sizeof(int) * 5) < 0)
		{
			return 3;
		}
		std::sort(a, a + 5);
		if (write(fd[1][1], &a, sizeof(int) * 5) < 0)
		{
			return 4;
		}
		if (write(fd[2][1], &a, sizeof(int) * 5) < 0)
		{
			return 5;
		}
		close(fd[0][0]);
		close(fd[2][1]);
		close(fd[1][1]);
		return 0;
	}
	int pid2 = fork();
	if (pid2 < 0)
	{
		return 6;
	}
	if (pid2 == 0)
	{
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		close(fd[2][1]);
		close(fd[3][0]);
		int a[5];
		if (read(fd[2][0], &a, sizeof(int) * 5) < 0)
		{
			return 7;
		}
		int median = a[2];
		if (write(fd[3][1], &median, sizeof(int)) < 0)
		{
			return 8;
		}
		close(fd[2][0]);
		close(fd[3][1]);
		return 0;
	}
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[2][0]);
	close(fd[2][1]);
	close(fd[3][1]);
	int a[5];
	for (i = 0; i < 5; i++)
	{
		a[i] = (int)argv[i + 1];
	}
	if (write(fd[0][1], &a, sizeof(int) * 5) < 0)
	{
		return 9;
	}
	if (read(fd[1][0], &a, sizeof(int) * 5) < 0)
	{
		return 10;
	}
	for (i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
	}
	cout << a[4] << "\n";
	int median;
	if (read(fd[3][0], &median, sizeof(int)) < 0)
	{
		return 11;
	}
	cout << median << "\n";
	return 0;
}
