PREFIX?=/usr/local
INSTALL_DIR=$(PREFIX)/include/cctest

install:
	mkdir -p $(INSTALL_DIR)
	cp -pR *.h $(INSTALL_DIR)