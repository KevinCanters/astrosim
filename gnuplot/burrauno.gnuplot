set term pngcairo size 800,600 font 'CMU Bright, 11'

set xrange [-5:7]
set yrange [-3:5]
system 'mkdir -p ../output/ffmpeg'
cd '../output/'
unset key
set title font 'CMU Bright, 18'
# loop variabels
n = 2
filename(n) = sprintf('ffmpeg/burraunon_%d.png', n)

do for [i = 0:118]{
set output filename(i)
set multiplot layout 2,1 title font 'Runge-Kutta 4 integration of the Burrau problem, 18'

set origin 0.0,0.35
set size 1,0.60
set xrange [-5:7]
set yrange [-3:5]
set ytics format '%.g'
set xlabel 'x'
set ylabel 'y'
unset logscale y
plot 'RK_noadap.txt' every ::::n*i u 2:3 with lines,\
'' every ::::n*i u 4:5 with lines,\
'' every ::::n*i u 6:7 with lines,\
'' every ::n*i::n*i u 2:3 with points pointtype 7 ps 0.5 lc 1,\
'' every ::n*i::n*i u 4:5 with points pointtype 7 ps 0.5 lc 2,\
'' every ::n*i::n*i u 6:7 with points pointtype 7 ps 0.5 lc 3

set size 1,0.3
set origin 0.0,0.0
set xrange [0:15]
set yrange [1e-16:1e-10]
set logscale y
set ylabel 'Delta E (10^x)'
set xlabel 'Unit time'
set ytics format '%T'
plot 'RK_noadap.txt' every ::::n*i u 1:8 with lines
unset multiplot
}

do for [i = 119:550]{
set output filename(i)
set multiplot layout 2,1 title font 'Runge-Kutta 4 integration of the Burrau problem, 18'

set origin 0.0,0.35
set size 1,0.60
set xrange [-5:7]
set yrange [-3:5]
set ytics format '%.g'
unset logscale y
set xlabel 'x'
set ylabel 'y'
plot 'RK_noadap.txt' every ::::n*i u 2:3 with lines,\
'' every ::::n*i u 4:5 with lines,\
'' every ::::n*i u 6:7 with lines,\
'' every ::n*i::n*i u 2:3 with points pointtype 7 ps 0.5 lc 1,\
'' every ::n*i::n*i u 4:5 with points pointtype 7 ps 0.5 lc 2,\
'' every ::n*i::n*i u 6:7 with points pointtype 7 ps 0.5 lc 3

set size 1,0.3
set origin 0.0,0.0
set xrange [0:15]
set yrange [1e-3:1e-1]
set logscale y
set xlabel 'x'
set ylabel 'y'
set ytics format '%T'
set ylabel 'Delta E (10^x)'
set xlabel 'Unit time'
plot 'RK_noadap.txt' every ::::n*i u 1:8 with lines
unset multiplot
}

do for [i = 550:820]{
set output filename(i)
set multiplot layout 2,1 title font 'Runge-Kutta 4 integration of the Burrau problem, 18'

set origin 0.0,0.35
set size 1,0.60
set xrange [-5:7]
set yrange [-3:5]
set ytics format '%.g'
unset logscale y
plot 'RK_noadap.txt' every ::::n*i u 2:3 with lines,\
'' every ::::n*i u 4:5 with lines,\
'' every ::::n*i u 6:7 with lines,\
'' every ::n*i::n*i u 2:3 with points pointtype 7 ps 0.5 lc 1,\
'' every ::n*i::n*i u 4:5 with points pointtype 7 ps 0.5 lc 2,\
'' every ::n*i::n*i u 6:7 with points pointtype 7 ps 0.5 lc 3

set size 1,0.3
set origin 0.0,0.0
set xrange [0:15]
set yrange [1e-1:1e4]
set logscale y
set ytics format '%T'
set ylabel 'Delta E (10^x)'
set xlabel 'Unit time'
plot 'RK_noadap.txt' every ::::n*i u 1:8 with lines
unset multiplot
}
