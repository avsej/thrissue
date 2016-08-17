test: libwrapper.so test.c
	$(CC) $(CFLAGS) $(LDFLAGS) -pthread -Wl,-rpath,${PWD} -L${PWD} -lwrapper -o $@ $>


libwrapper.so: wrapper.c
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -fPIC -o $@ $>
