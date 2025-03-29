# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:00:00 by obouayed          #+#    #+#              #
#    Updated: 2025/03/29 16:28:41 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color definitions
include colors.mk

# Project name
NAME = claptrap

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = includes

# Header files
INCLUDES = $(INCDIR)/ClapTrap.hpp

# Source files
SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/ClapTrap.cpp

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# For progress tracking
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE = 0

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@start_time=$$(date +%s.%N); \
	echo "$(TEAL)⚙️  Assembling ClapTrap Project...$(RESET)"; \
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME); \
	end_time=$$(date +%s.%N); \
	elapsed_secs=$$(echo "$$end_time - $$start_time" | bc); \
	total_seconds=$$(echo "$$elapsed_secs / 1" | bc); \
	milliseconds=$$(echo "scale=3; ($$elapsed_secs - $$total_seconds) * 1000 / 1" | bc | awk '{printf "%.0f", $$0}'); \
	minutes=$$(echo "$$total_seconds / 60" | bc); \
	seconds=$$(echo "$$total_seconds % 60" | bc); \
	if [ $$minutes -gt 0 ]; then \
		echo "$(BOLD_GREEN)✅ Compilation successful! $(BOLD_WHITE)[Time: $${minutes}m $${seconds}s $${milliseconds}ms]$(RESET)"; \
	elif [ $$seconds -gt 0 ]; then \
		echo "$(BOLD_GREEN)✅ Compilation successful! $(BOLD_WHITE)[Time: $${seconds}s $${milliseconds}ms]$(RESET)"; \
	else \
		echo "$(BOLD_GREEN)✅ Compilation successful! $(BOLD_WHITE)[Time: $${milliseconds}ms]$(RESET)"; \
	fi

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@printf "$(LIGHT_BLUE)🛠️  Compiling [%d/%d] %s...$(RESET)\n" $(CURRENT_FILE) $(TOTAL_FILES) $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@echo "$(LIGHT_YELLOW)📂 Creating objects directory...$(RESET)"
	@mkdir -p $(OBJDIR)

# Cleaning rules
clean:
	@echo "$(ORANGE)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(LAVENDER)🗑️  Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all
	@echo "$(LIME)♻️  Project rebuilt from scratch!$(RESET)"

# Compile if necessary and run
run: all
	@echo "$(BOLD_CYAN)▶️  Running $(NAME)...$(RESET)"
	@./$(NAME)

# Rebuild from scratch and run
rerun: re
	@echo "$(BOLD_CYAN)🔄 Running $(NAME) after rebuild...$(RESET)"
	@./$(NAME)

# Debug tool for memory leaks
valgrind: $(NAME)
	@echo "$(BOLD_RED)🔍 Running Valgrind memory check...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Help message
help:
	@echo "$(BOLD_CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)      - Build the program"
	@echo "  $(GREEN)clean$(RESET)    - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)   - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)       - Rebuild from scratch"
	@echo "  $(GREEN)run$(RESET)      - Compile if needed and run"
	@echo "  $(GREEN)rerun$(RESET)    - Rebuild from scratch and run"
	@echo "  $(GREEN)valgrind$(RESET) - Run with memory leak check"
	@echo "  $(GREEN)help$(RESET)     - Show this help message"

# Phony (non-file) targets
.PHONY: all clean fclean re valgrind help run rerun