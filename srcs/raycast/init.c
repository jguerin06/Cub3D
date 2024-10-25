/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lforgion <lforgion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:10:30 by lforgion          #+#    #+#             */
/*   Updated: 2024/10/24 16:42:15 by lforgion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_knife_animation(t_opt *opt)
{
	opt->current_frame = 0;
	opt->total_frames = 78;
	opt->animation_active = 0;
}
