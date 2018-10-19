set t wxt persist
set terminal pdfcairo
set output "../plots/ho.pdf"
plot '../output/ho.txt' u 1:3 with lines
