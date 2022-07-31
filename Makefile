NAME				=	so_long

CC 					= 	gcc
CFLAGS 				= 	
SRC_DIR				=	src
LIB_FT				=	Libft
LIB_GNL				=	Gnl
LIB_PRINTF			=	printf
SOURCES				=	$(LIB_GNL)/get_next_line.c \
						$(LIB_GNL)/get_next_line_utils.c \
						$(SRC_DIR)/print_hello.c

MAIN_SOURCES		= 	$(SRC_DIR)/main.c $(SOURCES)
OBJS				= 	$(MAIN_SOURCES:.c=.o)
LIB_MINILIBX		=	minilibx
CFLAGS_MINILIBX		= 	-L . -lmlx -framework OpenGL -framework AppKit
LIB_MINILIBX_NAME	=	libmlx.a

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

$(NAME): $(OBJS)
	@echo "\n\n$(GREEN)Compiling libft$(RESET)\n\n"
	make -C $(LIB_FT)
	@echo "\n\n$(RED)Compiling printf$(RESET)\n\n"
	make -C $(LIB_PRINTF)
	@echo "\n\n$(YELLOW)Compiling minilibx$(RESET)\n\n"
	make -C $(LIB_MINILIBX)
	cp $(LIB_MINILIBX)/libmlx.a .
	$(CC) $(CFLAGS) $(CFLAGS_MINILIBX) $(OBJS) $(LIB_FT)/libft.a $(LIB_PRINTF)/libftprintf.a libmlx.a -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS) $(NAME) libft.a libmlx.a
	make fclean -C $(LIB_FT)
	make fclean -C $(LIB_PRINTF)
	make clean -C $(LIB_MINILIBX)

.PHONY: all



















#$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) $(CFLAGS) -c $< -o $@