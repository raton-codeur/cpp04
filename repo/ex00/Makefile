NAME = animals
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc
SRCS = $(addprefix src/, \
	main.cpp \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \
)
OBJS = $(patsubst src/%.cpp, tmp/%.o, $(SRCS))

all : $(NAME)

tmp/%.o : src/%.cpp
	@ mkdir -p tmp
	@ c++ $(FLAGS) -c $< -o $@ && printf "."

$(NAME) : $(OBJS)
	@ echo
	@ c++ $(FLAGS) $(OBJS) -o $@

clean :
	@ rm -rf tmp && echo "clean"

fclean : clean
	@ rm -f $(NAME) && echo "fclean"

re : fclean all

.PHONY: all clean fclean re