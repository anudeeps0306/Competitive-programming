import paho.mqtt.client as mqtt

broker_address = "localhost"
topic = "my/topic"

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe(topic)

def on_message(client, userdata, message):
    print("Message received on topic '" + message.topic + "': " + str(message.payload.decode()))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(broker_address, 1883, 60)

client.loop_forever()
