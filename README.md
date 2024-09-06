# minitalk

**minitalk** is a project that involves creating a small data exchange program between a client and a server using UNIX signals. This project demonstrates how processes can communicate in a Unix environment using signals such as `SIGUSR1` and `SIGUSR2`.

## Features

- Implement a server that can receive strings sent by a client.
- Implement a client that sends strings to the server one character at a time.
- Use only UNIX signals `SIGUSR1` and `SIGUSR2` to communicate between the client and server.
- Handle errors such as invalid process IDs and signal failures.
- Support for sending strings of variable length.
- Support for unicode characters.

## Getting Started

### Prerequisites

- A Unix-based system (Linux or macOS)
- `gcc` compiler and `make`

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/arnoop88/minitalk.git
   cd minitalk

2. Compile the project:

	```bash
	make

## Running the server

To run the server, execute the following command:
```bash
./server
```
The server will display its process ID (PID), which is needed to communicate with the client.

## Running the client

To run the client and send a message to the server, use the following command:
```bash
./client [server-pid] "Your message here"
```
Replace [server-pid] with the PID provided by the server when it starts.

## Signals

The project uses two UNIX signals for communication:

- `SIGUSR1`: Used to transmit a binary `0`.
- `SIGUSR2`: Used to transmit a binary `1`.
