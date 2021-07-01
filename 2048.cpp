#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
int notgameover(int arr[][5], int n)
{
	for(int i = 0; i<5;i++)
	{
		for(int j=0; j<5; j++)
		{
			if(arr[i][j]==0)
			{
				return 1;
			}
		}
	}
	return 0;
}
void display(int arr[][5], int n)
{
	system("cls");
	cout<<"\n To Move down, press s";
	cout<<"\n To move right, press d";
	cout<<"\n To Move Left, press a\n\n";
    cout<<"--------------------\n";
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<"| "<<arr[i][j]<<" |";
		}
		cout<<"\n--------------------\n";
	}	
}
int combine(int arr[][5], int pos, int k)
{
	int flag = 0;
	if(arr[pos][k] == arr[pos+1][k])
	{
		arr[pos+1][k] *= 2;
		arr[pos][k] = 0;
		flag = 1;
	}
	if(arr[pos][k] == arr[pos][k-1])
	{
		arr[pos][k] *= 2;
		arr[pos][k-1] = 0;
		flag = 1;
	}
	if(arr[pos][k] == arr[pos][k+1])
	{
		arr[pos][k] *= 2;
		arr[pos][k+1] = 0;
		flag = 1;
	}
	return flag;
}
void combinex(int arr[][5], int pos, int k)
{
	if(arr[pos][k] == arr[pos+1][k])
	{
		arr[pos+1][k] *= 2;
		arr[pos][k] = 0;
	}
	if(arr[pos][k] == arr[pos][k-1])
	{
		arr[pos][k] *= 2;
		arr[pos][k-1] = 0;
	}
	if(arr[pos][k] == arr[pos][k+1])
	{
		arr[pos][k] *= 2;
		arr[pos][k+1] = 0;
	}
}
int nomove(int arr[][5], int pos, int k)
{
	if(arr[pos+1][k] && arr[pos][k-1] && arr[pos][k+1] &&(pos ==4 || k==4))
	{
		return 1;
	}
	return 0;
}
int rowfull(int arr[][5], int n)
{
	for(int i = 0; i<5; i++)
			{
				for(int j = 0; j<5; j++)
				{
					combinex(arr,i,j);
				}
			}
	for(int j = 0; j<4; j++)
	{
		if (arr[n][j] == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	
	int arr[5][5];
	int array[] = {2,4,8,16,32};
	int sum = 0;
	int k, pos;
	char ch;
	newgame:
	for(int i = 0; i<5;i++)
	{
		for(int j=0; j<5; j++)
		{
			arr[i][j] = 0;
		}
	}
    display(arr, 5);
	label4:
		k = rand()%4;
		pos = 0;
		arr[pos][k] = array[rand()%5];
		display(arr, 5);
		do
		{
			ch = getch();
			if(ch == 's')
			{
				swap(arr[pos][k], arr[pos+1][k]);
				pos = pos+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'a')
			{
				swap(arr[pos][k], arr[pos][k-1]);
				k = k-1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'd')
			{
				swap(arr[pos][k], arr[pos][k+1]);
				k = k+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			for(int i = 0; i<5; i++)
			{
				for(int j = 0; j<5; j++)
				{
					combinex(arr,i,j);
				}
			}
			display(arr,5);
							
		}while(pos < 4 && k<4 && nomove(arr,pos,k)==0);
		if(rowfull(arr, 4) == 0)
		{
			goto label4;
		}	
	label3:
		k = rand()%4;
		pos = 0;
		arr[pos][k] = array[rand()%5];
		display(arr, 5);
		do
		{
			ch = getch();
			if(ch == 's')
			{
				swap(arr[pos][k], arr[pos+1][k]);
				pos = pos+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'a')
			{
				swap(arr[pos][k], arr[pos][k-1]);
				k = k-1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'd')
			{
				swap(arr[pos][k], arr[pos][k+1]);
				k = k+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
							
		}while(pos < 3 && k<4 && nomove(arr,pos,k)==0);
		if(rowfull(arr, 4) == 0)
		{
			goto label4;
		}
		if(rowfull(arr, 3) == 0)
		{
			goto label3;
		}
	label2:
		k = rand()%4;
		pos = 0;
		arr[pos][k] = array[rand()%5];
		display(arr, 5);
		do
		{
			ch = getch();
			if(ch == 's')
			{
				swap(arr[pos][k], arr[pos+1][k]);
				pos = pos+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'a')
			{
				swap(arr[pos][k], arr[pos][k-1]);
				k = k-1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'd')
			{
				swap(arr[pos][k], arr[pos][k+1]);
				k = k+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
							
		}while(pos < 2 && k<4 && nomove(arr,pos,k)==0);
		if(rowfull(arr, 4) == 0)
		{
			goto label4;
		}
		if(rowfull(arr, 3) == 0)
		{
			goto label3;
		}
		if(rowfull(arr, 2) == 0)
		{
			goto label2;
		}
	label1:
		k = rand()%4;
		pos = 0;
		arr[pos][k] = array[rand()%5];
		display(arr, 5);
		do
		{
			ch = getch();
			if(ch == 's')
			{
				swap(arr[pos][k], arr[pos+1][k]);
				pos = pos+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'a')
			{
				swap(arr[pos][k], arr[pos][k-1]);
				k = k-1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
			
			if(ch == 'd')
			{
				swap(arr[pos][k], arr[pos][k+1]);
				k = k+1;
				if(combine(arr, pos, k) == 1)
				{
					display(arr,5);
					break;
				}
				else
				{
					display(arr,5);
				}
			}
							
		}while(pos < 1 && k<4 && nomove(arr,pos,k)==0);
		if(rowfull(arr, 4) == 0)
		{
			goto label4;
		}
		if(rowfull(arr, 3) == 0)
		{
			goto label3;
		}
		if(rowfull(arr, 2) == 0)
		{
			goto label2;
		}
		if(rowfull(arr, 1) == 0)
		{
			goto label1;
		}
	return 0;
}
