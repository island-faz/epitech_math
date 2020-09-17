/*
** my_strlen.c for my_strlen in /home/bourhi_a/rendu/Piscine-C-Jour_04
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Oct  3 10:45:07 2013 bourhime amine
** Last update Fri Oct  4 09:38:22 2013 bourhime amine
*/

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}
