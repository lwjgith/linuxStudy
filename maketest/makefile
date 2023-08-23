src=$(wildcard ./src/*.c) 
obj=$(patsubst ./src/%.c, ./obj/%.o,$(src))

inc_path=./inc

myArgs= -Wall -g

ALL:a.out	

a.out:$(obj)
	gcc $^ -o $@ $(myArgs)

$(obj):./obj/%.o:./src/%.c
	gcc -c $< -o $@ $(myArgs) -I $(inc_path)

clean:
	-rm -rf $(obj) a.out
.PHONY:clean ALL #伪目标	防止同目录下有同名文件