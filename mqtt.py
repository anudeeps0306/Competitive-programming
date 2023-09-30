import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect('localhost', 1883)

def on_message(client, userdata, message):
    topic = message.topic
    offer = message.payload.decode()
    print(f'Received message: {offer} on topic: {topic}')
    response = input('Would you like to book this offer? (y/n)')
    if response.lower() == 'y':
        new_order = f'Order for {offer} placed!'
        client.publish(topic, new_order)
        print(f'Order for {offer} placed!')
    else:
        new_order = f'Order not placed!'
        client.publish(topic, new_order)
        print('Offer not booked.')

client.on_message = on_message

client.subscribe('shopping_mall/#')

client.loop_forever()
