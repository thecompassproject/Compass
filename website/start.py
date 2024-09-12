import sys
import os
import webbrowser
from django.core.management import execute_from_command_line
import time
import threading
import webbrowser

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "website.settings")
ip = "127.0.0.1"
port = 8000
url = f"http://{ip}:{port}"


def resource_path(relative_path):
    """ Get absolute path to resource, works for dev and for PyInstaller """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)


def start_server():
   execute_from_command_line(
        ["manage.py", "runserver", "--noreload", "--insecure"])


if __name__ == '__main__':
    threading.Thread(target=start_server).start()
    webbrowser.open_new(url)

    while True:
        try:
            time.sleep(1)
        except KeyboardInterrupt:
            sys.exit(0)
