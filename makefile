startup: main.c
	gcc -o UNO main.c deck.c commands.c helperFxns.c

run: 
	./UNO 
	
clean: 
	rm UNO 
