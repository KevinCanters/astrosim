set term epslatex size 10.8cm, 5.34cm

set ylabel 'y'
set xlabel 'x'
unset key
 
set output '../latex/plots/supereight.tex'
plot '../output/GBS_10_4chain.txt' u 2:3 w l, '' u 4:5 w l, '' u 6:7 w l, '' u 8:9 w l
set output
