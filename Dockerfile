FROM gcc:latest
COPY program.c .
RUN gcc -o main program_1.c
CMD [”./main”]