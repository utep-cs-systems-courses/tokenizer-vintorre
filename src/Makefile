CFLAGS = -g -O3

all: tokenizer

tokenizer.o: tokenizer.h 
history.o: history.h
uimain.o: tokenizer.h history.h

tokenizer: tokenizer.o history.o uimain.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer
