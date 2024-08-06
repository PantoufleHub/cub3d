#include "../../inc/cub3D.h"
#include <math.h>


int side(void)
{
  // if (data->player.y < data->ray.y)
  //   return (create_trgb(0, 255, 0, 0)); // NORTH
  // if (data->player.y > data->ray.y)
  //   return (create_trgb(0, 255,255,0)); // SOUTH
  // if (data->player.x > data->ray.x)
  return(create_trgb(0, 0, 0, 0)); // DEFAULT COLOR
}

// int dda(t_data *data)
// {
//   int hit;
//   int side;
//   double raystepX;
//   double raystepY;
//
//   hit = 0;
//   side = 0;
//   raystepY = sqrt(1 + pow(data->ray.raySin / data->ray.rayCos, 2));
//   raystepX = sqrt(1 + pow(data->ray.rayCos / data->ray.raySin, 2));
//   while (hit == 0)
//   {
//
//   }
//   return (side);
// }

// TODO: DDA ?
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
    wall = data->map[lrint(data->ray.y)][lrint(data->ray.x)];
  }
  data->render.wall_color = side();
  distance = sqrt(pow(data->player.x - data->ray.x, 2) + pow(data->player.y - data->ray.y, 2));
  distance = distance * cos(degreetoRadiant(data->ray.rayAngle - data->player.angle));
  return (distance);
}

