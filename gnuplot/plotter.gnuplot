set terminal epslatex size 11.2cm, 5.8cm
set output "../latex/plots/harmonic_GBS.tex"

set multiplot layout 1, 2
set title "Position"
set key at graph 0.775, graph 0.95 Left width -2 samplen 2
set ytics 0.5
plot '../output/GBS_6_test.txt' u 1:2 with lines title "GBS", cos(x) title "cos(x)"
#
set title "Energy error"
unset key
set ytics autofreq 2e-15
plot '../output/GBS_6_test.txt' u 1:4 with lines

unset multiplot
