# line01.py ok for python 2 , 3
# -*- coding: utf-8 -*-

import requests

url = 'https://notify-api.line.me/api/notify'
token = 'j3DX08ec0q3Tqgsld9cAWuEd___________'
#headers = {'content-type':'application/x-www-form-urlencoded','Authorization':'Bearer '+token}
data = {'message':'hello ทดสอบจ้า'}

headers = {'Authorization':'Bearer ' + token}

r = requests.post(url, headers=headers, data=data)
print(r.text)
