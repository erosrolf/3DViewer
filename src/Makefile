UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	OPEN_CMD = xdg-open
	QTFLAGS = CONFIG+=qtquickcompiler
	GTEST_LIB = /usr/lib/libgtest.a
endif
ifeq ($(UNAME), Darwin)
	OPEN_CMD = open
	LCOV_FLAG = --ignore-errors inconsistent
	QTFLAGS = -spec macx-clang CONFIG+=qtquickcompiler
	GTEST_LIB = /usr/local/lib/libgtest.a
endif

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror --coverage
LDFLAGS = -lgtest -lgtest_main -pthread
LCOV = lcov
LCOV_FLAGS = --ignore-errors inconsistent --ignore-errors mismatch
GENHTML = genhtml
COVERAGE_DIR = $(DIR_BUILD)/coverage

DIR_CORE = ./core
DIR_OBJ = ./obj
DIR_BUILD = ./build
DIR_TESTS = ./tests

LIB_NAME = $(DIR_BUILD)/core.a

SRC = $(shell find $(DIR_CORE) -type f -name '*.cc')
OBJ = $(SRC:$(DIR_CORE)/%.cc=$(DIR_OBJ)/%.o)
TEST_SRC = $(shell find $(DIR_TESTS) -type f -name '*.cc')
TEST_OBJ = $(TEST_SRC:$(DIR_TESTS)/%.cc=$(DIR_OBJ)/%.o)
TEST_EXECUTABLE = $(DIR_BUILD)/core_test

all: $(LIB_NAME) test


# CORE LIB 
$(LIB_NAME): $(OBJ)
	@mkdir -p $(DIR_BUILD)
	ar rcs $@ $(OBJ)
	@ranlib $@

$(DIR_OBJ)/%.o: $(DIR_CORE)/%.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@


# CORE TESTS
test: $(TEST_EXECUTABLE)
	@./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(OBJ) $(TEST_OBJ)
	@mkdir -p $(DIR_BUILD)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

$(DIR_OBJ)/%.o: $(DIR_TESTS)/%.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@


#GCOV REPORT
gcov_report: test
	@mkdir -p $(COVERAGE_DIR)
	# Собираем данные о покрытии кода
	$(LCOV) --capture --directory $(DIR_OBJ) --output-file $(COVERAGE_DIR)/coverage.info $(LCOV_FLAGS)
	# Фильтруем данные, исключая тесты и внешние библиотеки
	$(LCOV) --remove $(COVERAGE_DIR)/coverage.info '*/tests/*' '/usr/*' --output-file $(COVERAGE_DIR)/coverage.filtered.info
	# Генерируем HTML-отчет
	$(GENHTML) -o $(COVERAGE_DIR)/html $(COVERAGE_DIR)/coverage.filtered.info
	# Открываем HTML-отчет в браузере
	@$(OPEN_CMD) $(COVERAGE_DIR)/html/index.html

clean:
	rm -rf $(DIR_OBJ) $(DIR_BUILD)

.PHONY: all clean test
