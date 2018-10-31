#!/bin/sh

# Make wave modeling programs

INC=/home/lbk/cwp/include
LIK=/home/lbk/cwp/lib
LIB=-lsu -lpar -lcwp -lm

#zjj:zjj.c
#	gcc zjj.c -o zjj -I$(INC) -L$(LIK)  $(LIB)
#pre2frequencybyone::pre2frequencybyone.c
#	gcc pre2frequencybyone.c -o pre2frequencybyone -I$(INC) -L$(LIK)  $(LIB)
#model::model.c
#	gcc model.c -o model -I$(INC) -L$(LIK)  $(LIB)
predeconv1::predeconv1.c
	gcc predeconv1.c -o predeconv1 -I$(INC) -L$(LIK)  $(LIB)
#predeconv2D::predeconv2D.c
	gcc predeconv2D.c -o predeconv2D -I$(INC) -L$(LIK)  $(LIB)
