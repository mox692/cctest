TEST_TARGET = basic_test
TEST_OBJS = basic_test.o basic.o

$(TEST_TARGET): $(TEST_OBJS)
	g++ -o $@ $^

%.o: %.c
	g++ -c -o $@ $^

c:;
	rm $(TEST_TARGET) *.o
