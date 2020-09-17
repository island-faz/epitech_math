/*
** helpers.c for hellpers in /home/bourhi_a/rendu/107transfert
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Mar  3 00:10:28 2014 
** Last update Tue Mar  4 00:02:31 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int	nb_sep(char *s, char sep)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  while (i < strlen(s))
    {
      if (s[i] == sep)
	cpt++;
      i++;
    }
  return (cpt);
}

int		is_dir(char *path)
{
  struct stat	sb;

  if (!lstat(path, &sb))
    return (S_ISDIR(sb.st_mode)) ? (1) : (0);
  return (0);
}

void		xerror(char *s)
{
  printf("%s\n", s);
  exit(1);
}
