NAME = mat_mul_test
NAME_DEBUG = debug_test

CRITERION_DIR = ${HOME}/Criterion/
CRITERION_LIB_DIR =  ${CRITERION_DIR}build/src/
CRITERION_LIB = libcriterion.a
CRITERION_INSTALL_SCRIPT = ../criterion_install.sh

COLOR_BCYAN = \e[1;96m
COLOR_END = \e[0m

SRCS_DIR_BASE = ../base/test_base/srcs
SRCS_DIR_ADD_SUB_SCA = ../ex00/srcs
SRCS_DIR_LIN_CMB = ../ex01/srcs
SRCS_DIR_LERP = ../ex02/srcs
SRCS_DIR_DOT_PRD = ../ex03/srcs
SRCS_DIR_NORM = ../ex04/srcs
SRCS_DIR_COSINE = ../ex05/srcs
SRCS_DIR_CRO_PRD = ../ex06/srcs
SRCS_MAT_MUL_PRD = ./srcs

vpath %.cpp $(SRCS_DIR_BASE) \
			$(SRCS_DIR_ADD_SUB_SCA) \
			$(SRCS_DIR_LIN_CMB) \
			$(SRCS_DIR_LERP) \
			$(SRCS_DIR_DOT_PRD) \
			$(SRCS_DIR_NORM) \
			$(SRCS_DIR_CRO_PRD) \
			$(SRCS_DIR_COSINE) \
			$(SRCS_MAT_MUL_PRD)

SRCS = 	test_vector.cpp \
		test_matrix.cpp \
		utils.cpp \
		test_add.cpp \
		test_sub.cpp \
		test_scl.cpp \
		test_lin_cmb.cpp \
		test_lerp.cpp \
		test_dot_product.cpp \
		test_norm.cpp \
		test_cosine.cpp \
		test_cross_product.cpp \
		test_mat_mul.cpp

SRCS_DEBUG =	debug.cpp \
				utils.cpp \

OBJS_DIR = objs/
OBJS = ${SRCS:%.cpp=${OBJS_DIR}%.o}
OBJS_DEBUG = ${SRCS_DEBUG:%.cpp=${OBJS_DIR}%.o}

DEPS = ${SRCS:%.cpp=${OBJS_DIR}%.d}
DEPS_DEBUG = ${SRCS_DEBUG:%.cpp=${OBJS_DIR}%.d}

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I../base/includes \
		 -I../ex00/includes \
		 -I../ex01/includes \
		 -I../ex02/includes \
		 -I../ex03/includes \
		 -I../ex04/includes \
		 -I../ex05/includes \
		 -I../ex06/includes \
		 -I./includes \
		 -I${HOME}/Criterion/include/ \
		 -MMD
LFLAGS = -Wl,-rpath=${CRITERION_LIB_DIR} -L${CRITERION_LIB_DIR} -lcriterion

${NAME}: ${CRITERION_LIB_DIR}${CRITERION_LIB} ${OBJS_DIR} ${OBJS}
	@echo "\n${COLOR_BCYAN}Linking...${COLOR_END}"
	${CXX} ${LFLAGS} ${CXXFLAGS} ${OBJS} -o ${NAME}

${NAME_DEBUG}: ${CRITERION_LIB_DIR}${CRITERION_LIB} ${OBJS_DIR} ${OBJS_DEBUG}
	@echo "\n${COLOR_BCYAN}Linking...${COLOR_END}"
	${CXX} ${LFLAGS} ${CXXFLAGS} ${OBJS_DEBUG} -o ${NAME_DEBUG}

${OBJS_DIR}%.o: %.cpp
	@echo "\n${COLOR_BCYAN}Compiling...${COLOR_END}"
	${CXX} ${IFLAGS} ${CXXFLAGS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${CRITERION_LIB_DIR}${CRITERION_LIB}:
	@echo "\n${COLOR_BCYAN}Getting and building Criterion...${COLOR_END}"
	. ${CRITERION_INSTALL_SCRIPT}

.PHONY: all
all: ${NAME} ${NAME_DEBUG}

.PHONY: debug
debug: ${NAME_DEBUG}

.PHONY: clean
clean:
	rm -rf ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}
	rm -rf ${NAME_DEBUG}
	rm -rf ${CRITERION_DIR}

.PHONY: re
re: fclean
	make -C . --no-print-directory

-include ${DEPS} ${DEPS_DEBUG}