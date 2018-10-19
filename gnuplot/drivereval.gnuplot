set term epslatex size 10.8cm, 5.34cm

set ylabel 'Driver evaluations ($10^x$)'
set xlabel 'Timestep ($10^x$)'
set key left Left
set xrange [1e-2:1e-5]
set xtics format '%T'
set ytics format '%T'
set logscale x
set logscale y 

set output '../latex/plots/drivereval.tex'
plot '../output/drivereval_gbs_4chain.txt' u 1:2 w l title 'GBS',\
'../output/drivereval_rk_4chain.txt' u 1:2 w l title 'RK'
set output
