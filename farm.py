import requests
import json
import threading
import time
import RPi.GPIO as GPIO


def toFarm(data_type, value):

    url = "https://api.gardsfabriken.de/api/v1/farm/measurement"

    payload = json.dumps({
      "type": data_type,
      "value": value
    })
    headers = {
      'Content-Type': 'application/json' 
    }
    try:
        response = requests.request("POST", url, headers=headers, data=payload)
        print(response.text)
    except Exception:
        pass



## define threads for each action to  avoid blocking



class TempSensor(threading.Thread):
    def run(self):
        while True:
            temp_cata_file = "/sys/bus/w1/devices/28-0120597725ab/w1_slave"

            with open(temp_cata_file, 'r') as f:
                contents = f.read()

            temp_datum = contents.split()[-1]
            celcius = float(temp_datum.replace("t=", ""))/1000

            print(celcius)
            toFarm("temperature_wachteln", celcius)
            time.sleep(60)



class BlinkyAnimation01(threading.Thread):
    def run(self):
        GPIO.output(23, GPIO.HIGH)
        time.sleep(0.2)
        GPIO.output(23, GPIO.LOW)
        time.sleep(0.1)
        GPIO.output(23, GPIO.HIGH)
        time.sleep(0.1)
        GPIO.output(23, GPIO.LOW)


class ButtonSensor(threading.Thread):
    def run(self):
        # Endlosschleife
        while True:
            if GPIO.input(24) == 0:
                # Ausschalten
                GPIO.output(23, GPIO.LOW)
            else:
                # Einschalten
                GPIO.output(23, GPIO.HIGH)
                run = BlinkyAnimation01()
                run.start()
                toFarm("egg_button", 1)
                run.join()
                # send one more EGG to the SERVER
                # make some nice animation
           



if __name__ == "__main__":
    GPIO.setmode(GPIO.BCM)

    GPIO.setup(23, GPIO.OUT)
    GPIO.setup(24, GPIO.IN)



    run_temp = TempSensor()
    run_temp.start()
    run_button = ButtonSensor()
    run_button.start()


