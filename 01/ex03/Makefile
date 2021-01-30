CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f
RUN		= ./${NAME}
RFLAGS	= -C
RUNWF	= ${RUN} ${RFLAGS}

NAME	= ft_hexdump

SRCDIR	= srcs
INCDIR	= includes
TESTDIR	= tests

SRCS	= ${SRCDIR}/ft_putchar.c \
	  		${SRCDIR}/ft_putstr.c \
	  		${SRCDIR}/ft_puterr.c \
	  		${SRCDIR}/ft_display_file.c \
	  		${SRCDIR}/ft_stdin.c \
	  		${SRCDIR}/ft_atoi.c \
	  		main.c
OBJS	= ${SRCS:.c=.o}

FILE1	= ${TESTDIR}/file1.txt
FILE2	= main.c
FILES	= ${FILE1} ${FILE2}

all:		${NAME}

%.o:%.c
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCDIR}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o $@ ${OBJS}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

files:		
			@echo "Hello World from file1!" > ${FILE1}

test_err:	${NAME} files
			@echo "Should handle errors for each file.."
			@echo "---"
			-@${RUNWF} nofile1.txt ${FILES} nofile2.txt
			@echo "-"
			-@hexdump ${RFLAGS} nofile1.txt ${FILES} nofile2.txt

test_diff:	${NAME} files
			@echo "---"
			@echo " No option - Diffs should be empty.."
			@echo "---"
			@echo "Single file"
			@echo "-"
			@hexdump ${FILE1} > a
			@${RUN} ${FILE1} > b
			-@diff a b > ${TESTDIR}/test_single.txt
			@rm a b
			@cat ${TESTDIR}/test_single.txt
			
t_backup:
			@echo "\n"
			@echo "---"
			@echo "Multiple files"
			@echo "-"
			@hexdump ${RFLAGS} ${FILES} > a
			@${RUNWF} ${FILES} > b
			-@diff a b > ${TESTDIR}/test_multiple.txt
			@rm a b
			@cat ${TESTDIR}/test_multiple.txt
			

tests:		test_diff test_err

.PHONY : 	re fclean clean all file
