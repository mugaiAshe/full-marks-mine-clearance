#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/********************************************************************************/
/********************************将学生的代码添加到下面******************************/

void machine(int GamePanel[30][30], int n, int m, int &x, int &y)
{
	if(GamePanel[0][0]==-1)
	{
		x=0;y=0;
		return;
	}
	int flag[22][22] = { 0 };          //给地图上的地雷插旗，0-1 
	int ceil[22][22] = { -1 };    //计算未打开格子个数，-1/0-8
	int mine[22][22] = { -1 };             //计算周围已插旗个数
	for (int i = 0; i < 22; i++)               //简单情况判断计算返回
	{
		for (int j = 0; j < 22; j++)
		{
			flag[i][j] = 0;
			ceil[i][j] = -1;
			mine[i][j] = -1;
		}
	}

	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			if (GamePanel[i][j] != -1)
			{
				int count = 0;
				if (GamePanel[i + 1][j] == -1)
					count++;
				if (GamePanel[i][j + 1] == -1)
					count++;
				if (GamePanel[i - 1][j] == -1)
					count++;
				if (GamePanel[i][j - 1] == -1)
					count++;
				if (GamePanel[i + 1][j + 1] == -1)
					count++;
				if (GamePanel[i + 1][j - 1] == -1)
					count++;
				if (GamePanel[i - 1][j + 1] == -1)
					count++;
				if (GamePanel[i - 1][j - 1] == -1)
					count++;
				ceil[i + 1][j + 1] = count;
				if (count == GamePanel[i][j])   //插旗 
				{
					mine[i + 1][j + 1] = GamePanel[i][j];
					if (GamePanel[i + 1][j] == -1)
						flag[i + 2][j + 1] = 1;
					if (GamePanel[i][j + 1] == -1)
						flag[i + 1][j + 2] = 1;
					if (GamePanel[i - 1][j] == -1)
						flag[i][j + 1] = 1;
					if (GamePanel[i][j - 1] == -1)
						flag[i + 1][j] = 1;
					if (GamePanel[i + 1][j + 1] == -1)
						flag[i + 2][j + 2] = 1;
					if (GamePanel[i + 1][j - 1] == -1)
						flag[i + 2][j] = 1;
					if (GamePanel[i - 1][j + 1] == -1)
						flag[i][j + 2] = 1;
					if (GamePanel[i - 1][j - 1] == -1)
						flag[i][j] = 1;
				}
			}
		}
	}

	for (int j = 1; j < 19; j++)
	{
		if (GamePanel[0][j] != -1)
		{
			int count = 0;
			if (GamePanel[1][j] == -1)
				count++;
			if (GamePanel[0][j + 1] == -1)
				count++;
			if (GamePanel[1][j + 1] == -1)
				count++;
			if (GamePanel[1][j - 1] == -1)
				count++;
			if (GamePanel[0][j - 1] == -1)
				count++;
			ceil[1][j + 1] = count;
			if (count == GamePanel[0][j])
			{
				mine[1][j + 1] = GamePanel[0][j];
				if (GamePanel[1][j] == -1)
					flag[2][j + 1] = 1;
				if (GamePanel[0][j + 1] == -1)
					flag[1][j + 2] = 1;
				if (GamePanel[1][j + 1] == -1)
					flag[2][j + 2] = 1;
				if (GamePanel[1][j - 1] == -1)
					flag[2][j] = 1;
				if (GamePanel[0][j - 1] == -1)
					flag[1][j] = 1;
			}
		}
	}
	for (int j = 1; j < 19; j++)
	{
		if (GamePanel[19][j] != -1)
		{
			int count = 0;
			if (GamePanel[18][j] == -1)
				count++;
			if (GamePanel[19][j + 1] == -1)
				count++;
			if (GamePanel[18][j + 1] == -1)
				count++;
			if (GamePanel[18][j - 1] == -1)
				count++;
			if (GamePanel[19][j - 1] == -1)
				count++;
			ceil[20][j + 1] = count;
			if (count == GamePanel[19][j])
			{
				mine[20][j + 1] = GamePanel[19][j];
				if (GamePanel[18][j] == -1)
					flag[19][j + 1] = 1;
				if (GamePanel[19][j + 1] == -1)
					flag[20][j + 2] = 1;
				if (GamePanel[18][j + 1] == -1)
					flag[19][j + 2] = 1;
				if (GamePanel[18][j - 1] == -1)
					flag[19][j] = 1;
				if (GamePanel[19][j - 1] == -1)
					flag[20][j] = 1;
			}
		}
	}
	for (int i = 1; i < 19; i++)
	{
		if (GamePanel[i][0] != -1)
		{
			int count = 0;
			if (GamePanel[i + 1][0] == -1)
				count++;
			if (GamePanel[i][1] == -1)
				count++;
			if (GamePanel[i - 1][0] == -1)
				count++;
			if (GamePanel[i - 1][1] == -1)
				count++;
			if (GamePanel[i + 1][1] == -1)
				count++;
			ceil[i + 1][1] = count;
			if (count == GamePanel[i][0])
			{
				mine[i + 1][1] = GamePanel[i][0];
				if (GamePanel[i + 1][0] == -1)
					flag[i + 2][1] = 1;
				if (GamePanel[i][1] == -1)
					flag[i + 1][2] = 1;
				if (GamePanel[i - 1][0] == -1)
					flag[i][1] = 1;
				if (GamePanel[i - 1][1] == -1)
					flag[i][2] = 1;
				if (GamePanel[i + 1][1] == -1)
					flag[i + 2][2] = 1;
			}
		}
	}
	for (int i = 1; i < 19; i++)
	{
		if (GamePanel[i][19] != -1)
		{
			int count = 0;
			if (GamePanel[i + 1][19] == -1)
				count++;
			if (GamePanel[i][18] == -1)
				count++;
			if (GamePanel[i - 1][19] == -1)
				count++;
			if (GamePanel[i - 1][18] == -1)
				count++;
			if (GamePanel[i + 1][18] == -1)
				count++;
			ceil[i + 1][20] = count;
			if (count == GamePanel[i][19])
			{
				mine[i + 1][20] = GamePanel[i][19];
				if (GamePanel[i + 1][19] == -1)
					flag[i + 2][20] = 1;
				if (GamePanel[i][18] == -1)
					flag[i + 1][19] = 1;
				if (GamePanel[i - 1][19] == -1)
					flag[i][20] = 1;
				if (GamePanel[i - 1][18] == -1)
					flag[i][19] = 1;
				if (GamePanel[i + 1][18] == -1)
					flag[i + 2][19] = 1;
			}
		}
	}
	int temp1 = 0;//计数（0,0）
	if (GamePanel[0][0] != -1)
	{
		if (GamePanel[1][0] == -1)
			temp1++;
		if (GamePanel[0][1] == -1)
			temp1++;
		if (GamePanel[1][1] == -1)
			temp1++;
		ceil[1][1] = temp1;
		if (temp1 == GamePanel[0][0])
		{
			mine[1][1] = GamePanel[0][0];
			if (GamePanel[1][0] == -1)
				flag[2][1] = 1;
			if (GamePanel[0][1] == -1)
				flag[1][2] = 1;
			if (GamePanel[1][1] == -1)
				flag[2][2] = 1;
		}
	}
	if (GamePanel[19][0] != -1)
	{
		temp1 = 0; //计数（n-1,0）
		if (GamePanel[18][0] == -1)
			temp1++;
		if (GamePanel[19][1] == -1)
			temp1++;
		if (GamePanel[18][1] == -1)
			temp1++;
		ceil[20][1] = temp1;
		if (temp1 == GamePanel[19][0])
		{
			mine[20][1] = GamePanel[19][0];
			if (GamePanel[18][0] == -1)
				flag[19][1] = 1;
			if (GamePanel[19][1] == -1)
				flag[20][2] = 1;
			if (GamePanel[18][1] == -1)
				flag[19][2] = 1;
		}
	}
	if (GamePanel[0][19] != -1)
	{
		temp1 = 0;//计数（0,m-1）
		if (GamePanel[1][m - 1] == -1)
			temp1++;
		if (GamePanel[0][m - 2] == -1)
			temp1++;
		if (GamePanel[1][m - 2] == -1)
			temp1++;
		ceil[1][20] = temp1;
		if (temp1 == GamePanel[0][m - 1])
		{
			mine[1][20] = GamePanel[0][m - 1];
			if (GamePanel[1][m - 1] == -1)
				flag[2][m] = 1;
			if (GamePanel[0][m - 2] == -1)
				flag[1][m - 1] = 1;
			if (GamePanel[1][m - 2] == -1)
				flag[2][m - 1] = 1;
		}
		temp1 = 0;//计数（n-1,m-1）
		if (GamePanel[n - 2][m - 1] == -1)
			temp1++;
		if (GamePanel[n - 1][m - 2] == -1)
			temp1++;
		if (GamePanel[n - 2][m - 2] == -1)
			temp1++;
		ceil[20][20] = temp1;
		if (temp1 == GamePanel[n - 1][m - 1])
		{
			mine[n][m] = GamePanel[n - 1][m - 1];
			if (GamePanel[n - 2][m - 1] == -1)
				flag[n - 1][m] = 1;
			if (GamePanel[n - 1][m - 2] == -1)
				flag[n][m - 1] = 1;
			if (GamePanel[n - 2][m - 2] == -1)
				flag[n - 1][m - 1] = 1;
		}
	}
	
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			if (GamePanel[i - 1][j - 1] > 0 )
			{
				int count = 0;
				if (flag[i + 1][j] == 1)
					count++;
				if (flag[i][j + 1] == 1)
					count++;
				if (flag[i - 1][j] == 1)
					count++;
				if (flag[i][j - 1] == 1)
					count++;
				if (flag[i + 1][j + 1] == 1)
					count++;
				if (flag[i + 1][j - 1] == 1)
					count++;
				if (flag[i - 1][j + 1] == 1)
					count++;
				if (flag[i - 1][j - 1] == 1)
					count++;
				mine[i][j] = count;
				if (mine[i][j] == GamePanel[i - 1][j - 1])
				{
					if (i == 1)
					{
						if (j == 1)
						{
							if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
							{
								x = i; y = j - 1;
								return;
							}
							if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
							{
								x = i - 1; y = j;
								return;
							}
							if (GamePanel[i][j] == -1 && flag[i + 1][j + 1] == 0)
							{
								x = i; y = j;
								return;
							}
						}
						else if (j == 20)
						{
							if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
							{
								x = i; y = j - 1;
								return;
							}
							if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
							{
								x = i - 1; y = j - 2;
								return;
							}
							if (GamePanel[i][j - 2] == -1 && flag[i + 1][j - 1] == 0)
							{
								x = i; y = j - 2;
								return;
							}
						}
						else {
							if (GamePanel[1][j - 1] == -1 && flag[2][j] == 0)
							{
								x = 1; y = j - 1;
								return;
							}
							if (GamePanel[0][j] == -1 && flag[1][j + 1] == 0)
							{
								x = 0; y = j;
								return;
							}
							if (GamePanel[0][j - 2] == -1 && flag[1][j - 1] == 0)
							{
								x = 0; y = j - 2;
								return;
							}
							if (GamePanel[1][j] == -1 && flag[2][j + 1] == 0)
							{
								x = 1; y = j;
								return;
							}
							if (GamePanel[1][j - 2] == -1 && flag[2][j - 1] == 0)
							{
								x = 1; y = j - 2;
								return;
							}
						}
					}
					else if (i == 20)
					{
						if (j == 1)
						{
							if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
							{
								x = i - 1; y = j;
								return;
							}
							if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
							{
								x = i - 2; y = j - 1;
								return;
							}
							if (GamePanel[i - 2][j] == -1 && flag[i - 1][j + 1] == 0)
							{
								x = i - 2; y = j;
								return;
							}
						}
						else if (j == 20)
						{
							if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
							{
								x = i - 2; y = j - 1;
								return;
							}
							if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
							{
								x = i - 1; y = j - 2;
								return;
							}
							if (GamePanel[i - 2][j - 2] == -1 && flag[i - 1][j - 1] == 0)
							{
								x = i - 2; y = j - 2;
								return;
							}
						}
						else {
							if (GamePanel[18][j - 1] == -1 && flag[19][j] == 0)
							{
								x = 18; y = j - 1;
								return;
							}
							if (GamePanel[19][j] == -1 && flag[20][j + 1] == 0)
							{
								x = 19; y = j;
								return;
							}
							if (GamePanel[19][j - 2] == -1 && flag[20][j - 1] == 0)
							{
								x = 19; y = j - 2;
								return;
							}
							if (GamePanel[18][j] == -1 && flag[19][j + 1] == 0)
							{
								x = 18; y = j;
								return;
							}
							if (GamePanel[18][j - 2] == -1 && flag[19][j - 1] == 0)
							{
								x = 18; y = j - 2;
								return;
							}
						}
					}
					else if (j == 1)
					{
						if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
						{
							x = i; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
						{
							x = i - 1; y = j;
							return;
						}
						if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
						{
							x = i - 2; y = j - 1;
							return;
						}
						if (GamePanel[i][j] == -1 && flag[i + 1][j + 1] == 0)
						{
							x = i; y = j;
							return;
						}
						if (GamePanel[i - 2][j] == -1 && flag[i - 1][j + 1] == 0)
						{
							x = i - 2; y = j;
							return;
						}
					}
					else if (j == 20)
					{
						if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
						{
							x = i; y = j - 1;
							return;
						}
						if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
						{
							x = i - 2; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
						{
							x = i - 1; y = j - 2;
							return;
						}
						if (GamePanel[i][j - 2] == -1 && flag[i + 1][j - 1] == 0)
						{
							x = i; y = j - 2;
							return;
						}
						if (GamePanel[i - 2][j - 2] == -1 && flag[i - 1][j - 1] == 0)
						{
							x = i - 2; y = j - 2;
							return;
						}
					}
					else {//normal
						if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
						{
							x = i; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
						{
							x = i - 1; y = j;
							return;
						}
						if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
						{
							x = i - 2; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
						{
							x = i - 1; y = j - 2;
							return;
						}
						if (GamePanel[i][j] == -1 && flag[i + 1][j + 1] == 0)
						{
							x = i; y = j;
							return;
						}
						if (GamePanel[i][j - 2] == -1 && flag[i + 1][j - 1] == 0)
						{
							x = i; y = j - 2;
							return;
						}
						if (GamePanel[i - 2][j] == -1 && flag[i - 1][j + 1] == 0)
						{
							x = i - 2; y = j;
							return;
						}
						if (GamePanel[i - 2][j - 2] == -1 && flag[i - 1][j - 1] == 0)
						{
							x = i - 2; y = j - 2;
							return;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<19;i++)//1-18
	{
		for(int j=1;j<21;j++)//1-20
		{
			if((GamePanel[i-1][j-1]>0)&&GamePanel[i][j-1]>0)
			{
			if((i==1)||(((j==1)||(flag[i-1][j-1]==1)||(GamePanel[i-2][j-2]!=-1))&&((flag[i-1][j]==1)||(GamePanel[i-2][j-1]!=-1))&&((j==20)||(flag[i-1][j+1]==1)||(GamePanel[i-2][j]!=-1))))
			{
				int count=0;
				for(int i1=i-1;i1<i+2;i1++)
				{
					for(int j1=j-1;j1<j+2;j1++)
					{
						if(j1==j&&i1==i)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i][j]=count;
				count=0;
				for(int i1=i;i1<i+3;i1++)
				{
					for(int j1=j-1;j1<j+2;j1++)
					{
						if(j1==j&&i1==i+1)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i+1][j]=count;
			
			if(mine[i][j]!=GamePanel[i-1][j-1])
			{
				if(GamePanel[i][j-1]-mine[i+1][j]>GamePanel[i-1][j-1]-mine[i][j])
				{
					if(GamePanel[i][j-1]-GamePanel[i-1][j-1]==ceil[i+1][j]-ceil[i][j])
					{
						if(GamePanel[i+1][j-1]==-1)
						flag[i+2][j]=1;
						if((j!=1)&&(GamePanel[i+1][j-2]==-1))
						flag[i+2][j-1]=1;
						if((j!=20)&&(GamePanel[i+1][j]==-1))
						flag[i+2][j+1]=1;
					}
				}
				else if(GamePanel[i][j-1]-mine[i+1][j]==GamePanel[i-1][j-1]-mine[i][j])
				{
					if((GamePanel[i+1][j-1]==-1)&&flag[i+2][j]==0)
					{
						x=i+1;y=j-1;
						return;
					}
					if((j!=1)&&(GamePanel[i+1][j-2]==-1)&&flag[i+2][j-1]==0)
					{
						x=i+1;y=j-2;
						return;
					}
					if((j!=20)&&(GamePanel[i+1][j]==-1)&&flag[i+2][j+1]==0)
					{
						x=i+1;y=j;
						return;
					}
				}
			}
			}
		}}
	}
	
	for(int i=3;i<21;i++)//3-20
	{
		for(int j=1;j<21;j++)//1-20
		{
			if((GamePanel[i-1][j-1]>0)&&GamePanel[i-2][j-1]>0)
			{
			if((i==20)||(((j==1)||(flag[i+1][j-1]==1)||(GamePanel[i][j-2]!=-1))&&((flag[i+1][j]==1)||(GamePanel[i][j-1]!=-1))&&((j==20)||(flag[i+1][j+1]==1)||(GamePanel[i][j]!=-1))))
			{
				int count=0;
			for(int i1=i-1;i1<i+2;i1++)
				{
					for(int j1=j-1;j1<j+2;j1++)
					{
						if(j1==j&&i1==i)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i][j]=count;
				count=0;
				for(int i1=i-2;i1<i+1;i1++)
				{
					for(int j1=j-1;j1<j+2;j1++)
					{
						if(j1==j&&i1==i-1)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i-1][j]=count;
			
			if(mine[i][j]!=GamePanel[i-1][j-1])
			{
				if(GamePanel[i-2][j-1]-mine[i-1][j]>GamePanel[i-1][j-1]-mine[i][j])
				{
					if(GamePanel[i-2][j-1]-GamePanel[i-1][j-1]==ceil[i-1][j]-ceil[i][j])
					{
						if(GamePanel[i-3][j-1]==-1)
						flag[i-2][j]=1;
						if((j!=1)&&(GamePanel[i-3][j-2]==-1))
						flag[i-2][j-1]=1;
						if((j!=20)&&(GamePanel[i-3][j]==-1))
						flag[i-2][j+1]=1;
					}
				}
				else if(GamePanel[i-2][j-1]-mine[i-1][j]==GamePanel[i-1][j-1]-mine[i][j])
				{
					if((GamePanel[i-3][j-1]==-1)&&flag[i-2][j]==0)
					{
						x=i-3;y=j-1;
						return;
					}
					if((j!=1)&&(GamePanel[i-3][j-2]==-1)&&flag[i-2][j-1]==0)
					{
						x=i-3;y=j-2;
						return;
					}
					if((j!=20)&&(GamePanel[i-3][j]==-1)&&flag[i-2][j+1]==0)
					{
						x=i-3;y=j;
						return;
					}
				}
			}
			}
		}}
	}
	
	for(int j=3;j<21;j++)//3-20
	{
		for(int i=1;i<21;i++)//1-20
		{
			if((GamePanel[i-1][j-1]>0)&&GamePanel[i-1][j-2]>0)
			{
			if((j==20)||(((i==1)||(flag[i-1][j+1]==1)||(GamePanel[i-2][j]!=-1))&&((flag[i][j+1]==1)||(GamePanel[i-1][j]!=-1))&&((i==20)||(flag[i+1][j+1]==1)||(GamePanel[i][j]!=-1))))
			{
				int count=0;
				for(int i1=i-1;i1<i+2;i1++)
				{
					for(int j1=j-1;j1<j+2;j1++)
					{
						if(j1==j&&i1==i)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i][j]=count;
				count=0;
				for(int i1=i-1;i1<i+2;i1++)
				{
					for(int j1=j-2;j1<j+1;j1++)
					{
						if(j1==j-1&&i1==i)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i][j-1]=count;
			
			if(mine[i][j]!=GamePanel[i-1][j-1])
			{
				if(GamePanel[i-1][j-2]-mine[i][j-1]>GamePanel[i-1][j-1]-mine[i][j])
				{
					if(GamePanel[i-1][j-2]-GamePanel[i-1][j-1]==ceil[i][j-1]-ceil[i][j])
					{
						if(GamePanel[i-1][j-3]==-1)
						flag[i][j-2]=1;
						if((i!=1)&&(GamePanel[i-2][j-3]==-1))
						flag[i-1][j-2]=1;
						if((i!=20)&&(GamePanel[i][j-3]==-1))
						flag[i+1][j-2]=1;
					}
				}
				else if(GamePanel[i-1][j-2]-mine[i][j-1]==GamePanel[i-1][j-1]-mine[i][j])
				{
					if((GamePanel[i-1][j-3]==-1)&&flag[i][j-2]==0)
					{
						x=i-1;y=j-3;
						return;
					}
					if((i!=1)&&(GamePanel[i-2][j-3]==-1)&&flag[i-1][j-2]==0)
					{
						x=i-2;y=j-3;
						return;
					}
					if((i!=20)&&(GamePanel[i][j-3]==-1)&&flag[i+1][j-2]==0)
					{
						x=i;y=j-3;
						return;
					}
				}
			}
			}
		}}
	}
	
	for(int j=1;j<19;j++)//1-18
	{
		for(int i=1;i<21;i++)//1-20
		{
			if((GamePanel[i-1][j-1]>0)&&GamePanel[i-1][j]>0)
			{
			if((j==1 )||(((i==1)||(flag[i-1][j-1]==1)||(GamePanel[i-2][j-2]!=-1))&&((flag[i][j-1]==1)||(GamePanel[i-1][j-2]!=-1))&&((i==20)||(flag[i+1][j-1]==1)||(GamePanel[i][j-2]!=-1))))
			{
				int count=0;
				for(int i1=i-1;i1<i+2;i1++)
				{
					for(int j1=j-1;j1<j+2;j1++)
					{
						if(j1==j&&i1==i)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i][j]=count;
				count=0;
				for(int i1=i-1;i1<i+2;i1++)
				{
					for(int j1=j;j1<j+3;j1++)
					{
						if(j1==j+1&&i1==i)
						continue;
						if(flag[i1][j1]==1)
						count++;
					}
				}
				mine[i][j+1]=count;
			if(mine[i][j]!=GamePanel[i-1][j-1])
			{
				if(GamePanel[i-1][j]-mine[i][j+1]>GamePanel[i-1][j-1]-mine[i][j])
				{
					if(GamePanel[i-1][j]-GamePanel[i-1][j-1]==ceil[i][j+1]-ceil[i][j])
					{
						if(GamePanel[i-1][j+1]==-1)
						flag[i][j+2]=1;
						if((i!=1)&&(GamePanel[i-2][j+1]==-1))
						flag[i-1][j+2]=1;
						if((i!=20)&&(GamePanel[i][j+1]==-1))
						flag[i+1][j+2]=1;
					}
				}
				else if(GamePanel[i-1][j]-mine[i][j+1]==GamePanel[i-1][j-1]-mine[i][j])
				{
					if((GamePanel[i-1][j+1]==-1)&&flag[i][j+2]==0)
					{
						x=i-1;y=j+1;
						return;
					}
					if((i!=1)&&(GamePanel[i-2][j+1]==-1)&&flag[i-1][j+2]==0)
					{
						x=i-2;y=j+1;
						return;
					}
					if((i!=20)&&(GamePanel[i][j+1]==-1)&&flag[i+1][j+2]==0)
					{
						x=i;y=j+1;
						return;
					}
				}
			}
			}
		}}
	}
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			if (GamePanel[i - 1][j - 1] > 0 )
			{
				int count = 0;
				if (flag[i + 1][j] == 1)
					count++;
				if (flag[i][j + 1] == 1)
					count++;
				if (flag[i - 1][j] == 1)
					count++;
				if (flag[i][j - 1] == 1)
					count++;
				if (flag[i + 1][j + 1] == 1)
					count++;
				if (flag[i + 1][j - 1] == 1)
					count++;
				if (flag[i - 1][j + 1] == 1)
					count++;
				if (flag[i - 1][j - 1] == 1)
					count++;
				mine[i][j] = count;
				if (mine[i][j] == GamePanel[i - 1][j - 1])
				{
					if (i == 1)
					{
						if (j == 1)
						{
							if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
							{
								x = i; y = j - 1;
								return;
							}
							if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
							{
								x = i - 1; y = j;
								return;
							}
							if (GamePanel[i][j] == -1 && flag[i + 1][j + 1] == 0)
							{
								x = i; y = j;
								return;
							}
						}
						else if (j == 20)
						{
							if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
							{
								x = i; y = j - 1;
								return;
							}
							if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
							{
								x = i - 1; y = j - 2;
								return;
							}
							if (GamePanel[i][j - 2] == -1 && flag[i + 1][j - 1] == 0)
							{
								x = i; y = j - 2;
								return;
							}
						}
						else {
							if (GamePanel[1][j - 1] == -1 && flag[2][j] == 0)
							{
								x = 1; y = j - 1;
								return;
							}
							if (GamePanel[0][j] == -1 && flag[1][j + 1] == 0)
							{
								x = 0; y = j;
								return;
							}
							if (GamePanel[0][j - 2] == -1 && flag[1][j - 1] == 0)
							{
								x = 0; y = j - 2;
								return;
							}
							if (GamePanel[1][j] == -1 && flag[2][j + 1] == 0)
							{
								x = 1; y = j;
								return;
							}
							if (GamePanel[1][j - 2] == -1 && flag[2][j - 1] == 0)
							{
								x = 1; y = j - 2;
								return;
							}
						}
					}
					else if (i == 20)
					{
						if (j == 1)
						{
							if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
							{
								x = i - 1; y = j;
								return;
							}
							if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
							{
								x = i - 2; y = j - 1;
								return;
							}
							if (GamePanel[i - 2][j] == -1 && flag[i - 1][j + 1] == 0)
							{
								x = i - 2; y = j;
								return;
							}
						}
						else if (j == 20)
						{
							if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
							{
								x = i - 2; y = j - 1;
								return;
							}
							if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
							{
								x = i - 1; y = j - 2;
								return;
							}
							if (GamePanel[i - 2][j - 2] == -1 && flag[i - 1][j - 1] == 0)
							{
								x = i - 2; y = j - 2;
								return;
							}
						}
						else {
							if (GamePanel[18][j - 1] == -1 && flag[19][j] == 0)
							{
								x = 18; y = j - 1;
								return;
							}
							if (GamePanel[19][j] == -1 && flag[20][j + 1] == 0)
							{
								x = 19; y = j;
								return;
							}
							if (GamePanel[19][j - 2] == -1 && flag[20][j - 1] == 0)
							{
								x = 19; y = j - 2;
								return;
							}
							if (GamePanel[18][j] == -1 && flag[19][j + 1] == 0)
							{
								x = 18; y = j;
								return;
							}
							if (GamePanel[18][j - 2] == -1 && flag[19][j - 1] == 0)
							{
								x = 18; y = j - 2;
								return;
							}
						}
					}
					else if (j == 1)
					{
						if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
						{
							x = i; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
						{
							x = i - 1; y = j;
							return;
						}
						if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
						{
							x = i - 2; y = j - 1;
							return;
						}
						if (GamePanel[i][j] == -1 && flag[i + 1][j + 1] == 0)
						{
							x = i; y = j;
							return;
						}
						if (GamePanel[i - 2][j] == -1 && flag[i - 1][j + 1] == 0)
						{
							x = i - 2; y = j;
							return;
						}
					}
					else if (j == 20)
					{
						if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
						{
							x = i; y = j - 1;
							return;
						}
						if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
						{
							x = i - 2; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
						{
							x = i - 1; y = j - 2;
							return;
						}
						if (GamePanel[i][j - 2] == -1 && flag[i + 1][j - 1] == 0)
						{
							x = i; y = j - 2;
							return;
						}
						if (GamePanel[i - 2][j - 2] == -1 && flag[i - 1][j - 1] == 0)
						{
							x = i - 2; y = j - 2;
							return;
						}
					}
					else {//normal
						if (GamePanel[i][j - 1] == -1 && flag[i + 1][j] == 0)
						{
							x = i; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j] == -1 && flag[i][j + 1] == 0)
						{
							x = i - 1; y = j;
							return;
						}
						if (GamePanel[i - 2][j - 1] == -1 && flag[i - 1][j] == 0)
						{
							x = i - 2; y = j - 1;
							return;
						}
						if (GamePanel[i - 1][j - 2] == -1 && flag[i][j - 1] == 0)
						{
							x = i - 1; y = j - 2;
							return;
						}
						if (GamePanel[i][j] == -1 && flag[i + 1][j + 1] == 0)
						{
							x = i; y = j;
							return;
						}
						if (GamePanel[i][j - 2] == -1 && flag[i + 1][j - 1] == 0)
						{
							x = i; y = j - 2;
							return;
						}
						if (GamePanel[i - 2][j] == -1 && flag[i - 1][j + 1] == 0)
						{
							x = i - 2; y = j;
							return;
						}
						if (GamePanel[i - 2][j - 2] == -1 && flag[i - 1][j - 1] == 0)
						{
							x = i - 2; y = j - 2;
							return;
						}
					}
				}
			}
		}
	}
	do
	{
		x = rand() % 20;
		y = rand() % 20;
	} while (flag[x + 1][y + 1] == 1 || GamePanel[x][y] != -1);
	
	return;
}

int getMineNum(int x, int y, int mine[30][30], int n, int m)
{
	int num_mine = 0;
	int round1[8] = { -1,1,0,0,-1,1,1,-1 };
	int round2[8] = { 0,0,-1,1,-1,1,-1,1 };
	for (int i = 0; i < 8; i++)
	{
		if (x + round1[i] >= 0 && x + round1[i] < n && y + round2[i] >= 0 && y + round2[i] < m)
		{
			if (mine[x + round1[i]][y + round2[i]] == 1)num_mine++;
		}
	}
	return num_mine;
}
void extend(int GamePanel[30][30], int x, int y, int mine[30][30], int n, int m)
{
	int round[2][8] = { -1,1,0,0,-1,1,1,-1,0,0,-1,1,-1,1,-1,1 };
	if (GamePanel[x][y] == -1)
	{
		if (getMineNum(x, y, mine, n, m) > 0)
		{
			GamePanel[x][y] = getMineNum(x, y, mine, n, m);
			return;
		}
		if (getMineNum(x, y, mine, n, m) == 0)
		{
			GamePanel[x][y] = 0;
			for (int i = 0; i < 8; i++)
			{
				if (x + round[0][i] >= 0 && x + round[0][i] < n && y + round[1][i] >= 0 && y + round[1][i] < m)
					extend(GamePanel, x + round[0][i], y + round[1][i], mine, n, m);
			}
		}
	}
}
int state(int GamePanel[30][30], int mine[30][30], int n, int m, int k)
{
	int i, j, num_mine = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (GamePanel[i][j] == -1)num_mine++;
	if (num_mine == k)return 1;
	return 0;
}
int RefreshGPanel(int GamePanel[30][30], int x, int y, int mine[30][30], int n, int m, int k)
{
	if (mine[x][y] == 1)return -1;
	else  extend(GamePanel, x, y, mine, n, m);
	if (state(GamePanel, mine, n, m, k) == 1) return 1;
	return 0;
}

/********************************将学生的代码添加到上面******************************/
/********************************************************************************/



int main()
{
	int GamePanel[30][30];
	int temp[30][30];
	int mine[30][30];
	int iii, ii, n, m, k, i, j, minenum, x, y, win = 0;
	int bonus;
	double score;
	double  maxscore = -999, minscore = 999, sumscore=0;
	int gamenum = 10000;
	int winnum = 0;
	n = 20;
	m = 20;
	minenum = 50;
	srand(int(time(0)));
	printf("正在评测中，请稍等，我们将进行1000局游戏，取平均分*1.3作为最终成绩......\n");
	
	for (iii = 0; iii<gamenum; iii++)
	{
		
		for (i = 0; i<n; i++)
			for (j = 0; j<m; j++)
		{
			GamePanel[i][j] = -1;
			mine[i][j] = 0;
		}
		
		int cnt = 0;
		
		for (ii = 0; ii<400; ii++)
		{	
			for (i = 0; i < 20; i++)
				for (j = 0; j < 20; j++)
					temp[i][j] = GamePanel[i][j];
			machine(temp, n, m, x, y);
			
			if (ii == 0)
			{
				for ( k = 0; k < minenum; k++)
				{
					i = rand() % 20;
					j = rand() % 20;
					while ((i == x && j == y) || mine[i][j] != 0)
					{
						i = rand() % 20;
						j = rand() % 20;
					}
					mine[i][j] = 1;
				}
			}
			if (GamePanel[x][y] == -1)
			{
				cnt++;
				win = RefreshGPanel(GamePanel, x, y, mine, n, m, minenum);
				if (win == 1)
				{
					if (cnt < 80) bonus = 35;
					else if (cnt < 90) bonus = 30;
					else if (cnt < 100) bonus = 25;
					else if (cnt < 120) bonus = 20;
					else if (cnt < 150) bonus = 15;
					else if (cnt < 200) bonus = 10;
					else if (cnt < 250) bonus = 5;
					else bonus = 0;
					score = 65.0 + bonus;
					if(iii==0 || (iii+1)%10==0) printf("第 %d 局,赢了,得 %d 分.\n", iii+1,(int)score);
					winnum++;
					
					break;
				}
				else if (win == -1)
				{
					score = 0;
					for (i = 0; i<n; i++)
						for (j = 0; j<m; j++)
					{
						if (GamePanel[i][j] != -1)
							score=score+1;
					}
					score = score/7;
					
					if (iii == 0 || (iii + 1) % 10 == 0)printf("第 %d 局,输了,得 %.2lf 分.\n", iii + 1, score);
					
					break;
				}
			}
			
		}
		if (win == 0)
		{
			score = 0;
			for (i = 0; i<n; i++)
				for (j = 0; j<m; j++)
			{
				if (GamePanel[i][j] != -1)
					score=score+1;
			}
			score = score / 7;
			if (iii == 0 || (iii + 1) % 10 == 0)printf("第 %d 局,输了,得 %.2lf 分.\n", iii + 1, score);
			
		}
		if (score>maxscore) maxscore = score;
		if (score<minscore) minscore = score;
		sumscore = sumscore+score;
		
	}
	
	int orignscore,finalscore;
	
	orignscore= ceil(1.3*ceil(sumscore/gamenum));
	
	if (orignscore > 100) finalscore = 100;
	else finalscore = orignscore;
	
	
	printf("该学生最终分数为 %d.\n\n", finalscore);
	printf("该学生胜率为 %.1lf%%\n\n", winnum/10.0);
	
	system("pause");
	return 0;
}
