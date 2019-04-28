
all : yc_shell

SRC1= cd
SRC2= cp
SRC3= ctblank
SRC4= ls
SRC5= main
SRC6= mkdir
SRC7= mv
SRC8= pipe
SRC9= pwd
SRC10= redir
SRC11= reset
SRC12= rm
SRC13= rmblank
SRC14= rmdir
SRC15= setoper
SRC16= setopt
SRC17= chmod

yc_shell : $(SRC1).o $(SRC2).o $(SRC3).o $(SRC4).o $(SRC5).o $(SRC6).o $(SRC7).o $(SRC8).o $(SRC9).o $(SRC10).o $(SRC11).o $(SRC12).o $(SRC13).o $(SRC14).o $(SRC15).o $(SRC16).o $(SRC17).o
	gcc -o yc_shell $(SRC1).o $(SRC2).o $(SRC3).o $(SRC4).o $(SRC5).o $(SRC6).o $(SRC7).o $(SRC8).o $(SRC9).o $(SRC10).o $(SRC11).o $(SRC12).o $(SRC13).o $(SRC14).o $(SRC15).o $(SRC16).o $(SRC17).c
	strip yc_shell

$(SRC1).o: $(SRC1).c
	gcc -c $(SRC1).c

$(SRC2).o: $(SRC2).c
	gcc -c $(SRC2).c

$(SRC3).o: $(SRC3).c
	gcc -c $(SRC3).c

$(SRC4).o: $(SRC4).c
	gcc -c $(SRC4).c

$(SRC5).o: $(SRC5).c
	gcc -c $(SRC5).c

$(SRC6).o: $(SRC6).c
	gcc -c $(SRC6).c

$(SRC7).o: $(SRC7).c
	gcc -c $(SRC7).c

$(SRC8).o: $(SRC8).c
	gcc -c $(SRC8).c

$(SRC9).o: $(SRC9).c
	gcc -c $(SRC9).c

$(SRC10).o: $(SRC10).c
	gcc -c $(SRC10).c

$(SRC11).o: $(SRC11).c
	gcc -c $(SRC11).c

$(SRC12).o: $(SRC12).c
	gcc -c $(SRC12).c

$(SRC13).o: $(SRC13).c
	gcc -c $(SRC13).c

$(SRC14).o: $(SRC14).c
	gcc -c $(SRC14).c

$(SRC15).o: $(SRC15).c
	gcc -c $(SRC15).c

$(SRC16).o: $(SRC16).c
	gcc -c $(SRC16).c

$(SRC17).o: $(SRC17).c
	gcc -c $(SRC17).c

clean:
	rm -f *.o yc_shell

