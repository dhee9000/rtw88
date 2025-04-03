export STAGING_DIR=/home/dheeraj/Repos/openwrt-sdk-ramips-1907/staging_dir
export PATH=$STAGING_DIR/toolchain-mipsel_24kc_gcc-7.5.0_musl/bin:$PATH

export KSRC=/home/dheeraj/Repos/openwrt-sdk-ramips-1907/build_dir/target-mipsel_24kc_musl/linux-ramips_mt7621/linux-4.14.195

make ARCH=mips CROSS_COMPILE=mipsel-openwrt-linux- KSRC=$KSRC