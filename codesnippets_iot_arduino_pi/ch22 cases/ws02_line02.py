# -*- coding: utf-8 -*-


from line_notify import LineNotify

ACCESS_TOKEN = "j3DX08ec0q3Tqgsld9cAWuEd9W___________"
imageFile = './myimg.jpg'

notify = LineNotify(ACCESS_TOKEN)

notify.send("Text test ทดสอบ")
notify.send("Image test ทดสอบ", image_path=imageFile)
notify.send("Sticker ทดสอบ ", sticker_id=1, package_id=1)
notify.send("Image & Sticker ทดสอบ test", 
	image_path=imageFile, 
	sticker_id=283, package_id=4)

