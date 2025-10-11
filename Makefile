install:
	mkdir -p build
	cd build
	cmake .
	cmake --build .
	sudo mkdir -p /usr/local/bin
	sudo cp um /usr/local/bin/um
	sudo ln -s /usr/local/bin/um /usr/local/bin/umpire	
