/*
** ia_random.c for ia_random.c in /home/cheval_8/test/CPE_2015_Allum1/bonus
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Feb 21 02:22:12 2016 Chevalier Nicolas
** Last update Sun Feb 21 17:48:36 2016 Chevalier Nicolas
*/

#include	"allum.h"

/*
** Can you to get the line with a number random (nb)
** return line if success
** else return 0
*/
int		get_line(t_alum *list, int nb)
{
  t_alum	*tmp;
  int		i;

  i = 1;
  tmp = list->next;
  while (nb != 0 || tmp != NULL)
    {
      if (tmp->nb_matches == 0)
	  i += 1;
      if (nb - 1 == 0)
	return (i);
      tmp = tmp->next;
      nb -= 1;
      i += 1;
    }
  return (0);
}

/*
** Function use in case of big mistake
*/
int		change_line(t_alum *list, int *line)
{
  t_alum	*tmp;
  int		i;

  i = 0;
  tmp = list->next;
  while (tmp != NULL)
    {
      i++;
      if (tmp->nb_matches > 0)
	{
	  (*line) = i;
	  return (my_rand(tmp->nb_matches));
	}
      tmp = tmp->next;
    }
  return (0);
}

/*
** Can you to get matches
** if matches == 0, call the function change_line
** else return a number random with number matches like RAND_MAX
*/
int		get_matches(t_alum *list, int *line)
{
  t_alum	*tmp;
  int		nb;

  nb = (*line);
  tmp = list->next;
  while (line != 0)
    {
      if (nb - 1 == 0)
	{
	  if (tmp->nb_matches == 0)
	    return (change_line(list, *(&line)));
	  else
	    return (my_rand(tmp->nb_matches));
	}
      tmp = tmp->next;
      nb -= 1;
    }
  return (0);
}

/*
** Player->a, it is for the difficulty medium
** Manage three algorithm
*/
void		start_ia_level(t_alum *list, int l_one_match, int nb_line,
			       t_player *player)
{
  int		line;
  int		matches;
  int		nb;

  player->a += (player->difficulty == 3) ? (2) : (1);
  nb = my_rand(nb_line);
  if (nb_line == l_one_match)
    display_message(line, remove_matches(list, search_one(list), 1), 0, player);
  else if (nb_line - l_one_match == 1)
    display_message(line, remove_matches(list, line, choose_params
  					 (list, &line, nb_line)), 0, player);
  else if (player->difficulty >= 2 &&
  	   player->a >= 2 && xor_line(list, xor(list), &line) != 0)
    display_message(line, remove_matches(list, line,
					 xor_line(list, xor(list), &line)), 0, player);
  else
    {
      line = get_line(list, nb);
      matches = get_matches(list, &line);
      display_message(line, remove_matches(list, line, matches), 2, player);
    }
}

/*
** ia begin
*/
int		ia_level(t_alum *list, t_player *player)
{
  int		l_one_match;
  int		nb_line;

  l_one_match = count_list(list, &nb_line);
  start_ia_level(list, l_one_match, nb_line, player);
  return (0);
}
