import copy
import multiprocessing

import pika
from pika.adapters.blocking_connection import BlockingChannel, BlockingConnection


class QueueClient:
    _channel: BlockingChannel
    _connection: BlockingConnection

    def __init__(self):
        pass

    def publish(self, message: str):
        credentials = pika.credentials.PlainCredentials('queue_user',
                                                        'queue_password')
        parameters = pika.ConnectionParameters(host='worksurf',
                                               credentials=credentials)
        self._connection = pika.BlockingConnection(parameters)
        self._channel = self._connection.channel()
        self._channel.exchange_declare(exchange='logs', exchange_type='fanout')
        self._channel.basic_publish(exchange='logs', routing_key='', body=message)
        self._connection.close()


class QueueServer(multiprocessing.Process):
    _channel: BlockingChannel
    _connection: BlockingConnection
    _executables: []
    _lock = multiprocessing.Lock()

    def __init__(self, executables: []):
        multiprocessing.Process.__init__(self)
        self._executables = copy.deepcopy(executables)


    def run(self):
        try:
            credentials = pika.credentials.PlainCredentials('queue_user',
                                                            'queue_password')
            parameters = pika.ConnectionParameters(host='worksurf',
                                                   credentials=credentials)
            self._connection = pika.BlockingConnection(parameters)
            self._channel = self._connection.channel()
            self._channel.exchange_declare(exchange='logs', exchange_type='fanout')
            result = self._channel.queue_declare(queue='', exclusive=True)
            queue_name = result.method.queue
            self._channel.queue_bind(exchange='logs', queue=queue_name)
            self._channel.basic_consume(
                queue=queue_name, on_message_callback=self.callback, auto_ack=True)
            self._channel.start_consuming()
        except Exception as e:
            print(f'exception raise {e}')


    def callback(self, ch, method, properties, body):
        try:
            value = body.decode()
            if self._executables.__contains__(value):
                self._lock.acquire()
                self._executables.remove(value)
                self._lock.release()
            if len(self._executables)==0:
                self._channel.stop_consuming()
                self._connection.close()
        except Exception as e:
            print(f'exception raise {e}')
        pass

    def get_values(self):
        return self._executables


if __name__ == '__main__':
    values = ['1', '2']
    server = QueueServer(values)
    try:
        server.start()
    except Exception as e:
        print(e)
