set terminal epslatex size 11.2cm, 5.8cm
set output "../latex/plots/comp_short.tex"

TMARGIN = "set tmargin at screen 0.95; set bmargin at screen 0.60"
BMARGIN = "set tmargin at screen 0.40; set bmargin at screen 0.05"
LMARGIN = "set lmargin at screen 0.05; set rmargin at screen 0.35"
RMARGIN = "set lmargin at screen 0.55; set rmargin at screen 0.95"

set size 1,1
set multiplot layout 2, 2 rowsfirst
set title "Positions"
unset key
@TMARGIN; @LMARGIN
set ytics autofreq 0.5
set xtics autofreq 0.5
set mytics 2
plot '../output/GBS_short.txt' u 2:3 with lines ,'' u 4:5 w l

set title "Energy error"
@TMARGIN; @RMARGIN
set ytics autofreq
set xtics autofreq
set ytics (0, 2e-14, 4e-14, 6e-14, 8e-14)
set ytics format '\num{%g}'
set key left Left
plot '../output/GBS_short.txt' u 1:6 with lines title 'GBS'

unset title
@BMARGIN; @LMARGIN
set ytics autofreq 0.5
set xtics autofreq 0.5
set ytics format '%g'
unset key
plot '../output/RK_short.txt' u 2:3 with lines ,'' u 4:5 w l

@BMARGIN; @RMARGIN
set ytics format '\num{%g}'
set xtics autofreq 0.1
set ytics autofreq 2e-11
set key left Left
plot '../output/RK_short.txt' u 1:6 with lines title 'RK'

unset multiplot
