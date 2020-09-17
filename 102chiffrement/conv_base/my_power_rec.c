/*
** my_power_rec.c for my_power_rec in /home/bourhi_a/rendu/Piscine-C-Jour_05
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri Oct  4 12:11:24 2013 bourhime amine
** Last update Sun Oct  6 22:15:50 2013 bourhime amine
*/

int	my_power_rec(int nb, int power)
{
  return (power > 0) ? nb * my_power_rec(nb, power - 1) : 1;
}
