#include "../../inc/cub3D.h"

void rotations(t_data *data, double rotspeed)
{
    double  oldDirX;
    double  oldPlaneX;

    oldDirX = data->vec.dir.x;
    data->vec.dir.x = data->vec.dir.x * cos(rotspeed) - data->vec.dir.y * sin(rotspeed); 
    data->vec.dir.y = oldDirX * sin(rotspeed) + data->vec.dir.y * cos(rotspeed);

    oldPlaneX = data->vec.plane.x ;
    data->vec.plane.x = data->vec.plane.x * cos(rotspeed) - data->vec.plane.y * sin(rotspeed);  
    data->vec.plane.y = oldPlaneX * sin(rotspeed) + data->vec.plane.y * cos(rotspeed);
	printf("Vec dir x %lf\nVec dir Y %lf\n",data->vec.dir.x,data->vec.dir.y);
}
