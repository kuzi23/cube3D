# **************************************************************************** #
#                              Makefile for cub3D                              #
# **************************************************************************** #

# Compiler & flags
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -g
MLX     := -lmlx -lX11 -lXext -lm

# Directories
SRCDIR  := src
INCDIR  := includes
OBJDIR  := obj

# Sources organized by subfolder
SRC     := main.c \
           cube3d.c \
           $(SRCDIR)/init/init_game.c \
           $(SRCDIR)/init/init_textures.c \
           $(SRCDIR)/parsing/parser.c \
           $(SRCDIR)/parsing/map_check.c \
           $(SRCDIR)/parsing/utils_parser.c \
           $(SRCDIR)/rendering/raycaster.c \
           $(SRCDIR)/rendering/draw_walls.c \
           $(SRCDIR)/rendering/draw_minimap.c \
           $(SRCDIR)/events/controls.c \
           $(SRCDIR)/events/exit.c \
           $(SRCDIR)/minilibx_linux/*\
           $(SRCDIR)/utils/error.c \
           $(SRCDIR)/utils/math_utils.c

# Object files
OBJ     := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Output binary
NAME    := cub3D

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@ $(MLX)

# Compile source files to object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Binary cleaned."

re: fclean all

.PHONY: all clean fclean re
