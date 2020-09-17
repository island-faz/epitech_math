/*
** my_put_nbr.c for my_put_nbr in /home/bourhi_a/rendu/Piscine-C-Jour_03
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Oct  2 17:58:17 2013 bourhime amine
** Last update Wed Oct  9 22:42:38 2013 bourhime amine
*/

void	my_put_nbr(int nbr)
{
  if (nbr < 0 && (nbr *= -1) >= 0)
    my_putchar('-');
  if (nbr > 9)
    my_put_nbr(nbr / 10);
  my_putchar(nbr % 10 + '0');
}
