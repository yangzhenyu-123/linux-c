src = $(wildcard ./*.c)
#读取所有.c文件
obj = $(patsubst %.c, %.o, $(src))
#obj = $(src:%.c=%.o) 把所有.c --> .o
target = app
#目标文件app
CC = gcc

$(target): $(obj)	
	$(CC) $(obj) -o $(target)   
%.o: %.c
	$(CC) -c $< -o $@
#把所有.c  转换为.o
.PHONY: clean
clean:
	rm -rf $(obj) $(target)
