
/*
** utils_prog.c for utils_prog.c in /home/cheval_8/rendu/CPE_2015_Allum1
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Tue Feb 16 20:22:47 2016 Chevalier Nicolas
** Last update Sun Feb 21 21:26:49 2016 Chevalier Nicolas
*/

#include	"allum.h"

int		remove_matches(t_alum *list, int line, int matches)
{
  t_alum	*tmp;
  int		i;

  tmp = list;
  i = line;
  while (--i >= 0)
    tmp = tmp->next;
  if (matches == 0)
    return (error_allum1("you have to remove at least one match\n"));
  else if (matches > tmp->nb_matches)
    return (error_allum1("not enough matches on this line\n"));
  else if (matches < 0)
    return (error_allum1("invalid input (positive number expected)\n"));
  else
    tmp->nb_matches -= matches;
  return (matches);
}

int		check_line(t_alum *list, int nb)
{
  t_alum	*tmp;

  tmp = list->next;
  while (--nb != 0)
    tmp = tmp->next;
  return ((tmp->nb_matches == 0) ? (-1) : (0));
}

int		count_list(t_alum *list, int *nb_line)
{
  t_alum	*tmp;
  int		i;

  i = 0;
  tmp = list->next;
  *(nb_line) = 0;
  while (tmp != NULL)
    {
      if (tmp->nb_matches == 1)
	i += 1;
      if (tmp->nb_matches > 0)
	*(nb_line) += 1;
      tmp = tmp->next;
    }
  return (i);
}

int		read_line(t_alum *list, int line)
{
  char		*s;
  int		nb;
  int		i;

  if ((s = get_next_line(0)) == NULL)
    return (0);
  i = -1;
 if (s[0] == '\0')
    return (error_allum1("invalid input (positive number expected)\n"));
  while (s[++i])
    if (s[i] < '0' || s[i] > '9')
      return (error_allum1("invalid input (positive number expected)\n"));
  nb = my_getnbr(s);
  return ((line == -1) ? check_error(list, nb) :
	  remove_matches(list, line, nb));
}
