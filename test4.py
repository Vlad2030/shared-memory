from loguru import logger
import json
# https://docs.python.org/3/library/json.html
import websocket
# https://websocket-client.readthedocs.io/en/latest/_modules/websocket/_app.html
import ctypes

sharedmem = ctypes.CDLL("sharedmem.c") 
# подключаем свою библиотеку sharedmem.so
sharedmem.restype = ctypes.c_char

BASE_URL: str = ""

class Memory:
    def __init__(self) -> None:
        self.write = Memory.write

    def write(message):
        return


class Operations:
    def __init__(self) -> None:
        self.message = Operations.message
        self.error = Operations.error
        self.open = Operations.open

    def message(ws, message):
        return Memory.write(message)

    def error(ws, error):
        return logger.error(error)

    def open(ws):
        params = {
            # стакани на декілька пар
            "method": "",
            "params": [
                "",
            ],
        }
        return ws.send(json.dumps(params))


if __name__ == "__main__":
    websocket.enableTrace(True)
    ws = websocket.WebSocketApp(
        url=BASE_URL,
        on_open=Operations.open,
        on_message=Operations.message,
        on_error=Operations.error,
    )
    ws.run_forever(
        ping_timeout=10,
        skip_utf8_validation=True,
    )

