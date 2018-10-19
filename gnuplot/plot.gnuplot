set terminal pdfcairo
set termopt enhanced

cd '../output/'
set output "Burrau_RK.pdf"
set multiplot layout 1,2 title "Burrau problem with RK timestep 10^{-5}" font ",14"
#
set title "Positions"
unset key
set xlabel 'x'
set ylabel 'y'
plot 'burrau.txt' u 2:3 w l, '' u 4:5 w l, '' u 6:7 w l

#
set title "Energy Error"
unset key
set xlabel 'time (program units)'
set ylabel 'relative energy error'
plot 'burrau.txt' u 1:8 w l 

#
unset multiplot
#
