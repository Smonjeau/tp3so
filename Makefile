all:
	gcc client/client.c -o client/client
	gcc server/server.c server/challenges.c server/utils.c -lm -o server/server

clean:
	rm client/client
	rm server/server