
# 📡 Computer Networks (CN) Lab

## 📘 Overview

This repository contains implementations of important **Computer Networks laboratory experiments** using both **C++ and Python**. The aim is to understand key networking concepts such as error detection, reliable communication, socket programming, and subnetting through practical implementation.

---

## 🧪 Experiments Included

### 🔢 1. Hamming Code (C++)

* Implemented in **C++**
* Detects and corrects **single-bit errors**
* Uses parity bit generation for error detection
* Demonstrates **error control coding in data transmission**

---

### 📦 2. Go-Back-N ARQ Protocol (C++)

* Implemented in **C++**
* Simulates **sliding window protocol**
* Handles:

  * Packet transmission
  * Acknowledgement (ACK)
  * Packet loss and retransmission
* Demonstrates **reliable data transfer in computer networks**

---

### 🌐 3. Client-Server Communication (Python)

* Implemented in **Python**
* Uses **socket programming (TCP/IP)**
* Features:

  * Client sends request to server
  * Server responds to client messages
* Demonstrates **basic network communication model**

---

### 🧮 4. Subnetting (C++)

* Implemented in **C++**
* Performs IP address calculations:

  * Network Address
  * Broadcast Address
  * Subnet Mask
  * Number of Hosts per subnet
* Helps understand **IP addressing and subnetting concepts**

---

## 🛠️ Technologies Used

* **C++**
* **Python**
* Socket Programming (TCP/IP)
* Computer Networking Concepts
* Command Line Interface

---

## 📂 Project Structure

```bash
CN-Lab/
│
├── hamming_code.cpp
├── go_back_n.cpp
├── subnetting.cpp
│
├── client.py
├── server.py
│
└── README.md
```

---

## 🚀 How to Run

### 🔧 Compile C++ Programs

```bash
g++ hamming_code.cpp -o hamming
g++ go_back_n.cpp -o gobackn
g++ subnetting.cpp -o subnetting
```

---

### ▶️ Run C++ Programs

#### 🔢 Hamming Code

```bash
./hamming
```

#### 📦 Go-Back-N

```bash
./gobackn
```

#### 🧮 Subnetting

```bash
./subnetting
```

---

### ▶️ Run Python Programs

#### 🌐 Server

```bash
python server.py
```

#### 🌐 Client

```bash
python client.py
```

---

## 🎯 Learning Outcomes

* Understanding **error detection & correction techniques**
* Implementation of **Go-Back-N sliding window protocol**
* Hands-on experience with **socket programming in Python**
* Practical knowledge of **IP addressing and subnetting**

---

## 👨‍💻 Author

* **Name:** Ritesh Deshmukh


---

## 📜 License

This project is created for **educational purposes only**.

---




