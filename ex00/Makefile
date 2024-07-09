NAME = add_sub_sca_test
NAME_DEBUG = debug_test

SRCS_DIR_BASE = ../base/test_base/srcs
SRCS_DIR_ADD_SUB_SCA = ./srcs

vpath %.cpp $(SRCS_DIR_BASE) \
			$(SRCS_DIR_ADD_SUB_SCA)

SRCS = 	test_vector.cpp \
		test_matrix.cpp \
		utils.cpp \
		test_add.cpp \
		test_sub.cpp \

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
		 -I../base/includes/add_sub_scale \
		 -I${HOME}/Criterion/include/ \
		 -MMD
LFLAGS = -Wl,-rpath=${HOME}/Criterion/build/src -L${HOME}/Criterion/build/src -lcriterion

.PHONY: all
all: ${NAME} ${NAME_DEBUG}

${NAME}: ${OBJS_DIR} ${OBJS}
	${CXX} ${LFLAGS} ${CXXFLAGS} ${OBJS} -o ${NAME}

${NAME_DEBUG}: ${OBJS_DIR} ${OBJS_DEBUG}
	${CXX} ${LFLAGS} ${CXXFLAGS} ${OBJS_DEBUG} -o ${NAME_DEBUG}


${OBJS_DIR}%.o: %.cpp 
	${CXX} ${IFLAGS} ${CXXFLAGS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

.PHONY: debug
debug: ${NAME_DEBUG}

.PHONY: clean
clean:
	rm -rf ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}
	rm -rf ${NAME_DEBUG}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS} ${DEPS_DEBUG}