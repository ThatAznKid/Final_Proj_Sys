startup: main.c
	gcc -o UNO main.c deck.c

run: 
	./UNO 
	
clean: 
	rm UNO
