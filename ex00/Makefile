NAME = add_sub_sca_test

SRCS_DIR_BASE = ../base/test_base/srcs
SRCS_DIR_ADD_SUB_SCA = ./srcs

vpath %.cpp $(SRCS_DIR_BASE) \
			$(SRCS_DIR_ADD_SUB_SCA)

SRCS = 	test_vector.cpp \
		test_matrix.cpp \
		utils.cpp \
		test_add.cpp \
		test_sub.cpp \

OBJS_DIR = objs/
OBJS = ${SRCS:%.cpp=${OBJS_DIR}%.o}

DEPS = ${SRCS:%.cpp=${OBJS_DIR}%.d}

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I../base/includes \
		 -I../base/includes/add_sub_scale \
		 -I${HOME}/Criterion/include/ \
		 -MMD
LFLAGS = -Wl,-rpath=${HOME}/Criterion/build/src -L${HOME}/Criterion/build/src -lcriterion

${NAME}: ${OBJS_DIR} ${OBJS}
	echo ${DEPS}
	${CXX} ${LFLAGS} ${CXXFLAGS} ${OBJS} -o ${NAME}

${OBJS_DIR}%.o: %.cpp 
	${CXX} ${IFLAGS} ${CXXFLAGS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

.PHONY: all
all: echo 

.PHONY: clean
clean:
	rm -rf ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}