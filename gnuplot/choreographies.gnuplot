set terminal epslatex size 11.2cm, 5.8cm
set output "../latex/plots/choreographies.tex"

set multiplot layout 2, 2
unset key

set title 'Butterfly'
set origin 0.0,0.5
set size 0.52,0.6
unset xtics
unset ytics
plot '../output/RK_15_butterfly2.txt' u 2:3 with lines ,'' u 4:5 w l, '' u 6:7 w l
unset key

set title 'Goggles'
set origin 0.5,0.5
set size 0.52,0.6
plot '../output/RK_20_goggles.txt' u 2:3 with lines ,'' u 4:5 w l, '' u 6:7 w l

unset key

set title 'Dragonfly'
set origin 0.0,0.0
set size 0.52,0.6
plot '../output/RK_40_dragonfly.txt' u 2:3 with lines ,'' u 4:5 w l, '' u 6:7 w l


unset key
set title 'Yin-Yang'
set origin 0.5,0.0
set size 0.52,0.6
plot '../output/RK_110_yin4.txt' u 2:3 with lines ,'' u 4:5 w l, '' u 6:7 w l

unset multiplot
