import requests


class MakerTrigger(object):
  def __init__(self,key,trigger):
    self.key = key
    self.trigger = trigger
    self.maker = "https://maker.ifttt.com/trigger/" + self.trigger + "/with/key/" + self.key
  def sendTrigger(self,value1=0,value2=0,value3=0):
    self.value1 = value1
    self.value2 = value2
    self.value3 = value3
    self.json={"value1": self.value1, "value2": self.value2, "value3": self.value3}
    r = requests.post(self.maker, json=self.json)
    return(r)

key = "cFZsBy9yOfGhLnxxx____________"
trigger = "temp"
ifttt = MakerTrigger(key,trigger)
ret = ifttt.sendTrigger("id772","25","50")    
print(ret)
