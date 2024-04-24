FROM gcc:latest
COPY program_1.c .
RUN gcc -o main program_1.c
CMD [”./main”]