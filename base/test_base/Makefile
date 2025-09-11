NAME = base_test

CRITERION_DIR = ${HOME}/Criterion/build/src/
CRITERION_LIB = libcriterion.a
CRITERION_INSTALL_SCRIPT = ../../criterion_install.sh

SRCS_DIR = srcs/
SRCS = ${addprefix ${SRCS_DIR}, \
		test_vector.cpp \
		test_matrix.cpp \
		utils.cpp \
	}
OBJS_DIR = objs/
OBJS = ${SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.o}
DEPS = ${SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.d}

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I../includes -I${HOME}/Criterion/include/ -MMD
LFLAGS = -Wl,-rpath=${HOME}/Criterion/build/src -L${HOME}/Criterion/build/src -lcriterion

${NAME}: ${CRITERION_DIR}${CRITERION_LIB} ${OBJS_DIR} ${OBJS}
	${CXX} ${LFLAGS} ${CXXFLAGS} ${OBJS} -o ${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp 
	${CXX} ${IFLAGS} ${CXXFLAGS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${CRITERION_DIR}${CRITERION_LIB}:
	. ${CRITERION_INSTALL_SCRIPT}


.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}
	rm -rf ${CRITERION_DIR}${CRITERION_LIB}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}