import socket
HOST,PORT = 'localhost',8080
listen_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
listen_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
listen_socket.bind((HOST,PORT))
listen_socket.listen(1)
print('SOCKET IS ON LISTENING BABY Whoooooo :))')
while True:
    client_connection,client_address=listen_socket.accept()
    req = client_connection.recv(1024)
    print(req)
    http_response = """\
HTTP/1.1 200 OK
<h1>asdadas</H1>
"""
    client_connection.sendall(http_response)
    client_connection.close()
