/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:53:50 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/12 03:44:16 by hgrissen         ###   ########.fr       */
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

	doc = ft_strjoin(strdup("/tmp/file"), ft_itoa(rdr->index));
	fd = open(doc, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		str = readline("> ");
		if (!str)
			break ;
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
	free(doc);
	return (fd);
}

int	create_file(t_redirection *rdr)
{
	int	fd;

	fd = -1;
	if (rdr->type == RDRIN)
		fd = open(rdr->file, O_RDONLY, 0644);
	else if (rdr->type == RDROUT)
		fd = open(rdr->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (rdr->type == APPEND)
		fd = open(rdr->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	return (fd);
}

void	redirect(t_cmd *cmd)
{
	t_redirection	*current;
	int				fd;

	current = cmd->rdr;
	while (current != NULL)
	{
		if (current->type != HEREDOC)
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

void	herdocs(t_cmd *cmd)
{
	t_cmd			*current;
	t_redirection	*cur_rdr;
	int				i;

	current = cmd;
	i = 0;
	while (current != NULL)
	{
		cur_rdr = current->rdr;
		while (cur_rdr != NULL)
		{
			if (cur_rdr->type == HEREDOC)
			{
				cur_rdr->index = i++;
				cur_rdr->fd = open_herdoc(cur_rdr);
			}
			cur_rdr = cur_rdr->next;
		}
		current = current->next;
	}
}
