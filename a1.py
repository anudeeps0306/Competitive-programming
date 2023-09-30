import paho.mqtt.client as mqtt
import time
import random

client = mqtt.Client()
client.connect('localhost', 1883)


topics = [
    'shopping_mall/shoes',
    'shopping_mall/clothes',
    'shopping_mall/accessories',
    'shopping_mall/electronics',
    'shopping_mall/home_appliances'
]

offers = {
    'Bata': '10% off',
    'Nike': '40% off',
    'Adidas': '30% off',
    'Puma': '20% off'
}

def on_message(client, userdata, message):
    topic = message.topic
    offer = message.payload.decode()
    print(f'This is booked Received message recive: {offer}')

client.on_message = on_message

while True:
    topic = random.choice(topics)
    brand = random.choice(list(offers.keys()))
    message = f'{brand} {offers[brand]}'
    client.publish(topic, message)

  
    print(f'Sent message: {message} to topic: {topic}')
    client.subscribe('shopping_mall/#')
    client.loop(timeout=1.0)

    time.sleep(5)




# Convert the given tables in graph data model

# Employee table

# ID           Name    DOJ                  Experience     BaseLocation     CurrentLocation

# E101      Ajay       12/04/2023    06                   JBP                      BPL

 

# Project table

# ProjectID            ProjectName         ProjectManager               ClientName                  ProjectStartDate

# P1001                  AAA                       Alex                                 XXX                                 12/06/23

# P1002                  BBB                       Bob                                  YYY                                 11/06/23

# P1003                  CCC                      Andrews                           ZZZ                                22/03/23

 

# Employee_Project table

# EmpID                              ProjectID

# E101                                 P1001

# E101                                 P1002

# E101                                 P1003

convert the given tables in graph data model

Employee table

ID           Name    DOJ                  Experience     BaseLocation   




CREATE NODE Employee (ID, Name, DOJ, Experience, BaseLocation, CurrentLocation); USING GRAPH DATABASE

CREATE EDGE Employee_Project (EmpID, ProjectID); USING GRAPH DATABASE


create employee_project (empid, projectid) values (E101, P1001)


create empolyee_project (a : )






