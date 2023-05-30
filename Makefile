#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:48:25 by yetay             #+#    #+#              #
#    Updated: 2023/05/25 17:46:24 by yetay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ..

MANDATORY = ft_isalpha ft_isdigit ft_isalnum ft_isascii \
            ft_isprint ft_strlen ft_memset ft_bzero \
            ft_memcpy ft_memmove ft_strlcpy ft_strlcat \
            ft_toupper ft_tolower ft_strchr ft_strrchr \
            ft_strncmp ft_memchr ft_memcmp ft_strnstr \
            ft_atoi ft_calloc ft_strdup \
            ft_substr ft_strjoin ft_strtrim ft_split \
            ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
            ft_putstr_fd ft_putendl_fd ft_putnbr_fd

BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
        ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
        ft_lstmap

TESTS = $(MANDATORY) $(BONUS)

CC = cc

CFLAGS = -Wall -Wextra -Werror

TEST_CFLAGS = -fsanitize=address $(CFLAGS)

ALL_SOURCES = $(foreach f, $(TESTS), $(LIBFT_DIR)/$(f).c)

.PHONY: mandatory mmsg bonus bmsg all $(TESTS)

mandatory: mmsg $(MANDATORY)
	@echo "DONE!"

mmsg:
	@echo "Checking mandatory functions..."

bonus: bmsg $(BONUS)
	@echo "DONE!"

bmsg:
	@echo "Checking bonus functions..."

all: $(MANDATORY) $(BONUS)

$(TESTS): $(ALL_SOURCES) $(addsuffix /main.c, $@)
	@echo "Running tests for $@"
	@$(CC) -I$(LIBFT_DIR) $(TEST_CFLAGS) $(ALL_SOURCES) $(addsuffix /main.c, $@)
	@./a.out
	@rm -rf a.out
