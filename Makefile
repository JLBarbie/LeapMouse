NAME=LeapMouse
SRC=src/main.cpp
RM=rm

all: install

install:
	g++ $(SRC) -o $(NAME) -lLeap -lX11

fclean:
	$(RM) $(NAME)
