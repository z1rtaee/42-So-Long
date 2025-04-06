/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:13:29 by bpires-r          #+#    #+#             */
/*   Updated: 2025/04/06 19:17:57 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	//t_solong data;
	
	if (argc != 2)
		exit_error("Invalid number of arguments.");
	if(!check_map_name(argv[1]))
		exit_error("Invalid map format.");
	read_map(argv[1]);
	
}