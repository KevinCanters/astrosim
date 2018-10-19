set term pngcairo size 800,600 font 'CMU Bright, 11'
#set t wxt

set xrange [-5:7]
set yrange [-3:5]
system 'mkdir -p ../output/ffmpeg'
cd '../output/'
unset key
set title font 'CMU Bright, 18'
# loop variabels
n = 3
filename(n) = sprintf('ffmpeg/burrauadap_%d.png', n)

do for [i = 0:3420]{
set output filename(i)
set multiplot layout 2,1 title font 'Runge-Kutta 4 with adaptive timestep integration of the Burrau problem, 18'

set origin 0.0,0.35
set size 1,0.60
set xrange [-5:7]
set yrange [-3:5]
set ytics format '%.g'
set xlabel 'x'
set ylabel 'y'
unset logscale y
plot 'RK_adap.txt' every ::::n*i u 2:3 with lines,\
'' every ::::n*i u 4:5 with lines,\
'' every ::::n*i u 6:7 with lines,\
'' every ::n*i::n*i u 2:3 with points pointtype 7 ps 0.5 lc 1,\
'' every ::n*i::n*i u 4:5 with points pointtype 7 ps 0.5 lc 2,\
'' every ::n*i::n*i u 6:7 with points pointtype 7 ps 0.5 lc 3

set size 1,0.3
set origin 0.0,0.0
set xrange [0:70]
set yrange [1e-16:5e-7]
set logscale y
set ylabel 'Delta E (10^x)'
set xlabel 'Unit time'
set ytics format '%T'
plot 'RK_adap.txt' every ::::n*i u 1:8 with lines
unset multiplot
}
