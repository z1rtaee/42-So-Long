/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:22:01 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/30 13:16:21 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

static double	get_time_in_seconds(void)
{
	struct timespec	ts;

	clock_gettime(1, &ts);
	return (ts.tv_sec + ts.tv_nsec / 1e9);
}

double	get_delta_time(void)
{
	static double	last_frame;
	double			current;
	double			dt;

	current = get_time_in_seconds();
	dt = current - last_frame;
	last_frame = current;
	return (dt);
}
