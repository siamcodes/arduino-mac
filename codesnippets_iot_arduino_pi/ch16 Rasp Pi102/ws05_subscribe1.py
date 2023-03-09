# -*- coding: utf-8 -*-
"""
@author: kobsb
"""

import paho.mqtt.client as mqtt

mqttBroker = "192.168.43.16"
port = 1883
keepAlive = 60


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))


    client.subscribe("kob/temp")

def on_message(client, userdata, msg):
    print(msg.topic+" : "+str(msg.payload))
    
def on_subscribe(mosq, obj, mid, granted_qos):
    print("Subscribed with QoS: " + str(granted_qos))   

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.on_subscribe = on_subscribe

client.connect(mqttBroker, port, keepAlive)

client.loop_start()
