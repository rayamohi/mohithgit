a.out: filecreate.o kill.o lsm.o task2.o task4.o task6.o task12.o task13.o

filecreate.o: filecreate.c
	gcc filecreate.c
kill.o: kill.c
	gcc kill.c
lsm.o: lsm.c
	gcc lsm.c
task2.o: task2.c
	gcc task2.c
task4.o: task4.c
	gcc task4.c
task6.o: task6.c
	gcc task6.c
task12.o: task12.c
	gcc task12.c
task13.o: task13.c
	gcc task13.c
task1.o: task1.c
	gcc task1.c
