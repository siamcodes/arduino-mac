import os

os.system("ffmpeg -f v4l2 -i /dev/video0  -s 640x480 -vb 1M -t 10 myvdo.avi -y")

print("done")

 