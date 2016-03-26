/*
** ia.c for ia.c in /home/cheval_8/rendu/CPE_2015_Allum1
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 12 11:41:21 2016 Nicolas Chevalier
** Last update Sun Feb 21 16:43:15 2016 Chevalier Nicolas
*/

#include	"allum.h"

/*
** Get first line
** return the line
*/
int		search_one(t_alum *list)
{
  t_alum	*tmp;
  int		i;

  i = 1;
  tmp = list->next;
  while (tmp != NULL)
    {
      if (tmp->nb_matches > 0)
	return (i);
      i += 1;
      tmp = tmp->next;
    }
  return (0);
}

/*
** Get first line > 1
** Return number matches if lines are pair
** else return matches -1
*/
int		choose_params(t_alum *list, int *line, int nb_line)
{
  t_alum	*tmp;

  *(line) = 1;
  tmp = list->next;
  while (tmp != NULL)
    {
      if (tmp->nb_matches > 1)
	return ((nb_line % 2 == 0) ? (tmp->nb_matches)
		: (tmp->nb_matches - 1));
      tmp = tmp->next;
      *(line) += 1;
    }
  return (0);
}

/*
** Calcul the xor total
*/
int		xor(t_alum *list)
{
  t_alum	*tmp;
  int		xor;

  tmp = list->next;
  xor = 0;
  while (tmp != NULL)
    {
      xor ^= tmp->nb_matches;
      tmp = tmp->next;
    }
  return (xor);
}

/*
** Calcul the xor per line
** Ti = number of matches which i is the line
** stop while when calcul = xor_total ⊕ Ti < Ti
** return (Ti - calcul)
*/
int		xor_line(t_alum *list, int xor, int *line)
{
  t_alum	*tmp;
  int		calcul;

  *(line) = 1;
  tmp = list->next;
  while (tmp != NULL)
    {
      if ((tmp->nb_matches ^ xor) < tmp->nb_matches)
	{
	  calcul = tmp->nb_matches ^ xor;
	  return (tmp->nb_matches - calcul);
	}
      *(line) += 1;
      tmp = tmp->next;
    }
  return (0);
}
