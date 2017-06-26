import time
import logging
import socket



logging.basicConfig(level=logging.DEBUG,
                    format='(%(threadName)-10s) %(message)s',
                    )
sock = socket.socket()


class HTTP_SERVER(threading.Thread):
    def __init__(self,serverPort):
        self.serverPort = serverPort
        threading.Thread.__init__(self)
    def run_test_script(self):
        time.sleep(5)

    def run(self):
        
        logging.debug('running with %s and',self.serverPort)
        try:
        sock.bind(('', int(sys.argv[1])))
        except:
            sock.bind(('',3215))
    sock.listen(5)
        
        
        return

    
    
    
    
import threading    
    

def run_server():
    
    try:
        sock.bind(('', int(sys.argv[1])))
    except:
        sock.bind(('',3215))
    sock.listen(5)
    while True :
        client, adress = sock.accept()
        
        
        client_request = client.recv(1000)
      #  print request_parser(client_request)
      #  print client_request
        print client_request
        client.send('HTTP/1.0 200 OK\n')
        client.send('Content-Type: text/html\n\n')
        config_data = read_config()
        file = open(config_data[0])

        client.send("{}".format(file.read()))
        client.close()
        


def request_parser(request):
    
    request_raw_data =  request.split('\n')
    return request_raw_data[2].split('/')

def read_config():
    config_file = open("site_config/main.yml","r")
    config_data = yaml.load(config_file)
    try:
        return config_data['docs_path'],config_data['author']
    except :
        return "NO docs_path ARGUMENT FOUND main.yml file. "