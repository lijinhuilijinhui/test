test_exe: liba  libcommon
	g++ -o test test.cpp -L. -lcommon -ldl -g -ggdb

liba: libcommon
	g++ -fPIC -shared -o liba.so a.cpp -L. -lcommon  -g -ggdb
#	g++ -fPIC -shared -o liba.so a.cpp -L. -lcommon  -g -ggdb -Wl,--version-script=my_export

libcommon:
#	g++ -fPIC -shared -o libcommon.so common.cpp   -g -ggdb
	g++ -fPIC -c -o common.o common.cpp -g -ggdb
	ar -r libcommon.a common.o
clean:
	rm -f ./*.o ./*.so ./*.a ./test

