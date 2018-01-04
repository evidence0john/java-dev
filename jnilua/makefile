cc = gcc
#set your include file by your jdk env
INC_FLAG = -I /usr/lib/jvm/java-8-openjdk/include/linux/ -I /usr/lib/jvm/java-8-openjdk/include/
CFLAG = -fPIC -shared
LINK_FLAG = -llua

libjnilua.so : jnilua.c
	$(cc) -o libjnilua.so $(INC_FLAG) $(CFLAG) $(LINK_FLAG) jnilua.c
