CC=gcc
C_FLAGS=-Wall -Wextra -Werror -std=c11 
TEST_FLAGS= $(C_FLAGS) -g
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
UNIT_TESTS=$(wildcard ./unit_tests/*.c)
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, $(SRC))
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

TARGET=math.a

all: $(TARGET) gcov_report clean_all_but_report
#build: math

$(TARGET): $(OBJ)
	ar rc $@ $^
	ranlib $@
	make clean_obj

test: $(TARGET)
ifeq ($(OS), Darwin)
	$(CC) $(C_FLAGS) $(UNIT_TESTS) $< -o units_test -lcheck
else
	$(CC) $(C_FLAGS) $(UNIT_TESTS) $< -o units_test -lcheck $(LINUX_FLAGS)
endif
	./units_test

gcov_report: clean_report

ifeq ($(OS), Darwin)
	$(CC) $(C_FLAGS) $(GCOV_FLAGS) $(UNIT_TESTS) $(SRC) -o test -lcheck
else
	$(CC) $(C_FLAGS) $(GCOV_FLAGS) $(UNIT_TESTS) $(SRC) -o test -lcheck $(LINUX_FLAGS)
endif
	./test
	lcov -t "TEST" -o test.info -c -d .
	genhtml -o report test.info

brsw:
	eval /opt/goinfre/$(USERNAME)/homebrew/bin/brew shellenv; \
	brew update --force --quiet; \
	chmod -R go-w "$(brew --prefix)/share/zsh"

install_brew:
	cd /opt/goinfre/$(USERNAME); \
	mkdir homebrew; \
	git clone https://github.com/Homebrew/brew homebrew; \
	make brsw

lcov:
	brew install lcov

clean:
	rm -rf *.o *.a units_test 
	make clean_report

clean_obj:
	rm -rf $(OBJ)

clean_report:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean_all_but_report:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test