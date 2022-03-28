CXX=g++
CXXFLAGS= -Wall -Wextra -Werror -pedantic -std=c++2a -lpthread

OBJS= $(addprefix src/, volume-list.o maximum-volume.o)
MAIN_OBJ=
TEST_OBJS= $(addprefix tests/, test.o)

main: ${OBJS} ${MAIN_OBJ}
	${CXX} -o $@ $^

test: ${TEST_OBJS} ${OBJS}
	${CXX} -o $@ $^ -lgtest -lpthread

check: test
	./test

clean:
	${RM} ${OBJS} ${TEST_OBJS} ${MAIN_OBJ} main test

.PHONY: main check test clean