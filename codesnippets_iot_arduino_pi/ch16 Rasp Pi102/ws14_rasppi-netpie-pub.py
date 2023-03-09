import microgear.client as microgear
import time
import logging

appid = "KobkiatProject"
gearkey = "u1urxmmgdThe___" 
gearsecret =  "NVhwAgueFTnGW_________"
alias = "kobPi"; 
pubtopic = "/kobkiat/switch"
counter = 0

microgear.create(gearkey,gearsecret,appid,{'debugmode': False})

def connection():
    logging.info("Now I am connected with netpie")

def subscription(topic,message):
    logging.info(topic+" "+message)

def disconnect():
    logging.debug("disconnect is work")

microgear.setalias(alias)
microgear.on_connect = connection
microgear.on_message = subscription
microgear.on_disconnect = disconnect

microgear.connect(False)

while True:
 	if(microgear.connected):
 		counter += 1
 		print('publishing %d' % (counter % 2))

 		microgear.publish(pubtopic,(counter % 2))
 	time.sleep(2)