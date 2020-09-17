/*
** conv_functions.c for convert base functions in /home/bourhi_a/rendu/prog_elem/PSU_2013_my_printf/convert_base
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Nov 14 06:28:56 2013 bourhime amine
** Last update Thu Nov 14 06:29:02 2013 bourhime amine
*/

char	*check(char *str, int *sign, char *base)
{
  char	*c;
  int	i;
  int	j;

  *sign = 1;
  while (str && (*str == '-' || *str == '+'))
    {
      if (*str == '-')
	*sign *= -1;
      *str++;
    }
  i = -1;
  while (str && str[++i] && !(j = 0))
    {
      while (j >= 0 &&  base && base[j])
	j = (str[i] == base[j++]) ? (-2) : (j);
      if (j >= 0)
	return (0);
    }
  i = -1;
  while (base && base[++i] && (j = -1))
      while (base[++j])
	if (base[i] == base[j] && i != j)
	  return (0);
  return (str);
}

int	get_base_place(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] && base[i] != c)
      i++;
  return (i);
}

int	my_getnbr_base(char *str, char *base, int *over)
{
  int	sign;
  int	str_len;
  int	i;
  int	res;
  int	base_len;
  int	j;
  int	checkone;

  if ((base_len = my_strlen(base)) < 2 || !(str = check(str, &sign, base)))
    return (0);
  str_len = my_strlen(str);
  j = str_len - 1;
  res = 0;
  i = 0;
  while (i < str_len)
    {
      checkone = res;
      res += get_base_place(str[i], base) * my_power_rec(base_len, j);
      if (res < checkone)
	*over = 1;
      i++;
      j--;
    }
  return (res * sign);
}

int		my_putnbr_base(unsigned int nbr, char *base, char *res)
{
  int		mod;
  int		len_str;
  unsigned int	nb;
  static int	i;

  i = 0;
  nb = nbr;
  if ((nb < 0) && (nb *= -1))
    res[i++] = '-';
  len_str = my_strlen(base);
  mod = nb % len_str;
  nb /= len_str;
  (nb > 0) ? my_putnbr_base(nb, base, res) : 1;
  res[i] = base[mod];
  i++;
  return (i);
}

void	my_putnbr(unsigned int nbr)
{
  if (nbr < 0 && (nbr *= -1) >= 0)
    my_putchar('-');
  if (nbr > 9)
    my_putnbr(nbr / 10);
  my_putchar(nbr % 10 + '0');
}
