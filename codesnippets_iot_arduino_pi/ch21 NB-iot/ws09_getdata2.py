
import requests
import json
import csv
import time

url = 'https://www.aismagellan.io/api/things/pull/f4503fb0-87f4--8955-_______'

filepath = './myfilecsv.txt' 	# data file



def getdata():
	r = requests.get(url)
	data = json.loads(r.content.decode())
	temp = data['Temperature'] -4 #
	humid = data['Humidity']
	press = data['Pressure']

	return [temp,humid,press]	

while True:
	row = getdata()

	with open(filepath, "a", encoding='utf-8') as outfile:
		writer = csv.writer(outfile)
		writer.writerow(row)
		print(row)

	time.sleep(2)
	