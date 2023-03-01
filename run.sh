#!/bin/sh

OUTPUT=lib/x86_64

platform=`uname -m`
echo $platform
if [ $platform = 'x86_64' ];then
	export EXE_NAME=_x86_64
	export OUTPUT=lib/x86_64
else
	export EXE_NAME=_x86
	export OUTPUT=lib/x86
fi

gcc sample.cpp -L${OUTPUT} -ldevicesdk -lrt -o sample


if [ ! -x "/dev/ttyUSB0" ]; then
	chmod 777 /dev/ttyUSB0
fi

export LD_LIBRARY_PATH=${OUTPUT}/:${LD_LIBRARY_PATH}
./sample
