
# -*- coding: utf-8 -*-


import paho.mqtt.client as mqtt


mqttBroker = "iot.eclipse.org"

port = 1883
keepAlive = 30

print(mqttBroker)

#LWT
willTopic = "lastwill/iot-temp"
willMessage = "iot-temp is DEAD!!!!"
willQos = 1
willRetain = False
iAmBack = "iot-temp is Online ja9"


def on_connect(client, userdata, flags, rc):
    print("CONNACK received with code %d." % (rc))
    client.publish("kob/temp", "Hello World! กอบเกียรติ") 
    client.publish("lastwill/iot-temp", iAmBack)
    

client = mqtt.Client()
client.will_set(willTopic, payload=willMessage, qos=willQos, retain=willRetain)
client.on_connect = on_connect
client.connect(mqttBroker, port, keepAlive)


client.loop_start()

for msg in ["msgtest1", "msgtest2", "test3"]:
    client.publish("kob/temp", msg)
    print msg


client.loop_stop()  
print "Finished"