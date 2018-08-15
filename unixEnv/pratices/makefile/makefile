src = $(wildcard *.c)
target = $(subst .c, ,$(src))
.PHONY:all
all: $(target)

$(target): $(src)
	gcc $< -o $@
.PHONY: clean
clean:
	-rm -f $(target)
