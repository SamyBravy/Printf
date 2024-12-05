/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:06:20 by alborghi          #+#    #+#             */
/*   Updated: 2024/11/19 10:30:07 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, (char *) s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (join);
}

/* int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <string1> <string2>\n", argv[0]);
		return (1);
	}
	char *s1 = argv[1];
	char *s2 = argv[2];
	char *join = ft_strjoin(s1, s2);
	printf("%s\n", join);
	free(join);
	return (0);
} */