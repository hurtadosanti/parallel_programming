import threading
import time

count_01 = 0
count_02 = 0
lock = threading.RLock()


def increase_counter_01():
    global count_01
    for i in range(10):
        lock.acquire()
        count_01 += 1
        lock.release()


def increase_counter_02():
    global count_02
    for i in range(10):
        lock.acquire()
        count_02 += 1
        increase_counter_01()
        lock.release()


if __name__ == '__main__':
    counter1 = threading.Thread(target=increase_counter_01)
    counter2 = threading.Thread(target=increase_counter_02)

    counter1.start()
    counter2.start()
    counter1.join()
    counter2.join()

    print('Total:', count_01, count_02)
