install:
	mkdir -p build
	ls
	cd build
	cmake ..
	cmake --build .
	cd ..
	sudo mkdir -p /usr/local/bin
	sudo cp build/um /usr/local/bin/um
	sudo ln -s /usr/local/bin/um /usr/local/bin/umpire	
