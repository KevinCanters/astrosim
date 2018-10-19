set terminal epslatex size 11.2cm, 5.8cm
set output "../latex/plots/errors_RK.tex"

TMARGIN = "set tmargin at screen 0.95; set bmargin at screen 0.60"
BMARGIN = "set tmargin at screen 0.40; set bmargin at screen 0.05"
LMARGIN = "set lmargin at screen 0.05; set rmargin at screen 0.35"
RMARGIN = "set lmargin at screen 0.60; set rmargin at screen 0.95"

set multiplot layout 2, 2 rowsfirst 
set title "Positions"
unset key
@TMARGIN; @LMARGIN
set ytics autofreq 0.5
set xtics autofreq 0.5
set mytics 2
plot '../output/RK_6_twobody.txt' u 2:3 with lines title '$10^{-4}$','' u 4:5 w l

set title "Energy error"
@TMARGIN; @RMARGIN
set xtics autofreq
set ytics (0, 4e-10, 8e-10, 1.2e-9, 1.6e-9)
set ytics format '\num{%g}'
set key left Left width -1
plot '../output/RK_6_twobody1.txt' u 1:6 with lines title '$10^{-4}$'

unset title
@BMARGIN; @LMARGIN
set ytics autofreq 0.5
set xtics autofreq 0.5
set ytics format '%g'
unset key
plot '../output/RK_6_twobody1.txt' u 2:3 with lines title '$10^{—5}$' ,'' u 4:5 w l

@BMARGIN; @RMARGIN
set ytics format '\num{%g}'
set xtics autofreq 
set ytics (0, 2e-14, 4e-14, 6e-14, 8e-14)
set key left Left width -1
plot '../output/RK_6_twobody.txt' u 1:6 with lines title '$10^{-5}$'

unset multiplot
