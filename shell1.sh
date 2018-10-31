#! /bin/sh

xgraph < data.dat n1=1000 d1=1 nplot=1 title="data" label1="t" label2="x" x2beg=-1 x2end=1 &

xgraph < prede1.dat n1=1000 d1=1 nplot=1 title="prede" label1="t" label2="x" x2beg=-1 x2end=1 &

xgraph < result1.dat n1=1000 d1=1 nplot=1 title="result" label1="t" label2="x" x2beg=-1 x2end=1 &

cat data.dat prede1.dat > all1.dat &

xgraph < all1.dat n1=1000 d1=1 nplot=2 title="compare" label1="t" label2="x" x2beg=-1 x2end=1 &
