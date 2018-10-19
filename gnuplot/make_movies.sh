mkdir -p ../latex/movies/
ffmpeg -i '../output/ffmpeg/burrau_%d.png' -vf scale="trunc(iw/2)*2:trunc(ih/2)*2" -c:v libx264 -profile:v high -pix_fmt yuv420p -g 30 -r 30 -s 800x600 "../latex/movies/burrau.mp4"
ffmpeg -i '../output/ffmpeg/yin_%d.png' -vf scale="trunc(iw/2)*2:trunc(ih/2)*2" -c:v libx264 -profile:v high -pix_fmt yuv420p -g 30 -r 30 -s 800x600 -filter:v "setpts=0.75*PTS" "../latex/movies/yin4.mp4"
ffmpeg -i '../output/ffmpeg/butterfly_%d.png' -vf scale="trunc(iw/2)*2:trunc(ih/2)*2" -c:v libx264 -profile:v high -pix_fmt yuv420p -g 30 -r 30 -s 950x712 -filter:v "setpts=0.75*PTS" "../latex/movies/butterfly.mp4"
ffmpeg -i '../output/ffmpeg/burraunon_%d.png' -vf scale="trunc(iw/2)*2:trunc(ih/2)*2" -c:v libx264 -profile:v high -pix_fmt yuv420p -g 30 -r 30 -s 800x600 -filter:v "setpts=0.75*PTS" "../latex/movies/burraunon.mp4"
ffmpeg -i '../output/ffmpeg/burrauadap_%d.png' -vf scale="trunc(iw/2)*2:trunc(ih/2)*2" -c:v libx264 -profile:v high -pix_fmt yuv420p -g 30 -r 30 -filter:v "setpts=0.25*PTS" -s 800x600 "../latex/movies/burrauadap.mp4"
