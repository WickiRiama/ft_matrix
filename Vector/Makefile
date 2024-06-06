NAME = vec_test

SRCS_DIR = srcs/
SRCS = ${addprefix ${SRCS_DIR}, \
	main.cpp \
	}

OBJS_DIR = objs/
OBJS = ${SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.o}
DEPS = ${SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.d}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./includes -I${HOME}/Criterion/include/criterion -MMD
LFLAGS = -L${HOME}/Criterion/build/src -lcriterion

${NAME}: ${OBJS_DIR} ${OBJS}
	echo "objs" ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp 
	${CXX} ${CXXFLAGS} -c $< -o $@ ${IFLAGS}

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}%