import sys
import os
import time
import webbrowser
from django.core.management import execute_from_command_line

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "website.settings")


def resource_path(relative_path):
    """ Get absolute path to resource, works for dev and for PyInstaller """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)


def run_server():
    execute_from_command_line(
        ["manage.py", "runserver", "--noreload", "--insecure"])
    os.system("start http://127.0.0.1:8000")


if __name__ == "__main__":
    run_server()
