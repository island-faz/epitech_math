/*
** my_getnbr.c for my_getnbr in /home/bourhi_a/rendu/Piscine-C-Jour_04
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Oct  3 12:59:46 2013 bourhime amine
** Last update Mon Oct 21 17:46:17 2013 bourhime amine
*/

int	my_getnbr(char *str)
{
  int	 nb;
  int	 isneg;

  nb = 0;
  isneg = 1;
  while (*str == '+' || *str == '-')
     {
       if (*str == '-')
	 {
	   isneg *= -1;
	 }
       str = str + 1;
     }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      nb = nb * 10;
      nb = nb + *str - 48;
      str = str + 1;
    }
  return (nb * isneg);
}
