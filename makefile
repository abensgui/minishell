CC = gcc

CFLAGS = -Wall -Wextra -Werror
CF = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

SRCS =	minishell.c\
		ft_getenv.c\
		ft_strlen.c\
		ft_strndup.c\
		parsing/ft_strjoin.c\
		parsing/ft_strdup.c\
		parsing/ft_lstadd_back_bonus.c\
		parsing/ft_lstnew_bonus.c\
		parsing/ft_join.c\
		parsing/ft_double_quote.c\
		parsing/ft_rdi_infile.c\
		parsing/ft_resize.c\
		parsing/ft_cmd.c\
		parsing/ft_quote.c\
		parsing/ft_error.c\
		parsing/ft_expand.c\
		parsing/ft_isalpha.c\
		parsing/ft_isdigit.c\
		parsing/ft_substr.c\
		parsing/error_quote.c\
		parsing/error_redi.c\
		parsing/error_pipe.c\
		parsing/free_data.c\
		parsing/ft_parce.c\
		parsing/ft_herdoc.c\
		parsing/check_redi.c\
		execution/ft_execute.c\
		execution/ft_heredoc.c\
		execution/ft_strcmp.c\
		execution/builtins/ft_builtins.c\
		execution/builtins/echo.c\
		execution/builtins/cd.c\
		execution/builtins/pwd.c\
		execution/builtins/exit.c\
		execution/builtins/env.c\
		execution/builtins/ft_strchr.c\
		execution/builtins/export.c\
		execution/builtins/ft_strjoin_env.c\
		execution/builtins/unset.c\
		execution/builtins/ft_atoi.c\
		execution/builtins/check_all_key.c\
		execution/builtins/check_start_key.c\
		execution/builtins/cmp.c\
		execution/builtins/ft_lstadd_back_export.c\
		execution/builtins/ft_lstnew_export.c\
		execution/builtins/ft_overwrite.c\
		execution/builtins/ft_sort.c\
		execution/builtins/is_not_in_env.c\
		execution/builtins/is_there_value.c\
		execution/builtins/print_export_list.c\
		execution/builtins/return_value.c\
		execution/builtins/strfind.c\
		execution/builtins/key_without_plus.c\
		execution/builtins/key_with_plus.c\
		execution/ft_itoa.c\
		execution/ft_lstsize.c\
		execution/ft_pipes.c\
		execution/ft_execve.c\
		execution/ft_split.c\
		execution/ft_redirections.c\
		execution/ft_childs.c\

OBJS = ${SRCS:.c=.o}

NAME = minishell

REM = rm -f

all : $(NAME)
$(NAME) : $(OBJS)                                                     
	$(CC) $(CFLAGS) $(OBJS) $(CFLAGS) $(CF) handle.c -o $(NAME)

clean :
	${REM} ${OBJS}

fclean : clean
	${REM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
