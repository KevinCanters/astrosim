set term epslatex size 10.8cm, 7.18cm 

set xrange [1:11]
set key left Left width -6
set ylabel 'Time (s)'
set output '../latex/plots/scalingellipses.tex'
set title 'Runge-Kutta 4, timestep \num{8e-5}' offset 0,-0.5
set multiplot layout 2,1
TMARGIN = "set tmargin at screen 0.90; set bmargin at screen 0.55"
BMARGIN = "set tmargin at screen 0.55; set bmargin at screen 0.20"
LMARGIN = "set lmargin at screen 0.10; set rmargin at screen 0.975"

f(x) = a*(x*(x-1)) + c
set ytics autofreq 1
set ylabel 'Time (s)'
unset xtics
fit f(x) '../output/ellipsest.txt' via a, c
@TMARGIN; @LMARGIN
plot '../output/ellipsest.txt' u 1:2 title '$N$-body solar system', f(x) title 'fit $0.020 \cdot N(N-1) + 0.50$'

f(x) = a*(x*(x-1)) + c
set ytics (0,1,2)
set xtics autofreq
unset title
set xlabel 'Bodies ($N$)'
set ylabel 'Time (s)'
set key width -7
fit f(x) '../output/randomt.txt' via a, c
@TMARGIN; @BMARGIN
plot '../output/randomt.txt' u 1:2 title '$N$ random initial conditions', f(x) title 'fit $0.020 \cdot N(N-1) + 0.46$'
