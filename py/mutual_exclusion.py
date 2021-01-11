import threading
import time

count = 0
lock = threading.Lock()


def client():
    global count
    for i in range(5):
        lock.acquire()
        count += 1
        time.sleep(0.1)
        lock.release()


if __name__ == '__main__':
    counter1 = threading.Thread(target=client)
    counter2 = threading.Thread(target=client)
    counter3 = threading.Thread(target=client)

    counter1.start()
    counter2.start()
    counter3.start()
    counter1.join()
    counter2.join()
    counter3.join()

    print(f'Total:', count)
