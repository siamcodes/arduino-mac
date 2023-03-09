
# -*- coding: utf-8 -*-

import requests


ACCESS_TOKEN = "j3DX08ec0q3Tqgsld9cAWuEd9_____________"
msg = 'halo ทดสอบ'

#imgfile = './image_1.jpg'
imgfile = '../opencv2/kob131.jpg'
url = "https://notify-api.line.me/api/notify"

file = {'imageFile': open(imgfile,'rb')}
data = {'message': msg}

LINE_HEADERS = {"Authorization":"Bearer " + ACCESS_TOKEN}
session = requests.Session()
r = session.post(url, 
				headers=LINE_HEADERS,
                files=file, 
                data=data)
print(r.text)    
