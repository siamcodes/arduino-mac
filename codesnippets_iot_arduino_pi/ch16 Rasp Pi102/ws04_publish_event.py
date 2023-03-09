#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
@author: kobsb
"""

import paho.mqtt.client as mqtt
import time

mqttBroker = "192.168.43.16"
port = 1883
keepAlive = 60

temperature = 10

def on_connect(client, userdata, flags, rc):
    print("CONNACK received with code %d." % (rc))
    client.publish("kob/temp", "Hello World! กอบเกียรติ") 

def on_publish(client, userdata, mid):
    print("published... "+str(mid))

client = mqtt.Client()
client.on_connect = on_connect
client.on_publish = on_publish

client.connect(mqttBroker, port, keepAlive)
client.loop_start()

while True:
    temperature += 1  # read data from thermometer
    (rc,mid) = client.publish("kob/temp", "Temp "+str(temperature) + " C")    
    time.sleep(2)
    
    
