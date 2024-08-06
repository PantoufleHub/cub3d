#include "../../inc/cub3D.h"

struct timeval	init_timer(void)
{
	struct timeval	time_of_day;

	if (gettimeofday(&time_of_day, NULL))
	{	
		time_of_day.tv_sec = 0;
		time_of_day.tv_usec = 0;
		return (time_of_day);
	}
	return (time_of_day);
}

long	sec_ms(time_t seconds)
{
	return (seconds * 1000);
}

long	usec_ms(useconds_t useconds)
{
	return (useconds / 1000);
}

long	get_time_elapse(struct timeval ref_time_of_day)
{
	struct timeval	now;
	long			current_time_ms;

	current_time_ms = 0;
	if (!gettimeofday(&now, NULL))
	{
		current_time_ms = sec_ms(now.tv_sec) - sec_ms(ref_time_of_day.tv_sec);
		current_time_ms += usec_ms(now.tv_usec)
			- usec_ms(ref_time_of_day.tv_usec);
	}

	return (current_time_ms);
}
