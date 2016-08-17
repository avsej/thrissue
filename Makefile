test: libwrapper.so libplatform.so plugin.so test.o
	$(CC) $(CFLAGS) $(LDFLAGS) -pthread -Wl,-rpath,${PWD} -L${PWD} -lwrapper -lplatform test.o -o $@

test.o: test.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) -o $@ $>

libplatform.so: platform.c
	$(CC) $(CFLAGS) $(LDFLAGS) -pthread -fPIC -shared -o $@ $>

libwrapper.so: wrapper.c
	$(CC) $(CFLAGS) $(LDFLAGS) -pthread -fPIC -shared -o $@ $>

plugin.so: plugin.c
	$(CC) $(CFLAGS) $(LDFLAGS) -pthread -fPIC -shared -o $@ $>

clean:
	rm -rf *.so *.o test
