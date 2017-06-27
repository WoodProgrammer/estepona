import socket
import time
import logging
import sys 
from mimetools import Message
from StringIO import StringIO
import yaml
import threading

logging.basicConfig(level=logging.DEBUG,
                    format='(%(threadName)-10s) %(message)s',
                    )



def request_parser(request):
    
    request_raw_data =  request.split('\n')
    return request_raw_data[2].split('/')

def read_config(param):
    config_file = open("site_config/main.yml","r")
    config_data = yaml.load(config_file)
    try:
        return config_data['{}'.format(param)]
    except :
        return "NO docs_path ARGUMENT FOUND main.yml file. "

def key_input():
    while key == 'STOP':
        key = raw_input('ENTER')
    exit(1)


sock = socket.socket()
sock.bind(('', 3215))
sock.listen(5)


wait_input = threading.Thread(target=key_input,args=())


def handle_request():

    while True :

        client, adress = sock.accept()
        client_request = client.recv(1000)
        print client_request

        client.send('HTTP/1.0 200 OK\n')
        client.send('Content-Type: text/html\n\n')
        config_data = read_config('docs_path')
        file = open(config_data)

        client.send("{}".format(file.read()))
        print client

        client.close()



def run_server(thread_count= 2):
    threads = [threading.Thread(target=handle_request, args=()) for i in range(thread_count)]

    for thread in threads:
        thread.start()

        print threading.enumerate()

    print threading.enumerate()



print threading.enumerate()

run_server(int(read_config('thread_count')))
