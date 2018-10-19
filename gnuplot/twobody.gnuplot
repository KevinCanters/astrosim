set t wxt persist
set terminal pdfcairo
cd '../output'
set output "twobody.pdf"
plot 'twobody.txt' u 2:3 with lines, 'twobody.txt' u 4:5 with lines, 'twobody.txt' u 6:7 with lines, 'twobody.txt' u 8:9 with lines

