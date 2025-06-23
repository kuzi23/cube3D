CC      := clang
CFLAGS  := -Wall -Wextra -Werror
MLX_DIR := minilibx_opengl
MLX     := -L$(MLX_DIR) -lminilibx_opengl -framework OpenGL -framework AppKit

# Directories
SRCDIR  := src
INCDIR  := includes
OBJDIR  := obj

# Sources organized by subfolder
SRC := main.c \
       cube3d.c \
       $(wildcard $(SRCDIR)/init/*.c) \
       $(wildcard $(SRCDIR)/parsing/*.c) \
       $(wildcard $(SRCDIR)/rendering/*.c) \
       $(wildcard $(SRCDIR)/events/*.c) \
       $(wildcard $(SRCDIR)/utils/*.c)

# Object files
OBJ := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Output binary
NAME := cub3D

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -I$(INCDIR) $(OBJ) $(MLX) -o $@

# Compile source files to object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Binary cleaned."

re: fclean all

.PHONY: all clean fclean re