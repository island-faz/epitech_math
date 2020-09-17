/*
** my_putstr.c for my_putstr in /home/bourhi_a/rendu/math/101pong
** 
** Made by 
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Nov 17 04:32:50 2013 
** Last update Sun Nov 17 04:33:07 2013 
*/

int		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *s)
{
  int		i;

  i = 0;
  if (!s)
    return (0);
  while (s[i])
    my_putchar(s[i++]);
  return (0);
}
