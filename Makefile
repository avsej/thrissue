test: libwrapper.so libplatform.so test.c
	$(CC) $(CFLAGS) $(LDFLAGS) -pthread -Wl,-rpath,${PWD} -L${PWD} -lplatform -lwrapper -o $@ $>

libplatform.so: platform.c
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -fPIC -o $@ $>

libwrapper.so: wrapper.c
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -fPIC -o $@ $>
