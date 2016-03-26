/*
** init.c for init.c in /home/cheval_8/rendu/CPE_2015_Allum1/src
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 12 11:30:08 2016 Nicolas Chevalier
** Last update Sun Feb 21 19:19:46 2016 Chevalier Nicolas
*/

#include	"allum.h"

/*
** create node for list simple
*/
t_alum		*init_node(int nb)
{
  t_alum	*node;

  if ((node = malloc(sizeof(t_alum))) == NULL)
    return (NULL);
  node->nb_matches = nb;
  node->max_matches = nb;
  node->next = NULL;
  return (node);
}

/*
** Put number matches in the node, and next
*/
void		init_matches(t_alum **list, int i)
{
  t_alum	*alum;
  t_alum	*tmp;

  alum = init_node(i * 2 + 1);
  if ((*list) == NULL)
    (*list) = alum;
  else
    {
      tmp = (*list);
      while (tmp != NULL && tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = alum;
    }
}

/*
** create list simple t_alum
*/
t_alum		*init_alum(int nb_matches)
{
  t_alum	*list;
  int		i;

  i = -1;
  if ((list = init_node(nb_matches)) == NULL)
    return (NULL);
  while (++i < nb_matches)
    init_matches(&(list->next), i);
  return (list);
}
