echo "Installing Umpire: "
mkdir -p build
cd build

cmake ..
if [ $? -ne 0 ]; then
  echo "Failed to generate CMake files for Umpire, make sure CMake, Make, and GCC (Version >= 8.0) are installed."
else
  cmake --build .
  cd ..  
  if [ $? -ne 0 ]; then
    echo "Failed to build Umpire, make sure CMake, Make, and GCC (Version >= 8.0) are installed."
  else
    sudo mkdir -p /usr/local/bin
    sudo cp build/um /usr/local/bin/um
    sudo ln -s /usr/local/bin/um /usr/local/bin/umpire
    echo "Umpire is installed successfully!"
  fi
fi

