pkgname="umpire"
pkgver="v1.0"
pkgrel=1
pkgdesc="A blazingly fast competitive programming helper"
arch=("x86_64" "aarch64")
source=("$pkgname-$pkgver.tar.gz::https://github.com/udontur/umpire/archive/refs/tags/v1.0-beta.tar.gz")
url="https://github.com/udontur/umpire"
makedepends=("cmake" "make" "gcc")
depends=("gcc" "fmt" "boost" "argparse")
sha512sums=("SKIP")
license=("GPL3")
build() {
    mkdir -p build
    cd build
    cmake ..
    cmake --build .
}
package() {
    mkdir -p "${pkgdir}/usr/bin"
    cp build/result/bin/um "${pkgdir}/usr/bin/"
    ln -s "${pkgdir}/usr/bin/um" "${pkgdir}/usr/bin/umpire"
}
