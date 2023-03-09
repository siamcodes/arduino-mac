#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
@author: kobsb
"""

import paho.mqtt.client as mqtt
print("test publishing")

mqttBroker = "iot.eclipse.org"  # 
port = 1883
keepAlive = 60

def on_publish(client, userdata, mid):
    print("published.. " + str(mid))

client = mqtt.Client()
client.on_publish = on_publish
client.connect(mqttBroker, port, keepAlive)

client.publish("kob/temp", "Hello World! python กอบเกียรติ") # topic/level2
client.disconnect(); 

print("bye..")