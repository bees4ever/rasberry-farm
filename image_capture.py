import requests
import os

os.system("raspistill -o rasberryimage.png")



url = "https://api.gardsfabriken.de/api/v1/farm/file?type=shed_cam"

payload={}
files=[
  ('file',('Shed_Image.png' ,open('/home/pi/scripts/rasberryimage.png','rb'),'image/png'))
]
headers = {}

response = requests.request("POST", url, headers=headers, data=payload, files=files)

os.system("rm rasberryimage.png")

print(response.text)


