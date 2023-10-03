/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:09 by btekinli          #+#    #+#             */
/*   Updated: 2023/10/03 21:00:59 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Bu fonksiyon, minishell adlı bir programda CD (Change Directory) komutunun işlemini 
yapar. İlk olarak, eğer input[1] boş değilse, input[1] deki dizin adına geçmeyi 
deniyor. Eğer başarısız olursa, perror fonksiyonuyla hatayı ekrana yazdırıyor. 
Eğer input[1] boş ise, HOME değişkeni içindeki ev dizinine geçmeyi deniyor. Eğer 
ev dizini bulunamazsa, perror fonksiyonuyla hatayı ekrana yazdırıyor. Son olarak, 
eğer programın çalıştığı dizin ana dizin değilse (is_parent() fonksiyonu ile 
kontrol ediliyor), program exit(errno) fonksiyonuyla sonlandırılıyor.
*/
void	builtin_cd(t_shell *ms, char **input)
{
	char	*home;

	if (input[1] != NULL)
	{
		if (chdir(input[1]))
			errno = 1;
			write(2, "minishell : No such file or directory\n", 38);
			strerror(errno); 
	}
	else
	{
		home = getenv("HOME");
		if (home && *home)
			if (chdir(home))
				perror("minishell ");
	}
	if (!is_parent(ms))
		exit (errno);
}

