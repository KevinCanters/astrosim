set term pngcairo size 800,600 font 'CMU Bright, 11'

set xrange [-2:2]
set yrange [-1:1]
system 'mkdir -p ../output/ffmpeg'
cd '../output/'
unset key
set title font 'CMU Bright, 18'
set title 'Runge-Kutta 4 with adaptive time step integration of the Yin-Yang choreography'
# loop variabels
n = 5
filename(n) = sprintf('ffmpeg/yin_%d.png', n)

do for [i = 0:1535]{
set output filename(i)
plot 'RK_30_yin4.txt' every ::::n*i u 2:3 with lines,\
'' every ::::n*i u 4:5 with lines,\
'' every ::::n*i u 6:7 with lines,\
'' every ::n*i::n*i u 2:3 with points pointtype 7 ps 0.5 lc 1,\
'' every ::n*i::n*i u 4:5 with points pointtype 7 ps 0.5 lc 2,\
'' every ::n*i::n*i u 6:7 with points pointtype 7 ps 0.5 lc 3}
