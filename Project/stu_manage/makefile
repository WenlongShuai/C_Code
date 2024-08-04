src1=stu_sort.c
src2=stu_link.c
src3=main.c

name=main
CC=gcc
opt=-o


$(name):main.o stu_sort.o stu_link.o
	$(CC) main.o stu_sort.o stu_link.o $(opt) $@
main.o:$(src3)
	$(CC) -c $(src3) $(opt) $@
stu_link.o:$(src2)
	$(CC) -c $(src2) $(opt) $@
stu_sort.o:$(src1)
	$(CC) -c $(src1) $(opt) $@

clean:
	rm *.o

