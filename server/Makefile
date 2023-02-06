all: database server

database: createDB.c
	gcc -o database createDB.c -lpthread `pkg-config --libs mysqlclient`
server: server.c serverFunction.c
	gcc -pthread -o server server.c serverFunction.c -lpthread `pkg-config --libs mysqlclient`

clean:
	rm -f database server