###############################################################################
#                                              FILES                          #
###############################################################################
CFILES		= \
			main.c \
			funtions/check/check_arg.c funtions/check/check_map.c funtions/open_map.c \
			funtions/liberator_map.c funtions/find.c funtions/create_vector.c \
			grafic/view_map.c funtions/mod_map.c grafic/print_objets.c \
			grafic/only_render.c grafic/gfc_control.c \
			#grafic/img_to_struc.c
OBJS	=	${CFILES:.c=.o}

CLIBFT		= \
			libft/lib/ft_atoi.c libft/lib/ft_bzero.c libft/lib/ft_calloc.c \
			libft/lib/ft_isalnum.c libft/lib/ft_isalpha.c libft/lib/ft_isascii.c \
			libft/lib/ft_isdigit.c libft/lib/ft_isprint.c libft/lib/ft_memchr.c \
			libft/lib/ft_memcmp.c libft/lib/ft_memcpy.c libft/lib/ft_memmove.c \
			libft/lib/ft_memset.c libft/lib/ft_strchr.c libft/lib/ft_strdup.c \
			libft/lib/ft_strlcat.c libft/lib/ft_strlcpy.c libft/lib/ft_strlen.c \
			libft/lib/ft_strncmp.c libft/lib/ft_strnstr.c libft/lib/ft_strrchr.c \
			libft/lib/ft_tolower.c libft/lib/ft_toupper.c libft/lib/ft_substr.c \
			libft/lib/ft_strjoin.c libft/lib/ft_strtrim.c libft/lib/ft_putchar_fd.c \
			libft/lib/ft_putstr_fd.c libft/lib/ft_putendl_fd.c libft/lib/ft_putnbr_fd.c \
			libft/lib/ft_itoa.c libft/lib/ft_strmapi.c libft/lib/ft_striteri.c \
			libft/lib/ft_split.c libft/lib/ft_lstnew_bonus.c \
			libft/lib/ft_lstadd_front_bonus.c libft/lib/ft_lstsize_bonus.c \
			libft/lib/ft_lstlast_bonus.c libft/lib/ft_lstadd_back_bonus.c \
			libft/lib/ft_lstdelone_bonus.c libft/lib/ft_lstclear_bonus.c \
			libft/lib/ft_lstiter_bonus.c libft/lib/ft_lstmap_bonus.c \

OLIBFT	=	${CLIBFT:.c=.o}

CPRINTF		= \
			libft/printf/ft_printf.c \
			libft/printf/utils/ft_selectoption.c libft/printf/utils/ft_strchrp.c \
			libft/printf/utils/ft_putstr.c libft/printf/ft_options/ft_c.c \
			libft/printf/ft_options/ft_di.c libft/printf/ft_options/ft_u.c \
			libft/printf/ft_options/ft_s.c libft/printf/ft_options/ft_x.c \
			libft/printf/ft_options/ft_p.c \
			\

OPRINTF	=	${CPRINTF:.c=.o}

CGNL		= \
			libft/gnl/get_next_line.c libft/gnl/get_next_line_utils.c \
			libft/gnl/get_next_line_bonus.c
OGNL	=	${CGNL:.c=.o}

###############################################################################
#                                              SETTINGS                       #
###############################################################################
NAME = so_long
HDRS = so_long.h

NLIBRARY= libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OPGRAFIC = -lmlx -framework OpenGL -framework AppKit

AR = ar
ARFLAGS = -rcs
RM = rm -f

LIBFT = $(OLIBFT) $(OPRINTF) $(OGNL)

###############################################################################
#                                              OPTIONS                        #
###############################################################################
all: ${NAME}

${NAME}: ${NLIBRARY} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${NLIBRARY} ${OPGRAFIC} -o $@ #-fsanitize=address -g
	@echo "Created so_long."

$(NLIBRARY): $(LIBFT)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "Created LIBFT."

.c.o:
		 @${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

###############################################################################
clean:
		@${RM} ${OBJS} ${LIBFT}
		@echo "Delete .o."

fclean: clean
		@${RM} ${NLIBRARY} ${NAME}
		@echo "Delete libft.a and so_long."

re: fclean all

help:
	@echo "Options of MakeFile:"
	@echo "\tDeault: Created '${NAME}'"
	@echo "\tclean: Delete '.o'."
	@echo "\tfclean: Delete'.o', '${NLIBRARY}' and '${NAME}'"
	@echo "\tre: Delete '.o', '${NLIBRARY}', '${NAME}' and creates '${NAME}'"
	@echo "MakeFile by tvillare."

.PHONY = all clean fclean re help
