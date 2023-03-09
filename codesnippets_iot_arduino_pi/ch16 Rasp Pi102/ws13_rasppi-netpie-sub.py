import microgear.client as microgear
import time
import logging

appid = "KobkiatProject"
gearkey = "u1urxmmgd___" # 
gearsecret =  "NVhwAgueFTnGWsB___"
alias = "kobPi"; 

microgear.create(gearkey,gearsecret,appid,{'debugmode': False})

def connection():
    logging.info("Now I am connected with netpie")

def subscription(topic,message):
    logging.info(topic+" "+message)
    print('--> %s' % message)

def disconnect():
    logging.debug("disconnect is work")

microgear.setalias(alias)
microgear.on_connect = connection
microgear.on_message = subscription
microgear.on_disconnect = disconnect
microgear.subscribe("/sensor/+")
microgear.connect(True)

