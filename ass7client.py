import socket

HOST = '127.0.0.1'
PORT = 8080
MSG = "Hello from Client"

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    s.settimeout(5.0)
    s.sendto(MSG.encode(), (HOST, PORT))
    try:
        data, addr = s.recvfrom(1024)
        print("Server:", data.decode())
    except socket.timeout:
        print("No response (timeout)")