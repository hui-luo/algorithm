#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
 
typedef struct
{
	float x;
	float y;
}POINT;
 
typedef struct
{
	int index;  //该元素在X数组中的下标
	float x;
	float y;
}A_POINT;
 
bool cmp_x(POINT p1, POINT p2)
{
	return p1.x < p2.x;
}
 
bool cmp_y(A_POINT p1, A_POINT p2)
{
	return p1.y < p2.y;
}
 
float dist(POINT a, POINT b)    //计算a与b之间的距离
{
	float dx, dy;
	dx = a.x - b.x;
	dy = a.y - b.y;
	return (dx * dx + dy * dy);
}
 
//分治法计算平面点集的最接近点对
void closest(POINT X[], A_POINT Y[], int low, int high, POINT &a, POINT &b, float &d)
{
	int i, j, k, m;
	POINT al, bl, ar, br;
	float dl, dr;
	if ((high - low) == 1)   //n=2，直接计算
	{
		a = X[low];
		b = X[high];
		d = dist(X[low], X[high]);
	}
	else if ((high - low) == 2)  //n=3,直接计算
	{
		dl = dist(X[low], X[low + 1]);
		dr = dist(X[low], X[low + 2]);
		d = dist(X[low + 1], X[low + 2]);
		if ((dl <= dr) && (dl <= d))
		{
			a = X[low];
			b = X[low + 1];
			d = dl;
		}
		else if (dr <= d)
		{
			a = X[low];
			b = X[low + 2];
			d = dr;
		}
		else
		{
			a = X[low + 1];
			b = X[low + 2];			
		}
	}
	else
	{
		m = (high - low) / 2 + low;   //以m为界将X划分为两半
		A_POINT *SL = new A_POINT[m + 1 - low];
		A_POINT *SR = new A_POINT[high, m];
		j = k = 0;
		for (i = 0; i <= high - low; i++)
		{
			if (Y[i].index <= m)
				SL[j++] = Y[i];
			else
				SR[k++] = Y[i];
		}
		closest(X, SL, low, m, al, bl, dl);   //寻找左半平面的最近点
		closest(X, SR, m + 1, high, ar, br, dr); //寻找右半平面的最近点
		if (dl < dr)   //比较并选取左右两边平面的的最近点
		{
			a = al;
			b = bl;
			d = dl;
		}
		else
		{
			a = ar;
			b = br;
			d = dr;
		}
		POINT *Z = new POINT[high - low + 1];
		k = 0;
		for (i = 0; i <= high - low; i++)  //收集两侧距离中线小于d的元素
		{
			if (fabs(X[m].x - Y[i].x) < d)
			{
				Z[k].x = Y[i].x;
				Z[k].y = Y[i].y;
				k++;
			}
		}
		for (i = 0; i < k; i++)     //寻找两侧距离中线小于d的元素中的最接近点
		{
			for (j = i + 1; (j < k) && (Z[j].y - Z[i].y < d); j++)
			{
				dl = dist(Z[i], Z[j]);
				if (dl < d)  //如果找到距离小于原先最短距离的两个点，则替换原来的值
				{
					a = Z[i];
					b = Z[j];
					d = dl;
				}
			}
		}
		delete SL;
		delete SR;
		delete Z;
	}
}
 
//数组X存放平面点集元素，n为元素个数
void closest_pair(POINT X[], int n, POINT &a, POINT &b, float &d)
{
	if (n < 2)
		d = 0;
	else
	{
		sort(X, X + n, cmp_x);       //对点集数组按照x值升序排序
		A_POINT *Y = new A_POINT[n]; 
		for (int i = 0; i < n; i++)  //将X中的元素复制到Y中
		{
			Y[i].index = i;
			Y[i].x = X[i].x;
			Y[i].y = X[i].x;
		}
		sort(Y, Y + n, cmp_y);   //将Y按照y的升序排序
		closest(X, Y, 0, n - 1, a, b, d);  //寻找最接近点的坐标和距离
		d = sqrt(d);   //开方
		delete Y;
	}
}

int main()
{
    
}