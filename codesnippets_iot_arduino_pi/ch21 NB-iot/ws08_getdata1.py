

import requests
import json

url = 'https://www.aismagellan.io/api/things/pull/f4503fb0-87f4-11e8-8955-_____'

r = requests.get(url)
data = json.loads(r.content.decode())
print(data)
temp = data['Temperature'] 
humid = data['Humidity']
press = data['Pressure']
print('Temp =', temp)
print('Humid =', humid)
print('Pressure', press)

