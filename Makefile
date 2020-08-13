all: clean build run

clean:
	rm -f main libsite-parse.so 2>/dev/null || true
build:
	gcc src/*.c -lcurl -fPIC -Isrc -shared -o libsite-parse.so
	gcc example/main.c -Isrc -L. -lsite-parse -o main
	
run:
	LD_LIBRARY_PATH=./ ./main
