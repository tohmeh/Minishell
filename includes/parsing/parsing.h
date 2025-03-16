/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:19:36 by mtohmeh           #+#    #+#             */
/*   Updated: 2025/01/19 16:56:36 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H
# include "../tokenization/tokenization.h"
# include "parsing_utils.h"

t_command_line	*parse_tokens(t_parsing_utils **ctx);

#endif