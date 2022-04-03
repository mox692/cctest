TEST_TARGET = basic_test
TEST_OBJS = basic_test.o basic.o

$(TEST_TARGET): $(TEST_OBJS)
	gcc -o $@ $^

%.o: %.c
	gcc -c -o $@ $^

c:;
	rm $(TEST_TARGET) *.o
