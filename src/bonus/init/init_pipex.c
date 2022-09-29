/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:19:55 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/23 06:48:20 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	init_pipex(t_pipex *pipex, int argc)
{
	int			i;
	t_pipex_cmd	*copy;	

	i = -1;
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->argc = argc;
	pipex->first_cmd = ft_lstnew_pipex(pipex);
	pipex->tab_pid = ft_calloc(argc - 3, sizeof(pid_t));
	if (pipex->tab_pid == NULL)
		clear_program(pipex, "In init_pipex.c, malloc failed");
	copy = pipex->first_cmd;
	while (++i < argc - 4)
	{
		ft_lstaddback_pipex(pipex, ft_lstnew_pipex(pipex));
		copy = copy->next;
	}
}
