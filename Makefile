all:
	gcc client/client.c -o client/client -Wall -std=c99 -pedantic
	gcc server/server.c server/challenges.c server/utils.c -lm -o server/server -Wall -std=c99 -pedantic

clean:
	rm client/client
	rm server/server