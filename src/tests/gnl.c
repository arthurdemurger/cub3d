#include "../../inc/test/gnl.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		i = -1;
		j = -1;
		while (s1[++i])
			str[i] = s1[i];
		while (s2[++j])
			str[i++] = s2[j];
		str[i] = '\0';
	}
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_clean(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != '\n') // On place le compteur juste apres le '\n'
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	new_str = malloc (sizeof(char) * (ft_strlen(str) - i + 1)); // Le resultat sera la longueur totale - ce qui precede le '\n' - '\n' + '\0'
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new_str[j++] = str[i++]; // notre nouvelle chaine (qui deviendra notre stash pour le prochian appel) est composee de ce qui suit le '\n' dans notre str
	new_str[j] = '\0';
	free (str);
	return (new_str);
}

char	*make_new_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i]) // Si la str est vide, ERREUR
		return (NULL);
	while (str[i] && str[i] != '\n') // On compte les caracteres jusqu'a un '\n' ou la fin du infile
		i++;
	line = malloc (sizeof(char) * (i + 2)); // On cree une chaine qui contiendra la str jusqu'au '\n'(non inclus) + '\n' (sauf en fin de infile) + '\0'
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line); // On renvoie la ligne debarassee de ce qui suit le '\n' ou qui s'arrete a la fin du infile
}

char	*read_and_stash(int fd, char *str)
{
	int		char_count;
	char	*temp;

	temp = malloc (sizeof(char) * (BUFFER_SIZE + 1)); // On cree une chaine qui servira a remplir la stash a coup de BUFFER_SIZE caracteres
	if (!temp)
		return (NULL);
	char_count = 1; // On initialise le compte a 1 pour lire le infile au moins une fois
	while (!ft_strchr(str, '\n') && char_count != 0) // On lit le infile a coups de BUFFER_SIZE caracteres et on arrete si on trouve un passage a la ligne ou s'il n'y a plus rien a lire
	{
		char_count = read(fd, temp, BUFFER_SIZE); // On lit le infile et on insere BUFFER_SIZE caractere dans temp
		if (char_count == -1) // On prevoit une erreur de read
		{
			free(temp);
			return (NULL);
		}
		temp[char_count] = '\0';
		str = ft_strjoin_gnl(str, temp); // On concatene les "temp" dans "str" jusqu'a ce que "str" contienne un passage a la ligne ou la fin du infile
	}
	free(temp);
	return (str); // Dans la plupart des cas, str devrait ressembler a ca : xxxxxx'\n'xxxxx.
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash; // On cree une chaine qui servira de reserve tout le long de l'execution
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash); // On remplit la stash de tout ce qu'on lit jusqu'a ce qu'elle contienne un passage a la ligne ou la fin du infile
	if (!stash)
		return (NULL);
	line = make_new_line(stash); // On cree une ligne a print a partir du stash, jusqu'a un passage a la ligne ou la fin du infile
	stash = ft_clean(stash); // On debarasse la stash de ce qui precede le '\n'
	return (line);
}