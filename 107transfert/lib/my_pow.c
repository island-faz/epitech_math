/*
** my_pow.c for lib in /home/bourhi_a/rendu/107transfert
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Mar  2 22:54:23 2014 
** Last update Mon Mar  3 00:53:39 2014 
*/

double	my_pow(double d, int n)
{
  int	i = 1;

  if (!n)
    return (1);
  if (n == 1)
    return (d);
  while (i++ < n)
    d *= d;
  return (d);
}
