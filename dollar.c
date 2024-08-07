/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcekul <tugcekul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:13:08 by tugcekul          #+#    #+#             */
/*   Updated: 2024/08/07 20:47:03 by tugcekul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *remove_by_index(char *str, int start, int end) 
{
    char *new_str;
    int i;
    int j;

    i = -1;
    j = 0;
    new_str = malloc(sizeof(char) * (ft_strlen(str) - end + 1));
    while (str[++i])
    {
        if (i < start || i > start + end)
        {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return (new_str);
}


int process_dollar_variable(t_data *data, char **str, int i)
{
    int j;

    j = i + 1;
    while (ft_isalpha((*str)[j]))
        j++;
    data->lexer->key = ft_substr(*str, i + 1, j - i - 1);
    if (!data->lexer->key)
        return (-1);
    data->lexer->value = ft_getenv_by_key(data->lexer->key, data->env);
    if (!data->lexer->value)
        *str = remove_by_index(*str, i, j - i - 1);
    else
    {
        *str = remove_by_index(*str, i, j - i - 1);
        *str = ft_joinstr_index(*str, data->lexer->value, i);
        free(data->lexer->key);
        free(data->lexer->value);
    }  
    if (!*str)
        return (-1);
    return (0);
}

int handle_dollar(t_data *data, char **str)
{
    int i;
    int quote; 

    i = -1;
    quote = -1;
    while ((*str)[++i])
    {
        ft_set_quote_type(&quote, (*str)[i]);
        if (quote != '\'' && (*str)[i] == '$')
        {
            if ((*str)[i] == '$' && (*str)[i + 1] == '?')
            {
                printf("status: %s\n", ft_itoa(data->status));
                if (data->status == 0)
                {
                    *str = remove_by_index(*str, i, 1);
                    *str = ft_joinstr_index(*str, "0", i);
                }
            }
            else if ((*str)[i] == '$' && ft_isalpha((*str)[i + 1]))
            {
                if (process_dollar_variable(data, str, i) == -1)
                    return (-1);
            }
        }
    }
    return (0);
}
