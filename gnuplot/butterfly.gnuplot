set term pngcairo size 950,712 font 'CMU Bright, 11'

set xrange [-1.5:1.5]
set yrange [-0.15:0.15]
system 'mkdir -p ../output/ffmpeg'
cd '../output/'
unset key
set title font 'CMU Bright, 18'
set title 'GBS with adaptive time step integration of the Butterfly choreography'
# loop variabels
n = 5
filename(n) = sprintf('ffmpeg/butterfly_%d.png', n)

do for [i = 0:4450]{
set output filename(i)
plot 'GBS_200_butterfly4.txt' every ::::n*i u 2:3 with lines,\
'' every ::::n*i u 4:5 with lines,\
'' every ::::n*i u 6:7 with lines,\
'' every ::n*i::n*i u 2:3 with points pointtype 7 ps 0.5 lc 1,\
'' every ::n*i::n*i u 4:5 with points pointtype 7 ps 0.5 lc 2,\
'' every ::n*i::n*i u 6:7 with points pointtype 7 ps 0.5 lc 3}
