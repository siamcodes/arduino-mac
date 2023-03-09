import microgear.client as microgear
import time
import logging

appid = "KobkiatProject"
gearkey = "u1urxmmgd___" 
gearsecret = "NVhwAgueFTnG______"
alias = "kobPi"; 

microgear.create(gearkey,gearsecret,appid,{'debugmode': True})

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
		microgear.chat(alias,"Hello world."+str(int(time.time())))
	time.sleep(3)