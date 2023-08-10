СXX:=g++
CXXFLAGS:=-std=c++11

SRC:=$(wildcard ./lib/*.cc)
OBJ:=$(patsubst %.cc,%.o,$(SRC))
HEADER:=s21_matrix_oop.h

$(OBJ): $(SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

tell:
	echo $(SRC)

all: test s21_matrix_oop.a

test: gtest_install
	cmake -S . -B build
	cmake --build build
	cd build && ctest --rerun-failed --output-on-failure

s21_matrix_oop.a: $(OBJ)
	ar rcs s21_matrix_oop.a lib/*.o
	ranlib s21_matrix_oop.a

gtest_install:
	if test ! -d googletest; \
	then \
	`git clone https://github.com/google/googletest.git -b v1.13.0`; \
	cd googletest; cmake -B build googletest/build ..; \
	fi

gtest_uninstall:
	rm -rf googletest

coverage: test
	mkdir report 
	gcovr --verbose --html-details report/coverage.html  -r s21_matrix_oop .

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=_valgrind_res.txt ./build/s21_matrix_tests

leaks: test
	leaks -atExit -- ./build/s21_matrix_tests

style:
	clang-format -n lib/*.cc *.h
	clang-format -n tests/*.cc

retest: clean test

cppcheck:
	cppcheck --std=c++11 --language=c++ --enable=all --suppress=unusedFunction --suppress=missingIncludeSystem lib/*.cc *.h

clean:
	rm -rf build report *.o *.a *.html *.css _valgrind_res.txt lib/*.o