import socket

SERVER = ('127.0.0.1', 8080)
MSG = "Hello from Client"

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    s.settimeout(5.0)
    s.sendto(MSG.encode(), SERVER)
    try:
        data, _ = s.recvfrom(1024)
        print("Server:", data.decode())
    except socket.timeout:
        print("No response from server (timeout)")