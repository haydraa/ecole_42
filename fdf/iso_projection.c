#include "fdf.h"



void isometric(float  *x,float *y,int  z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void zoom(t_dda *dda)
{
	dda->zoom = 20;
	dda->x0 *= dda->zoom;
	dda->x1 *= dda->zoom;
	dda->y0 *= dda->zoom;
	dda->y1 *= dda->zoom;
}

void get_place(t_dda *dda)
{	
	dda->x0 += 150;
	dda->y0 += 150;
	dda->x1 += 150;
	dda->y1 += 150;
}
void color_rgb(t_dda *dda, t_tab *tab)
{
	dda->z = tab->tab[(int)dda->y0][(int)dda->x0];
	dda->z1 = tab->tab[(int)dda->y1][(int)dda->x1];
	dda->color = (dda->z) ? 0xe80c0c : 0xFFFFFF;	
}

void in_struct(t_dda *dda, int  i,int  j, int index)
{
	if (index == 0)
	{
		dda->x0 = i;
		dda->y0 = j;
		dda->x1 = i;
		dda->y1 = j + 1;
	}
	if (index == 1)	
	{
		dda->x0 = i;
		dda->y0 = j;
		dda->x1 = i + 1;
		dda->y1 = j;
	}
}
