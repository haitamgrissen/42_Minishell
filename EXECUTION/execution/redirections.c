/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:53:50 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/11 03:23:03 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/execution.h"

int	redirect_file(t_redirection *rdr)
{
	int				tmp_fd;
	t_redirection	*current;

	current = rdr;
	while (current != NULL)
	{
		tmp_fd = current->fd;
		if (current->type == RDROUT || current->type == APPEND)
			tmp_fd = dup2(current->fd, 1);
		else
			tmp_fd = dup2(current->fd, 0);
		close(current->fd);
		current = current->next;
	}
	return (0);
}

int	open_herdoc(t_redirection *rdr)
{
	int		fd;
	char	*doc;
	char	*str;

	doc = ft_strjoin(strdup("/tmp/file"), strdup(ft_itoa(rdr->index)));
	fd = open(doc, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		str = readline("> ");
		if (ft_strcmp(rdr->file, str) == 0)
		{
			free(str);
			break ;
		}
		str = ft_strjoin(str, ft_strdup("\n"));
		ft_putstr_fd(str, fd);
		free(str);
	}
	close(fd);
	fd = open(doc, O_RDONLY, 0644);
	return (fd);
}

int	create_file(t_redirection *rdr)
{
	int	fd;

	if (rdr->type == RDRIN)
		fd = open(rdr->file, O_RDONLY, 0644);
	else if (rdr->type == RDROUT)
		fd = open(rdr->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (rdr->type == APPEND)
		fd = open(rdr->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (rdr->type == HEREDOC)
		fd = open_herdoc(rdr);
	return (fd);
}

void	redirect(t_cmd *cmd, t_pipes *p)
{
	t_redirection	*current;
	int				fd;
	int				i;

	current = cmd->rdr;
	i = 0;
	while (current != NULL)
	{
		current->index = i++;
		current->fd = create_file(current);
		if (current->fd == -1)
		{
			write(2, "MINI: ", 6);
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			exit(0);
			return ;
		}
		current = current->next;
	}
	redirect_file(cmd->rdr);
}
