set term epslatex size 10.8cm, 5.34cm

set logscale y
set ytics format '%T'
set ylabel '$\Delta E\medskip(10^{x})$' offset 1,0
set xlabel 'Integration time'
set xrange [0:15]
set key above center Left width -2 maxrows 2 maxcols 2

set output '../latex/plots/deltae.tex'
plot '../output/GBS_15_3_4chain.txt' u 1:10 w l title 'GBS $\Delta t$ \num{e-3}',\
'../output/RK_15_3_4chain.txt' u 1:10 w l title 'RK $\,\Delta t$ \num{e-3}',\
'../output/RK_15_4_4chain.txt' u 1:10 w l title 'RK $\,\Delta t$ \num{e-4}',\
'../output/RK_15_5_4chain.txt' u 1:10 w l title 'RK $\,\Delta t$ \num{e-5}'
set output
