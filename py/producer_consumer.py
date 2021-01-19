import queue
import threading
import time

serving_line = queue.Queue(maxsize=5)


def service_producer():
    for i in range(20):
        serving_line.put_nowait(f'item {i}')
        print(f'serve {i} remaining capacity {serving_line.maxsize - serving_line.qsize()}')
        time.sleep(0.2)


def service_consumer():
    while True:
        item = serving_line.get()
        print(f'get item {item}')
        time.sleep(0.3)


if __name__ == '__main__':
    for i in range(2):
        threading.Thread(target=service_consumer).start()
    threading.Thread(target=service_producer).start()
