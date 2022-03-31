#! /bin/sh
#
# Tentative script to allow compilation without Eclipse.
# Must be launched from the project base directory.

# Argument: just one or all
SOURCE="*.cpp"
if [ -n "$1" ]; then
	SOURCE=$1
fi

PROJ_DIR=$(pwd)
CIEPKI_DIR=$PROJ_DIR/cie-pkcs11
CIESDK_DIR=$PROJ_DIR/cie_sign_sdk
TARGET_DIR=$PROJ_DIR/Debug

INCLUDE="-I/usr/include/PCSC -I$CIEPKI_DIR/Util -I$CIEPKI_DIR/PKCS11"

GOPT="-D__STDC_LIB_EXT1__ -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -pthread"

# Set NO_DEP to use native libraries
if [ -z "$NO_DEP" ]; then
	DEPENDENCIES="-L$CIESDK_DIR/Dependencies/zlib
	 -L$CIESDK_DIR/Dependencies/openssl
	 -L$CIESDK_DIR/Dependencies/libiconv
	 -L$CIESDK_DIR/Dependencies/libpng
	 -L$CIEPKI_DIR
	 -L$CIEPKI_DIR/Sign
	 -L$CIESDK_DIR/Dependencies/bzip2
	 -L$CIESDK_DIR/Dependencies/fontconfig
	 -L$CIESDK_DIR/Dependencies/freetype
	 -L$CIESDK_DIR/Dependencies/libcurl
	 -L$CIESDK_DIR/Dependencies/libxml2
	 -L$CIESDK_DIR/Dependencies/podofo"

	LIBS="-lcryptopp -lssl -lfontconfig -lcurl -lbz2 -lfreetype -lpng16 -lz -lcie_sign_sdk -lcrypto -lpcsclite -lxml2 -lpodofo"
else
	unset DEPENDENCIES
	GOPT="-DDEFINE_CFuncCallInfo $GOPT"
	LIBS="-Wl,-Bstatic -lcrypto++ -Wl,-Bdynamic -lpcsclite -lxml2 -lcrypto"
fi


if cd $TARGET_DIR; then
	ALL_OBJ=""
	failed=1
	for src in $(find ../cie-pkcs11 -type f -name $SOURCE); do
		failed=1
		obj=$(echo $src| sed -e 's/^\.\.\///' -e 's/.cpp$/.o/')
		mkdir -p $(dirname $obj) || break
		echo "Compile $src"
		g++ $INCLUDE $GOPT -o $obj $src || break
		ALL_OBJ="$ALL_OBJ $obj"
		failed=0
	done

	if [ $failed = 0 ]; then
		echo "Linking with $LIBS"
		#g++ $DEPENDENCIES -Xlinker --undefined=EVP_idea_cbc -Xlinker --undefined=TLS_client_method -Xlinker --undefined=curl_global_init -Xlinker --undefined=png_get_valid -Xlinker --undefined=FcInitLoadConfigAndFonts -shared -pthread -o libcie-pkcs11.so $ALL_OBJ $LIBS && echo "Link ok"
		g++ $DEPENDENCIES -shared -pthread -o libcie-pkcs11.so $ALL_OBJ $LIBS && echo "Link ok"
	fi
fi



