##
## Makefile for Makefile in /home/cheval_8/rendu/CPE_2015_Allum1
## 
## Made by Nicolas Chevalier
## Login   <cheval_8@epitech.net>
## 
## Started on  Mon Feb  8 14:58:11 2016 Nicolas Chevalier
## Last update Sun Feb 21 22:09:29 2016 Chevalier Nicolas
##


NAME		= allum1

SRC		= src/main.c \
		  src/init.c \
		  src/ia.c \
		  src/display.c \
		  src/utils_prog.c \
		  src/error.c \
		  src/choose.c \
		  src/ia_level.c

MOD		= $(SRC:.c=.o)

LIB		= -Llib/
LIB		+= -Ilib/include -Llib/ -lmyutils

LIBMYUTILS_MAKE	= make -C lib/
LIBMYUTILS	= lib/libmyutils.a

CFLAGS		= -W -Wall -Werror -Wextra
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -Iinclude/
CFLAGS		+= -D_BSD_SOURCE -D_POSIX_SOURCE
CFLAGS		+= $(LIB)

LDFLAGS		= $(LIB)

all:		$(LIBMYUTILS) $(NAME)

$(NAME):	$(MOD)
		gcc $(MOD) -o $(NAME) $(LDFLAGS)

$(LIBMYUTILS):
	 	$(LIBMYUTILS_MAKE)

clean		:
		 rm -rf $(MOD)
		 $(LIBMYUTILS_MAKE) clean

fclean		: clean
		  rm -rf $(NAME)
		  $(LIBMYUTILS_MAKE) fclean

re:		fclean all

.PHONY:		all clean fclean re
