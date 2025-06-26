echo "Installing Umpire: "
mkdir -p build
cd build

cmake ..
if [ $? -ne 0 ]; then
  cmake --build .
  cd ..  
  if [ $? -ne 0 ]; then
    sudo mkdir -p /usr/local/bin
    sudo ln -s /usr/local/bin/um /usr/local/bin/umpire
    sudo cp build/um /usr/local/bin/um
    echo "Umpire is installed successfully!"
  else
    echo "Failed to build Umpire, make sure CMake, Make, and GCC (Version >= 8.0) are installed."
  fi
else
  echo "Failed to generate CMake files for Umpire, make sure CMake, Make, and GCC (Version >= 8.0) are installed."
fi

