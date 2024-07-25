#include "../../inc/cub3D.h"

// Give the distance for a ray
double	raycasting(t_data *data)
{
  char	  wall;
  double  distance;

  distance = 0;
  data->ray.x = data->player.x;
  data->ray.y = data->player.y;
  data->ray.rayCos = cos_degree(data->ray.rayAngle) / data->raycast.presicion;
  data->ray.raySin = sin_degree(data->ray.rayAngle) / data->raycast.presicion;
  wall = '0';
  while(wall == '0')
  {
    data->ray.x += data->ray.rayCos;
    data->ray.y += data->ray.raySin;
    wall = data->map[(int)data->ray.y][(int)data->ray.x];
  }
  distance = sqrt(pow(data->player.x - data->ray.x, 2) + pow(data->player.y - data->ray.y, 2));
  distance = distance * cos(degreetoRadiant(data->ray.rayAngle - data->player.angle));
  return (distance);
}

