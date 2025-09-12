NAME = base_test

CRITERION_DIR = ${HOME}/Criterion/
CRITERION_LIB_DIR =  ${CRITERION_DIR}build/src/
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
LFLAGS = -Wl,-rpath=${CRITERION_LIB_DIR} -L${CRITERION_LIB_DIR} -lcriterion

${NAME}: ${CRITERION_LIB_DIR}${CRITERION_LIB} ${OBJS_DIR} ${OBJS}
	@echo "\n${COLOR_BCYAN}Linking...${COLOR_END}"
	${CXX} ${LFLAGS} ${CXXFLAGS} ${OBJS} -o ${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
	@echo "\n${COLOR_BCYAN}Compiling...${COLOR_END}"
	${CXX} ${IFLAGS} ${CXXFLAGS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${CRITERION_LIB_DIR}${CRITERION_LIB}:
	@echo "\n${COLOR_BCYAN}Getting and building Criterion...${COLOR_END}"
	. ${CRITERION_INSTALL_SCRIPT}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}
	rm -rf ${CRITERION_DIR}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}