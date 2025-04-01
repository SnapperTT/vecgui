#!/bin/bash
#if [ "$1" != "" ]; then
#	IS_STTR_ENABLED="-DSTTR_ENABLED=1"
#else
#	IS_STTR_ENABLED=""
#fi

#STTR_CLASS_REG_DEF=`sed 's/STTR_CLASS_SIG //' sttr_compat_macros.def | head -n 1`
#../../tools-nondist/lzz *.lzz $IS_STTR_ENABLED -hx hh && \
#../../tools-nondist/lzz example.lzz -hx hh && \
#touch ../../src/vecguiWrapper.lzz

g++ example.cpp -I .. -g -Wall `pkg-config --cflags --libs sdl3` -o example

